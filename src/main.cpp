#include <iostream>

#include "ANTLRInputStream.h" // antlr头文件 位于deps/antlr4-runtime目录下

#include "CplabLexer.h" // 词法分析器头文件 位于grammar目录下
#include "CplabParser.h" // 语法分析器头文件 位于grammar目录下
#include "syntax_error_listener.h" // 语法错误监听器头文件 位于src目录下

int main(int argc, const char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <input file>" << std::endl;
        return 1;
    } // 检查命令行参数

    std::ifstream stream(argv[1]); //打开文件
    if (!stream)
    {
        std::cerr << "Failed to open file: " << argv[1] << std::endl;
        return 1;
    } // 检查输入文件
    antlr4::ANTLRInputStream input(stream); // 从文件建立antlr输入流input
    cplab_parser::CplabLexer lexer(&input); // 建立词法分析器lexer
    antlr4::CommonTokenStream tokens(&lexer); // 建立token流
    cplab_parser::CplabParser parser(&tokens); // 建立语法分析器parser
    lexer.removeErrorListeners(); // 删除默认的错误监听器
    parser.removeErrorListeners(); // 删除默认的错误监听器
    cplab_parser::CplabSyntaxErrorListener cact_error_listener; // 创建语法错误监听器并将其添加到lexer和parser
    lexer.addErrorListener(&cact_error_listener);
    parser.addErrorListener(&cact_error_listener);

    try
    {
        antlr4::tree::ParseTree *tree = parser.compilation_unit(); // 解析输入文件
        if (cact_error_listener.hasSyntaxError()) // 检查是否有语法错误
        {
            std::cerr << "Syntax error detected." << std::endl;
            return 1;
        }
    }
    catch (const std::exception &e)  // 捕获异常
    {
        std::cerr << "Parsing failed: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}