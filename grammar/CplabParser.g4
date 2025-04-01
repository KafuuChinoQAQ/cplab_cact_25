parser grammar CplabParser;

options {
    tokenVocab=CplabLexer;
}

/*-----声明&定义-----*/
compilation_unit: (declaration | function_definition)*; // 编译单元
declaration: constant_declaration | variable_declaration; // 声明
constant_declaration: Const basic_type constant_definition (Comma constant_definition)* Semicolon; // 常量声明
basic_type: Int | Float | Char; // 基本类型
constant_definition: Identifier (LeftBracket IntegerConstant RightBracket)* Equal constant_initial_value; // 常量定义
constant_initial_value: constant_expression | LeftBrace (constant_initial_value (Comma constant_initial_value)*)? RightBrace; // 常量初始值
variable_declaration: basic_type variable_definition (Comma variable_definition)* Semicolon; // 变量声明
variable_definition: Identifier (LeftBracket IntegerConstant RightBracket)* (Equal constant_initial_value)?; // 变量定义
function_definition: function_type Identifier LeftParenthesis (function_formal_params)? RightParenthesis block; // 函数定义
function_type: Void | Int | Float | Char; // 函数类型
function_formal_params: function_formal_param (Comma function_formal_param)*; // 函数形参列表
function_formal_param: basic_type Identifier (LeftBracket IntegerConstant? RightBracket (LeftBracket IntegerConstant RightBracket)*)?; // 函数形参

/*-----语句&表达式-----*/
block: LeftBrace (block_item)* RightBrace; // 语句块
block_item: declaration | statement; // 语句块项
statement: left_value Equal expression Semicolon 
            | (expression)? Semicolon 
            | block 
            | Return expression? Semicolon 
            | If LeftParenthesis condition RightParenthesis statement (Else statement)? 
            | While LeftParenthesis condition RightParenthesis statement 
            | Break Semicolon 
            | Continue Semicolon; // 语句
expression: additive_expression; // 表达式
constant_expression: additive_expression; // 常量表达式
condition: logical_or_expression; // 条件表达式
left_value: Identifier (LeftBracket expression RightBracket)*; // 左值
number: IntegerConstant | FloatConstant | CharConstant; // 数值
function_real_params: expression (Comma expression)*; // 函数实参列表
primary_expression: LeftParenthesis expression RightParenthesis | left_value | number;
unary_expression: primary_expression 
            | (Plus | Minus | ExclamationMark) unary_expression 
            | Identifier LeftParenthesis (function_real_params)? RightParenthesis; // 一元表达式
multiplicative_expression: unary_expression | multiplicative_expression (Asterisk | Slash | Percent) unary_expression; // 乘法表达式
additive_expression: multiplicative_expression | additive_expression (Plus | Minus) multiplicative_expression; // 加法表达式
relational_expression: additive_expression | relational_expression (Less | LessEqual | Greater | GreaterEqual) additive_expression; // 关系表达式
equal_expression: relational_expression | equal_expression (LogicalEqual | NotEqual) relational_expression; // 相等表达式
logical_and_expression: equal_expression | logical_and_expression LogicalAnd equal_expression; // 逻辑与表达式
logical_or_expression: logical_and_expression | logical_or_expression LogicalOr logical_and_expression; // 逻辑或表达式