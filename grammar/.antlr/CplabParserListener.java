// Generated from e:/Homework/cplab/cact/grammar/CplabParser.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link CplabParser}.
 */
public interface CplabParserListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link CplabParser#compilation_unit}.
	 * @param ctx the parse tree
	 */
	void enterCompilation_unit(CplabParser.Compilation_unitContext ctx);
	/**
	 * Exit a parse tree produced by {@link CplabParser#compilation_unit}.
	 * @param ctx the parse tree
	 */
	void exitCompilation_unit(CplabParser.Compilation_unitContext ctx);
	/**
	 * Enter a parse tree produced by {@link CplabParser#declaration}.
	 * @param ctx the parse tree
	 */
	void enterDeclaration(CplabParser.DeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link CplabParser#declaration}.
	 * @param ctx the parse tree
	 */
	void exitDeclaration(CplabParser.DeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link CplabParser#constant_declaration}.
	 * @param ctx the parse tree
	 */
	void enterConstant_declaration(CplabParser.Constant_declarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link CplabParser#constant_declaration}.
	 * @param ctx the parse tree
	 */
	void exitConstant_declaration(CplabParser.Constant_declarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link CplabParser#basic_type}.
	 * @param ctx the parse tree
	 */
	void enterBasic_type(CplabParser.Basic_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link CplabParser#basic_type}.
	 * @param ctx the parse tree
	 */
	void exitBasic_type(CplabParser.Basic_typeContext ctx);
	/**
	 * Enter a parse tree produced by {@link CplabParser#constant_definition}.
	 * @param ctx the parse tree
	 */
	void enterConstant_definition(CplabParser.Constant_definitionContext ctx);
	/**
	 * Exit a parse tree produced by {@link CplabParser#constant_definition}.
	 * @param ctx the parse tree
	 */
	void exitConstant_definition(CplabParser.Constant_definitionContext ctx);
	/**
	 * Enter a parse tree produced by {@link CplabParser#constant_initial_value}.
	 * @param ctx the parse tree
	 */
	void enterConstant_initial_value(CplabParser.Constant_initial_valueContext ctx);
	/**
	 * Exit a parse tree produced by {@link CplabParser#constant_initial_value}.
	 * @param ctx the parse tree
	 */
	void exitConstant_initial_value(CplabParser.Constant_initial_valueContext ctx);
	/**
	 * Enter a parse tree produced by {@link CplabParser#variable_declaration}.
	 * @param ctx the parse tree
	 */
	void enterVariable_declaration(CplabParser.Variable_declarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link CplabParser#variable_declaration}.
	 * @param ctx the parse tree
	 */
	void exitVariable_declaration(CplabParser.Variable_declarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link CplabParser#variable_definition}.
	 * @param ctx the parse tree
	 */
	void enterVariable_definition(CplabParser.Variable_definitionContext ctx);
	/**
	 * Exit a parse tree produced by {@link CplabParser#variable_definition}.
	 * @param ctx the parse tree
	 */
	void exitVariable_definition(CplabParser.Variable_definitionContext ctx);
	/**
	 * Enter a parse tree produced by {@link CplabParser#function_definition}.
	 * @param ctx the parse tree
	 */
	void enterFunction_definition(CplabParser.Function_definitionContext ctx);
	/**
	 * Exit a parse tree produced by {@link CplabParser#function_definition}.
	 * @param ctx the parse tree
	 */
	void exitFunction_definition(CplabParser.Function_definitionContext ctx);
	/**
	 * Enter a parse tree produced by {@link CplabParser#function_type}.
	 * @param ctx the parse tree
	 */
	void enterFunction_type(CplabParser.Function_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link CplabParser#function_type}.
	 * @param ctx the parse tree
	 */
	void exitFunction_type(CplabParser.Function_typeContext ctx);
	/**
	 * Enter a parse tree produced by {@link CplabParser#function_formal_params}.
	 * @param ctx the parse tree
	 */
	void enterFunction_formal_params(CplabParser.Function_formal_paramsContext ctx);
	/**
	 * Exit a parse tree produced by {@link CplabParser#function_formal_params}.
	 * @param ctx the parse tree
	 */
	void exitFunction_formal_params(CplabParser.Function_formal_paramsContext ctx);
	/**
	 * Enter a parse tree produced by {@link CplabParser#function_formal_param}.
	 * @param ctx the parse tree
	 */
	void enterFunction_formal_param(CplabParser.Function_formal_paramContext ctx);
	/**
	 * Exit a parse tree produced by {@link CplabParser#function_formal_param}.
	 * @param ctx the parse tree
	 */
	void exitFunction_formal_param(CplabParser.Function_formal_paramContext ctx);
	/**
	 * Enter a parse tree produced by {@link CplabParser#block}.
	 * @param ctx the parse tree
	 */
	void enterBlock(CplabParser.BlockContext ctx);
	/**
	 * Exit a parse tree produced by {@link CplabParser#block}.
	 * @param ctx the parse tree
	 */
	void exitBlock(CplabParser.BlockContext ctx);
	/**
	 * Enter a parse tree produced by {@link CplabParser#block_item}.
	 * @param ctx the parse tree
	 */
	void enterBlock_item(CplabParser.Block_itemContext ctx);
	/**
	 * Exit a parse tree produced by {@link CplabParser#block_item}.
	 * @param ctx the parse tree
	 */
	void exitBlock_item(CplabParser.Block_itemContext ctx);
	/**
	 * Enter a parse tree produced by {@link CplabParser#statement}.
	 * @param ctx the parse tree
	 */
	void enterStatement(CplabParser.StatementContext ctx);
	/**
	 * Exit a parse tree produced by {@link CplabParser#statement}.
	 * @param ctx the parse tree
	 */
	void exitStatement(CplabParser.StatementContext ctx);
	/**
	 * Enter a parse tree produced by {@link CplabParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterExpression(CplabParser.ExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link CplabParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitExpression(CplabParser.ExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link CplabParser#constant_expression}.
	 * @param ctx the parse tree
	 */
	void enterConstant_expression(CplabParser.Constant_expressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link CplabParser#constant_expression}.
	 * @param ctx the parse tree
	 */
	void exitConstant_expression(CplabParser.Constant_expressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link CplabParser#condition}.
	 * @param ctx the parse tree
	 */
	void enterCondition(CplabParser.ConditionContext ctx);
	/**
	 * Exit a parse tree produced by {@link CplabParser#condition}.
	 * @param ctx the parse tree
	 */
	void exitCondition(CplabParser.ConditionContext ctx);
	/**
	 * Enter a parse tree produced by {@link CplabParser#left_value}.
	 * @param ctx the parse tree
	 */
	void enterLeft_value(CplabParser.Left_valueContext ctx);
	/**
	 * Exit a parse tree produced by {@link CplabParser#left_value}.
	 * @param ctx the parse tree
	 */
	void exitLeft_value(CplabParser.Left_valueContext ctx);
	/**
	 * Enter a parse tree produced by {@link CplabParser#number}.
	 * @param ctx the parse tree
	 */
	void enterNumber(CplabParser.NumberContext ctx);
	/**
	 * Exit a parse tree produced by {@link CplabParser#number}.
	 * @param ctx the parse tree
	 */
	void exitNumber(CplabParser.NumberContext ctx);
	/**
	 * Enter a parse tree produced by {@link CplabParser#function_real_params}.
	 * @param ctx the parse tree
	 */
	void enterFunction_real_params(CplabParser.Function_real_paramsContext ctx);
	/**
	 * Exit a parse tree produced by {@link CplabParser#function_real_params}.
	 * @param ctx the parse tree
	 */
	void exitFunction_real_params(CplabParser.Function_real_paramsContext ctx);
	/**
	 * Enter a parse tree produced by {@link CplabParser#primary_expression}.
	 * @param ctx the parse tree
	 */
	void enterPrimary_expression(CplabParser.Primary_expressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link CplabParser#primary_expression}.
	 * @param ctx the parse tree
	 */
	void exitPrimary_expression(CplabParser.Primary_expressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link CplabParser#unary_expression}.
	 * @param ctx the parse tree
	 */
	void enterUnary_expression(CplabParser.Unary_expressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link CplabParser#unary_expression}.
	 * @param ctx the parse tree
	 */
	void exitUnary_expression(CplabParser.Unary_expressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link CplabParser#multiplicative_expression}.
	 * @param ctx the parse tree
	 */
	void enterMultiplicative_expression(CplabParser.Multiplicative_expressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link CplabParser#multiplicative_expression}.
	 * @param ctx the parse tree
	 */
	void exitMultiplicative_expression(CplabParser.Multiplicative_expressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link CplabParser#additive_expression}.
	 * @param ctx the parse tree
	 */
	void enterAdditive_expression(CplabParser.Additive_expressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link CplabParser#additive_expression}.
	 * @param ctx the parse tree
	 */
	void exitAdditive_expression(CplabParser.Additive_expressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link CplabParser#relational_expression}.
	 * @param ctx the parse tree
	 */
	void enterRelational_expression(CplabParser.Relational_expressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link CplabParser#relational_expression}.
	 * @param ctx the parse tree
	 */
	void exitRelational_expression(CplabParser.Relational_expressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link CplabParser#equal_expression}.
	 * @param ctx the parse tree
	 */
	void enterEqual_expression(CplabParser.Equal_expressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link CplabParser#equal_expression}.
	 * @param ctx the parse tree
	 */
	void exitEqual_expression(CplabParser.Equal_expressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link CplabParser#logical_and_expression}.
	 * @param ctx the parse tree
	 */
	void enterLogical_and_expression(CplabParser.Logical_and_expressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link CplabParser#logical_and_expression}.
	 * @param ctx the parse tree
	 */
	void exitLogical_and_expression(CplabParser.Logical_and_expressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link CplabParser#logical_or_expression}.
	 * @param ctx the parse tree
	 */
	void enterLogical_or_expression(CplabParser.Logical_or_expressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link CplabParser#logical_or_expression}.
	 * @param ctx the parse tree
	 */
	void exitLogical_or_expression(CplabParser.Logical_or_expressionContext ctx);
}