lexer grammar CplabLexer;

/*-----关键词----- */
Const: 'const' ;
Int: 'int' ;
Char: 'char' ;
Float: 'float' ;
Void: 'void' ;
If : 'if';
Else : 'else';
While : 'while';
Break : 'break';
Continue : 'continue';
Return : 'return';

/*-----运算符----- */
Equal: '=' ;
LogicalEqual: '==' ;
LogicalAnd: '&&' ;
LogicalOr: '||' ;
NotEqual: '!=' ;
Less: '<' ;
LessEqual: '<=' ;
Greater: '>' ;
GreaterEqual: '>=' ;
Period : '.' ;
Comma : ',' ;
Semicolon : ';' ;
Colon : ':' ;
LeftParenthesis : '(' ;
RightParenthesis : ')' ;
LeftBracket : '[' ;
RightBracket : ']' ;
LeftBrace : '{' ;
RightBrace : '}' ;
Plus: '+';
Minus: '-';
Pipe: '|';
ExclamationMark: '!';
Asterisk: '*';
Slash: '/';
Percent: '%';
Identifier: [a-zA-Z_][a-zA-Z0-9_]* ;
IntegerConstant: '0' | [1-9][0-9]* | '0'[0-7]+ | '0'[xX][0-9a-fA-F]+;
FloatConstant: '.'[0-9]+[fF]
              | [0-9]+'.'[fF]
              | [0-9]+'.'[0-9]+[fF]
              | '.'[0-9]+[eE][+-]?[0-9]+[fF]
              | [0-9]+[eE][+-]?[0-9]+[fF]
              | [0-9]+'.'[eE][+-]?[0-9]+[fF]
              | [0-9]+'.'[0-9]+[eE][+-]?[0-9]+[fF];
CharConstant: '\'' ( '\\' [ntr0\\'"] | ~['\\] ) '\'' ;
LineComment: '//' ~[\r\n]* -> skip;
BlockComment: '/*' .*? '*/' -> skip;
NewLine: ('\r' ('\n')? | '\n') -> skip;
WhiteSpaces : (' ' | '\t')+ -> skip;