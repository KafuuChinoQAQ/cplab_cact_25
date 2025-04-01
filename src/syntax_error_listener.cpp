#include "syntax_error_listener.h"
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
        std::cerr << "    Syntax Error Message: " << msg << std::endl;
    }

    bool CplabSyntaxErrorListener::hasSyntaxError() 
    {
        return has_syntax_error;
    }
}