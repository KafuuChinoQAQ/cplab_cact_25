#include <filesystem> // 文件系统库 需要C++17标准
#include <iostream>   // 标准输入输出流

#include "ANTLRInputStream.h" // antlr头文件 位于deps/antlr4-runtime目录下
#include "CplabLexer.h"       // 词法分析器头文件 位于grammar目录下
#include "CplabParser.h"      // 语法分析器头文件 位于grammar目录下
#include "syntax_error_listener.h" // 语法错误监听器头文件 位于src目录下
#include "ast_generator.h" // AST生成器头文件 位于src目录下
#include "variable_scope_generator.h" // 作用域生成器头文件 位于src目录下
#include "ir_generator.h" // IR生成器头文件 位于src目录下
#include "static_check.h" // 静态检查头文件 位于src目录下

// 递归打印语法树，包含语法单元类型
void printParseTree(antlr4::tree::ParseTree *tree, antlr4::Parser *parser, std::ostream &out, const std::string &prefix = "", bool isLast = true, int childIndex = -1)
{
    // 打印当前节点
    out << prefix;
    out << (isLast ? "└── " : "├── ");

    // 获取节点文本
    std::string nodeText = tree->getText();
    // 获取语法单元类型（规则名称）和index
    std::string ruleName = "";
    int ruleIndex = -1;
    // 如果节点是ParserRuleContext类型，则获取规则名称
    if (auto *ctx = dynamic_cast<antlr4::ParserRuleContext *>(tree)) {
        ruleIndex = ctx->getRuleIndex();
        ruleName = parser->getRuleNames()[ruleIndex];
    }
    // 如果节点是TerminalNode类型，则获取token类型
    else if (auto *terminalNode = dynamic_cast<antlr4::tree::TerminalNode *>(tree)) {
        ruleIndex = terminalNode->getSymbol()->getType();
        ruleName = parser->getVocabulary().getSymbolicName(ruleIndex);
    }
    // 打印节点信息:先输出index再输出rule_name
    out << nodeText;
    if (!ruleName.empty()) {
        out << " (" << ruleName << ")";
    }
    out << std::endl;

    // 获取子节点数量
    size_t childCount = tree->children.size();
    for (size_t i = 0; i < childCount; ++i)
    {
        // 递归打印子节点
        printParseTree(tree->children[i], parser, out, prefix + (isLast ? "    " : "│   "), i == childCount - 1, static_cast<int>(i));
    }
}

// 编译器主函数
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

        // 设置输出目录为./output,文件名为输入文件名后加.txt后缀
        std::string output_filepath = "./output/" + filename + ".txt";

        // 打印语法分析树到文本文件中（树形结构，包含语法单元类型）
        std::cout << "\033[34mSyntax Tree (Tree View):\033[0m" << std::endl;
        std::ofstream outfile_0(output_filepath); // 以追加模式输出到文件
        printParseTree(tree, &parser, outfile_0); // 调用递归函数打印树形结构到文件
        outfile_0.close();
        std::cout << "语法树已输出" << std::endl << std::endl;
        
        // 生成AST
        ast_node ast_root = cplab_ast_generator::ast_generator(tree, &parser); // 调用AST生成器函数
        cplab_ast_generator::set_parent_pointers(ast_root, nullptr); // 设置AST中各节点的父节点指针
        std::cout << "AST已生成" << std::endl << std::endl; // 输出AST生成成功信息
        // 生成作用域树
        scope_node scope_root = cplab_variable_scope_generator::variable_scope_generator(ast_root); // 调用作用域生成器函数
        std::cout << "作用域树已生成" << std::endl << std::endl; // 输出作用域树生成成功信息
        // 生成IR代码
        cplab_ir_generator::ir_gen_declaration(ast_root); // 先生成declaration相关结点的IR代码
        // 打印作用域树到文本文件中
        std::ofstream outfile_2(output_filepath, std::ios::app); // 以追加模式输出到文件
        outfile_2 << std::endl << "Variable Scope Tree:" << std::endl; // 输出作用域树标题
        cplab_variable_scope_generator::variable_scope_printer(scope_root, outfile_2); // 调用作用域打印函数
        outfile_2.close(); // 关闭输出文件
        std::cout << "作用域树已输出" << std::endl << std::endl; // 输出作用域树成功信息

        cplab_ir_generator::ir_generator(ast_root); // 调用其余部分的IR生成器函数

        // 静态检查

        // 以上为静态检查部分


        // 将新生成的AST输出到文本文件中
        std::ofstream outfile_3(output_filepath, std::ios::app); // 以追加模式输出到文件
        outfile_3 << std::endl << "Abstract Syntax Tree (AST):" << std::endl; // 输出AST标题
        cplab_ast_generator::ast_printer(ast_root, outfile_3); // 调用AST打印函数 
        outfile_3.close(); // 关闭输出文件
        
        // 将AST根节点的IR代码覆盖输出到test.ll文件中
        std::ofstream outfile_4("test.ll"); // 打开test.ll文件
        outfile_4 << ast_root.ir_code; // 将AST根节点的IR代码写入文件
        outfile_4.close(); // 关闭输出文件
        std::cout << "IR代码已输出到test.ll" << std::endl << std::endl; // 输出IR代码成功信息
        
        return 0;
    }
    catch (const std::exception &e) // 捕获异常
    {
        std::cerr << "Parsing failed: " << e.what() << std::endl << std::endl; // 输出异常信息
        return 1;
    }

    return 1;
}