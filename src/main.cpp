#include <filesystem> // 文件系统库 需要C++17标准
#include <iostream>   // 标准输入输出流
#include <fstream>    // 文件流
#include <iomanip>    // 用于格式化输出

#include "ANTLRInputStream.h" // antlr头文件 位于deps/antlr4-runtime目录下
#include "CplabLexer.h"       // 词法分析器头文件 位于grammar目录下
#include "CplabParser.h"      // 语法分析器头文件 位于grammar目录下
#include "syntax_error_listener.h" // 语法错误监听器头文件 位于src目录下

// 递归打印语法树，包含语法单元类型
void printParseTree(antlr4::tree::ParseTree *tree, antlr4::Parser *parser, const std::string &prefix = "", bool isLast = true)
{
    // 打印当前节点
    std::cout << prefix;
    std::cout << (isLast ? "└── " : "├── ");

    // 获取节点文本
    std::string nodeText = tree->getText();
    // 获取语法单元类型（规则名称）
    std::string ruleName = "";
    if (auto *ctx = dynamic_cast<antlr4::ParserRuleContext *>(tree)) {
        ruleName = parser->getRuleNames()[ctx->getRuleIndex()];
    }

    // 打印节点信息
    std::cout << nodeText;
    if (!ruleName.empty()) {
        std::cout << " (" << ruleName << ")";
    }
    std::cout << std::endl;

    // 获取子节点数量
    size_t childCount = tree->children.size();
    for (size_t i = 0; i < childCount; ++i)
    {
        // 递归打印子节点
        printParseTree(tree->children[i], parser, prefix + (isLast ? "    " : "│   "), i == childCount - 1);
    }
}

int main(int argc, const char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <input file>" << std::endl << std::endl;
        return 1;
    } // 检查命令行参数

    std::ifstream stream(argv[1]); // 打开文件
    if (!stream)
    {
        std::cerr << "Failed to open file: " << argv[1] << std::endl << std::endl;
        return 1;
    } // 检查输入文件

    // 获取不包括路径的文件名
    std::string filename = std::filesystem::path(argv[1]).filename().string();

    // 建立antlr处理流
    antlr4::ANTLRInputStream input(stream);           // 从文件建立antlr输入流input
    cplab_parser::CplabLexer lexer(&input);           // 建立词法分析器lexer
    antlr4::CommonTokenStream tokens(&lexer);         // 建立token流
    cplab_parser::CplabParser parser(&tokens);        // 建立语法分析器parser
    lexer.removeErrorListeners();                     // 删除默认的错误监听器
    parser.removeErrorListeners();                    // 删除默认的错误监听器
    cplab_parser::CplabSyntaxErrorListener cact_error_listener; // 创建语法错误监听器并将其添加到lexer和parser
    lexer.addErrorListener(&cact_error_listener);
    parser.addErrorListener(&cact_error_listener);

    try
    {
        antlr4::tree::ParseTree *tree = parser.compilation_unit(); // 解析输入文件
        if (cact_error_listener.hasSyntaxError()) // 检查是否有语法错误
        {
            std::cerr << "\033[33m" << filename << ": Syntax error detected." << "\033[0m" << std::endl << std::endl; // 输出错误信息
            return 1;
        }
        if (tokens.LA(1) != antlr4::Token::EOF) // 检查是否还有未消费的 token
        {
            std::cerr << "\033[31m" << filename << ": Error: Unmatched input detected after parsing.\033[0m" << std::endl << std::endl;
            return 1;
        }
        // 打印语法分析树（树形结构，包含语法单元类型）
        std::cout << "\033[34mSyntax Tree (Tree View):\033[0m" << std::endl;
        printParseTree(tree, &parser); // 调用递归函数打印树形结构
        std::cout << std::endl;

        std::cout << "\033[32m" << filename << ": Parsing succeeded." << "\033[0m" << std::endl << std::endl; // 输出成功信息
        return 0;
    }
    catch (const std::exception &e) // 捕获异常
    {
        std::cerr << "Parsing failed: " << e.what() << std::endl << std::endl; // 输出异常信息
        return 1;
    }

    return 1;
}