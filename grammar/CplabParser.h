
// Generated from E:/Homework/cplab/cact/grammar/CplabParser.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"


namespace cplab_parser {


class  CplabParser : public antlr4::Parser {
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

  enum {
    RuleCompilation_unit = 0, RuleDeclaration = 1, RuleConstant_declaration = 2, 
    RuleBasic_type = 3, RuleConstant_definition = 4, RuleConstant_initial_value = 5, 
    RuleVariable_declaration = 6, RuleVariable_definition = 7, RuleFunction_definition = 8, 
    RuleFunction_type = 9, RuleFunction_formal_params = 10, RuleFunction_formal_param = 11, 
    RuleBlock = 12, RuleBlock_item = 13, RuleStatement = 14, RuleExpression = 15, 
    RuleConstant_expression = 16, RuleCondition = 17, RuleLeft_value = 18, 
    RuleNumber = 19, RuleFunction_real_params = 20, RulePrimary_expression = 21, 
    RuleUnary_expression = 22, RuleMultiplicative_expression = 23, RuleAdditive_expression = 24, 
    RuleRelational_expression = 25, RuleEqual_expression = 26, RuleLogical_and_expression = 27, 
    RuleLogical_or_expression = 28
  };

  explicit CplabParser(antlr4::TokenStream *input);

  CplabParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~CplabParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class Compilation_unitContext;
  class DeclarationContext;
  class Constant_declarationContext;
  class Basic_typeContext;
  class Constant_definitionContext;
  class Constant_initial_valueContext;
  class Variable_declarationContext;
  class Variable_definitionContext;
  class Function_definitionContext;
  class Function_typeContext;
  class Function_formal_paramsContext;
  class Function_formal_paramContext;
  class BlockContext;
  class Block_itemContext;
  class StatementContext;
  class ExpressionContext;
  class Constant_expressionContext;
  class ConditionContext;
  class Left_valueContext;
  class NumberContext;
  class Function_real_paramsContext;
  class Primary_expressionContext;
  class Unary_expressionContext;
  class Multiplicative_expressionContext;
  class Additive_expressionContext;
  class Relational_expressionContext;
  class Equal_expressionContext;
  class Logical_and_expressionContext;
  class Logical_or_expressionContext; 

