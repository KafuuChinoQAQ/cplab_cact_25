// Generated from e:/Homework/cplab/cact/grammar/CplabParser.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class CplabParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		Const=1, Int=2, Char=3, Float=4, Void=5, If=6, Else=7, While=8, Break=9, 
		Continue=10, Return=11, Equal=12, LogicalEqual=13, LogicalAnd=14, LogicalOr=15, 
		NotEqual=16, Less=17, LessEqual=18, Greater=19, GreaterEqual=20, Period=21, 
		Comma=22, Semicolon=23, Colon=24, LeftParenthesis=25, RightParenthesis=26, 
		LeftBracket=27, RightBracket=28, LeftBrace=29, RightBrace=30, Plus=31, 
		Minus=32, Pipe=33, ExclamationMark=34, Asterisk=35, Slash=36, Percent=37, 
		Identifier=38, IntegerConstant=39, FloatConstant=40, CharConstant=41, 
		LineComment=42, BlockComment=43, NewLine=44, WhiteSpaces=45;
	public static final int
		RULE_compilation_unit = 0, RULE_declaration = 1, RULE_constant_declaration = 2, 
		RULE_basic_type = 3, RULE_constant_definition = 4, RULE_constant_initial_value = 5, 
		RULE_variable_declaration = 6, RULE_variable_definition = 7, RULE_function_definition = 8, 
		RULE_function_type = 9, RULE_function_formal_params = 10, RULE_function_formal_param = 11, 
		RULE_block = 12, RULE_block_item = 13, RULE_statement = 14, RULE_expression = 15, 
		RULE_constant_expression = 16, RULE_condition = 17, RULE_left_value = 18, 
		RULE_number = 19, RULE_function_real_params = 20, RULE_primary_expression = 21, 
		RULE_unary_expression = 22, RULE_multiplicative_expression = 23, RULE_additive_expression = 24, 
		RULE_relational_expression = 25, RULE_equal_expression = 26, RULE_logical_and_expression = 27, 
		RULE_logical_or_expression = 28;
	private static String[] makeRuleNames() {
		return new String[] {
			"compilation_unit", "declaration", "constant_declaration", "basic_type", 
			"constant_definition", "constant_initial_value", "variable_declaration", 
			"variable_definition", "function_definition", "function_type", "function_formal_params", 
			"function_formal_param", "block", "block_item", "statement", "expression", 
			"constant_expression", "condition", "left_value", "number", "function_real_params", 
			"primary_expression", "unary_expression", "multiplicative_expression", 
			"additive_expression", "relational_expression", "equal_expression", "logical_and_expression", 
			"logical_or_expression"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'const'", "'int'", "'char'", "'float'", "'void'", "'if'", "'else'", 
			"'while'", "'break'", "'continue'", "'return'", "'='", "'=='", "'&&'", 
			"'||'", "'!='", "'<'", "'<='", "'>'", "'>='", "'.'", "','", "';'", "':'", 
			"'('", "')'", "'['", "']'", "'{'", "'}'", "'+'", "'-'", "'|'", "'!'", 
			"'*'", "'/'", "'%'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "Const", "Int", "Char", "Float", "Void", "If", "Else", "While", 
			"Break", "Continue", "Return", "Equal", "LogicalEqual", "LogicalAnd", 
			"LogicalOr", "NotEqual", "Less", "LessEqual", "Greater", "GreaterEqual", 
			"Period", "Comma", "Semicolon", "Colon", "LeftParenthesis", "RightParenthesis", 
			"LeftBracket", "RightBracket", "LeftBrace", "RightBrace", "Plus", "Minus", 
			"Pipe", "ExclamationMark", "Asterisk", "Slash", "Percent", "Identifier", 
			"IntegerConstant", "FloatConstant", "CharConstant", "LineComment", "BlockComment", 
			"NewLine", "WhiteSpaces"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "CplabParser.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public CplabParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Compilation_unitContext extends ParserRuleContext {
		public List<DeclarationContext> declaration() {
			return getRuleContexts(DeclarationContext.class);
		}
		public DeclarationContext declaration(int i) {
			return getRuleContext(DeclarationContext.class,i);
		}
		public List<Function_definitionContext> function_definition() {
			return getRuleContexts(Function_definitionContext.class);
		}
		public Function_definitionContext function_definition(int i) {
			return getRuleContext(Function_definitionContext.class,i);
		}
		public Compilation_unitContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_compilation_unit; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).enterCompilation_unit(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).exitCompilation_unit(this);
		}
	}

	public final Compilation_unitContext compilation_unit() throws RecognitionException {
		Compilation_unitContext _localctx = new Compilation_unitContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_compilation_unit);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(62);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & 62L) != 0)) {
				{
				setState(60);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,0,_ctx) ) {
				case 1:
					{
					setState(58);
					declaration();
					}
					break;
				case 2:
					{
					setState(59);
					function_definition();
					}
					break;
				}
				}
				setState(64);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class DeclarationContext extends ParserRuleContext {
		public Constant_declarationContext constant_declaration() {
			return getRuleContext(Constant_declarationContext.class,0);
		}
		public Variable_declarationContext variable_declaration() {
			return getRuleContext(Variable_declarationContext.class,0);
		}
		public DeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declaration; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).enterDeclaration(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).exitDeclaration(this);
		}
	}

	public final DeclarationContext declaration() throws RecognitionException {
		DeclarationContext _localctx = new DeclarationContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_declaration);
		try {
			setState(67);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Const:
				enterOuterAlt(_localctx, 1);
				{
				setState(65);
				constant_declaration();
				}
				break;
			case Int:
			case Char:
			case Float:
				enterOuterAlt(_localctx, 2);
				{
				setState(66);
				variable_declaration();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Constant_declarationContext extends ParserRuleContext {
		public TerminalNode Const() { return getToken(CplabParser.Const, 0); }
		public Basic_typeContext basic_type() {
			return getRuleContext(Basic_typeContext.class,0);
		}
		public List<Constant_definitionContext> constant_definition() {
			return getRuleContexts(Constant_definitionContext.class);
		}
		public Constant_definitionContext constant_definition(int i) {
			return getRuleContext(Constant_definitionContext.class,i);
		}
		public TerminalNode Semicolon() { return getToken(CplabParser.Semicolon, 0); }
		public List<TerminalNode> Comma() { return getTokens(CplabParser.Comma); }
		public TerminalNode Comma(int i) {
			return getToken(CplabParser.Comma, i);
		}
		public Constant_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constant_declaration; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).enterConstant_declaration(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).exitConstant_declaration(this);
		}
	}

	public final Constant_declarationContext constant_declaration() throws RecognitionException {
		Constant_declarationContext _localctx = new Constant_declarationContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_constant_declaration);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(69);
			match(Const);
			setState(70);
			basic_type();
			setState(71);
			constant_definition();
			setState(76);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==Comma) {
				{
				{
				setState(72);
				match(Comma);
				setState(73);
				constant_definition();
				}
				}
				setState(78);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(79);
			match(Semicolon);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Basic_typeContext extends ParserRuleContext {
		public TerminalNode Int() { return getToken(CplabParser.Int, 0); }
		public TerminalNode Float() { return getToken(CplabParser.Float, 0); }
		public TerminalNode Char() { return getToken(CplabParser.Char, 0); }
		public Basic_typeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_basic_type; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).enterBasic_type(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).exitBasic_type(this);
		}
	}

	public final Basic_typeContext basic_type() throws RecognitionException {
		Basic_typeContext _localctx = new Basic_typeContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_basic_type);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(81);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 28L) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Constant_definitionContext extends ParserRuleContext {
		public TerminalNode Identifier() { return getToken(CplabParser.Identifier, 0); }
		public TerminalNode Equal() { return getToken(CplabParser.Equal, 0); }
		public Constant_initial_valueContext constant_initial_value() {
			return getRuleContext(Constant_initial_valueContext.class,0);
		}
		public List<TerminalNode> LeftBracket() { return getTokens(CplabParser.LeftBracket); }
		public TerminalNode LeftBracket(int i) {
			return getToken(CplabParser.LeftBracket, i);
		}
		public List<TerminalNode> IntegerConstant() { return getTokens(CplabParser.IntegerConstant); }
		public TerminalNode IntegerConstant(int i) {
			return getToken(CplabParser.IntegerConstant, i);
		}
		public List<TerminalNode> RightBracket() { return getTokens(CplabParser.RightBracket); }
		public TerminalNode RightBracket(int i) {
			return getToken(CplabParser.RightBracket, i);
		}
		public Constant_definitionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constant_definition; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).enterConstant_definition(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).exitConstant_definition(this);
		}
	}

	public final Constant_definitionContext constant_definition() throws RecognitionException {
		Constant_definitionContext _localctx = new Constant_definitionContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_constant_definition);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(83);
			match(Identifier);
			setState(89);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==LeftBracket) {
				{
				{
				setState(84);
				match(LeftBracket);
				setState(85);
				match(IntegerConstant);
				setState(86);
				match(RightBracket);
				}
				}
				setState(91);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(92);
			match(Equal);
			setState(93);
			constant_initial_value();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Constant_initial_valueContext extends ParserRuleContext {
		public Constant_expressionContext constant_expression() {
			return getRuleContext(Constant_expressionContext.class,0);
		}
		public TerminalNode LeftBrace() { return getToken(CplabParser.LeftBrace, 0); }
		public TerminalNode RightBrace() { return getToken(CplabParser.RightBrace, 0); }
		public List<Constant_initial_valueContext> constant_initial_value() {
			return getRuleContexts(Constant_initial_valueContext.class);
		}
		public Constant_initial_valueContext constant_initial_value(int i) {
			return getRuleContext(Constant_initial_valueContext.class,i);
		}
		public List<TerminalNode> Comma() { return getTokens(CplabParser.Comma); }
		public TerminalNode Comma(int i) {
			return getToken(CplabParser.Comma, i);
		}
		public Constant_initial_valueContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constant_initial_value; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).enterConstant_initial_value(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).exitConstant_initial_value(this);
		}
	}

	public final Constant_initial_valueContext constant_initial_value() throws RecognitionException {
		Constant_initial_valueContext _localctx = new Constant_initial_valueContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_constant_initial_value);
		int _la;
		try {
			setState(108);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LeftParenthesis:
			case Plus:
			case Minus:
			case ExclamationMark:
			case Identifier:
			case IntegerConstant:
			case FloatConstant:
			case CharConstant:
				enterOuterAlt(_localctx, 1);
				{
				setState(95);
				constant_expression();
				}
				break;
			case LeftBrace:
				enterOuterAlt(_localctx, 2);
				{
				setState(96);
				match(LeftBrace);
				setState(105);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 4147361349632L) != 0)) {
					{
					setState(97);
					constant_initial_value();
					setState(102);
					_errHandler.sync(this);
					_la = _input.LA(1);
					while (_la==Comma) {
						{
						{
						setState(98);
						match(Comma);
						setState(99);
						constant_initial_value();
						}
						}
						setState(104);
						_errHandler.sync(this);
						_la = _input.LA(1);
					}
					}
				}

				setState(107);
				match(RightBrace);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Variable_declarationContext extends ParserRuleContext {
		public Basic_typeContext basic_type() {
			return getRuleContext(Basic_typeContext.class,0);
		}
		public List<Variable_definitionContext> variable_definition() {
			return getRuleContexts(Variable_definitionContext.class);
		}
		public Variable_definitionContext variable_definition(int i) {
			return getRuleContext(Variable_definitionContext.class,i);
		}
		public TerminalNode Semicolon() { return getToken(CplabParser.Semicolon, 0); }
		public List<TerminalNode> Comma() { return getTokens(CplabParser.Comma); }
		public TerminalNode Comma(int i) {
			return getToken(CplabParser.Comma, i);
		}
		public Variable_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variable_declaration; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).enterVariable_declaration(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).exitVariable_declaration(this);
		}
	}

	public final Variable_declarationContext variable_declaration() throws RecognitionException {
		Variable_declarationContext _localctx = new Variable_declarationContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_variable_declaration);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(110);
			basic_type();
			setState(111);
			variable_definition();
			setState(116);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==Comma) {
				{
				{
				setState(112);
				match(Comma);
				setState(113);
				variable_definition();
				}
				}
				setState(118);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(119);
			match(Semicolon);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Variable_definitionContext extends ParserRuleContext {
		public TerminalNode Identifier() { return getToken(CplabParser.Identifier, 0); }
		public List<TerminalNode> LeftBracket() { return getTokens(CplabParser.LeftBracket); }
		public TerminalNode LeftBracket(int i) {
			return getToken(CplabParser.LeftBracket, i);
		}
		public List<TerminalNode> IntegerConstant() { return getTokens(CplabParser.IntegerConstant); }
		public TerminalNode IntegerConstant(int i) {
			return getToken(CplabParser.IntegerConstant, i);
		}
		public List<TerminalNode> RightBracket() { return getTokens(CplabParser.RightBracket); }
		public TerminalNode RightBracket(int i) {
			return getToken(CplabParser.RightBracket, i);
		}
		public TerminalNode Equal() { return getToken(CplabParser.Equal, 0); }
		public Constant_initial_valueContext constant_initial_value() {
			return getRuleContext(Constant_initial_valueContext.class,0);
		}
		public Variable_definitionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variable_definition; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).enterVariable_definition(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).exitVariable_definition(this);
		}
	}

	public final Variable_definitionContext variable_definition() throws RecognitionException {
		Variable_definitionContext _localctx = new Variable_definitionContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_variable_definition);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(121);
			match(Identifier);
			setState(127);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==LeftBracket) {
				{
				{
				setState(122);
				match(LeftBracket);
				setState(123);
				match(IntegerConstant);
				setState(124);
				match(RightBracket);
				}
				}
				setState(129);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(132);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==Equal) {
				{
				setState(130);
				match(Equal);
				setState(131);
				constant_initial_value();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Function_definitionContext extends ParserRuleContext {
		public Function_typeContext function_type() {
			return getRuleContext(Function_typeContext.class,0);
		}
		public TerminalNode Identifier() { return getToken(CplabParser.Identifier, 0); }
		public TerminalNode LeftParenthesis() { return getToken(CplabParser.LeftParenthesis, 0); }
		public TerminalNode RightParenthesis() { return getToken(CplabParser.RightParenthesis, 0); }
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public Function_formal_paramsContext function_formal_params() {
			return getRuleContext(Function_formal_paramsContext.class,0);
		}
		public Function_definitionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_function_definition; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).enterFunction_definition(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).exitFunction_definition(this);
		}
	}

	public final Function_definitionContext function_definition() throws RecognitionException {
		Function_definitionContext _localctx = new Function_definitionContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_function_definition);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(134);
			function_type();
			setState(135);
			match(Identifier);
			setState(136);
			match(LeftParenthesis);
			setState(138);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 28L) != 0)) {
				{
				setState(137);
				function_formal_params();
				}
			}

			setState(140);
			match(RightParenthesis);
			setState(141);
			block();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Function_typeContext extends ParserRuleContext {
		public TerminalNode Void() { return getToken(CplabParser.Void, 0); }
		public TerminalNode Int() { return getToken(CplabParser.Int, 0); }
		public TerminalNode Float() { return getToken(CplabParser.Float, 0); }
		public TerminalNode Char() { return getToken(CplabParser.Char, 0); }
		public Function_typeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_function_type; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).enterFunction_type(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).exitFunction_type(this);
		}
	}

	public final Function_typeContext function_type() throws RecognitionException {
		Function_typeContext _localctx = new Function_typeContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_function_type);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(143);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 60L) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Function_formal_paramsContext extends ParserRuleContext {
		public List<Function_formal_paramContext> function_formal_param() {
			return getRuleContexts(Function_formal_paramContext.class);
		}
		public Function_formal_paramContext function_formal_param(int i) {
			return getRuleContext(Function_formal_paramContext.class,i);
		}
		public List<TerminalNode> Comma() { return getTokens(CplabParser.Comma); }
		public TerminalNode Comma(int i) {
			return getToken(CplabParser.Comma, i);
		}
		public Function_formal_paramsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_function_formal_params; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).enterFunction_formal_params(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).exitFunction_formal_params(this);
		}
	}

	public final Function_formal_paramsContext function_formal_params() throws RecognitionException {
		Function_formal_paramsContext _localctx = new Function_formal_paramsContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_function_formal_params);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(145);
			function_formal_param();
			setState(150);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==Comma) {
				{
				{
				setState(146);
				match(Comma);
				setState(147);
				function_formal_param();
				}
				}
				setState(152);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Function_formal_paramContext extends ParserRuleContext {
		public Basic_typeContext basic_type() {
			return getRuleContext(Basic_typeContext.class,0);
		}
		public TerminalNode Identifier() { return getToken(CplabParser.Identifier, 0); }
		public List<TerminalNode> LeftBracket() { return getTokens(CplabParser.LeftBracket); }
		public TerminalNode LeftBracket(int i) {
			return getToken(CplabParser.LeftBracket, i);
		}
		public List<TerminalNode> RightBracket() { return getTokens(CplabParser.RightBracket); }
		public TerminalNode RightBracket(int i) {
			return getToken(CplabParser.RightBracket, i);
		}
		public List<TerminalNode> IntegerConstant() { return getTokens(CplabParser.IntegerConstant); }
		public TerminalNode IntegerConstant(int i) {
			return getToken(CplabParser.IntegerConstant, i);
		}
		public Function_formal_paramContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_function_formal_param; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).enterFunction_formal_param(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).exitFunction_formal_param(this);
		}
	}

	public final Function_formal_paramContext function_formal_param() throws RecognitionException {
		Function_formal_paramContext _localctx = new Function_formal_paramContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_function_formal_param);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(153);
			basic_type();
			setState(154);
			match(Identifier);
			setState(168);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==LeftBracket) {
				{
				setState(155);
				match(LeftBracket);
				setState(157);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==IntegerConstant) {
					{
					setState(156);
					match(IntegerConstant);
					}
				}

				setState(159);
				match(RightBracket);
				setState(165);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==LeftBracket) {
					{
					{
					setState(160);
					match(LeftBracket);
					setState(161);
					match(IntegerConstant);
					setState(162);
					match(RightBracket);
					}
					}
					setState(167);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class BlockContext extends ParserRuleContext {
		public TerminalNode LeftBrace() { return getToken(CplabParser.LeftBrace, 0); }
		public TerminalNode RightBrace() { return getToken(CplabParser.RightBrace, 0); }
		public List<Block_itemContext> block_item() {
			return getRuleContexts(Block_itemContext.class);
		}
		public Block_itemContext block_item(int i) {
			return getRuleContext(Block_itemContext.class,i);
		}
		public BlockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_block; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).enterBlock(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).exitBlock(this);
		}
	}

	public final BlockContext block() throws RecognitionException {
		BlockContext _localctx = new BlockContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_block);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(170);
			match(LeftBrace);
			setState(174);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & 4147369742174L) != 0)) {
				{
				{
				setState(171);
				block_item();
				}
				}
				setState(176);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(177);
			match(RightBrace);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Block_itemContext extends ParserRuleContext {
		public DeclarationContext declaration() {
			return getRuleContext(DeclarationContext.class,0);
		}
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public Block_itemContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_block_item; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).enterBlock_item(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).exitBlock_item(this);
		}
	}

	public final Block_itemContext block_item() throws RecognitionException {
		Block_itemContext _localctx = new Block_itemContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_block_item);
		try {
			setState(181);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Const:
			case Int:
			case Char:
			case Float:
				enterOuterAlt(_localctx, 1);
				{
				setState(179);
				declaration();
				}
				break;
			case If:
			case While:
			case Break:
			case Continue:
			case Return:
			case Semicolon:
			case LeftParenthesis:
			case LeftBrace:
			case Plus:
			case Minus:
			case ExclamationMark:
			case Identifier:
			case IntegerConstant:
			case FloatConstant:
			case CharConstant:
				enterOuterAlt(_localctx, 2);
				{
				setState(180);
				statement();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StatementContext extends ParserRuleContext {
		public Left_valueContext left_value() {
			return getRuleContext(Left_valueContext.class,0);
		}
		public TerminalNode Equal() { return getToken(CplabParser.Equal, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode Semicolon() { return getToken(CplabParser.Semicolon, 0); }
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public TerminalNode Return() { return getToken(CplabParser.Return, 0); }
		public TerminalNode If() { return getToken(CplabParser.If, 0); }
		public TerminalNode LeftParenthesis() { return getToken(CplabParser.LeftParenthesis, 0); }
		public ConditionContext condition() {
			return getRuleContext(ConditionContext.class,0);
		}
		public TerminalNode RightParenthesis() { return getToken(CplabParser.RightParenthesis, 0); }
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public TerminalNode Else() { return getToken(CplabParser.Else, 0); }
		public TerminalNode While() { return getToken(CplabParser.While, 0); }
		public TerminalNode Break() { return getToken(CplabParser.Break, 0); }
		public TerminalNode Continue() { return getToken(CplabParser.Continue, 0); }
		public StatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statement; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).enterStatement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).exitStatement(this);
		}
	}

	public final StatementContext statement() throws RecognitionException {
		StatementContext _localctx = new StatementContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_statement);
		int _la;
		try {
			setState(217);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,21,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(183);
				left_value();
				setState(184);
				match(Equal);
				setState(185);
				expression();
				setState(186);
				match(Semicolon);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(189);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 4146824478720L) != 0)) {
					{
					setState(188);
					expression();
					}
				}

				setState(191);
				match(Semicolon);
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(192);
				block();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(193);
				match(Return);
				setState(195);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 4146824478720L) != 0)) {
					{
					setState(194);
					expression();
					}
				}

				setState(197);
				match(Semicolon);
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(198);
				match(If);
				setState(199);
				match(LeftParenthesis);
				setState(200);
				condition();
				setState(201);
				match(RightParenthesis);
				setState(202);
				statement();
				setState(205);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,20,_ctx) ) {
				case 1:
					{
					setState(203);
					match(Else);
					setState(204);
					statement();
					}
					break;
				}
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(207);
				match(While);
				setState(208);
				match(LeftParenthesis);
				setState(209);
				condition();
				setState(210);
				match(RightParenthesis);
				setState(211);
				statement();
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(213);
				match(Break);
				setState(214);
				match(Semicolon);
				}
				break;
			case 8:
				enterOuterAlt(_localctx, 8);
				{
				setState(215);
				match(Continue);
				setState(216);
				match(Semicolon);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ExpressionContext extends ParserRuleContext {
		public Additive_expressionContext additive_expression() {
			return getRuleContext(Additive_expressionContext.class,0);
		}
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).enterExpression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).exitExpression(this);
		}
	}

	public final ExpressionContext expression() throws RecognitionException {
		ExpressionContext _localctx = new ExpressionContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_expression);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(219);
			additive_expression(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Constant_expressionContext extends ParserRuleContext {
		public Additive_expressionContext additive_expression() {
			return getRuleContext(Additive_expressionContext.class,0);
		}
		public Constant_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constant_expression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).enterConstant_expression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).exitConstant_expression(this);
		}
	}

	public final Constant_expressionContext constant_expression() throws RecognitionException {
		Constant_expressionContext _localctx = new Constant_expressionContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_constant_expression);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(221);
			additive_expression(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ConditionContext extends ParserRuleContext {
		public Logical_or_expressionContext logical_or_expression() {
			return getRuleContext(Logical_or_expressionContext.class,0);
		}
		public ConditionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_condition; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).enterCondition(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).exitCondition(this);
		}
	}

	public final ConditionContext condition() throws RecognitionException {
		ConditionContext _localctx = new ConditionContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_condition);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(223);
			logical_or_expression(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Left_valueContext extends ParserRuleContext {
		public TerminalNode Identifier() { return getToken(CplabParser.Identifier, 0); }
		public List<TerminalNode> LeftBracket() { return getTokens(CplabParser.LeftBracket); }
		public TerminalNode LeftBracket(int i) {
			return getToken(CplabParser.LeftBracket, i);
		}
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public List<TerminalNode> RightBracket() { return getTokens(CplabParser.RightBracket); }
		public TerminalNode RightBracket(int i) {
			return getToken(CplabParser.RightBracket, i);
		}
		public Left_valueContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_left_value; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).enterLeft_value(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).exitLeft_value(this);
		}
	}

	public final Left_valueContext left_value() throws RecognitionException {
		Left_valueContext _localctx = new Left_valueContext(_ctx, getState());
		enterRule(_localctx, 36, RULE_left_value);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(225);
			match(Identifier);
			setState(232);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,22,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(226);
					match(LeftBracket);
					setState(227);
					expression();
					setState(228);
					match(RightBracket);
					}
					} 
				}
				setState(234);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,22,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class NumberContext extends ParserRuleContext {
		public TerminalNode IntegerConstant() { return getToken(CplabParser.IntegerConstant, 0); }
		public TerminalNode FloatConstant() { return getToken(CplabParser.FloatConstant, 0); }
		public TerminalNode CharConstant() { return getToken(CplabParser.CharConstant, 0); }
		public NumberContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_number; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).enterNumber(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).exitNumber(this);
		}
	}

	public final NumberContext number() throws RecognitionException {
		NumberContext _localctx = new NumberContext(_ctx, getState());
		enterRule(_localctx, 38, RULE_number);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(235);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 3848290697216L) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Function_real_paramsContext extends ParserRuleContext {
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public List<TerminalNode> Comma() { return getTokens(CplabParser.Comma); }
		public TerminalNode Comma(int i) {
			return getToken(CplabParser.Comma, i);
		}
		public Function_real_paramsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_function_real_params; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).enterFunction_real_params(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).exitFunction_real_params(this);
		}
	}

	public final Function_real_paramsContext function_real_params() throws RecognitionException {
		Function_real_paramsContext _localctx = new Function_real_paramsContext(_ctx, getState());
		enterRule(_localctx, 40, RULE_function_real_params);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(237);
			expression();
			setState(242);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==Comma) {
				{
				{
				setState(238);
				match(Comma);
				setState(239);
				expression();
				}
				}
				setState(244);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Primary_expressionContext extends ParserRuleContext {
		public TerminalNode LeftParenthesis() { return getToken(CplabParser.LeftParenthesis, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode RightParenthesis() { return getToken(CplabParser.RightParenthesis, 0); }
		public Left_valueContext left_value() {
			return getRuleContext(Left_valueContext.class,0);
		}
		public NumberContext number() {
			return getRuleContext(NumberContext.class,0);
		}
		public Primary_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_primary_expression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).enterPrimary_expression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).exitPrimary_expression(this);
		}
	}

	public final Primary_expressionContext primary_expression() throws RecognitionException {
		Primary_expressionContext _localctx = new Primary_expressionContext(_ctx, getState());
		enterRule(_localctx, 42, RULE_primary_expression);
		try {
			setState(251);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LeftParenthesis:
				enterOuterAlt(_localctx, 1);
				{
				setState(245);
				match(LeftParenthesis);
				setState(246);
				expression();
				setState(247);
				match(RightParenthesis);
				}
				break;
			case Identifier:
				enterOuterAlt(_localctx, 2);
				{
				setState(249);
				left_value();
				}
				break;
			case IntegerConstant:
			case FloatConstant:
			case CharConstant:
				enterOuterAlt(_localctx, 3);
				{
				setState(250);
				number();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Unary_expressionContext extends ParserRuleContext {
		public Primary_expressionContext primary_expression() {
			return getRuleContext(Primary_expressionContext.class,0);
		}
		public Unary_expressionContext unary_expression() {
			return getRuleContext(Unary_expressionContext.class,0);
		}
		public TerminalNode Plus() { return getToken(CplabParser.Plus, 0); }
		public TerminalNode Minus() { return getToken(CplabParser.Minus, 0); }
		public TerminalNode ExclamationMark() { return getToken(CplabParser.ExclamationMark, 0); }
		public TerminalNode Identifier() { return getToken(CplabParser.Identifier, 0); }
		public TerminalNode LeftParenthesis() { return getToken(CplabParser.LeftParenthesis, 0); }
		public TerminalNode RightParenthesis() { return getToken(CplabParser.RightParenthesis, 0); }
		public Function_real_paramsContext function_real_params() {
			return getRuleContext(Function_real_paramsContext.class,0);
		}
		public Unary_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unary_expression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).enterUnary_expression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).exitUnary_expression(this);
		}
	}

	public final Unary_expressionContext unary_expression() throws RecognitionException {
		Unary_expressionContext _localctx = new Unary_expressionContext(_ctx, getState());
		enterRule(_localctx, 44, RULE_unary_expression);
		int _la;
		try {
			setState(262);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,26,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(253);
				primary_expression();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(254);
				_la = _input.LA(1);
				if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 23622320128L) != 0)) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(255);
				unary_expression();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(256);
				match(Identifier);
				setState(257);
				match(LeftParenthesis);
				setState(259);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 4146824478720L) != 0)) {
					{
					setState(258);
					function_real_params();
					}
				}

				setState(261);
				match(RightParenthesis);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Multiplicative_expressionContext extends ParserRuleContext {
		public Unary_expressionContext unary_expression() {
			return getRuleContext(Unary_expressionContext.class,0);
		}
		public Multiplicative_expressionContext multiplicative_expression() {
			return getRuleContext(Multiplicative_expressionContext.class,0);
		}
		public TerminalNode Asterisk() { return getToken(CplabParser.Asterisk, 0); }
		public TerminalNode Slash() { return getToken(CplabParser.Slash, 0); }
		public TerminalNode Percent() { return getToken(CplabParser.Percent, 0); }
		public Multiplicative_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_multiplicative_expression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).enterMultiplicative_expression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).exitMultiplicative_expression(this);
		}
	}

	public final Multiplicative_expressionContext multiplicative_expression() throws RecognitionException {
		return multiplicative_expression(0);
	}

	private Multiplicative_expressionContext multiplicative_expression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Multiplicative_expressionContext _localctx = new Multiplicative_expressionContext(_ctx, _parentState);
		Multiplicative_expressionContext _prevctx = _localctx;
		int _startState = 46;
		enterRecursionRule(_localctx, 46, RULE_multiplicative_expression, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(265);
			unary_expression();
			}
			_ctx.stop = _input.LT(-1);
			setState(272);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,27,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new Multiplicative_expressionContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_multiplicative_expression);
					setState(267);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(268);
					_la = _input.LA(1);
					if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 240518168576L) != 0)) ) {
					_errHandler.recoverInline(this);
					}
					else {
						if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
						_errHandler.reportMatch(this);
						consume();
					}
					setState(269);
					unary_expression();
					}
					} 
				}
				setState(274);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,27,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Additive_expressionContext extends ParserRuleContext {
		public Multiplicative_expressionContext multiplicative_expression() {
			return getRuleContext(Multiplicative_expressionContext.class,0);
		}
		public Additive_expressionContext additive_expression() {
			return getRuleContext(Additive_expressionContext.class,0);
		}
		public TerminalNode Plus() { return getToken(CplabParser.Plus, 0); }
		public TerminalNode Minus() { return getToken(CplabParser.Minus, 0); }
		public Additive_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_additive_expression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).enterAdditive_expression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).exitAdditive_expression(this);
		}
	}

	public final Additive_expressionContext additive_expression() throws RecognitionException {
		return additive_expression(0);
	}

	private Additive_expressionContext additive_expression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Additive_expressionContext _localctx = new Additive_expressionContext(_ctx, _parentState);
		Additive_expressionContext _prevctx = _localctx;
		int _startState = 48;
		enterRecursionRule(_localctx, 48, RULE_additive_expression, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(276);
			multiplicative_expression(0);
			}
			_ctx.stop = _input.LT(-1);
			setState(283);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,28,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new Additive_expressionContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_additive_expression);
					setState(278);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(279);
					_la = _input.LA(1);
					if ( !(_la==Plus || _la==Minus) ) {
					_errHandler.recoverInline(this);
					}
					else {
						if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
						_errHandler.reportMatch(this);
						consume();
					}
					setState(280);
					multiplicative_expression(0);
					}
					} 
				}
				setState(285);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,28,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Relational_expressionContext extends ParserRuleContext {
		public Additive_expressionContext additive_expression() {
			return getRuleContext(Additive_expressionContext.class,0);
		}
		public Relational_expressionContext relational_expression() {
			return getRuleContext(Relational_expressionContext.class,0);
		}
		public TerminalNode Less() { return getToken(CplabParser.Less, 0); }
		public TerminalNode LessEqual() { return getToken(CplabParser.LessEqual, 0); }
		public TerminalNode Greater() { return getToken(CplabParser.Greater, 0); }
		public TerminalNode GreaterEqual() { return getToken(CplabParser.GreaterEqual, 0); }
		public Relational_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_relational_expression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).enterRelational_expression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).exitRelational_expression(this);
		}
	}

	public final Relational_expressionContext relational_expression() throws RecognitionException {
		return relational_expression(0);
	}

	private Relational_expressionContext relational_expression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Relational_expressionContext _localctx = new Relational_expressionContext(_ctx, _parentState);
		Relational_expressionContext _prevctx = _localctx;
		int _startState = 50;
		enterRecursionRule(_localctx, 50, RULE_relational_expression, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(287);
			additive_expression(0);
			}
			_ctx.stop = _input.LT(-1);
			setState(294);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,29,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new Relational_expressionContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_relational_expression);
					setState(289);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(290);
					_la = _input.LA(1);
					if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 1966080L) != 0)) ) {
					_errHandler.recoverInline(this);
					}
					else {
						if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
						_errHandler.reportMatch(this);
						consume();
					}
					setState(291);
					additive_expression(0);
					}
					} 
				}
				setState(296);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,29,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Equal_expressionContext extends ParserRuleContext {
		public Relational_expressionContext relational_expression() {
			return getRuleContext(Relational_expressionContext.class,0);
		}
		public Equal_expressionContext equal_expression() {
			return getRuleContext(Equal_expressionContext.class,0);
		}
		public TerminalNode LogicalEqual() { return getToken(CplabParser.LogicalEqual, 0); }
		public TerminalNode NotEqual() { return getToken(CplabParser.NotEqual, 0); }
		public Equal_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_equal_expression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).enterEqual_expression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).exitEqual_expression(this);
		}
	}

	public final Equal_expressionContext equal_expression() throws RecognitionException {
		return equal_expression(0);
	}

	private Equal_expressionContext equal_expression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Equal_expressionContext _localctx = new Equal_expressionContext(_ctx, _parentState);
		Equal_expressionContext _prevctx = _localctx;
		int _startState = 52;
		enterRecursionRule(_localctx, 52, RULE_equal_expression, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(298);
			relational_expression(0);
			}
			_ctx.stop = _input.LT(-1);
			setState(305);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,30,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new Equal_expressionContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_equal_expression);
					setState(300);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(301);
					_la = _input.LA(1);
					if ( !(_la==LogicalEqual || _la==NotEqual) ) {
					_errHandler.recoverInline(this);
					}
					else {
						if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
						_errHandler.reportMatch(this);
						consume();
					}
					setState(302);
					relational_expression(0);
					}
					} 
				}
				setState(307);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,30,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Logical_and_expressionContext extends ParserRuleContext {
		public Equal_expressionContext equal_expression() {
			return getRuleContext(Equal_expressionContext.class,0);
		}
		public Logical_and_expressionContext logical_and_expression() {
			return getRuleContext(Logical_and_expressionContext.class,0);
		}
		public TerminalNode LogicalAnd() { return getToken(CplabParser.LogicalAnd, 0); }
		public Logical_and_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_logical_and_expression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).enterLogical_and_expression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).exitLogical_and_expression(this);
		}
	}

	public final Logical_and_expressionContext logical_and_expression() throws RecognitionException {
		return logical_and_expression(0);
	}

	private Logical_and_expressionContext logical_and_expression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Logical_and_expressionContext _localctx = new Logical_and_expressionContext(_ctx, _parentState);
		Logical_and_expressionContext _prevctx = _localctx;
		int _startState = 54;
		enterRecursionRule(_localctx, 54, RULE_logical_and_expression, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(309);
			equal_expression(0);
			}
			_ctx.stop = _input.LT(-1);
			setState(316);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,31,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new Logical_and_expressionContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_logical_and_expression);
					setState(311);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(312);
					match(LogicalAnd);
					setState(313);
					equal_expression(0);
					}
					} 
				}
				setState(318);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,31,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Logical_or_expressionContext extends ParserRuleContext {
		public Logical_and_expressionContext logical_and_expression() {
			return getRuleContext(Logical_and_expressionContext.class,0);
		}
		public Logical_or_expressionContext logical_or_expression() {
			return getRuleContext(Logical_or_expressionContext.class,0);
		}
		public TerminalNode LogicalOr() { return getToken(CplabParser.LogicalOr, 0); }
		public Logical_or_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_logical_or_expression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).enterLogical_or_expression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CplabParserListener ) ((CplabParserListener)listener).exitLogical_or_expression(this);
		}
	}

	public final Logical_or_expressionContext logical_or_expression() throws RecognitionException {
		return logical_or_expression(0);
	}

	private Logical_or_expressionContext logical_or_expression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Logical_or_expressionContext _localctx = new Logical_or_expressionContext(_ctx, _parentState);
		Logical_or_expressionContext _prevctx = _localctx;
		int _startState = 56;
		enterRecursionRule(_localctx, 56, RULE_logical_or_expression, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(320);
			logical_and_expression(0);
			}
			_ctx.stop = _input.LT(-1);
			setState(327);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,32,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new Logical_or_expressionContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_logical_or_expression);
					setState(322);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(323);
					match(LogicalOr);
					setState(324);
					logical_and_expression(0);
					}
					} 
				}
				setState(329);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,32,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 23:
			return multiplicative_expression_sempred((Multiplicative_expressionContext)_localctx, predIndex);
		case 24:
			return additive_expression_sempred((Additive_expressionContext)_localctx, predIndex);
		case 25:
			return relational_expression_sempred((Relational_expressionContext)_localctx, predIndex);
		case 26:
			return equal_expression_sempred((Equal_expressionContext)_localctx, predIndex);
		case 27:
			return logical_and_expression_sempred((Logical_and_expressionContext)_localctx, predIndex);
		case 28:
			return logical_or_expression_sempred((Logical_or_expressionContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean multiplicative_expression_sempred(Multiplicative_expressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean additive_expression_sempred(Additive_expressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 1:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean relational_expression_sempred(Relational_expressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 2:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean equal_expression_sempred(Equal_expressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 3:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean logical_and_expression_sempred(Logical_and_expressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 4:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean logical_or_expression_sempred(Logical_or_expressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 5:
			return precpred(_ctx, 1);
		}
		return true;
	}

	public static final String _serializedATN =
		"\u0004\u0001-\u014b\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002"+
		"\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007\u0002"+
		"\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b\u0002"+
		"\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002\u000f\u0007\u000f"+
		"\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011\u0002\u0012\u0007\u0012"+
		"\u0002\u0013\u0007\u0013\u0002\u0014\u0007\u0014\u0002\u0015\u0007\u0015"+
		"\u0002\u0016\u0007\u0016\u0002\u0017\u0007\u0017\u0002\u0018\u0007\u0018"+
		"\u0002\u0019\u0007\u0019\u0002\u001a\u0007\u001a\u0002\u001b\u0007\u001b"+
		"\u0002\u001c\u0007\u001c\u0001\u0000\u0001\u0000\u0005\u0000=\b\u0000"+
		"\n\u0000\f\u0000@\t\u0000\u0001\u0001\u0001\u0001\u0003\u0001D\b\u0001"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0005\u0002"+
		"K\b\u0002\n\u0002\f\u0002N\t\u0002\u0001\u0002\u0001\u0002\u0001\u0003"+
		"\u0001\u0003\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0005\u0004"+
		"X\b\u0004\n\u0004\f\u0004[\t\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0005\u0005"+
		"e\b\u0005\n\u0005\f\u0005h\t\u0005\u0003\u0005j\b\u0005\u0001\u0005\u0003"+
		"\u0005m\b\u0005\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0005"+
		"\u0006s\b\u0006\n\u0006\f\u0006v\t\u0006\u0001\u0006\u0001\u0006\u0001"+
		"\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0005\u0007~\b\u0007\n\u0007"+
		"\f\u0007\u0081\t\u0007\u0001\u0007\u0001\u0007\u0003\u0007\u0085\b\u0007"+
		"\u0001\b\u0001\b\u0001\b\u0001\b\u0003\b\u008b\b\b\u0001\b\u0001\b\u0001"+
		"\b\u0001\t\u0001\t\u0001\n\u0001\n\u0001\n\u0005\n\u0095\b\n\n\n\f\n\u0098"+
		"\t\n\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0003\u000b\u009e"+
		"\b\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0005\u000b\u00a4"+
		"\b\u000b\n\u000b\f\u000b\u00a7\t\u000b\u0003\u000b\u00a9\b\u000b\u0001"+
		"\f\u0001\f\u0005\f\u00ad\b\f\n\f\f\f\u00b0\t\f\u0001\f\u0001\f\u0001\r"+
		"\u0001\r\u0003\r\u00b6\b\r\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e"+
		"\u0001\u000e\u0001\u000e\u0003\u000e\u00be\b\u000e\u0001\u000e\u0001\u000e"+
		"\u0001\u000e\u0001\u000e\u0003\u000e\u00c4\b\u000e\u0001\u000e\u0001\u000e"+
		"\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e"+
		"\u0003\u000e\u00ce\b\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e"+
		"\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e"+
		"\u0003\u000e\u00da\b\u000e\u0001\u000f\u0001\u000f\u0001\u0010\u0001\u0010"+
		"\u0001\u0011\u0001\u0011\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0012"+
		"\u0001\u0012\u0005\u0012\u00e7\b\u0012\n\u0012\f\u0012\u00ea\t\u0012\u0001"+
		"\u0013\u0001\u0013\u0001\u0014\u0001\u0014\u0001\u0014\u0005\u0014\u00f1"+
		"\b\u0014\n\u0014\f\u0014\u00f4\t\u0014\u0001\u0015\u0001\u0015\u0001\u0015"+
		"\u0001\u0015\u0001\u0015\u0001\u0015\u0003\u0015\u00fc\b\u0015\u0001\u0016"+
		"\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0003\u0016"+
		"\u0104\b\u0016\u0001\u0016\u0003\u0016\u0107\b\u0016\u0001\u0017\u0001"+
		"\u0017\u0001\u0017\u0001\u0017\u0001\u0017\u0001\u0017\u0005\u0017\u010f"+
		"\b\u0017\n\u0017\f\u0017\u0112\t\u0017\u0001\u0018\u0001\u0018\u0001\u0018"+
		"\u0001\u0018\u0001\u0018\u0001\u0018\u0005\u0018\u011a\b\u0018\n\u0018"+
		"\f\u0018\u011d\t\u0018\u0001\u0019\u0001\u0019\u0001\u0019\u0001\u0019"+
		"\u0001\u0019\u0001\u0019\u0005\u0019\u0125\b\u0019\n\u0019\f\u0019\u0128"+
		"\t\u0019\u0001\u001a\u0001\u001a\u0001\u001a\u0001\u001a\u0001\u001a\u0001"+
		"\u001a\u0005\u001a\u0130\b\u001a\n\u001a\f\u001a\u0133\t\u001a\u0001\u001b"+
		"\u0001\u001b\u0001\u001b\u0001\u001b\u0001\u001b\u0001\u001b\u0005\u001b"+
		"\u013b\b\u001b\n\u001b\f\u001b\u013e\t\u001b\u0001\u001c\u0001\u001c\u0001"+
		"\u001c\u0001\u001c\u0001\u001c\u0001\u001c\u0005\u001c\u0146\b\u001c\n"+
		"\u001c\f\u001c\u0149\t\u001c\u0001\u001c\u0000\u0006.02468\u001d\u0000"+
		"\u0002\u0004\u0006\b\n\f\u000e\u0010\u0012\u0014\u0016\u0018\u001a\u001c"+
		"\u001e \"$&(*,.02468\u0000\b\u0001\u0000\u0002\u0004\u0001\u0000\u0002"+
		"\u0005\u0001\u0000\')\u0002\u0000\u001f \"\"\u0001\u0000#%\u0001\u0000"+
		"\u001f \u0001\u0000\u0011\u0014\u0002\u0000\r\r\u0010\u0010\u0156\u0000"+
		">\u0001\u0000\u0000\u0000\u0002C\u0001\u0000\u0000\u0000\u0004E\u0001"+
		"\u0000\u0000\u0000\u0006Q\u0001\u0000\u0000\u0000\bS\u0001\u0000\u0000"+
		"\u0000\nl\u0001\u0000\u0000\u0000\fn\u0001\u0000\u0000\u0000\u000ey\u0001"+
		"\u0000\u0000\u0000\u0010\u0086\u0001\u0000\u0000\u0000\u0012\u008f\u0001"+
		"\u0000\u0000\u0000\u0014\u0091\u0001\u0000\u0000\u0000\u0016\u0099\u0001"+
		"\u0000\u0000\u0000\u0018\u00aa\u0001\u0000\u0000\u0000\u001a\u00b5\u0001"+
		"\u0000\u0000\u0000\u001c\u00d9\u0001\u0000\u0000\u0000\u001e\u00db\u0001"+
		"\u0000\u0000\u0000 \u00dd\u0001\u0000\u0000\u0000\"\u00df\u0001\u0000"+
		"\u0000\u0000$\u00e1\u0001\u0000\u0000\u0000&\u00eb\u0001\u0000\u0000\u0000"+
		"(\u00ed\u0001\u0000\u0000\u0000*\u00fb\u0001\u0000\u0000\u0000,\u0106"+
		"\u0001\u0000\u0000\u0000.\u0108\u0001\u0000\u0000\u00000\u0113\u0001\u0000"+
		"\u0000\u00002\u011e\u0001\u0000\u0000\u00004\u0129\u0001\u0000\u0000\u0000"+
		"6\u0134\u0001\u0000\u0000\u00008\u013f\u0001\u0000\u0000\u0000:=\u0003"+
		"\u0002\u0001\u0000;=\u0003\u0010\b\u0000<:\u0001\u0000\u0000\u0000<;\u0001"+
		"\u0000\u0000\u0000=@\u0001\u0000\u0000\u0000><\u0001\u0000\u0000\u0000"+
		">?\u0001\u0000\u0000\u0000?\u0001\u0001\u0000\u0000\u0000@>\u0001\u0000"+
		"\u0000\u0000AD\u0003\u0004\u0002\u0000BD\u0003\f\u0006\u0000CA\u0001\u0000"+
		"\u0000\u0000CB\u0001\u0000\u0000\u0000D\u0003\u0001\u0000\u0000\u0000"+
		"EF\u0005\u0001\u0000\u0000FG\u0003\u0006\u0003\u0000GL\u0003\b\u0004\u0000"+
		"HI\u0005\u0016\u0000\u0000IK\u0003\b\u0004\u0000JH\u0001\u0000\u0000\u0000"+
		"KN\u0001\u0000\u0000\u0000LJ\u0001\u0000\u0000\u0000LM\u0001\u0000\u0000"+
		"\u0000MO\u0001\u0000\u0000\u0000NL\u0001\u0000\u0000\u0000OP\u0005\u0017"+
		"\u0000\u0000P\u0005\u0001\u0000\u0000\u0000QR\u0007\u0000\u0000\u0000"+
		"R\u0007\u0001\u0000\u0000\u0000SY\u0005&\u0000\u0000TU\u0005\u001b\u0000"+
		"\u0000UV\u0005\'\u0000\u0000VX\u0005\u001c\u0000\u0000WT\u0001\u0000\u0000"+
		"\u0000X[\u0001\u0000\u0000\u0000YW\u0001\u0000\u0000\u0000YZ\u0001\u0000"+
		"\u0000\u0000Z\\\u0001\u0000\u0000\u0000[Y\u0001\u0000\u0000\u0000\\]\u0005"+
		"\f\u0000\u0000]^\u0003\n\u0005\u0000^\t\u0001\u0000\u0000\u0000_m\u0003"+
		" \u0010\u0000`i\u0005\u001d\u0000\u0000af\u0003\n\u0005\u0000bc\u0005"+
		"\u0016\u0000\u0000ce\u0003\n\u0005\u0000db\u0001\u0000\u0000\u0000eh\u0001"+
		"\u0000\u0000\u0000fd\u0001\u0000\u0000\u0000fg\u0001\u0000\u0000\u0000"+
		"gj\u0001\u0000\u0000\u0000hf\u0001\u0000\u0000\u0000ia\u0001\u0000\u0000"+
		"\u0000ij\u0001\u0000\u0000\u0000jk\u0001\u0000\u0000\u0000km\u0005\u001e"+
		"\u0000\u0000l_\u0001\u0000\u0000\u0000l`\u0001\u0000\u0000\u0000m\u000b"+
		"\u0001\u0000\u0000\u0000no\u0003\u0006\u0003\u0000ot\u0003\u000e\u0007"+
		"\u0000pq\u0005\u0016\u0000\u0000qs\u0003\u000e\u0007\u0000rp\u0001\u0000"+
		"\u0000\u0000sv\u0001\u0000\u0000\u0000tr\u0001\u0000\u0000\u0000tu\u0001"+
		"\u0000\u0000\u0000uw\u0001\u0000\u0000\u0000vt\u0001\u0000\u0000\u0000"+
		"wx\u0005\u0017\u0000\u0000x\r\u0001\u0000\u0000\u0000y\u007f\u0005&\u0000"+
		"\u0000z{\u0005\u001b\u0000\u0000{|\u0005\'\u0000\u0000|~\u0005\u001c\u0000"+
		"\u0000}z\u0001\u0000\u0000\u0000~\u0081\u0001\u0000\u0000\u0000\u007f"+
		"}\u0001\u0000\u0000\u0000\u007f\u0080\u0001\u0000\u0000\u0000\u0080\u0084"+
		"\u0001\u0000\u0000\u0000\u0081\u007f\u0001\u0000\u0000\u0000\u0082\u0083"+
		"\u0005\f\u0000\u0000\u0083\u0085\u0003\n\u0005\u0000\u0084\u0082\u0001"+
		"\u0000\u0000\u0000\u0084\u0085\u0001\u0000\u0000\u0000\u0085\u000f\u0001"+
		"\u0000\u0000\u0000\u0086\u0087\u0003\u0012\t\u0000\u0087\u0088\u0005&"+
		"\u0000\u0000\u0088\u008a\u0005\u0019\u0000\u0000\u0089\u008b\u0003\u0014"+
		"\n\u0000\u008a\u0089\u0001\u0000\u0000\u0000\u008a\u008b\u0001\u0000\u0000"+
		"\u0000\u008b\u008c\u0001\u0000\u0000\u0000\u008c\u008d\u0005\u001a\u0000"+
		"\u0000\u008d\u008e\u0003\u0018\f\u0000\u008e\u0011\u0001\u0000\u0000\u0000"+
		"\u008f\u0090\u0007\u0001\u0000\u0000\u0090\u0013\u0001\u0000\u0000\u0000"+
		"\u0091\u0096\u0003\u0016\u000b\u0000\u0092\u0093\u0005\u0016\u0000\u0000"+
		"\u0093\u0095\u0003\u0016\u000b\u0000\u0094\u0092\u0001\u0000\u0000\u0000"+
		"\u0095\u0098\u0001\u0000\u0000\u0000\u0096\u0094\u0001\u0000\u0000\u0000"+
		"\u0096\u0097\u0001\u0000\u0000\u0000\u0097\u0015\u0001\u0000\u0000\u0000"+
		"\u0098\u0096\u0001\u0000\u0000\u0000\u0099\u009a\u0003\u0006\u0003\u0000"+
		"\u009a\u00a8\u0005&\u0000\u0000\u009b\u009d\u0005\u001b\u0000\u0000\u009c"+
		"\u009e\u0005\'\u0000\u0000\u009d\u009c\u0001\u0000\u0000\u0000\u009d\u009e"+
		"\u0001\u0000\u0000\u0000\u009e\u009f\u0001\u0000\u0000\u0000\u009f\u00a5"+
		"\u0005\u001c\u0000\u0000\u00a0\u00a1\u0005\u001b\u0000\u0000\u00a1\u00a2"+
		"\u0005\'\u0000\u0000\u00a2\u00a4\u0005\u001c\u0000\u0000\u00a3\u00a0\u0001"+
		"\u0000\u0000\u0000\u00a4\u00a7\u0001\u0000\u0000\u0000\u00a5\u00a3\u0001"+
		"\u0000\u0000\u0000\u00a5\u00a6\u0001\u0000\u0000\u0000\u00a6\u00a9\u0001"+
		"\u0000\u0000\u0000\u00a7\u00a5\u0001\u0000\u0000\u0000\u00a8\u009b\u0001"+
		"\u0000\u0000\u0000\u00a8\u00a9\u0001\u0000\u0000\u0000\u00a9\u0017\u0001"+
		"\u0000\u0000\u0000\u00aa\u00ae\u0005\u001d\u0000\u0000\u00ab\u00ad\u0003"+
		"\u001a\r\u0000\u00ac\u00ab\u0001\u0000\u0000\u0000\u00ad\u00b0\u0001\u0000"+
		"\u0000\u0000\u00ae\u00ac\u0001\u0000\u0000\u0000\u00ae\u00af\u0001\u0000"+
		"\u0000\u0000\u00af\u00b1\u0001\u0000\u0000\u0000\u00b0\u00ae\u0001\u0000"+
		"\u0000\u0000\u00b1\u00b2\u0005\u001e\u0000\u0000\u00b2\u0019\u0001\u0000"+
		"\u0000\u0000\u00b3\u00b6\u0003\u0002\u0001\u0000\u00b4\u00b6\u0003\u001c"+
		"\u000e\u0000\u00b5\u00b3\u0001\u0000\u0000\u0000\u00b5\u00b4\u0001\u0000"+
		"\u0000\u0000\u00b6\u001b\u0001\u0000\u0000\u0000\u00b7\u00b8\u0003$\u0012"+
		"\u0000\u00b8\u00b9\u0005\f\u0000\u0000\u00b9\u00ba\u0003\u001e\u000f\u0000"+
		"\u00ba\u00bb\u0005\u0017\u0000\u0000\u00bb\u00da\u0001\u0000\u0000\u0000"+
		"\u00bc\u00be\u0003\u001e\u000f\u0000\u00bd\u00bc\u0001\u0000\u0000\u0000"+
		"\u00bd\u00be\u0001\u0000\u0000\u0000\u00be\u00bf\u0001\u0000\u0000\u0000"+
		"\u00bf\u00da\u0005\u0017\u0000\u0000\u00c0\u00da\u0003\u0018\f\u0000\u00c1"+
		"\u00c3\u0005\u000b\u0000\u0000\u00c2\u00c4\u0003\u001e\u000f\u0000\u00c3"+
		"\u00c2\u0001\u0000\u0000\u0000\u00c3\u00c4\u0001\u0000\u0000\u0000\u00c4"+
		"\u00c5\u0001\u0000\u0000\u0000\u00c5\u00da\u0005\u0017\u0000\u0000\u00c6"+
		"\u00c7\u0005\u0006\u0000\u0000\u00c7\u00c8\u0005\u0019\u0000\u0000\u00c8"+
		"\u00c9\u0003\"\u0011\u0000\u00c9\u00ca\u0005\u001a\u0000\u0000\u00ca\u00cd"+
		"\u0003\u001c\u000e\u0000\u00cb\u00cc\u0005\u0007\u0000\u0000\u00cc\u00ce"+
		"\u0003\u001c\u000e\u0000\u00cd\u00cb\u0001\u0000\u0000\u0000\u00cd\u00ce"+
		"\u0001\u0000\u0000\u0000\u00ce\u00da\u0001\u0000\u0000\u0000\u00cf\u00d0"+
		"\u0005\b\u0000\u0000\u00d0\u00d1\u0005\u0019\u0000\u0000\u00d1\u00d2\u0003"+
		"\"\u0011\u0000\u00d2\u00d3\u0005\u001a\u0000\u0000\u00d3\u00d4\u0003\u001c"+
		"\u000e\u0000\u00d4\u00da\u0001\u0000\u0000\u0000\u00d5\u00d6\u0005\t\u0000"+
		"\u0000\u00d6\u00da\u0005\u0017\u0000\u0000\u00d7\u00d8\u0005\n\u0000\u0000"+
		"\u00d8\u00da\u0005\u0017\u0000\u0000\u00d9\u00b7\u0001\u0000\u0000\u0000"+
		"\u00d9\u00bd\u0001\u0000\u0000\u0000\u00d9\u00c0\u0001\u0000\u0000\u0000"+
		"\u00d9\u00c1\u0001\u0000\u0000\u0000\u00d9\u00c6\u0001\u0000\u0000\u0000"+
		"\u00d9\u00cf\u0001\u0000\u0000\u0000\u00d9\u00d5\u0001\u0000\u0000\u0000"+
		"\u00d9\u00d7\u0001\u0000\u0000\u0000\u00da\u001d\u0001\u0000\u0000\u0000"+
		"\u00db\u00dc\u00030\u0018\u0000\u00dc\u001f\u0001\u0000\u0000\u0000\u00dd"+
		"\u00de\u00030\u0018\u0000\u00de!\u0001\u0000\u0000\u0000\u00df\u00e0\u0003"+
		"8\u001c\u0000\u00e0#\u0001\u0000\u0000\u0000\u00e1\u00e8\u0005&\u0000"+
		"\u0000\u00e2\u00e3\u0005\u001b\u0000\u0000\u00e3\u00e4\u0003\u001e\u000f"+
		"\u0000\u00e4\u00e5\u0005\u001c\u0000\u0000\u00e5\u00e7\u0001\u0000\u0000"+
		"\u0000\u00e6\u00e2\u0001\u0000\u0000\u0000\u00e7\u00ea\u0001\u0000\u0000"+
		"\u0000\u00e8\u00e6\u0001\u0000\u0000\u0000\u00e8\u00e9\u0001\u0000\u0000"+
		"\u0000\u00e9%\u0001\u0000\u0000\u0000\u00ea\u00e8\u0001\u0000\u0000\u0000"+
		"\u00eb\u00ec\u0007\u0002\u0000\u0000\u00ec\'\u0001\u0000\u0000\u0000\u00ed"+
		"\u00f2\u0003\u001e\u000f\u0000\u00ee\u00ef\u0005\u0016\u0000\u0000\u00ef"+
		"\u00f1\u0003\u001e\u000f\u0000\u00f0\u00ee\u0001\u0000\u0000\u0000\u00f1"+
		"\u00f4\u0001\u0000\u0000\u0000\u00f2\u00f0\u0001\u0000\u0000\u0000\u00f2"+
		"\u00f3\u0001\u0000\u0000\u0000\u00f3)\u0001\u0000\u0000\u0000\u00f4\u00f2"+
		"\u0001\u0000\u0000\u0000\u00f5\u00f6\u0005\u0019\u0000\u0000\u00f6\u00f7"+
		"\u0003\u001e\u000f\u0000\u00f7\u00f8\u0005\u001a\u0000\u0000\u00f8\u00fc"+
		"\u0001\u0000\u0000\u0000\u00f9\u00fc\u0003$\u0012\u0000\u00fa\u00fc\u0003"+
		"&\u0013\u0000\u00fb\u00f5\u0001\u0000\u0000\u0000\u00fb\u00f9\u0001\u0000"+
		"\u0000\u0000\u00fb\u00fa\u0001\u0000\u0000\u0000\u00fc+\u0001\u0000\u0000"+
		"\u0000\u00fd\u0107\u0003*\u0015\u0000\u00fe\u00ff\u0007\u0003\u0000\u0000"+
		"\u00ff\u0107\u0003,\u0016\u0000\u0100\u0101\u0005&\u0000\u0000\u0101\u0103"+
		"\u0005\u0019\u0000\u0000\u0102\u0104\u0003(\u0014\u0000\u0103\u0102\u0001"+
		"\u0000\u0000\u0000\u0103\u0104\u0001\u0000\u0000\u0000\u0104\u0105\u0001"+
		"\u0000\u0000\u0000\u0105\u0107\u0005\u001a\u0000\u0000\u0106\u00fd\u0001"+
		"\u0000\u0000\u0000\u0106\u00fe\u0001\u0000\u0000\u0000\u0106\u0100\u0001"+
		"\u0000\u0000\u0000\u0107-\u0001\u0000\u0000\u0000\u0108\u0109\u0006\u0017"+
		"\uffff\uffff\u0000\u0109\u010a\u0003,\u0016\u0000\u010a\u0110\u0001\u0000"+
		"\u0000\u0000\u010b\u010c\n\u0001\u0000\u0000\u010c\u010d\u0007\u0004\u0000"+
		"\u0000\u010d\u010f\u0003,\u0016\u0000\u010e\u010b\u0001\u0000\u0000\u0000"+
		"\u010f\u0112\u0001\u0000\u0000\u0000\u0110\u010e\u0001\u0000\u0000\u0000"+
		"\u0110\u0111\u0001\u0000\u0000\u0000\u0111/\u0001\u0000\u0000\u0000\u0112"+
		"\u0110\u0001\u0000\u0000\u0000\u0113\u0114\u0006\u0018\uffff\uffff\u0000"+
		"\u0114\u0115\u0003.\u0017\u0000\u0115\u011b\u0001\u0000\u0000\u0000\u0116"+
		"\u0117\n\u0001\u0000\u0000\u0117\u0118\u0007\u0005\u0000\u0000\u0118\u011a"+
		"\u0003.\u0017\u0000\u0119\u0116\u0001\u0000\u0000\u0000\u011a\u011d\u0001"+
		"\u0000\u0000\u0000\u011b\u0119\u0001\u0000\u0000\u0000\u011b\u011c\u0001"+
		"\u0000\u0000\u0000\u011c1\u0001\u0000\u0000\u0000\u011d\u011b\u0001\u0000"+
		"\u0000\u0000\u011e\u011f\u0006\u0019\uffff\uffff\u0000\u011f\u0120\u0003"+
		"0\u0018\u0000\u0120\u0126\u0001\u0000\u0000\u0000\u0121\u0122\n\u0001"+
		"\u0000\u0000\u0122\u0123\u0007\u0006\u0000\u0000\u0123\u0125\u00030\u0018"+
		"\u0000\u0124\u0121\u0001\u0000\u0000\u0000\u0125\u0128\u0001\u0000\u0000"+
		"\u0000\u0126\u0124\u0001\u0000\u0000\u0000\u0126\u0127\u0001\u0000\u0000"+
		"\u0000\u01273\u0001\u0000\u0000\u0000\u0128\u0126\u0001\u0000\u0000\u0000"+
		"\u0129\u012a\u0006\u001a\uffff\uffff\u0000\u012a\u012b\u00032\u0019\u0000"+
		"\u012b\u0131\u0001\u0000\u0000\u0000\u012c\u012d\n\u0001\u0000\u0000\u012d"+
		"\u012e\u0007\u0007\u0000\u0000\u012e\u0130\u00032\u0019\u0000\u012f\u012c"+
		"\u0001\u0000\u0000\u0000\u0130\u0133\u0001\u0000\u0000\u0000\u0131\u012f"+
		"\u0001\u0000\u0000\u0000\u0131\u0132\u0001\u0000\u0000\u0000\u01325\u0001"+
		"\u0000\u0000\u0000\u0133\u0131\u0001\u0000\u0000\u0000\u0134\u0135\u0006"+
		"\u001b\uffff\uffff\u0000\u0135\u0136\u00034\u001a\u0000\u0136\u013c\u0001"+
		"\u0000\u0000\u0000\u0137\u0138\n\u0001\u0000\u0000\u0138\u0139\u0005\u000e"+
		"\u0000\u0000\u0139\u013b\u00034\u001a\u0000\u013a\u0137\u0001\u0000\u0000"+
		"\u0000\u013b\u013e\u0001\u0000\u0000\u0000\u013c\u013a\u0001\u0000\u0000"+
		"\u0000\u013c\u013d\u0001\u0000\u0000\u0000\u013d7\u0001\u0000\u0000\u0000"+
		"\u013e\u013c\u0001\u0000\u0000\u0000\u013f\u0140\u0006\u001c\uffff\uffff"+
		"\u0000\u0140\u0141\u00036\u001b\u0000\u0141\u0147\u0001\u0000\u0000\u0000"+
		"\u0142\u0143\n\u0001\u0000\u0000\u0143\u0144\u0005\u000f\u0000\u0000\u0144"+
		"\u0146\u00036\u001b\u0000\u0145\u0142\u0001\u0000\u0000\u0000\u0146\u0149"+
		"\u0001\u0000\u0000\u0000\u0147\u0145\u0001\u0000\u0000\u0000\u0147\u0148"+
		"\u0001\u0000\u0000\u0000\u01489\u0001\u0000\u0000\u0000\u0149\u0147\u0001"+
		"\u0000\u0000\u0000!<>CLYfilt\u007f\u0084\u008a\u0096\u009d\u00a5\u00a8"+
		"\u00ae\u00b5\u00bd\u00c3\u00cd\u00d9\u00e8\u00f2\u00fb\u0103\u0106\u0110"+
		"\u011b\u0126\u0131\u013c\u0147";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}