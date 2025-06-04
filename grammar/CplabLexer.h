
// Generated from E:/Homework/cplab/cact/grammar/CplabLexer.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"


namespace cplab_parser {


class  CplabLexer : public antlr4::Lexer {
public:
  enum {
    Const = 1, Int = 2, Char = 3, Float = 4, Void = 5, If = 6, Else = 7, 
    While = 8, Break = 9, Continue = 10, Return = 11, Equal = 12, LogicalEqual = 13, 
    LogicalAnd = 14, LogicalOr = 15, NotEqual = 16, Less = 17, LessEqual = 18, 
    Greater = 19, GreaterEqual = 20, Period = 21, Comma = 22, Semicolon = 23, 
    Colon = 24, LeftParenthesis = 25, RightParenthesis = 26, LeftBracket = 27, 
    RightBracket = 28, LeftBrace = 29, RightBrace = 30, Plus = 31, Minus = 32, 
    Pipe = 33, ExclamationMark = 34, Asterisk = 35, Slash = 36, Percent = 37, 
    Identifier = 38, IntegerConstant = 39, FloatConstant = 40, CharConstant = 41, 
    LineComment = 42, BlockComment = 43, NewLine = 44, WhiteSpaces = 45
  };

  explicit CplabLexer(antlr4::CharStream *input);

  ~CplabLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

}  // namespace cplab_parser
