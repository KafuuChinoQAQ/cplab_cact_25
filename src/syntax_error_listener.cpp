#include "syntax_error_listener.h"
#include "antlr4-runtime.h"
#include <iostream>
namespace cplab_parser 
{
    void CplabSyntaxErrorListener::syntaxError(antlr4::Recognizer *recognizer,
                                            antlr4::Token *offendingSymbol,
                                            size_t line,
                                            size_t charPositionInLine,
                                            const std::string &msg,
                                            std::exception_ptr e) 
    {
        has_syntax_error = true;
        std::cerr << "    Syntax Error Message: " << msg << std::endl; // 输出具体的语法错误信息
        std::cerr << "    Line: " << line << ", Position: " << charPositionInLine << std::endl; // 输出错误所在行和列
        std::cerr << "    Offending Symbol: " << (offendingSymbol ? offendingSymbol->getText() : "N/A") << std::endl; // 输出错误的token
    }

    bool CplabSyntaxErrorListener::hasSyntaxError() 
    {
        return has_syntax_error;
    }
}