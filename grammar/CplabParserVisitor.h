
// Generated from E:/Homework/cplab/cact/grammar/CplabParser.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "CplabParser.h"


namespace cplab_parser {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by CplabParser.
 */
class  CplabParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by CplabParser.
   */
    virtual std::any visitCompilation_unit(CplabParser::Compilation_unitContext *context) = 0;

    virtual std::any visitDeclaration(CplabParser::DeclarationContext *context) = 0;

    virtual std::any visitConstant_declaration(CplabParser::Constant_declarationContext *context) = 0;

    virtual std::any visitBasic_type(CplabParser::Basic_typeContext *context) = 0;

    virtual std::any visitConstant_definition(CplabParser::Constant_definitionContext *context) = 0;

    virtual std::any visitConstant_initial_value(CplabParser::Constant_initial_valueContext *context) = 0;

    virtual std::any visitVariable_declaration(CplabParser::Variable_declarationContext *context) = 0;

    virtual std::any visitVariable_definition(CplabParser::Variable_definitionContext *context) = 0;

    virtual std::any visitFunction_definition(CplabParser::Function_definitionContext *context) = 0;

    virtual std::any visitFunction_type(CplabParser::Function_typeContext *context) = 0;

    virtual std::any visitFunction_formal_params(CplabParser::Function_formal_paramsContext *context) = 0;

    virtual std::any visitFunction_formal_param(CplabParser::Function_formal_paramContext *context) = 0;

    virtual std::any visitBlock(CplabParser::BlockContext *context) = 0;

    virtual std::any visitBlock_item(CplabParser::Block_itemContext *context) = 0;

    virtual std::any visitStatement(CplabParser::StatementContext *context) = 0;

    virtual std::any visitExpression(CplabParser::ExpressionContext *context) = 0;

    virtual std::any visitConstant_expression(CplabParser::Constant_expressionContext *context) = 0;

    virtual std::any visitCondition(CplabParser::ConditionContext *context) = 0;

    virtual std::any visitLeft_value(CplabParser::Left_valueContext *context) = 0;

    virtual std::any visitNumber(CplabParser::NumberContext *context) = 0;

    virtual std::any visitFunction_real_params(CplabParser::Function_real_paramsContext *context) = 0;

    virtual std::any visitPrimary_expression(CplabParser::Primary_expressionContext *context) = 0;

    virtual std::any visitUnary_expression(CplabParser::Unary_expressionContext *context) = 0;

    virtual std::any visitMultiplicative_expression(CplabParser::Multiplicative_expressionContext *context) = 0;

    virtual std::any visitAdditive_expression(CplabParser::Additive_expressionContext *context) = 0;

    virtual std::any visitRelational_expression(CplabParser::Relational_expressionContext *context) = 0;

    virtual std::any visitEqual_expression(CplabParser::Equal_expressionContext *context) = 0;

    virtual std::any visitLogical_and_expression(CplabParser::Logical_and_expressionContext *context) = 0;

    virtual std::any visitLogical_or_expression(CplabParser::Logical_or_expressionContext *context) = 0;


};

}  // namespace cplab_parser
