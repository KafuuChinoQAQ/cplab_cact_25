// Generated from /home/sophia/cact/chiisai-llvm/grammar/LLVMParser.g4 by ANTLR 4.13.1

    #include <optional>
    #include <memory>
    #include <variant>
    #include <mini-llvm/ref.h>
    #include <mini-llvm/type.h>
    #include <mini-llvm/function.h>
    #include <mini-llvm/constant.h>
    #include <mini-llvm/constant-array.h>
    #include <mini-llvm/array-type.h>
    #include <mini-llvm/instruction.h>

import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class LLVMParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		Global=1, ConstantStr=2, External=3, Define=4, Declare=5, Align=6, Unreachable=7, 
		Br=8, Ret=9, Call=10, Load=11, Store=12, Alloca=13, GetElementPtr=14, 
		Phi=15, Add=16, FAdd=17, Sub=18, FSub=19, Mul=20, FMul=21, Div=22, FDiv=23, 
		And=24, Srem=25, Or=26, Xor=27, Shl=28, Lshr=29, Ashr=30, Icmp=31, Fcmp=32, 
		Sext=33, Zext=34, Trunc=35, Label=36, Void=37, Ptr=38, I1=39, I32=40, 
		Int=41, I64=42, Float=43, Double=44, Eq=45, Ne=46, Ugt=47, Uge=48, Ult=49, 
		Ule=50, Sgt=51, Sge=52, Slt=53, Sle=54, Oeq=55, One=56, Ogt=57, Oge=58, 
		Olt=59, Ole=60, Equals=61, Comma=62, LeftParen=63, RightParen=64, LeftBrace=65, 
		RightBrace=66, LeftBracket=67, RightBracket=68, At=69, Percent=70, Asterisk=71, 
		Colon=72, Cross=73, Minus=74, SourceFilename=75, GlobalName=76, LocalName=77, 
		LabelName=78, IntegerLiteral=79, HexLiteral=80, Whitespace=81, Comment=82, 
		SourceFileComment=83;
	public static final int
		RULE_scalarType = 0, RULE_basicType = 1, RULE_type = 2, RULE_pointerType = 3, 
		RULE_arrayType = 4, RULE_globalIdentifier = 5, RULE_localIdentifier = 6, 
		RULE_variable = 7, RULE_literal = 8, RULE_immediatelyUsableValue = 9, 
		RULE_module = 10, RULE_initializer = 11, RULE_constantArray = 12, RULE_globalDeclaration = 13, 
		RULE_functionDeclaration = 14, RULE_functionDefinition = 15, RULE_functionArguments = 16, 
		RULE_parameterList = 17, RULE_parameter = 18, RULE_basicBlock = 19, RULE_instruction = 20, 
		RULE_returnInstruction = 21, RULE_branchInstruction = 22, RULE_callInstruction = 23, 
		RULE_arithmeticInstruction = 24, RULE_loadInstruction = 25, RULE_storeInstruction = 26, 
		RULE_phiInstruction = 27, RULE_phiValue = 28, RULE_comparisonOperation = 29, 
		RULE_comparisonInstruction = 30, RULE_allocaInstruction = 31, RULE_binaryOperation = 32, 
		RULE_comparisonPredicate = 33, RULE_terminatorInstruction = 34, RULE_gepInstruction = 35;
	private static String[] makeRuleNames() {
		return new String[] {
			"scalarType", "basicType", "type", "pointerType", "arrayType", "globalIdentifier", 
			"localIdentifier", "variable", "literal", "immediatelyUsableValue", "module", 
			"initializer", "constantArray", "globalDeclaration", "functionDeclaration", 
			"functionDefinition", "functionArguments", "parameterList", "parameter", 
			"basicBlock", "instruction", "returnInstruction", "branchInstruction", 
			"callInstruction", "arithmeticInstruction", "loadInstruction", "storeInstruction", 
			"phiInstruction", "phiValue", "comparisonOperation", "comparisonInstruction", 
			"allocaInstruction", "binaryOperation", "comparisonPredicate", "terminatorInstruction", 
			"gepInstruction"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'global'", "'constant'", "'external'", "'define'", "'declare'", 
			"'align'", "'unreachable'", "'br'", "'ret'", "'call'", "'load'", "'store'", 
			"'alloca'", "'getelementptr'", "'phi'", "'add'", "'fadd'", "'sub'", "'fsub'", 
			"'mul'", "'fmul'", "'sdiv'", "'fdiv'", "'and'", "'srem'", "'or'", "'xor'", 
			"'shl'", "'lshr'", "'ashr'", "'icmp'", "'fcmp'", "'sext'", "'zext'", 
			"'trunc'", "'label'", "'void'", "'ptr'", "'i1'", "'i32'", "'int'", "'i64'", 
			"'float'", "'double'", "'eq'", "'ne'", "'ugt'", "'uge'", "'ult'", "'ule'", 
			"'sgt'", "'sge'", "'slt'", "'sle'", "'oeq'", "'one'", "'ogt'", "'oge'", 
			"'olt'", "'ole'", "'='", "','", "'('", "')'", "'{'", "'}'", "'['", "']'", 
			"'@'", "'%'", "'*'", "':'", "'x'", "'-'", "'source_filename'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "Global", "ConstantStr", "External", "Define", "Declare", "Align", 
			"Unreachable", "Br", "Ret", "Call", "Load", "Store", "Alloca", "GetElementPtr", 
			"Phi", "Add", "FAdd", "Sub", "FSub", "Mul", "FMul", "Div", "FDiv", "And", 
			"Srem", "Or", "Xor", "Shl", "Lshr", "Ashr", "Icmp", "Fcmp", "Sext", "Zext", 
			"Trunc", "Label", "Void", "Ptr", "I1", "I32", "Int", "I64", "Float", 
			"Double", "Eq", "Ne", "Ugt", "Uge", "Ult", "Ule", "Sgt", "Sge", "Slt", 
			"Sle", "Oeq", "One", "Ogt", "Oge", "Olt", "Ole", "Equals", "Comma", "LeftParen", 
			"RightParen", "LeftBrace", "RightBrace", "LeftBracket", "RightBracket", 
			"At", "Percent", "Asterisk", "Colon", "Cross", "Minus", "SourceFilename", 
			"GlobalName", "LocalName", "LabelName", "IntegerLiteral", "HexLiteral", 
			"Whitespace", "Comment", "SourceFileComment"
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
	public String getGrammarFileName() { return "LLVMParser.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public LLVMParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ScalarTypeContext extends ParserRuleContext {
		public CRef<Type> typeRef;
		public TerminalNode I1() { return getToken(LLVMParser.I1, 0); }
		public TerminalNode I32() { return getToken(LLVMParser.I32, 0); }
		public TerminalNode I64() { return getToken(LLVMParser.I64, 0); }
		public TerminalNode Float() { return getToken(LLVMParser.Float, 0); }
		public TerminalNode Double() { return getToken(LLVMParser.Double, 0); }
		public TerminalNode Int() { return getToken(LLVMParser.Int, 0); }
		public ScalarTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_scalarType; }
	}

	public final ScalarTypeContext scalarType() throws RecognitionException {
		ScalarTypeContext _localctx = new ScalarTypeContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_scalarType);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(72);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 34634616274944L) != 0)) ) {
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
	public static class BasicTypeContext extends ParserRuleContext {
		public CRef<Type> typeRef;
		public TerminalNode Void() { return getToken(LLVMParser.Void, 0); }
		public ScalarTypeContext scalarType() {
			return getRuleContext(ScalarTypeContext.class,0);
		}
		public BasicTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_basicType; }
	}

	public final BasicTypeContext basicType() throws RecognitionException {
		BasicTypeContext _localctx = new BasicTypeContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_basicType);
		try {
			setState(76);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Void:
				enterOuterAlt(_localctx, 1);
				{
				setState(74);
				match(Void);
				}
				break;
			case I1:
			case I32:
			case Int:
			case I64:
			case Float:
			case Double:
				enterOuterAlt(_localctx, 2);
				{
				setState(75);
				scalarType();
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
	public static class TypeContext extends ParserRuleContext {
		public CRef<Type> typeRef;
		public BasicTypeContext basicType() {
			return getRuleContext(BasicTypeContext.class,0);
		}
		public PointerTypeContext pointerType() {
			return getRuleContext(PointerTypeContext.class,0);
		}
		public ArrayTypeContext arrayType() {
			return getRuleContext(ArrayTypeContext.class,0);
		}
		public TypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type; }
	}

	public final TypeContext type() throws RecognitionException {
		TypeContext _localctx = new TypeContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_type);
		try {
			setState(81);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,1,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(78);
				basicType();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(79);
				pointerType(0);
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(80);
				arrayType();
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
	public static class PointerTypeContext extends ParserRuleContext {
		public CRef<Type> typeRef;
		public BasicTypeContext basicType() {
			return getRuleContext(BasicTypeContext.class,0);
		}
		public List<TerminalNode> Asterisk() { return getTokens(LLVMParser.Asterisk); }
		public TerminalNode Asterisk(int i) {
			return getToken(LLVMParser.Asterisk, i);
		}
		public ArrayTypeContext arrayType() {
			return getRuleContext(ArrayTypeContext.class,0);
		}
		public PointerTypeContext pointerType() {
			return getRuleContext(PointerTypeContext.class,0);
		}
		public PointerTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_pointerType; }
	}

	public final PointerTypeContext pointerType() throws RecognitionException {
		return pointerType(0);
	}

	private PointerTypeContext pointerType(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		PointerTypeContext _localctx = new PointerTypeContext(_ctx, _parentState);
		PointerTypeContext _prevctx = _localctx;
		int _startState = 6;
		enterRecursionRule(_localctx, 6, RULE_pointerType, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(96);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Void:
			case I1:
			case I32:
			case Int:
			case I64:
			case Float:
			case Double:
				{
				setState(84);
				basicType();
				setState(86); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(85);
						match(Asterisk);
						}
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					setState(88); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				}
				break;
			case LeftBracket:
				{
				setState(90);
				arrayType();
				setState(92); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(91);
						match(Asterisk);
						}
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					setState(94); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,3,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(106);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,6,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new PointerTypeContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_pointerType);
					setState(98);
					if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
					setState(100); 
					_errHandler.sync(this);
					_alt = 1;
					do {
						switch (_alt) {
						case 1:
							{
							{
							setState(99);
							match(Asterisk);
							}
							}
							break;
						default:
							throw new NoViableAltException(this);
						}
						setState(102); 
						_errHandler.sync(this);
						_alt = getInterpreter().adaptivePredict(_input,5,_ctx);
					} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
					}
					} 
				}
				setState(108);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,6,_ctx);
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
	public static class ArrayTypeContext extends ParserRuleContext {
		public CRef<ArrayType> typeRef;
		public TerminalNode LeftBracket() { return getToken(LLVMParser.LeftBracket, 0); }
		public TerminalNode IntegerLiteral() { return getToken(LLVMParser.IntegerLiteral, 0); }
		public TerminalNode Cross() { return getToken(LLVMParser.Cross, 0); }
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public TerminalNode RightBracket() { return getToken(LLVMParser.RightBracket, 0); }
		public ArrayTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_arrayType; }
	}

	public final ArrayTypeContext arrayType() throws RecognitionException {
		ArrayTypeContext _localctx = new ArrayTypeContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_arrayType);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(109);
			match(LeftBracket);
			setState(110);
			match(IntegerLiteral);
			setState(111);
			match(Cross);
			setState(112);
			type();
			setState(113);
			match(RightBracket);
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
	public static class GlobalIdentifierContext extends ParserRuleContext {
		public TerminalNode GlobalName() { return getToken(LLVMParser.GlobalName, 0); }
		public GlobalIdentifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_globalIdentifier; }
	}

	public final GlobalIdentifierContext globalIdentifier() throws RecognitionException {
		GlobalIdentifierContext _localctx = new GlobalIdentifierContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_globalIdentifier);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(115);
			match(GlobalName);
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
	public static class LocalIdentifierContext extends ParserRuleContext {
		public TerminalNode LocalName() { return getToken(LLVMParser.LocalName, 0); }
		public TerminalNode Percent() { return getToken(LLVMParser.Percent, 0); }
		public TerminalNode IntegerLiteral() { return getToken(LLVMParser.IntegerLiteral, 0); }
		public LocalIdentifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_localIdentifier; }
	}

	public final LocalIdentifierContext localIdentifier() throws RecognitionException {
		LocalIdentifierContext _localctx = new LocalIdentifierContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_localIdentifier);
		try {
			setState(120);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LocalName:
				enterOuterAlt(_localctx, 1);
				{
				setState(117);
				match(LocalName);
				}
				break;
			case Percent:
				enterOuterAlt(_localctx, 2);
				{
				setState(118);
				match(Percent);
				setState(119);
				match(IntegerLiteral);
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
	public static class VariableContext extends ParserRuleContext {
		public bool isGlobal;
		public GlobalIdentifierContext globalIdentifier() {
			return getRuleContext(GlobalIdentifierContext.class,0);
		}
		public LocalIdentifierContext localIdentifier() {
			return getRuleContext(LocalIdentifierContext.class,0);
		}
		public VariableContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variable; }
	}

	public final VariableContext variable() throws RecognitionException {
		VariableContext _localctx = new VariableContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_variable);
		try {
			setState(124);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case GlobalName:
				enterOuterAlt(_localctx, 1);
				{
				setState(122);
				globalIdentifier();
				}
				break;
			case Percent:
			case LocalName:
				enterOuterAlt(_localctx, 2);
				{
				setState(123);
				localIdentifier();
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
	public static class LiteralContext extends ParserRuleContext {
		public TerminalNode IntegerLiteral() { return getToken(LLVMParser.IntegerLiteral, 0); }
		public TerminalNode Minus() { return getToken(LLVMParser.Minus, 0); }
		public TerminalNode HexLiteral() { return getToken(LLVMParser.HexLiteral, 0); }
		public LiteralContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_literal; }
	}

	public final LiteralContext literal() throws RecognitionException {
		LiteralContext _localctx = new LiteralContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_literal);
		int _la;
		try {
			setState(131);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Minus:
			case IntegerLiteral:
				enterOuterAlt(_localctx, 1);
				{
				setState(127);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==Minus) {
					{
					setState(126);
					match(Minus);
					}
				}

				setState(129);
				match(IntegerLiteral);
				}
				break;
			case HexLiteral:
				enterOuterAlt(_localctx, 2);
				{
				setState(130);
				match(HexLiteral);
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
	public static class ImmediatelyUsableValueContext extends ParserRuleContext {
		public bool isConstant;
		public LocalIdentifierContext localIdentifier() {
			return getRuleContext(LocalIdentifierContext.class,0);
		}
		public LiteralContext literal() {
			return getRuleContext(LiteralContext.class,0);
		}
		public ImmediatelyUsableValueContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_immediatelyUsableValue; }
	}

	public final ImmediatelyUsableValueContext immediatelyUsableValue() throws RecognitionException {
		ImmediatelyUsableValueContext _localctx = new ImmediatelyUsableValueContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_immediatelyUsableValue);
		try {
			setState(135);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Percent:
			case LocalName:
				enterOuterAlt(_localctx, 1);
				{
				setState(133);
				localIdentifier();
				}
				break;
			case Minus:
			case IntegerLiteral:
			case HexLiteral:
				enterOuterAlt(_localctx, 2);
				{
				setState(134);
				literal();
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
	public static class ModuleContext extends ParserRuleContext {
		public List<GlobalDeclarationContext> globalDeclaration() {
			return getRuleContexts(GlobalDeclarationContext.class);
		}
		public GlobalDeclarationContext globalDeclaration(int i) {
			return getRuleContext(GlobalDeclarationContext.class,i);
		}
		public List<FunctionDeclarationContext> functionDeclaration() {
			return getRuleContexts(FunctionDeclarationContext.class);
		}
		public FunctionDeclarationContext functionDeclaration(int i) {
			return getRuleContext(FunctionDeclarationContext.class,i);
		}
		public List<FunctionDefinitionContext> functionDefinition() {
			return getRuleContexts(FunctionDefinitionContext.class);
		}
		public FunctionDefinitionContext functionDefinition(int i) {
			return getRuleContext(FunctionDefinitionContext.class,i);
		}
		public ModuleContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_module; }
	}

	public final ModuleContext module() throws RecognitionException {
		ModuleContext _localctx = new ModuleContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_module);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(142);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==Define || _la==Declare || _la==GlobalName) {
				{
				setState(140);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case GlobalName:
					{
					setState(137);
					globalDeclaration();
					}
					break;
				case Declare:
					{
					setState(138);
					functionDeclaration();
					}
					break;
				case Define:
					{
					setState(139);
					functionDefinition();
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				}
				setState(144);
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
	public static class InitializerContext extends ParserRuleContext {
		public std::string name;
		public CRef<Type> typeRef;
		public CRef<Constant> constant;
		public ScalarTypeContext scalarType() {
			return getRuleContext(ScalarTypeContext.class,0);
		}
		public TerminalNode IntegerLiteral() { return getToken(LLVMParser.IntegerLiteral, 0); }
		public TerminalNode HexLiteral() { return getToken(LLVMParser.HexLiteral, 0); }
		public ConstantArrayContext constantArray() {
			return getRuleContext(ConstantArrayContext.class,0);
		}
		public InitializerContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_initializer; }
	}

	public final InitializerContext initializer() throws RecognitionException {
		InitializerContext _localctx = new InitializerContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_initializer);
		try {
			setState(152);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,14,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(145);
				scalarType();
				setState(146);
				match(IntegerLiteral);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(148);
				scalarType();
				setState(149);
				match(HexLiteral);
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(151);
				constantArray();
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
	public static class ConstantArrayContext extends ParserRuleContext {
		public std::string name;
		public CRef<Constant> constArray;
		public ArrayTypeContext arrayType() {
			return getRuleContext(ArrayTypeContext.class,0);
		}
		public TerminalNode LeftBracket() { return getToken(LLVMParser.LeftBracket, 0); }
		public TerminalNode RightBracket() { return getToken(LLVMParser.RightBracket, 0); }
		public List<InitializerContext> initializer() {
			return getRuleContexts(InitializerContext.class);
		}
		public InitializerContext initializer(int i) {
			return getRuleContext(InitializerContext.class,i);
		}
		public List<TerminalNode> Comma() { return getTokens(LLVMParser.Comma); }
		public TerminalNode Comma(int i) {
			return getToken(LLVMParser.Comma, i);
		}
		public ConstantArrayContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constantArray; }
	}

	public final ConstantArrayContext constantArray() throws RecognitionException {
		ConstantArrayContext _localctx = new ConstantArrayContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_constantArray);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(154);
			arrayType();
			setState(155);
			match(LeftBracket);
			setState(164);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (((((_la - 39)) & ~0x3f) == 0 && ((1L << (_la - 39)) & 268435519L) != 0)) {
				{
				setState(156);
				initializer();
				setState(161);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==Comma) {
					{
					{
					setState(157);
					match(Comma);
					setState(158);
					initializer();
					}
					}
					setState(163);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
			}

			setState(166);
			match(RightBracket);
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
	public static class GlobalDeclarationContext extends ParserRuleContext {
		public GlobalIdentifierContext globalIdentifier() {
			return getRuleContext(GlobalIdentifierContext.class,0);
		}
		public TerminalNode Equals() { return getToken(LLVMParser.Equals, 0); }
		public InitializerContext initializer() {
			return getRuleContext(InitializerContext.class,0);
		}
		public TerminalNode Global() { return getToken(LLVMParser.Global, 0); }
		public TerminalNode ConstantStr() { return getToken(LLVMParser.ConstantStr, 0); }
		public TerminalNode Comma() { return getToken(LLVMParser.Comma, 0); }
		public TerminalNode Align() { return getToken(LLVMParser.Align, 0); }
		public TerminalNode IntegerLiteral() { return getToken(LLVMParser.IntegerLiteral, 0); }
		public GlobalDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_globalDeclaration; }
	}

	public final GlobalDeclarationContext globalDeclaration() throws RecognitionException {
		GlobalDeclarationContext _localctx = new GlobalDeclarationContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_globalDeclaration);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(168);
			globalIdentifier();
			setState(169);
			match(Equals);
			setState(170);
			_la = _input.LA(1);
			if ( !(_la==Global || _la==ConstantStr) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			setState(171);
			initializer();
			setState(175);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==Comma) {
				{
				setState(172);
				match(Comma);
				setState(173);
				match(Align);
				setState(174);
				match(IntegerLiteral);
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
	public static class FunctionDeclarationContext extends ParserRuleContext {
		public std::unique_ptr<Function> function;
		public std::vector<CRef<Type>> argTypes;
		public std::vector<std::string> argNames;
		public TerminalNode Declare() { return getToken(LLVMParser.Declare, 0); }
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public GlobalIdentifierContext globalIdentifier() {
			return getRuleContext(GlobalIdentifierContext.class,0);
		}
		public FunctionArgumentsContext functionArguments() {
			return getRuleContext(FunctionArgumentsContext.class,0);
		}
		public FunctionDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_functionDeclaration; }
	}

	public final FunctionDeclarationContext functionDeclaration() throws RecognitionException {
		FunctionDeclarationContext _localctx = new FunctionDeclarationContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_functionDeclaration);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(177);
			match(Declare);
			setState(178);
			type();
			setState(179);
			globalIdentifier();
			setState(180);
			functionArguments();
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
	public static class FunctionDefinitionContext extends ParserRuleContext {
		public std::unique_ptr<Function> function;
		public std::vector<CRef<Type>> argTypes;
		public std::vector<std::string> argNames;
		public TerminalNode Define() { return getToken(LLVMParser.Define, 0); }
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public GlobalIdentifierContext globalIdentifier() {
			return getRuleContext(GlobalIdentifierContext.class,0);
		}
		public FunctionArgumentsContext functionArguments() {
			return getRuleContext(FunctionArgumentsContext.class,0);
		}
		public TerminalNode LeftBrace() { return getToken(LLVMParser.LeftBrace, 0); }
		public TerminalNode RightBrace() { return getToken(LLVMParser.RightBrace, 0); }
		public List<BasicBlockContext> basicBlock() {
			return getRuleContexts(BasicBlockContext.class);
		}
		public BasicBlockContext basicBlock(int i) {
			return getRuleContext(BasicBlockContext.class,i);
		}
		public FunctionDefinitionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_functionDefinition; }
	}

	public final FunctionDefinitionContext functionDefinition() throws RecognitionException {
		FunctionDefinitionContext _localctx = new FunctionDefinitionContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_functionDefinition);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(182);
			match(Define);
			setState(183);
			type();
			setState(184);
			globalIdentifier();
			setState(185);
			functionArguments();
			setState(194);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==LeftBrace) {
				{
				setState(186);
				match(LeftBrace);
				setState(190);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==LabelName) {
					{
					{
					setState(187);
					basicBlock();
					}
					}
					setState(192);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(193);
				match(RightBrace);
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
	public static class FunctionArgumentsContext extends ParserRuleContext {
		public std::vector<CRef<Type>> argTypes;
		public std::vector<std::string> argNames;
		public TerminalNode LeftParen() { return getToken(LLVMParser.LeftParen, 0); }
		public TerminalNode RightParen() { return getToken(LLVMParser.RightParen, 0); }
		public ParameterListContext parameterList() {
			return getRuleContext(ParameterListContext.class,0);
		}
		public FunctionArgumentsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_functionArguments; }
	}

	public final FunctionArgumentsContext functionArguments() throws RecognitionException {
		FunctionArgumentsContext _localctx = new FunctionArgumentsContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_functionArguments);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(196);
			match(LeftParen);
			setState(198);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (((((_la - 37)) & ~0x3f) == 0 && ((1L << (_la - 37)) & 1073742077L) != 0)) {
				{
				setState(197);
				parameterList();
				}
			}

			setState(200);
			match(RightParen);
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
	public static class ParameterListContext extends ParserRuleContext {
		public std::vector<CRef<Type>> argTypes;
		public std::vector<std::string> argNames;
		public List<ParameterContext> parameter() {
			return getRuleContexts(ParameterContext.class);
		}
		public ParameterContext parameter(int i) {
			return getRuleContext(ParameterContext.class,i);
		}
		public List<TerminalNode> Comma() { return getTokens(LLVMParser.Comma); }
		public TerminalNode Comma(int i) {
			return getToken(LLVMParser.Comma, i);
		}
		public ParameterListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameterList; }
	}

	public final ParameterListContext parameterList() throws RecognitionException {
		ParameterListContext _localctx = new ParameterListContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_parameterList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(202);
			parameter();
			setState(207);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==Comma) {
				{
				{
				setState(203);
				match(Comma);
				setState(204);
				parameter();
				}
				}
				setState(209);
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
	public static class ParameterContext extends ParserRuleContext {
		public CRef<Type> argType;
		public std::string argName;
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public LocalIdentifierContext localIdentifier() {
			return getRuleContext(LocalIdentifierContext.class,0);
		}
		public ParameterContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameter; }
	}

	public final ParameterContext parameter() throws RecognitionException {
		ParameterContext _localctx = new ParameterContext(_ctx, getState());
		enterRule(_localctx, 36, RULE_parameter);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(210);
			type();
			setState(212);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==Percent || _la==LocalName) {
				{
				setState(211);
				localIdentifier();
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
	public static class BasicBlockContext extends ParserRuleContext {
		public TerminalNode LabelName() { return getToken(LLVMParser.LabelName, 0); }
		public List<InstructionContext> instruction() {
			return getRuleContexts(InstructionContext.class);
		}
		public InstructionContext instruction(int i) {
			return getRuleContext(InstructionContext.class,i);
		}
		public BasicBlockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_basicBlock; }
	}

	public final BasicBlockContext basicBlock() throws RecognitionException {
		BasicBlockContext _localctx = new BasicBlockContext(_ctx, getState());
		enterRule(_localctx, 38, RULE_basicBlock);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(214);
			match(LabelName);
			setState(218);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & 5888L) != 0) || _la==Percent || _la==LocalName) {
				{
				{
				setState(215);
				instruction();
				}
				}
				setState(220);
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
	public static class InstructionContext extends ParserRuleContext {
		public std::unique_ptr<Instruction> inst;
		public CallInstructionContext callInstruction() {
			return getRuleContext(CallInstructionContext.class,0);
		}
		public ArithmeticInstructionContext arithmeticInstruction() {
			return getRuleContext(ArithmeticInstructionContext.class,0);
		}
		public LoadInstructionContext loadInstruction() {
			return getRuleContext(LoadInstructionContext.class,0);
		}
		public StoreInstructionContext storeInstruction() {
			return getRuleContext(StoreInstructionContext.class,0);
		}
		public PhiInstructionContext phiInstruction() {
			return getRuleContext(PhiInstructionContext.class,0);
		}
		public ComparisonInstructionContext comparisonInstruction() {
			return getRuleContext(ComparisonInstructionContext.class,0);
		}
		public AllocaInstructionContext allocaInstruction() {
			return getRuleContext(AllocaInstructionContext.class,0);
		}
		public TerminatorInstructionContext terminatorInstruction() {
			return getRuleContext(TerminatorInstructionContext.class,0);
		}
		public GepInstructionContext gepInstruction() {
			return getRuleContext(GepInstructionContext.class,0);
		}
		public InstructionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_instruction; }
	}

	public final InstructionContext instruction() throws RecognitionException {
		InstructionContext _localctx = new InstructionContext(_ctx, getState());
		enterRule(_localctx, 40, RULE_instruction);
		try {
			setState(230);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,24,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(221);
				callInstruction();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(222);
				arithmeticInstruction();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(223);
				loadInstruction();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(224);
				storeInstruction();
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(225);
				phiInstruction();
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(226);
				comparisonInstruction();
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(227);
				allocaInstruction();
				}
				break;
			case 8:
				enterOuterAlt(_localctx, 8);
				{
				setState(228);
				terminatorInstruction();
				}
				break;
			case 9:
				enterOuterAlt(_localctx, 9);
				{
				setState(229);
				gepInstruction();
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
	public static class ReturnInstructionContext extends ParserRuleContext {
		public TerminalNode Ret() { return getToken(LLVMParser.Ret, 0); }
		public TerminalNode Void() { return getToken(LLVMParser.Void, 0); }
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public ImmediatelyUsableValueContext immediatelyUsableValue() {
			return getRuleContext(ImmediatelyUsableValueContext.class,0);
		}
		public ReturnInstructionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_returnInstruction; }
	}

	public final ReturnInstructionContext returnInstruction() throws RecognitionException {
		ReturnInstructionContext _localctx = new ReturnInstructionContext(_ctx, getState());
		enterRule(_localctx, 42, RULE_returnInstruction);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(232);
			match(Ret);
			setState(237);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,25,_ctx) ) {
			case 1:
				{
				setState(233);
				match(Void);
				}
				break;
			case 2:
				{
				{
				setState(234);
				type();
				setState(235);
				immediatelyUsableValue();
				}
				}
				break;
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
	public static class BranchInstructionContext extends ParserRuleContext {
		public TerminalNode Br() { return getToken(LLVMParser.Br, 0); }
		public TerminalNode I1() { return getToken(LLVMParser.I1, 0); }
		public ImmediatelyUsableValueContext immediatelyUsableValue() {
			return getRuleContext(ImmediatelyUsableValueContext.class,0);
		}
		public List<TerminalNode> Comma() { return getTokens(LLVMParser.Comma); }
		public TerminalNode Comma(int i) {
			return getToken(LLVMParser.Comma, i);
		}
		public List<TerminalNode> Label() { return getTokens(LLVMParser.Label); }
		public TerminalNode Label(int i) {
			return getToken(LLVMParser.Label, i);
		}
		public List<LocalIdentifierContext> localIdentifier() {
			return getRuleContexts(LocalIdentifierContext.class);
		}
		public LocalIdentifierContext localIdentifier(int i) {
			return getRuleContext(LocalIdentifierContext.class,i);
		}
		public BranchInstructionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_branchInstruction; }
	}

	public final BranchInstructionContext branchInstruction() throws RecognitionException {
		BranchInstructionContext _localctx = new BranchInstructionContext(_ctx, getState());
		enterRule(_localctx, 44, RULE_branchInstruction);
		try {
			setState(252);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,26,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(239);
				match(Br);
				setState(240);
				match(I1);
				setState(241);
				immediatelyUsableValue();
				setState(242);
				match(Comma);
				setState(243);
				match(Label);
				setState(244);
				localIdentifier();
				setState(245);
				match(Comma);
				setState(246);
				match(Label);
				setState(247);
				localIdentifier();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(249);
				match(Br);
				setState(250);
				match(Label);
				setState(251);
				localIdentifier();
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
	public static class CallInstructionContext extends ParserRuleContext {
		public TerminalNode Call() { return getToken(LLVMParser.Call, 0); }
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public GlobalIdentifierContext globalIdentifier() {
			return getRuleContext(GlobalIdentifierContext.class,0);
		}
		public FunctionArgumentsContext functionArguments() {
			return getRuleContext(FunctionArgumentsContext.class,0);
		}
		public LocalIdentifierContext localIdentifier() {
			return getRuleContext(LocalIdentifierContext.class,0);
		}
		public TerminalNode Equals() { return getToken(LLVMParser.Equals, 0); }
		public CallInstructionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_callInstruction; }
	}

	public final CallInstructionContext callInstruction() throws RecognitionException {
		CallInstructionContext _localctx = new CallInstructionContext(_ctx, getState());
		enterRule(_localctx, 46, RULE_callInstruction);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(257);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==Percent || _la==LocalName) {
				{
				setState(254);
				localIdentifier();
				setState(255);
				match(Equals);
				}
			}

			setState(259);
			match(Call);
			setState(260);
			type();
			setState(261);
			globalIdentifier();
			setState(262);
			functionArguments();
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
	public static class ArithmeticInstructionContext extends ParserRuleContext {
		public LocalIdentifierContext localIdentifier() {
			return getRuleContext(LocalIdentifierContext.class,0);
		}
		public TerminalNode Equals() { return getToken(LLVMParser.Equals, 0); }
		public BinaryOperationContext binaryOperation() {
			return getRuleContext(BinaryOperationContext.class,0);
		}
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public List<ImmediatelyUsableValueContext> immediatelyUsableValue() {
			return getRuleContexts(ImmediatelyUsableValueContext.class);
		}
		public ImmediatelyUsableValueContext immediatelyUsableValue(int i) {
			return getRuleContext(ImmediatelyUsableValueContext.class,i);
		}
		public TerminalNode Comma() { return getToken(LLVMParser.Comma, 0); }
		public ArithmeticInstructionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_arithmeticInstruction; }
	}

	public final ArithmeticInstructionContext arithmeticInstruction() throws RecognitionException {
		ArithmeticInstructionContext _localctx = new ArithmeticInstructionContext(_ctx, getState());
		enterRule(_localctx, 48, RULE_arithmeticInstruction);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(264);
			localIdentifier();
			setState(265);
			match(Equals);
			setState(266);
			binaryOperation();
			setState(267);
			type();
			setState(268);
			immediatelyUsableValue();
			setState(269);
			match(Comma);
			setState(270);
			immediatelyUsableValue();
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
	public static class LoadInstructionContext extends ParserRuleContext {
		public LocalIdentifierContext localIdentifier() {
			return getRuleContext(LocalIdentifierContext.class,0);
		}
		public TerminalNode Equals() { return getToken(LLVMParser.Equals, 0); }
		public TerminalNode Load() { return getToken(LLVMParser.Load, 0); }
		public List<TypeContext> type() {
			return getRuleContexts(TypeContext.class);
		}
		public TypeContext type(int i) {
			return getRuleContext(TypeContext.class,i);
		}
		public List<TerminalNode> Comma() { return getTokens(LLVMParser.Comma); }
		public TerminalNode Comma(int i) {
			return getToken(LLVMParser.Comma, i);
		}
		public TerminalNode Asterisk() { return getToken(LLVMParser.Asterisk, 0); }
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public TerminalNode Align() { return getToken(LLVMParser.Align, 0); }
		public TerminalNode IntegerLiteral() { return getToken(LLVMParser.IntegerLiteral, 0); }
		public LoadInstructionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_loadInstruction; }
	}

	public final LoadInstructionContext loadInstruction() throws RecognitionException {
		LoadInstructionContext _localctx = new LoadInstructionContext(_ctx, getState());
		enterRule(_localctx, 50, RULE_loadInstruction);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(272);
			localIdentifier();
			setState(273);
			match(Equals);
			setState(274);
			match(Load);
			setState(275);
			type();
			setState(276);
			match(Comma);
			setState(277);
			type();
			setState(278);
			match(Asterisk);
			setState(279);
			variable();
			setState(283);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==Comma) {
				{
				setState(280);
				match(Comma);
				setState(281);
				match(Align);
				setState(282);
				match(IntegerLiteral);
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
	public static class StoreInstructionContext extends ParserRuleContext {
		public TerminalNode Store() { return getToken(LLVMParser.Store, 0); }
		public List<TypeContext> type() {
			return getRuleContexts(TypeContext.class);
		}
		public TypeContext type(int i) {
			return getRuleContext(TypeContext.class,i);
		}
		public ImmediatelyUsableValueContext immediatelyUsableValue() {
			return getRuleContext(ImmediatelyUsableValueContext.class,0);
		}
		public List<TerminalNode> Comma() { return getTokens(LLVMParser.Comma); }
		public TerminalNode Comma(int i) {
			return getToken(LLVMParser.Comma, i);
		}
		public TerminalNode Asterisk() { return getToken(LLVMParser.Asterisk, 0); }
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public TerminalNode Align() { return getToken(LLVMParser.Align, 0); }
		public TerminalNode IntegerLiteral() { return getToken(LLVMParser.IntegerLiteral, 0); }
		public StoreInstructionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_storeInstruction; }
	}

	public final StoreInstructionContext storeInstruction() throws RecognitionException {
		StoreInstructionContext _localctx = new StoreInstructionContext(_ctx, getState());
		enterRule(_localctx, 52, RULE_storeInstruction);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(285);
			match(Store);
			setState(286);
			type();
			setState(287);
			immediatelyUsableValue();
			setState(288);
			match(Comma);
			setState(289);
			type();
			setState(290);
			match(Asterisk);
			setState(291);
			variable();
			setState(295);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==Comma) {
				{
				setState(292);
				match(Comma);
				setState(293);
				match(Align);
				setState(294);
				match(IntegerLiteral);
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
	public static class PhiInstructionContext extends ParserRuleContext {
		public LocalIdentifierContext localIdentifier() {
			return getRuleContext(LocalIdentifierContext.class,0);
		}
		public TerminalNode Equals() { return getToken(LLVMParser.Equals, 0); }
		public TerminalNode Phi() { return getToken(LLVMParser.Phi, 0); }
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public List<PhiValueContext> phiValue() {
			return getRuleContexts(PhiValueContext.class);
		}
		public PhiValueContext phiValue(int i) {
			return getRuleContext(PhiValueContext.class,i);
		}
		public List<TerminalNode> Comma() { return getTokens(LLVMParser.Comma); }
		public TerminalNode Comma(int i) {
			return getToken(LLVMParser.Comma, i);
		}
		public PhiInstructionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_phiInstruction; }
	}

	public final PhiInstructionContext phiInstruction() throws RecognitionException {
		PhiInstructionContext _localctx = new PhiInstructionContext(_ctx, getState());
		enterRule(_localctx, 54, RULE_phiInstruction);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(297);
			localIdentifier();
			setState(298);
			match(Equals);
			setState(299);
			match(Phi);
			setState(300);
			type();
			setState(301);
			phiValue();
			setState(306);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==Comma) {
				{
				{
				setState(302);
				match(Comma);
				setState(303);
				phiValue();
				}
				}
				setState(308);
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
	public static class PhiValueContext extends ParserRuleContext {
		public Ref<BasicBlock> block;
		public Ref<Value> value;
		public CRef<Type> typeRef;
		public TerminalNode LeftBrace() { return getToken(LLVMParser.LeftBrace, 0); }
		public ImmediatelyUsableValueContext immediatelyUsableValue() {
			return getRuleContext(ImmediatelyUsableValueContext.class,0);
		}
		public TerminalNode Comma() { return getToken(LLVMParser.Comma, 0); }
		public LocalIdentifierContext localIdentifier() {
			return getRuleContext(LocalIdentifierContext.class,0);
		}
		public TerminalNode RightBrace() { return getToken(LLVMParser.RightBrace, 0); }
		public PhiValueContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_phiValue; }
	}

	public final PhiValueContext phiValue() throws RecognitionException {
		PhiValueContext _localctx = new PhiValueContext(_ctx, getState());
		enterRule(_localctx, 56, RULE_phiValue);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(309);
			match(LeftBrace);
			setState(310);
			immediatelyUsableValue();
			setState(311);
			match(Comma);
			setState(312);
			localIdentifier();
			setState(313);
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
	public static class ComparisonOperationContext extends ParserRuleContext {
		public TerminalNode Icmp() { return getToken(LLVMParser.Icmp, 0); }
		public TerminalNode Fcmp() { return getToken(LLVMParser.Fcmp, 0); }
		public ComparisonOperationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_comparisonOperation; }
	}

	public final ComparisonOperationContext comparisonOperation() throws RecognitionException {
		ComparisonOperationContext _localctx = new ComparisonOperationContext(_ctx, getState());
		enterRule(_localctx, 58, RULE_comparisonOperation);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(315);
			_la = _input.LA(1);
			if ( !(_la==Icmp || _la==Fcmp) ) {
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
	public static class ComparisonInstructionContext extends ParserRuleContext {
		public LocalIdentifierContext localIdentifier() {
			return getRuleContext(LocalIdentifierContext.class,0);
		}
		public TerminalNode Equals() { return getToken(LLVMParser.Equals, 0); }
		public ComparisonOperationContext comparisonOperation() {
			return getRuleContext(ComparisonOperationContext.class,0);
		}
		public ComparisonPredicateContext comparisonPredicate() {
			return getRuleContext(ComparisonPredicateContext.class,0);
		}
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public List<ImmediatelyUsableValueContext> immediatelyUsableValue() {
			return getRuleContexts(ImmediatelyUsableValueContext.class);
		}
		public ImmediatelyUsableValueContext immediatelyUsableValue(int i) {
			return getRuleContext(ImmediatelyUsableValueContext.class,i);
		}
		public TerminalNode Comma() { return getToken(LLVMParser.Comma, 0); }
		public ComparisonInstructionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_comparisonInstruction; }
	}

	public final ComparisonInstructionContext comparisonInstruction() throws RecognitionException {
		ComparisonInstructionContext _localctx = new ComparisonInstructionContext(_ctx, getState());
		enterRule(_localctx, 60, RULE_comparisonInstruction);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(317);
			localIdentifier();
			setState(318);
			match(Equals);
			setState(319);
			comparisonOperation();
			setState(320);
			comparisonPredicate();
			setState(321);
			type();
			setState(322);
			immediatelyUsableValue();
			setState(323);
			match(Comma);
			setState(324);
			immediatelyUsableValue();
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
	public static class AllocaInstructionContext extends ParserRuleContext {
		public LocalIdentifierContext localIdentifier() {
			return getRuleContext(LocalIdentifierContext.class,0);
		}
		public TerminalNode Equals() { return getToken(LLVMParser.Equals, 0); }
		public TerminalNode Alloca() { return getToken(LLVMParser.Alloca, 0); }
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public List<TerminalNode> Comma() { return getTokens(LLVMParser.Comma); }
		public TerminalNode Comma(int i) {
			return getToken(LLVMParser.Comma, i);
		}
		public TerminalNode I32() { return getToken(LLVMParser.I32, 0); }
		public List<TerminalNode> IntegerLiteral() { return getTokens(LLVMParser.IntegerLiteral); }
		public TerminalNode IntegerLiteral(int i) {
			return getToken(LLVMParser.IntegerLiteral, i);
		}
		public TerminalNode Align() { return getToken(LLVMParser.Align, 0); }
		public AllocaInstructionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_allocaInstruction; }
	}

	public final AllocaInstructionContext allocaInstruction() throws RecognitionException {
		AllocaInstructionContext _localctx = new AllocaInstructionContext(_ctx, getState());
		enterRule(_localctx, 62, RULE_allocaInstruction);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(326);
			localIdentifier();
			setState(327);
			match(Equals);
			setState(328);
			match(Alloca);
			setState(329);
			type();
			setState(333);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,31,_ctx) ) {
			case 1:
				{
				setState(330);
				match(Comma);
				setState(331);
				match(I32);
				setState(332);
				match(IntegerLiteral);
				}
				break;
			}
			setState(338);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==Comma) {
				{
				setState(335);
				match(Comma);
				setState(336);
				match(Align);
				setState(337);
				match(IntegerLiteral);
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
	public static class BinaryOperationContext extends ParserRuleContext {
		public TerminalNode Add() { return getToken(LLVMParser.Add, 0); }
		public TerminalNode Sub() { return getToken(LLVMParser.Sub, 0); }
		public TerminalNode Mul() { return getToken(LLVMParser.Mul, 0); }
		public TerminalNode Div() { return getToken(LLVMParser.Div, 0); }
		public TerminalNode Srem() { return getToken(LLVMParser.Srem, 0); }
		public TerminalNode FAdd() { return getToken(LLVMParser.FAdd, 0); }
		public TerminalNode FSub() { return getToken(LLVMParser.FSub, 0); }
		public TerminalNode FMul() { return getToken(LLVMParser.FMul, 0); }
		public TerminalNode FDiv() { return getToken(LLVMParser.FDiv, 0); }
		public BinaryOperationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_binaryOperation; }
	}

	public final BinaryOperationContext binaryOperation() throws RecognitionException {
		BinaryOperationContext _localctx = new BinaryOperationContext(_ctx, getState());
		enterRule(_localctx, 64, RULE_binaryOperation);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(340);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 50266112L) != 0)) ) {
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
	public static class ComparisonPredicateContext extends ParserRuleContext {
		public TerminalNode Eq() { return getToken(LLVMParser.Eq, 0); }
		public TerminalNode Ne() { return getToken(LLVMParser.Ne, 0); }
		public TerminalNode Ugt() { return getToken(LLVMParser.Ugt, 0); }
		public TerminalNode Uge() { return getToken(LLVMParser.Uge, 0); }
		public TerminalNode Ult() { return getToken(LLVMParser.Ult, 0); }
		public TerminalNode Ule() { return getToken(LLVMParser.Ule, 0); }
		public TerminalNode Sgt() { return getToken(LLVMParser.Sgt, 0); }
		public TerminalNode Sge() { return getToken(LLVMParser.Sge, 0); }
		public TerminalNode Slt() { return getToken(LLVMParser.Slt, 0); }
		public TerminalNode Sle() { return getToken(LLVMParser.Sle, 0); }
		public TerminalNode Oeq() { return getToken(LLVMParser.Oeq, 0); }
		public TerminalNode One() { return getToken(LLVMParser.One, 0); }
		public TerminalNode Ogt() { return getToken(LLVMParser.Ogt, 0); }
		public TerminalNode Oge() { return getToken(LLVMParser.Oge, 0); }
		public TerminalNode Olt() { return getToken(LLVMParser.Olt, 0); }
		public TerminalNode Ole() { return getToken(LLVMParser.Ole, 0); }
		public ComparisonPredicateContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_comparisonPredicate; }
	}

	public final ComparisonPredicateContext comparisonPredicate() throws RecognitionException {
		ComparisonPredicateContext _localctx = new ComparisonPredicateContext(_ctx, getState());
		enterRule(_localctx, 66, RULE_comparisonPredicate);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(342);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 2305807824841605120L) != 0)) ) {
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
	public static class TerminatorInstructionContext extends ParserRuleContext {
		public ReturnInstructionContext returnInstruction() {
			return getRuleContext(ReturnInstructionContext.class,0);
		}
		public BranchInstructionContext branchInstruction() {
			return getRuleContext(BranchInstructionContext.class,0);
		}
		public TerminatorInstructionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_terminatorInstruction; }
	}

	public final TerminatorInstructionContext terminatorInstruction() throws RecognitionException {
		TerminatorInstructionContext _localctx = new TerminatorInstructionContext(_ctx, getState());
		enterRule(_localctx, 68, RULE_terminatorInstruction);
		try {
			setState(346);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Ret:
				enterOuterAlt(_localctx, 1);
				{
				setState(344);
				returnInstruction();
				}
				break;
			case Br:
				enterOuterAlt(_localctx, 2);
				{
				setState(345);
				branchInstruction();
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
	public static class GepInstructionContext extends ParserRuleContext {
		public LocalIdentifierContext localIdentifier() {
			return getRuleContext(LocalIdentifierContext.class,0);
		}
		public TerminalNode Equals() { return getToken(LLVMParser.Equals, 0); }
		public TerminalNode GetElementPtr() { return getToken(LLVMParser.GetElementPtr, 0); }
		public List<TypeContext> type() {
			return getRuleContexts(TypeContext.class);
		}
		public TypeContext type(int i) {
			return getRuleContext(TypeContext.class,i);
		}
		public List<TerminalNode> Comma() { return getTokens(LLVMParser.Comma); }
		public TerminalNode Comma(int i) {
			return getToken(LLVMParser.Comma, i);
		}
		public TerminalNode Asterisk() { return getToken(LLVMParser.Asterisk, 0); }
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public ScalarTypeContext scalarType() {
			return getRuleContext(ScalarTypeContext.class,0);
		}
		public ImmediatelyUsableValueContext immediatelyUsableValue() {
			return getRuleContext(ImmediatelyUsableValueContext.class,0);
		}
		public GepInstructionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_gepInstruction; }
	}

	public final GepInstructionContext gepInstruction() throws RecognitionException {
		GepInstructionContext _localctx = new GepInstructionContext(_ctx, getState());
		enterRule(_localctx, 70, RULE_gepInstruction);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(348);
			localIdentifier();
			setState(349);
			match(Equals);
			setState(350);
			match(GetElementPtr);
			setState(351);
			type();
			setState(352);
			match(Comma);
			setState(353);
			type();
			setState(354);
			match(Asterisk);
			setState(355);
			variable();
			setState(360);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==Comma) {
				{
				setState(356);
				match(Comma);
				setState(357);
				scalarType();
				setState(358);
				immediatelyUsableValue();
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

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 3:
			return pointerType_sempred((PointerTypeContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean pointerType_sempred(PointerTypeContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 2);
		}
		return true;
	}

	public static final String _serializedATN =
		"\u0004\u0001S\u016b\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002"+
		"\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007\u0002"+
		"\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b\u0002"+
		"\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002\u000f\u0007\u000f"+
		"\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011\u0002\u0012\u0007\u0012"+
		"\u0002\u0013\u0007\u0013\u0002\u0014\u0007\u0014\u0002\u0015\u0007\u0015"+
		"\u0002\u0016\u0007\u0016\u0002\u0017\u0007\u0017\u0002\u0018\u0007\u0018"+
		"\u0002\u0019\u0007\u0019\u0002\u001a\u0007\u001a\u0002\u001b\u0007\u001b"+
		"\u0002\u001c\u0007\u001c\u0002\u001d\u0007\u001d\u0002\u001e\u0007\u001e"+
		"\u0002\u001f\u0007\u001f\u0002 \u0007 \u0002!\u0007!\u0002\"\u0007\"\u0002"+
		"#\u0007#\u0001\u0000\u0001\u0000\u0001\u0001\u0001\u0001\u0003\u0001M"+
		"\b\u0001\u0001\u0002\u0001\u0002\u0001\u0002\u0003\u0002R\b\u0002\u0001"+
		"\u0003\u0001\u0003\u0001\u0003\u0004\u0003W\b\u0003\u000b\u0003\f\u0003"+
		"X\u0001\u0003\u0001\u0003\u0004\u0003]\b\u0003\u000b\u0003\f\u0003^\u0003"+
		"\u0003a\b\u0003\u0001\u0003\u0001\u0003\u0004\u0003e\b\u0003\u000b\u0003"+
		"\f\u0003f\u0005\u0003i\b\u0003\n\u0003\f\u0003l\t\u0003\u0001\u0004\u0001"+
		"\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0005\u0001"+
		"\u0005\u0001\u0006\u0001\u0006\u0001\u0006\u0003\u0006y\b\u0006\u0001"+
		"\u0007\u0001\u0007\u0003\u0007}\b\u0007\u0001\b\u0003\b\u0080\b\b\u0001"+
		"\b\u0001\b\u0003\b\u0084\b\b\u0001\t\u0001\t\u0003\t\u0088\b\t\u0001\n"+
		"\u0001\n\u0001\n\u0005\n\u008d\b\n\n\n\f\n\u0090\t\n\u0001\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0003"+
		"\u000b\u0099\b\u000b\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0005\f\u00a0"+
		"\b\f\n\f\f\f\u00a3\t\f\u0003\f\u00a5\b\f\u0001\f\u0001\f\u0001\r\u0001"+
		"\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0003\r\u00b0\b\r\u0001\u000e"+
		"\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000f\u0001\u000f"+
		"\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0005\u000f\u00bd\b\u000f"+
		"\n\u000f\f\u000f\u00c0\t\u000f\u0001\u000f\u0003\u000f\u00c3\b\u000f\u0001"+
		"\u0010\u0001\u0010\u0003\u0010\u00c7\b\u0010\u0001\u0010\u0001\u0010\u0001"+
		"\u0011\u0001\u0011\u0001\u0011\u0005\u0011\u00ce\b\u0011\n\u0011\f\u0011"+
		"\u00d1\t\u0011\u0001\u0012\u0001\u0012\u0003\u0012\u00d5\b\u0012\u0001"+
		"\u0013\u0001\u0013\u0005\u0013\u00d9\b\u0013\n\u0013\f\u0013\u00dc\t\u0013"+
		"\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014"+
		"\u0001\u0014\u0001\u0014\u0001\u0014\u0003\u0014\u00e7\b\u0014\u0001\u0015"+
		"\u0001\u0015\u0001\u0015\u0001\u0015\u0001\u0015\u0003\u0015\u00ee\b\u0015"+
		"\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016"+
		"\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016"+
		"\u0001\u0016\u0003\u0016\u00fd\b\u0016\u0001\u0017\u0001\u0017\u0001\u0017"+
		"\u0003\u0017\u0102\b\u0017\u0001\u0017\u0001\u0017\u0001\u0017\u0001\u0017"+
		"\u0001\u0017\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0018"+
		"\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0019\u0001\u0019\u0001\u0019"+
		"\u0001\u0019\u0001\u0019\u0001\u0019\u0001\u0019\u0001\u0019\u0001\u0019"+
		"\u0001\u0019\u0001\u0019\u0003\u0019\u011c\b\u0019\u0001\u001a\u0001\u001a"+
		"\u0001\u001a\u0001\u001a\u0001\u001a\u0001\u001a\u0001\u001a\u0001\u001a"+
		"\u0001\u001a\u0001\u001a\u0003\u001a\u0128\b\u001a\u0001\u001b\u0001\u001b"+
		"\u0001\u001b\u0001\u001b\u0001\u001b\u0001\u001b\u0001\u001b\u0005\u001b"+
		"\u0131\b\u001b\n\u001b\f\u001b\u0134\t\u001b\u0001\u001c\u0001\u001c\u0001"+
		"\u001c\u0001\u001c\u0001\u001c\u0001\u001c\u0001\u001d\u0001\u001d\u0001"+
		"\u001e\u0001\u001e\u0001\u001e\u0001\u001e\u0001\u001e\u0001\u001e\u0001"+
		"\u001e\u0001\u001e\u0001\u001e\u0001\u001f\u0001\u001f\u0001\u001f\u0001"+
		"\u001f\u0001\u001f\u0001\u001f\u0001\u001f\u0003\u001f\u014e\b\u001f\u0001"+
		"\u001f\u0001\u001f\u0001\u001f\u0003\u001f\u0153\b\u001f\u0001 \u0001"+
		" \u0001!\u0001!\u0001\"\u0001\"\u0003\"\u015b\b\"\u0001#\u0001#\u0001"+
		"#\u0001#\u0001#\u0001#\u0001#\u0001#\u0001#\u0001#\u0001#\u0001#\u0003"+
		"#\u0169\b#\u0001#\u0000\u0001\u0006$\u0000\u0002\u0004\u0006\b\n\f\u000e"+
		"\u0010\u0012\u0014\u0016\u0018\u001a\u001c\u001e \"$&(*,.02468:<>@BDF"+
		"\u0000\u0005\u0001\u0000\',\u0001\u0000\u0001\u0002\u0001\u0000\u001f"+
		" \u0002\u0000\u0010\u0017\u0019\u0019\u0001\u0000-<\u0173\u0000H\u0001"+
		"\u0000\u0000\u0000\u0002L\u0001\u0000\u0000\u0000\u0004Q\u0001\u0000\u0000"+
		"\u0000\u0006`\u0001\u0000\u0000\u0000\bm\u0001\u0000\u0000\u0000\ns\u0001"+
		"\u0000\u0000\u0000\fx\u0001\u0000\u0000\u0000\u000e|\u0001\u0000\u0000"+
		"\u0000\u0010\u0083\u0001\u0000\u0000\u0000\u0012\u0087\u0001\u0000\u0000"+
		"\u0000\u0014\u008e\u0001\u0000\u0000\u0000\u0016\u0098\u0001\u0000\u0000"+
		"\u0000\u0018\u009a\u0001\u0000\u0000\u0000\u001a\u00a8\u0001\u0000\u0000"+
		"\u0000\u001c\u00b1\u0001\u0000\u0000\u0000\u001e\u00b6\u0001\u0000\u0000"+
		"\u0000 \u00c4\u0001\u0000\u0000\u0000\"\u00ca\u0001\u0000\u0000\u0000"+
		"$\u00d2\u0001\u0000\u0000\u0000&\u00d6\u0001\u0000\u0000\u0000(\u00e6"+
		"\u0001\u0000\u0000\u0000*\u00e8\u0001\u0000\u0000\u0000,\u00fc\u0001\u0000"+
		"\u0000\u0000.\u0101\u0001\u0000\u0000\u00000\u0108\u0001\u0000\u0000\u0000"+
		"2\u0110\u0001\u0000\u0000\u00004\u011d\u0001\u0000\u0000\u00006\u0129"+
		"\u0001\u0000\u0000\u00008\u0135\u0001\u0000\u0000\u0000:\u013b\u0001\u0000"+
		"\u0000\u0000<\u013d\u0001\u0000\u0000\u0000>\u0146\u0001\u0000\u0000\u0000"+
		"@\u0154\u0001\u0000\u0000\u0000B\u0156\u0001\u0000\u0000\u0000D\u015a"+
		"\u0001\u0000\u0000\u0000F\u015c\u0001\u0000\u0000\u0000HI\u0007\u0000"+
		"\u0000\u0000I\u0001\u0001\u0000\u0000\u0000JM\u0005%\u0000\u0000KM\u0003"+
		"\u0000\u0000\u0000LJ\u0001\u0000\u0000\u0000LK\u0001\u0000\u0000\u0000"+
		"M\u0003\u0001\u0000\u0000\u0000NR\u0003\u0002\u0001\u0000OR\u0003\u0006"+
		"\u0003\u0000PR\u0003\b\u0004\u0000QN\u0001\u0000\u0000\u0000QO\u0001\u0000"+
		"\u0000\u0000QP\u0001\u0000\u0000\u0000R\u0005\u0001\u0000\u0000\u0000"+
		"ST\u0006\u0003\uffff\uffff\u0000TV\u0003\u0002\u0001\u0000UW\u0005G\u0000"+
		"\u0000VU\u0001\u0000\u0000\u0000WX\u0001\u0000\u0000\u0000XV\u0001\u0000"+
		"\u0000\u0000XY\u0001\u0000\u0000\u0000Ya\u0001\u0000\u0000\u0000Z\\\u0003"+
		"\b\u0004\u0000[]\u0005G\u0000\u0000\\[\u0001\u0000\u0000\u0000]^\u0001"+
		"\u0000\u0000\u0000^\\\u0001\u0000\u0000\u0000^_\u0001\u0000\u0000\u0000"+
		"_a\u0001\u0000\u0000\u0000`S\u0001\u0000\u0000\u0000`Z\u0001\u0000\u0000"+
		"\u0000aj\u0001\u0000\u0000\u0000bd\n\u0002\u0000\u0000ce\u0005G\u0000"+
		"\u0000dc\u0001\u0000\u0000\u0000ef\u0001\u0000\u0000\u0000fd\u0001\u0000"+
		"\u0000\u0000fg\u0001\u0000\u0000\u0000gi\u0001\u0000\u0000\u0000hb\u0001"+
		"\u0000\u0000\u0000il\u0001\u0000\u0000\u0000jh\u0001\u0000\u0000\u0000"+
		"jk\u0001\u0000\u0000\u0000k\u0007\u0001\u0000\u0000\u0000lj\u0001\u0000"+
		"\u0000\u0000mn\u0005C\u0000\u0000no\u0005O\u0000\u0000op\u0005I\u0000"+
		"\u0000pq\u0003\u0004\u0002\u0000qr\u0005D\u0000\u0000r\t\u0001\u0000\u0000"+
		"\u0000st\u0005L\u0000\u0000t\u000b\u0001\u0000\u0000\u0000uy\u0005M\u0000"+
		"\u0000vw\u0005F\u0000\u0000wy\u0005O\u0000\u0000xu\u0001\u0000\u0000\u0000"+
		"xv\u0001\u0000\u0000\u0000y\r\u0001\u0000\u0000\u0000z}\u0003\n\u0005"+
		"\u0000{}\u0003\f\u0006\u0000|z\u0001\u0000\u0000\u0000|{\u0001\u0000\u0000"+
		"\u0000}\u000f\u0001\u0000\u0000\u0000~\u0080\u0005J\u0000\u0000\u007f"+
		"~\u0001\u0000\u0000\u0000\u007f\u0080\u0001\u0000\u0000\u0000\u0080\u0081"+
		"\u0001\u0000\u0000\u0000\u0081\u0084\u0005O\u0000\u0000\u0082\u0084\u0005"+
		"P\u0000\u0000\u0083\u007f\u0001\u0000\u0000\u0000\u0083\u0082\u0001\u0000"+
		"\u0000\u0000\u0084\u0011\u0001\u0000\u0000\u0000\u0085\u0088\u0003\f\u0006"+
		"\u0000\u0086\u0088\u0003\u0010\b\u0000\u0087\u0085\u0001\u0000\u0000\u0000"+
		"\u0087\u0086\u0001\u0000\u0000\u0000\u0088\u0013\u0001\u0000\u0000\u0000"+
		"\u0089\u008d\u0003\u001a\r\u0000\u008a\u008d\u0003\u001c\u000e\u0000\u008b"+
		"\u008d\u0003\u001e\u000f\u0000\u008c\u0089\u0001\u0000\u0000\u0000\u008c"+
		"\u008a\u0001\u0000\u0000\u0000\u008c\u008b\u0001\u0000\u0000\u0000\u008d"+
		"\u0090\u0001\u0000\u0000\u0000\u008e\u008c\u0001\u0000\u0000\u0000\u008e"+
		"\u008f\u0001\u0000\u0000\u0000\u008f\u0015\u0001\u0000\u0000\u0000\u0090"+
		"\u008e\u0001\u0000\u0000\u0000\u0091\u0092\u0003\u0000\u0000\u0000\u0092"+
		"\u0093\u0005O\u0000\u0000\u0093\u0099\u0001\u0000\u0000\u0000\u0094\u0095"+
		"\u0003\u0000\u0000\u0000\u0095\u0096\u0005P\u0000\u0000\u0096\u0099\u0001"+
		"\u0000\u0000\u0000\u0097\u0099\u0003\u0018\f\u0000\u0098\u0091\u0001\u0000"+
		"\u0000\u0000\u0098\u0094\u0001\u0000\u0000\u0000\u0098\u0097\u0001\u0000"+
		"\u0000\u0000\u0099\u0017\u0001\u0000\u0000\u0000\u009a\u009b\u0003\b\u0004"+
		"\u0000\u009b\u00a4\u0005C\u0000\u0000\u009c\u00a1\u0003\u0016\u000b\u0000"+
		"\u009d\u009e\u0005>\u0000\u0000\u009e\u00a0\u0003\u0016\u000b\u0000\u009f"+
		"\u009d\u0001\u0000\u0000\u0000\u00a0\u00a3\u0001\u0000\u0000\u0000\u00a1"+
		"\u009f\u0001\u0000\u0000\u0000\u00a1\u00a2\u0001\u0000\u0000\u0000\u00a2"+
		"\u00a5\u0001\u0000\u0000\u0000\u00a3\u00a1\u0001\u0000\u0000\u0000\u00a4"+
		"\u009c\u0001\u0000\u0000\u0000\u00a4\u00a5\u0001\u0000\u0000\u0000\u00a5"+
		"\u00a6\u0001\u0000\u0000\u0000\u00a6\u00a7\u0005D\u0000\u0000\u00a7\u0019"+
		"\u0001\u0000\u0000\u0000\u00a8\u00a9\u0003\n\u0005\u0000\u00a9\u00aa\u0005"+
		"=\u0000\u0000\u00aa\u00ab\u0007\u0001\u0000\u0000\u00ab\u00af\u0003\u0016"+
		"\u000b\u0000\u00ac\u00ad\u0005>\u0000\u0000\u00ad\u00ae\u0005\u0006\u0000"+
		"\u0000\u00ae\u00b0\u0005O\u0000\u0000\u00af\u00ac\u0001\u0000\u0000\u0000"+
		"\u00af\u00b0\u0001\u0000\u0000\u0000\u00b0\u001b\u0001\u0000\u0000\u0000"+
		"\u00b1\u00b2\u0005\u0005\u0000\u0000\u00b2\u00b3\u0003\u0004\u0002\u0000"+
		"\u00b3\u00b4\u0003\n\u0005\u0000\u00b4\u00b5\u0003 \u0010\u0000\u00b5"+
		"\u001d\u0001\u0000\u0000\u0000\u00b6\u00b7\u0005\u0004\u0000\u0000\u00b7"+
		"\u00b8\u0003\u0004\u0002\u0000\u00b8\u00b9\u0003\n\u0005\u0000\u00b9\u00c2"+
		"\u0003 \u0010\u0000\u00ba\u00be\u0005A\u0000\u0000\u00bb\u00bd\u0003&"+
		"\u0013\u0000\u00bc\u00bb\u0001\u0000\u0000\u0000\u00bd\u00c0\u0001\u0000"+
		"\u0000\u0000\u00be\u00bc\u0001\u0000\u0000\u0000\u00be\u00bf\u0001\u0000"+
		"\u0000\u0000\u00bf\u00c1\u0001\u0000\u0000\u0000\u00c0\u00be\u0001\u0000"+
		"\u0000\u0000\u00c1\u00c3\u0005B\u0000\u0000\u00c2\u00ba\u0001\u0000\u0000"+
		"\u0000\u00c2\u00c3\u0001\u0000\u0000\u0000\u00c3\u001f\u0001\u0000\u0000"+
		"\u0000\u00c4\u00c6\u0005?\u0000\u0000\u00c5\u00c7\u0003\"\u0011\u0000"+
		"\u00c6\u00c5\u0001\u0000\u0000\u0000\u00c6\u00c7\u0001\u0000\u0000\u0000"+
		"\u00c7\u00c8\u0001\u0000\u0000\u0000\u00c8\u00c9\u0005@\u0000\u0000\u00c9"+
		"!\u0001\u0000\u0000\u0000\u00ca\u00cf\u0003$\u0012\u0000\u00cb\u00cc\u0005"+
		">\u0000\u0000\u00cc\u00ce\u0003$\u0012\u0000\u00cd\u00cb\u0001\u0000\u0000"+
		"\u0000\u00ce\u00d1\u0001\u0000\u0000\u0000\u00cf\u00cd\u0001\u0000\u0000"+
		"\u0000\u00cf\u00d0\u0001\u0000\u0000\u0000\u00d0#\u0001\u0000\u0000\u0000"+
		"\u00d1\u00cf\u0001\u0000\u0000\u0000\u00d2\u00d4\u0003\u0004\u0002\u0000"+
		"\u00d3\u00d5\u0003\f\u0006\u0000\u00d4\u00d3\u0001\u0000\u0000\u0000\u00d4"+
		"\u00d5\u0001\u0000\u0000\u0000\u00d5%\u0001\u0000\u0000\u0000\u00d6\u00da"+
		"\u0005N\u0000\u0000\u00d7\u00d9\u0003(\u0014\u0000\u00d8\u00d7\u0001\u0000"+
		"\u0000\u0000\u00d9\u00dc\u0001\u0000\u0000\u0000\u00da\u00d8\u0001\u0000"+
		"\u0000\u0000\u00da\u00db\u0001\u0000\u0000\u0000\u00db\'\u0001\u0000\u0000"+
		"\u0000\u00dc\u00da\u0001\u0000\u0000\u0000\u00dd\u00e7\u0003.\u0017\u0000"+
		"\u00de\u00e7\u00030\u0018\u0000\u00df\u00e7\u00032\u0019\u0000\u00e0\u00e7"+
		"\u00034\u001a\u0000\u00e1\u00e7\u00036\u001b\u0000\u00e2\u00e7\u0003<"+
		"\u001e\u0000\u00e3\u00e7\u0003>\u001f\u0000\u00e4\u00e7\u0003D\"\u0000"+
		"\u00e5\u00e7\u0003F#\u0000\u00e6\u00dd\u0001\u0000\u0000\u0000\u00e6\u00de"+
		"\u0001\u0000\u0000\u0000\u00e6\u00df\u0001\u0000\u0000\u0000\u00e6\u00e0"+
		"\u0001\u0000\u0000\u0000\u00e6\u00e1\u0001\u0000\u0000\u0000\u00e6\u00e2"+
		"\u0001\u0000\u0000\u0000\u00e6\u00e3\u0001\u0000\u0000\u0000\u00e6\u00e4"+
		"\u0001\u0000\u0000\u0000\u00e6\u00e5\u0001\u0000\u0000\u0000\u00e7)\u0001"+
		"\u0000\u0000\u0000\u00e8\u00ed\u0005\t\u0000\u0000\u00e9\u00ee\u0005%"+
		"\u0000\u0000\u00ea\u00eb\u0003\u0004\u0002\u0000\u00eb\u00ec\u0003\u0012"+
		"\t\u0000\u00ec\u00ee\u0001\u0000\u0000\u0000\u00ed\u00e9\u0001\u0000\u0000"+
		"\u0000\u00ed\u00ea\u0001\u0000\u0000\u0000\u00ee+\u0001\u0000\u0000\u0000"+
		"\u00ef\u00f0\u0005\b\u0000\u0000\u00f0\u00f1\u0005\'\u0000\u0000\u00f1"+
		"\u00f2\u0003\u0012\t\u0000\u00f2\u00f3\u0005>\u0000\u0000\u00f3\u00f4"+
		"\u0005$\u0000\u0000\u00f4\u00f5\u0003\f\u0006\u0000\u00f5\u00f6\u0005"+
		">\u0000\u0000\u00f6\u00f7\u0005$\u0000\u0000\u00f7\u00f8\u0003\f\u0006"+
		"\u0000\u00f8\u00fd\u0001\u0000\u0000\u0000\u00f9\u00fa\u0005\b\u0000\u0000"+
		"\u00fa\u00fb\u0005$\u0000\u0000\u00fb\u00fd\u0003\f\u0006\u0000\u00fc"+
		"\u00ef\u0001\u0000\u0000\u0000\u00fc\u00f9\u0001\u0000\u0000\u0000\u00fd"+
		"-\u0001\u0000\u0000\u0000\u00fe\u00ff\u0003\f\u0006\u0000\u00ff\u0100"+
		"\u0005=\u0000\u0000\u0100\u0102\u0001\u0000\u0000\u0000\u0101\u00fe\u0001"+
		"\u0000\u0000\u0000\u0101\u0102\u0001\u0000\u0000\u0000\u0102\u0103\u0001"+
		"\u0000\u0000\u0000\u0103\u0104\u0005\n\u0000\u0000\u0104\u0105\u0003\u0004"+
		"\u0002\u0000\u0105\u0106\u0003\n\u0005\u0000\u0106\u0107\u0003 \u0010"+
		"\u0000\u0107/\u0001\u0000\u0000\u0000\u0108\u0109\u0003\f\u0006\u0000"+
		"\u0109\u010a\u0005=\u0000\u0000\u010a\u010b\u0003@ \u0000\u010b\u010c"+
		"\u0003\u0004\u0002\u0000\u010c\u010d\u0003\u0012\t\u0000\u010d\u010e\u0005"+
		">\u0000\u0000\u010e\u010f\u0003\u0012\t\u0000\u010f1\u0001\u0000\u0000"+
		"\u0000\u0110\u0111\u0003\f\u0006\u0000\u0111\u0112\u0005=\u0000\u0000"+
		"\u0112\u0113\u0005\u000b\u0000\u0000\u0113\u0114\u0003\u0004\u0002\u0000"+
		"\u0114\u0115\u0005>\u0000\u0000\u0115\u0116\u0003\u0004\u0002\u0000\u0116"+
		"\u0117\u0005G\u0000\u0000\u0117\u011b\u0003\u000e\u0007\u0000\u0118\u0119"+
		"\u0005>\u0000\u0000\u0119\u011a\u0005\u0006\u0000\u0000\u011a\u011c\u0005"+
		"O\u0000\u0000\u011b\u0118\u0001\u0000\u0000\u0000\u011b\u011c\u0001\u0000"+
		"\u0000\u0000\u011c3\u0001\u0000\u0000\u0000\u011d\u011e\u0005\f\u0000"+
		"\u0000\u011e\u011f\u0003\u0004\u0002\u0000\u011f\u0120\u0003\u0012\t\u0000"+
		"\u0120\u0121\u0005>\u0000\u0000\u0121\u0122\u0003\u0004\u0002\u0000\u0122"+
		"\u0123\u0005G\u0000\u0000\u0123\u0127\u0003\u000e\u0007\u0000\u0124\u0125"+
		"\u0005>\u0000\u0000\u0125\u0126\u0005\u0006\u0000\u0000\u0126\u0128\u0005"+
		"O\u0000\u0000\u0127\u0124\u0001\u0000\u0000\u0000\u0127\u0128\u0001\u0000"+
		"\u0000\u0000\u01285\u0001\u0000\u0000\u0000\u0129\u012a\u0003\f\u0006"+
		"\u0000\u012a\u012b\u0005=\u0000\u0000\u012b\u012c\u0005\u000f\u0000\u0000"+
		"\u012c\u012d\u0003\u0004\u0002\u0000\u012d\u0132\u00038\u001c\u0000\u012e"+
		"\u012f\u0005>\u0000\u0000\u012f\u0131\u00038\u001c\u0000\u0130\u012e\u0001"+
		"\u0000\u0000\u0000\u0131\u0134\u0001\u0000\u0000\u0000\u0132\u0130\u0001"+
		"\u0000\u0000\u0000\u0132\u0133\u0001\u0000\u0000\u0000\u01337\u0001\u0000"+
		"\u0000\u0000\u0134\u0132\u0001\u0000\u0000\u0000\u0135\u0136\u0005A\u0000"+
		"\u0000\u0136\u0137\u0003\u0012\t\u0000\u0137\u0138\u0005>\u0000\u0000"+
		"\u0138\u0139\u0003\f\u0006\u0000\u0139\u013a\u0005B\u0000\u0000\u013a"+
		"9\u0001\u0000\u0000\u0000\u013b\u013c\u0007\u0002\u0000\u0000\u013c;\u0001"+
		"\u0000\u0000\u0000\u013d\u013e\u0003\f\u0006\u0000\u013e\u013f\u0005="+
		"\u0000\u0000\u013f\u0140\u0003:\u001d\u0000\u0140\u0141\u0003B!\u0000"+
		"\u0141\u0142\u0003\u0004\u0002\u0000\u0142\u0143\u0003\u0012\t\u0000\u0143"+
		"\u0144\u0005>\u0000\u0000\u0144\u0145\u0003\u0012\t\u0000\u0145=\u0001"+
		"\u0000\u0000\u0000\u0146\u0147\u0003\f\u0006\u0000\u0147\u0148\u0005="+
		"\u0000\u0000\u0148\u0149\u0005\r\u0000\u0000\u0149\u014d\u0003\u0004\u0002"+
		"\u0000\u014a\u014b\u0005>\u0000\u0000\u014b\u014c\u0005(\u0000\u0000\u014c"+
		"\u014e\u0005O\u0000\u0000\u014d\u014a\u0001\u0000\u0000\u0000\u014d\u014e"+
		"\u0001\u0000\u0000\u0000\u014e\u0152\u0001\u0000\u0000\u0000\u014f\u0150"+
		"\u0005>\u0000\u0000\u0150\u0151\u0005\u0006\u0000\u0000\u0151\u0153\u0005"+
		"O\u0000\u0000\u0152\u014f\u0001\u0000\u0000\u0000\u0152\u0153\u0001\u0000"+
		"\u0000\u0000\u0153?\u0001\u0000\u0000\u0000\u0154\u0155\u0007\u0003\u0000"+
		"\u0000\u0155A\u0001\u0000\u0000\u0000\u0156\u0157\u0007\u0004\u0000\u0000"+
		"\u0157C\u0001\u0000\u0000\u0000\u0158\u015b\u0003*\u0015\u0000\u0159\u015b"+
		"\u0003,\u0016\u0000\u015a\u0158\u0001\u0000\u0000\u0000\u015a\u0159\u0001"+
		"\u0000\u0000\u0000\u015bE\u0001\u0000\u0000\u0000\u015c\u015d\u0003\f"+
		"\u0006\u0000\u015d\u015e\u0005=\u0000\u0000\u015e\u015f\u0005\u000e\u0000"+
		"\u0000\u015f\u0160\u0003\u0004\u0002\u0000\u0160\u0161\u0005>\u0000\u0000"+
		"\u0161\u0162\u0003\u0004\u0002\u0000\u0162\u0163\u0005G\u0000\u0000\u0163"+
		"\u0168\u0003\u000e\u0007\u0000\u0164\u0165\u0005>\u0000\u0000\u0165\u0166"+
		"\u0003\u0000\u0000\u0000\u0166\u0167\u0003\u0012\t\u0000\u0167\u0169\u0001"+
		"\u0000\u0000\u0000\u0168\u0164\u0001\u0000\u0000\u0000\u0168\u0169\u0001"+
		"\u0000\u0000\u0000\u0169G\u0001\u0000\u0000\u0000#LQX^`fjx|\u007f\u0083"+
		"\u0087\u008c\u008e\u0098\u00a1\u00a4\u00af\u00be\u00c2\u00c6\u00cf\u00d4"+
		"\u00da\u00e6\u00ed\u00fc\u0101\u011b\u0127\u0132\u014d\u0152\u015a\u0168";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}