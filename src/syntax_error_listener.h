#ifndef CPLAB_SYNTAX_ERROR_LISTENER
#define CPLAB_SYNTAX_ERROR_LISTENER

#include "BaseErrorListener.h"

namespace cplab_parser 
{
    class CplabSyntaxErrorListener final : public antlr4::BaseErrorListener 
    {
        public:
            void syntaxError(antlr4::Recognizer *recognizer,
                            antlr4::Token *offendingSymbol,
                            size_t line,
                            size_t charPositionInLine,
                            const std::string &msg,
                            std::exception_ptr e) override; // 覆写语法错误函数
            bool hasSyntaxError(); // 检查是否有语法错误的函数

        private:
            bool has_syntax_error{}; // 语法错误标志 默认值为false
    };
}

#endif