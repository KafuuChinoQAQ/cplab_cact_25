
// Generated from E:/Homework/cplab/cact/grammar/CplabParser.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "CplabParserVisitor.h"


namespace cplab_parser {

/**
 * This class provides an empty implementation of CplabParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  CplabParserBaseVisitor : public CplabParserVisitor {
public:

  virtual std::any visitCompilation_unit(CplabParser::Compilation_unitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclaration(CplabParser::DeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstant_declaration(CplabParser::Constant_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBasic_type(CplabParser::Basic_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstant_definition(CplabParser::Constant_definitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstant_initial_value(CplabParser::Constant_initial_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariable_declaration(CplabParser::Variable_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariable_definition(CplabParser::Variable_definitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunction_definition(CplabParser::Function_definitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunction_type(CplabParser::Function_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunction_formal_params(CplabParser::Function_formal_paramsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunction_formal_param(CplabParser::Function_formal_paramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(CplabParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock_item(CplabParser::Block_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(CplabParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression(CplabParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstant_expression(CplabParser::Constant_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCondition(CplabParser::ConditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLeft_value(CplabParser::Left_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumber(CplabParser::NumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunction_real_params(CplabParser::Function_real_paramsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimary_expression(CplabParser::Primary_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnary_expression(CplabParser::Unary_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMultiplicative_expression(CplabParser::Multiplicative_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAdditive_expression(CplabParser::Additive_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRelational_expression(CplabParser::Relational_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEqual_expression(CplabParser::Equal_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogical_and_expression(CplabParser::Logical_and_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogical_or_expression(CplabParser::Logical_or_expressionContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace cplab_parser