  class  Compilation_unitContext : public antlr4::ParserRuleContext {
  public:
    Compilation_unitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<DeclarationContext *> declaration();
    DeclarationContext* declaration(size_t i);
    std::vector<Function_definitionContext *> function_definition();
    Function_definitionContext* function_definition(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Compilation_unitContext* compilation_unit();

  class  DeclarationContext : public antlr4::ParserRuleContext {
  public:
    DeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Constant_declarationContext *constant_declaration();
    Variable_declarationContext *variable_declaration();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclarationContext* declaration();

  class  Constant_declarationContext : public antlr4::ParserRuleContext {
  public:
    Constant_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Const();
    Basic_typeContext *basic_type();
    std::vector<Constant_definitionContext *> constant_definition();
    Constant_definitionContext* constant_definition(size_t i);
    antlr4::tree::TerminalNode *Semicolon();
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constant_declarationContext* constant_declaration();

  class  Basic_typeContext : public antlr4::ParserRuleContext {
  public:
    Basic_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Int();
    antlr4::tree::TerminalNode *Float();
    antlr4::tree::TerminalNode *Char();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Basic_typeContext* basic_type();

  class  Constant_definitionContext : public antlr4::ParserRuleContext {
  public:
    Constant_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *Equal();
    Constant_initial_valueContext *constant_initial_value();
    std::vector<antlr4::tree::TerminalNode *> LeftBracket();
    antlr4::tree::TerminalNode* LeftBracket(size_t i);
    std::vector<antlr4::tree::TerminalNode *> IntegerConstant();
    antlr4::tree::TerminalNode* IntegerConstant(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RightBracket();
    antlr4::tree::TerminalNode* RightBracket(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constant_definitionContext* constant_definition();

  class  Constant_initial_valueContext : public antlr4::ParserRuleContext {
  public:
    Constant_initial_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Constant_expressionContext *constant_expression();
    antlr4::tree::TerminalNode *LeftBrace();
    antlr4::tree::TerminalNode *RightBrace();
    std::vector<Constant_initial_valueContext *> constant_initial_value();
    Constant_initial_valueContext* constant_initial_value(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constant_initial_valueContext* constant_initial_value();

  class  Variable_declarationContext : public antlr4::ParserRuleContext {
  public:
    Variable_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Basic_typeContext *basic_type();
    std::vector<Variable_definitionContext *> variable_definition();
    Variable_definitionContext* variable_definition(size_t i);
    antlr4::tree::TerminalNode *Semicolon();
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Variable_declarationContext* variable_declaration();

  class  Variable_definitionContext : public antlr4::ParserRuleContext {
  public:
    Variable_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    std::vector<antlr4::tree::TerminalNode *> LeftBracket();
    antlr4::tree::TerminalNode* LeftBracket(size_t i);
    std::vector<antlr4::tree::TerminalNode *> IntegerConstant();
    antlr4::tree::TerminalNode* IntegerConstant(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RightBracket();
    antlr4::tree::TerminalNode* RightBracket(size_t i);
    antlr4::tree::TerminalNode *Equal();
    Constant_initial_valueContext *constant_initial_value();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Variable_definitionContext* variable_definition();

  class  Function_definitionContext : public antlr4::ParserRuleContext {
  public:
    Function_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Function_typeContext *function_type();
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *LeftParenthesis();
    antlr4::tree::TerminalNode *RightParenthesis();
    BlockContext *block();
    Function_formal_paramsContext *function_formal_params();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_definitionContext* function_definition();

  class  Function_typeContext : public antlr4::ParserRuleContext {
  public:
    Function_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Void();
    antlr4::tree::TerminalNode *Int();
    antlr4::tree::TerminalNode *Float();
    antlr4::tree::TerminalNode *Char();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_typeContext* function_type();

  class  Function_formal_paramsContext : public antlr4::ParserRuleContext {
  public:
    Function_formal_paramsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Function_formal_paramContext *> function_formal_param();
    Function_formal_paramContext* function_formal_param(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_formal_paramsContext* function_formal_params();

  class  Function_formal_paramContext : public antlr4::ParserRuleContext {
  public:
    Function_formal_paramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Basic_typeContext *basic_type();
    antlr4::tree::TerminalNode *Identifier();
    std::vector<antlr4::tree::TerminalNode *> LeftBracket();
    antlr4::tree::TerminalNode* LeftBracket(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RightBracket();
    antlr4::tree::TerminalNode* RightBracket(size_t i);
    std::vector<antlr4::tree::TerminalNode *> IntegerConstant();
    antlr4::tree::TerminalNode* IntegerConstant(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_formal_paramContext* function_formal_param();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LeftBrace();
    antlr4::tree::TerminalNode *RightBrace();
    std::vector<Block_itemContext *> block_item();
    Block_itemContext* block_item(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockContext* block();

  class  Block_itemContext : public antlr4::ParserRuleContext {
  public:
    Block_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeclarationContext *declaration();
    StatementContext *statement();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Block_itemContext* block_item();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Left_valueContext *left_value();
    antlr4::tree::TerminalNode *Equal();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *Semicolon();
    BlockContext *block();
    antlr4::tree::TerminalNode *Return();
    antlr4::tree::TerminalNode *If();
    antlr4::tree::TerminalNode *LeftParenthesis();
    ConditionContext *condition();
    antlr4::tree::TerminalNode *RightParenthesis();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    antlr4::tree::TerminalNode *Else();
    antlr4::tree::TerminalNode *While();
    antlr4::tree::TerminalNode *Break();
    antlr4::tree::TerminalNode *Continue();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Additive_expressionContext *additive_expression();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionContext* expression();

  class  Constant_expressionContext : public antlr4::ParserRuleContext {
  public:
    Constant_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Additive_expressionContext *additive_expression();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constant_expressionContext* constant_expression();

  class  ConditionContext : public antlr4::ParserRuleContext {
  public:
    ConditionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Logical_or_expressionContext *logical_or_expression();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConditionContext* condition();

  class  Left_valueContext : public antlr4::ParserRuleContext {
  public:
    Left_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    std::vector<antlr4::tree::TerminalNode *> LeftBracket();
    antlr4::tree::TerminalNode* LeftBracket(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RightBracket();
    antlr4::tree::TerminalNode* RightBracket(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Left_valueContext* left_value();

  class  NumberContext : public antlr4::ParserRuleContext {
  public:
    NumberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IntegerConstant();
    antlr4::tree::TerminalNode *FloatConstant();
    antlr4::tree::TerminalNode *CharConstant();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NumberContext* number();

  class  Function_real_paramsContext : public antlr4::ParserRuleContext {
  public:
    Function_real_paramsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_real_paramsContext* function_real_params();

  class  Primary_expressionContext : public antlr4::ParserRuleContext {
  public:
    Primary_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LeftParenthesis();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RightParenthesis();
    Left_valueContext *left_value();
    NumberContext *number();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Primary_expressionContext* primary_expression();

  class  Unary_expressionContext : public antlr4::ParserRuleContext {
  public:
    Unary_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Primary_expressionContext *primary_expression();
    Unary_expressionContext *unary_expression();
    antlr4::tree::TerminalNode *Plus();
    antlr4::tree::TerminalNode *Minus();
    antlr4::tree::TerminalNode *ExclamationMark();
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *LeftParenthesis();
    antlr4::tree::TerminalNode *RightParenthesis();
    Function_real_paramsContext *function_real_params();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Unary_expressionContext* unary_expression();

  class  Multiplicative_expressionContext : public antlr4::ParserRuleContext {
  public:
    Multiplicative_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Unary_expressionContext *unary_expression();
    Multiplicative_expressionContext *multiplicative_expression();
    antlr4::tree::TerminalNode *Asterisk();
    antlr4::tree::TerminalNode *Slash();
    antlr4::tree::TerminalNode *Percent();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Multiplicative_expressionContext* multiplicative_expression();
  Multiplicative_expressionContext* multiplicative_expression(int precedence);
  class  Additive_expressionContext : public antlr4::ParserRuleContext {
  public:
    Additive_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Multiplicative_expressionContext *multiplicative_expression();
    Additive_expressionContext *additive_expression();
    antlr4::tree::TerminalNode *Plus();
    antlr4::tree::TerminalNode *Minus();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Additive_expressionContext* additive_expression();
  Additive_expressionContext* additive_expression(int precedence);
  class  Relational_expressionContext : public antlr4::ParserRuleContext {
  public:
    Relational_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Additive_expressionContext *additive_expression();
    Relational_expressionContext *relational_expression();
    antlr4::tree::TerminalNode *Less();
    antlr4::tree::TerminalNode *LessEqual();
    antlr4::tree::TerminalNode *Greater();
    antlr4::tree::TerminalNode *GreaterEqual();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Relational_expressionContext* relational_expression();
  Relational_expressionContext* relational_expression(int precedence);
  class  Equal_expressionContext : public antlr4::ParserRuleContext {
  public:
    Equal_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Relational_expressionContext *relational_expression();
    Equal_expressionContext *equal_expression();
    antlr4::tree::TerminalNode *LogicalEqual();
    antlr4::tree::TerminalNode *NotEqual();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Equal_expressionContext* equal_expression();
  Equal_expressionContext* equal_expression(int precedence);
  class  Logical_and_expressionContext : public antlr4::ParserRuleContext {
  public:
    Logical_and_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Equal_expressionContext *equal_expression();
    Logical_and_expressionContext *logical_and_expression();
    antlr4::tree::TerminalNode *LogicalAnd();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Logical_and_expressionContext* logical_and_expression();
  Logical_and_expressionContext* logical_and_expression(int precedence);
  class  Logical_or_expressionContext : public antlr4::ParserRuleContext {
  public:
    Logical_or_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Logical_and_expressionContext *logical_and_expression();
    Logical_or_expressionContext *logical_or_expression();
    antlr4::tree::TerminalNode *LogicalOr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Logical_or_expressionContext* logical_or_expression();
  Logical_or_expressionContext* logical_or_expression(int precedence);

  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool multiplicative_expressionSempred(Multiplicative_expressionContext *_localctx, size_t predicateIndex);
  bool additive_expressionSempred(Additive_expressionContext *_localctx, size_t predicateIndex);
  bool relational_expressionSempred(Relational_expressionContext *_localctx, size_t predicateIndex);
  bool equal_expressionSempred(Equal_expressionContext *_localctx, size_t predicateIndex);
  bool logical_and_expressionSempred(Logical_and_expressionContext *_localctx, size_t predicateIndex);
  bool logical_or_expressionSempred(Logical_or_expressionContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

}  // namespace cplab_parser
