
// Generated from E:/Homework/cplab/cact/grammar/CplabParser.g4 by ANTLR 4.13.1


#include "CplabParserVisitor.h"

#include "CplabParser.h"


using namespace antlrcpp;
using namespace cplab_parser;

using namespace antlr4;

namespace {

struct CplabParserStaticData final {
  CplabParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  CplabParserStaticData(const CplabParserStaticData&) = delete;
  CplabParserStaticData(CplabParserStaticData&&) = delete;
  CplabParserStaticData& operator=(const CplabParserStaticData&) = delete;
  CplabParserStaticData& operator=(CplabParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag cplabparserParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
CplabParserStaticData *cplabparserParserStaticData = nullptr;

void cplabparserParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (cplabparserParserStaticData != nullptr) {
    return;
  }
#else
  assert(cplabparserParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<CplabParserStaticData>(
    std::vector<std::string>{
      "compilation_unit", "declaration", "constant_declaration", "basic_type", 
      "constant_definition", "constant_initial_value", "variable_declaration", 
      "variable_definition", "function_definition", "function_type", "function_formal_params", 
      "function_formal_param", "block", "block_item", "statement", "expression", 
      "constant_expression", "condition", "left_value", "number", "function_real_params", 
      "primary_expression", "unary_expression", "multiplicative_expression", 
      "additive_expression", "relational_expression", "equal_expression", 
      "logical_and_expression", "logical_or_expression"
    },
    std::vector<std::string>{
      "", "'const'", "'int'", "'char'", "'float'", "'void'", "'if'", "'else'", 
      "'while'", "'break'", "'continue'", "'return'", "'='", "'=='", "'&&'", 
      "'||'", "'!='", "'<'", "'<='", "'>'", "'>='", "'.'", "','", "';'", 
      "':'", "'('", "')'", "'['", "']'", "'{'", "'}'", "'+'", "'-'", "'|'", 
      "'!'", "'*'", "'/'", "'%'"
    },
    std::vector<std::string>{
      "", "Const", "Int", "Char", "Float", "Void", "If", "Else", "While", 
      "Break", "Continue", "Return", "Equal", "LogicalEqual", "LogicalAnd", 
      "LogicalOr", "NotEqual", "Less", "LessEqual", "Greater", "GreaterEqual", 
      "Period", "Comma", "Semicolon", "Colon", "LeftParenthesis", "RightParenthesis", 
      "LeftBracket", "RightBracket", "LeftBrace", "RightBrace", "Plus", 
      "Minus", "Pipe", "ExclamationMark", "Asterisk", "Slash", "Percent", 
      "Identifier", "IntegerConstant", "FloatConstant", "CharConstant", 
      "LineComment", "BlockComment", "NewLine", "WhiteSpaces"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,45,331,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,1,0,1,0,5,0,61,8,0,10,0,12,0,64,9,0,1,1,1,1,3,1,68,8,1,1,2,1,2,1,2,
  	1,2,1,2,5,2,75,8,2,10,2,12,2,78,9,2,1,2,1,2,1,3,1,3,1,4,1,4,1,4,1,4,5,
  	4,88,8,4,10,4,12,4,91,9,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,5,5,101,8,5,
  	10,5,12,5,104,9,5,3,5,106,8,5,1,5,3,5,109,8,5,1,6,1,6,1,6,1,6,5,6,115,
  	8,6,10,6,12,6,118,9,6,1,6,1,6,1,7,1,7,1,7,1,7,5,7,126,8,7,10,7,12,7,129,
  	9,7,1,7,1,7,3,7,133,8,7,1,8,1,8,1,8,1,8,3,8,139,8,8,1,8,1,8,1,8,1,9,1,
  	9,1,10,1,10,1,10,5,10,149,8,10,10,10,12,10,152,9,10,1,11,1,11,1,11,1,
  	11,3,11,158,8,11,1,11,1,11,1,11,1,11,5,11,164,8,11,10,11,12,11,167,9,
  	11,3,11,169,8,11,1,12,1,12,5,12,173,8,12,10,12,12,12,176,9,12,1,12,1,
  	12,1,13,1,13,3,13,182,8,13,1,14,1,14,1,14,1,14,1,14,1,14,3,14,190,8,14,
  	1,14,1,14,1,14,1,14,3,14,196,8,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,
  	1,14,3,14,206,8,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,
  	3,14,218,8,14,1,15,1,15,1,16,1,16,1,17,1,17,1,18,1,18,1,18,1,18,1,18,
  	5,18,231,8,18,10,18,12,18,234,9,18,1,19,1,19,1,20,1,20,1,20,5,20,241,
  	8,20,10,20,12,20,244,9,20,1,21,1,21,1,21,1,21,1,21,1,21,3,21,252,8,21,
  	1,22,1,22,1,22,1,22,1,22,1,22,3,22,260,8,22,1,22,3,22,263,8,22,1,23,1,
  	23,1,23,1,23,1,23,1,23,5,23,271,8,23,10,23,12,23,274,9,23,1,24,1,24,1,
  	24,1,24,1,24,1,24,5,24,282,8,24,10,24,12,24,285,9,24,1,25,1,25,1,25,1,
  	25,1,25,1,25,5,25,293,8,25,10,25,12,25,296,9,25,1,26,1,26,1,26,1,26,1,
  	26,1,26,5,26,304,8,26,10,26,12,26,307,9,26,1,27,1,27,1,27,1,27,1,27,1,
  	27,5,27,315,8,27,10,27,12,27,318,9,27,1,28,1,28,1,28,1,28,1,28,1,28,5,
  	28,326,8,28,10,28,12,28,329,9,28,1,28,0,6,46,48,50,52,54,56,29,0,2,4,
  	6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,
  	54,56,0,8,1,0,2,4,1,0,2,5,1,0,39,41,2,0,31,32,34,34,1,0,35,37,1,0,31,
  	32,1,0,17,20,2,0,13,13,16,16,342,0,62,1,0,0,0,2,67,1,0,0,0,4,69,1,0,0,
  	0,6,81,1,0,0,0,8,83,1,0,0,0,10,108,1,0,0,0,12,110,1,0,0,0,14,121,1,0,
  	0,0,16,134,1,0,0,0,18,143,1,0,0,0,20,145,1,0,0,0,22,153,1,0,0,0,24,170,
  	1,0,0,0,26,181,1,0,0,0,28,217,1,0,0,0,30,219,1,0,0,0,32,221,1,0,0,0,34,
  	223,1,0,0,0,36,225,1,0,0,0,38,235,1,0,0,0,40,237,1,0,0,0,42,251,1,0,0,
  	0,44,262,1,0,0,0,46,264,1,0,0,0,48,275,1,0,0,0,50,286,1,0,0,0,52,297,
  	1,0,0,0,54,308,1,0,0,0,56,319,1,0,0,0,58,61,3,2,1,0,59,61,3,16,8,0,60,
  	58,1,0,0,0,60,59,1,0,0,0,61,64,1,0,0,0,62,60,1,0,0,0,62,63,1,0,0,0,63,
  	1,1,0,0,0,64,62,1,0,0,0,65,68,3,4,2,0,66,68,3,12,6,0,67,65,1,0,0,0,67,
  	66,1,0,0,0,68,3,1,0,0,0,69,70,5,1,0,0,70,71,3,6,3,0,71,76,3,8,4,0,72,
  	73,5,22,0,0,73,75,3,8,4,0,74,72,1,0,0,0,75,78,1,0,0,0,76,74,1,0,0,0,76,
  	77,1,0,0,0,77,79,1,0,0,0,78,76,1,0,0,0,79,80,5,23,0,0,80,5,1,0,0,0,81,
  	82,7,0,0,0,82,7,1,0,0,0,83,89,5,38,0,0,84,85,5,27,0,0,85,86,5,39,0,0,
  	86,88,5,28,0,0,87,84,1,0,0,0,88,91,1,0,0,0,89,87,1,0,0,0,89,90,1,0,0,
  	0,90,92,1,0,0,0,91,89,1,0,0,0,92,93,5,12,0,0,93,94,3,10,5,0,94,9,1,0,
  	0,0,95,109,3,32,16,0,96,105,5,29,0,0,97,102,3,10,5,0,98,99,5,22,0,0,99,
  	101,3,10,5,0,100,98,1,0,0,0,101,104,1,0,0,0,102,100,1,0,0,0,102,103,1,
  	0,0,0,103,106,1,0,0,0,104,102,1,0,0,0,105,97,1,0,0,0,105,106,1,0,0,0,
  	106,107,1,0,0,0,107,109,5,30,0,0,108,95,1,0,0,0,108,96,1,0,0,0,109,11,
  	1,0,0,0,110,111,3,6,3,0,111,116,3,14,7,0,112,113,5,22,0,0,113,115,3,14,
  	7,0,114,112,1,0,0,0,115,118,1,0,0,0,116,114,1,0,0,0,116,117,1,0,0,0,117,
  	119,1,0,0,0,118,116,1,0,0,0,119,120,5,23,0,0,120,13,1,0,0,0,121,127,5,
  	38,0,0,122,123,5,27,0,0,123,124,5,39,0,0,124,126,5,28,0,0,125,122,1,0,
  	0,0,126,129,1,0,0,0,127,125,1,0,0,0,127,128,1,0,0,0,128,132,1,0,0,0,129,
  	127,1,0,0,0,130,131,5,12,0,0,131,133,3,10,5,0,132,130,1,0,0,0,132,133,
  	1,0,0,0,133,15,1,0,0,0,134,135,3,18,9,0,135,136,5,38,0,0,136,138,5,25,
  	0,0,137,139,3,20,10,0,138,137,1,0,0,0,138,139,1,0,0,0,139,140,1,0,0,0,
  	140,141,5,26,0,0,141,142,3,24,12,0,142,17,1,0,0,0,143,144,7,1,0,0,144,
  	19,1,0,0,0,145,150,3,22,11,0,146,147,5,22,0,0,147,149,3,22,11,0,148,146,
  	1,0,0,0,149,152,1,0,0,0,150,148,1,0,0,0,150,151,1,0,0,0,151,21,1,0,0,
  	0,152,150,1,0,0,0,153,154,3,6,3,0,154,168,5,38,0,0,155,157,5,27,0,0,156,
  	158,5,39,0,0,157,156,1,0,0,0,157,158,1,0,0,0,158,159,1,0,0,0,159,165,
  	5,28,0,0,160,161,5,27,0,0,161,162,5,39,0,0,162,164,5,28,0,0,163,160,1,
  	0,0,0,164,167,1,0,0,0,165,163,1,0,0,0,165,166,1,0,0,0,166,169,1,0,0,0,
  	167,165,1,0,0,0,168,155,1,0,0,0,168,169,1,0,0,0,169,23,1,0,0,0,170,174,
  	5,29,0,0,171,173,3,26,13,0,172,171,1,0,0,0,173,176,1,0,0,0,174,172,1,
  	0,0,0,174,175,1,0,0,0,175,177,1,0,0,0,176,174,1,0,0,0,177,178,5,30,0,
  	0,178,25,1,0,0,0,179,182,3,2,1,0,180,182,3,28,14,0,181,179,1,0,0,0,181,
  	180,1,0,0,0,182,27,1,0,0,0,183,184,3,36,18,0,184,185,5,12,0,0,185,186,
  	3,30,15,0,186,187,5,23,0,0,187,218,1,0,0,0,188,190,3,30,15,0,189,188,
  	1,0,0,0,189,190,1,0,0,0,190,191,1,0,0,0,191,218,5,23,0,0,192,218,3,24,
  	12,0,193,195,5,11,0,0,194,196,3,30,15,0,195,194,1,0,0,0,195,196,1,0,0,
  	0,196,197,1,0,0,0,197,218,5,23,0,0,198,199,5,6,0,0,199,200,5,25,0,0,200,
  	201,3,34,17,0,201,202,5,26,0,0,202,205,3,28,14,0,203,204,5,7,0,0,204,
  	206,3,28,14,0,205,203,1,0,0,0,205,206,1,0,0,0,206,218,1,0,0,0,207,208,
  	5,8,0,0,208,209,5,25,0,0,209,210,3,34,17,0,210,211,5,26,0,0,211,212,3,
  	28,14,0,212,218,1,0,0,0,213,214,5,9,0,0,214,218,5,23,0,0,215,216,5,10,
  	0,0,216,218,5,23,0,0,217,183,1,0,0,0,217,189,1,0,0,0,217,192,1,0,0,0,
  	217,193,1,0,0,0,217,198,1,0,0,0,217,207,1,0,0,0,217,213,1,0,0,0,217,215,
  	1,0,0,0,218,29,1,0,0,0,219,220,3,48,24,0,220,31,1,0,0,0,221,222,3,48,
  	24,0,222,33,1,0,0,0,223,224,3,56,28,0,224,35,1,0,0,0,225,232,5,38,0,0,
  	226,227,5,27,0,0,227,228,3,30,15,0,228,229,5,28,0,0,229,231,1,0,0,0,230,
  	226,1,0,0,0,231,234,1,0,0,0,232,230,1,0,0,0,232,233,1,0,0,0,233,37,1,
  	0,0,0,234,232,1,0,0,0,235,236,7,2,0,0,236,39,1,0,0,0,237,242,3,30,15,
  	0,238,239,5,22,0,0,239,241,3,30,15,0,240,238,1,0,0,0,241,244,1,0,0,0,
  	242,240,1,0,0,0,242,243,1,0,0,0,243,41,1,0,0,0,244,242,1,0,0,0,245,246,
  	5,25,0,0,246,247,3,30,15,0,247,248,5,26,0,0,248,252,1,0,0,0,249,252,3,
  	36,18,0,250,252,3,38,19,0,251,245,1,0,0,0,251,249,1,0,0,0,251,250,1,0,
  	0,0,252,43,1,0,0,0,253,263,3,42,21,0,254,255,7,3,0,0,255,263,3,44,22,
  	0,256,257,5,38,0,0,257,259,5,25,0,0,258,260,3,40,20,0,259,258,1,0,0,0,
  	259,260,1,0,0,0,260,261,1,0,0,0,261,263,5,26,0,0,262,253,1,0,0,0,262,
  	254,1,0,0,0,262,256,1,0,0,0,263,45,1,0,0,0,264,265,6,23,-1,0,265,266,
  	3,44,22,0,266,272,1,0,0,0,267,268,10,1,0,0,268,269,7,4,0,0,269,271,3,
  	44,22,0,270,267,1,0,0,0,271,274,1,0,0,0,272,270,1,0,0,0,272,273,1,0,0,
  	0,273,47,1,0,0,0,274,272,1,0,0,0,275,276,6,24,-1,0,276,277,3,46,23,0,
  	277,283,1,0,0,0,278,279,10,1,0,0,279,280,7,5,0,0,280,282,3,46,23,0,281,
  	278,1,0,0,0,282,285,1,0,0,0,283,281,1,0,0,0,283,284,1,0,0,0,284,49,1,
  	0,0,0,285,283,1,0,0,0,286,287,6,25,-1,0,287,288,3,48,24,0,288,294,1,0,
  	0,0,289,290,10,1,0,0,290,291,7,6,0,0,291,293,3,48,24,0,292,289,1,0,0,
  	0,293,296,1,0,0,0,294,292,1,0,0,0,294,295,1,0,0,0,295,51,1,0,0,0,296,
  	294,1,0,0,0,297,298,6,26,-1,0,298,299,3,50,25,0,299,305,1,0,0,0,300,301,
  	10,1,0,0,301,302,7,7,0,0,302,304,3,50,25,0,303,300,1,0,0,0,304,307,1,
  	0,0,0,305,303,1,0,0,0,305,306,1,0,0,0,306,53,1,0,0,0,307,305,1,0,0,0,
  	308,309,6,27,-1,0,309,310,3,52,26,0,310,316,1,0,0,0,311,312,10,1,0,0,
  	312,313,5,14,0,0,313,315,3,52,26,0,314,311,1,0,0,0,315,318,1,0,0,0,316,
  	314,1,0,0,0,316,317,1,0,0,0,317,55,1,0,0,0,318,316,1,0,0,0,319,320,6,
  	28,-1,0,320,321,3,54,27,0,321,327,1,0,0,0,322,323,10,1,0,0,323,324,5,
  	15,0,0,324,326,3,54,27,0,325,322,1,0,0,0,326,329,1,0,0,0,327,325,1,0,
  	0,0,327,328,1,0,0,0,328,57,1,0,0,0,329,327,1,0,0,0,33,60,62,67,76,89,
  	102,105,108,116,127,132,138,150,157,165,168,174,181,189,195,205,217,232,
  	242,251,259,262,272,283,294,305,316,327
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  cplabparserParserStaticData = staticData.release();
}

}

CplabParser::CplabParser(TokenStream *input) : CplabParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

CplabParser::CplabParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  CplabParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *cplabparserParserStaticData->atn, cplabparserParserStaticData->decisionToDFA, cplabparserParserStaticData->sharedContextCache, options);
}

CplabParser::~CplabParser() {
  delete _interpreter;
}

const atn::ATN& CplabParser::getATN() const {
  return *cplabparserParserStaticData->atn;
}

std::string CplabParser::getGrammarFileName() const {
  return "CplabParser.g4";
}

const std::vector<std::string>& CplabParser::getRuleNames() const {
  return cplabparserParserStaticData->ruleNames;
}

const dfa::Vocabulary& CplabParser::getVocabulary() const {
  return cplabparserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView CplabParser::getSerializedATN() const {
  return cplabparserParserStaticData->serializedATN;
}


//----------------- Compilation_unitContext ------------------------------------------------------------------

CplabParser::Compilation_unitContext::Compilation_unitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CplabParser::DeclarationContext *> CplabParser::Compilation_unitContext::declaration() {
  return getRuleContexts<CplabParser::DeclarationContext>();
}

CplabParser::DeclarationContext* CplabParser::Compilation_unitContext::declaration(size_t i) {
  return getRuleContext<CplabParser::DeclarationContext>(i);
}

std::vector<CplabParser::Function_definitionContext *> CplabParser::Compilation_unitContext::function_definition() {
  return getRuleContexts<CplabParser::Function_definitionContext>();
}

CplabParser::Function_definitionContext* CplabParser::Compilation_unitContext::function_definition(size_t i) {
  return getRuleContext<CplabParser::Function_definitionContext>(i);
}


size_t CplabParser::Compilation_unitContext::getRuleIndex() const {
  return CplabParser::RuleCompilation_unit;
}


std::any CplabParser::Compilation_unitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CplabParserVisitor*>(visitor))
    return parserVisitor->visitCompilation_unit(this);
  else
    return visitor->visitChildren(this);
}

CplabParser::Compilation_unitContext* CplabParser::compilation_unit() {
  Compilation_unitContext *_localctx = _tracker.createInstance<Compilation_unitContext>(_ctx, getState());
  enterRule(_localctx, 0, CplabParser::RuleCompilation_unit);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(62);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 62) != 0)) {
      setState(60);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
      case 1: {
        setState(58);
        declaration();
        break;
      }

      case 2: {
        setState(59);
        function_definition();
        break;
      }

      default:
        break;
      }
      setState(64);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

CplabParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CplabParser::Constant_declarationContext* CplabParser::DeclarationContext::constant_declaration() {
  return getRuleContext<CplabParser::Constant_declarationContext>(0);
}

CplabParser::Variable_declarationContext* CplabParser::DeclarationContext::variable_declaration() {
  return getRuleContext<CplabParser::Variable_declarationContext>(0);
}


size_t CplabParser::DeclarationContext::getRuleIndex() const {
  return CplabParser::RuleDeclaration;
}


std::any CplabParser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CplabParserVisitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

CplabParser::DeclarationContext* CplabParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 2, CplabParser::RuleDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(67);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CplabParser::Const: {
        enterOuterAlt(_localctx, 1);
        setState(65);
        constant_declaration();
        break;
      }

      case CplabParser::Int:
      case CplabParser::Char:
      case CplabParser::Float: {
        enterOuterAlt(_localctx, 2);
        setState(66);
        variable_declaration();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Constant_declarationContext ------------------------------------------------------------------

CplabParser::Constant_declarationContext::Constant_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CplabParser::Constant_declarationContext::Const() {
  return getToken(CplabParser::Const, 0);
}

CplabParser::Basic_typeContext* CplabParser::Constant_declarationContext::basic_type() {
  return getRuleContext<CplabParser::Basic_typeContext>(0);
}

std::vector<CplabParser::Constant_definitionContext *> CplabParser::Constant_declarationContext::constant_definition() {
  return getRuleContexts<CplabParser::Constant_definitionContext>();
}

CplabParser::Constant_definitionContext* CplabParser::Constant_declarationContext::constant_definition(size_t i) {
  return getRuleContext<CplabParser::Constant_definitionContext>(i);
}

tree::TerminalNode* CplabParser::Constant_declarationContext::Semicolon() {
  return getToken(CplabParser::Semicolon, 0);
}

std::vector<tree::TerminalNode *> CplabParser::Constant_declarationContext::Comma() {
  return getTokens(CplabParser::Comma);
}

tree::TerminalNode* CplabParser::Constant_declarationContext::Comma(size_t i) {
  return getToken(CplabParser::Comma, i);
}


size_t CplabParser::Constant_declarationContext::getRuleIndex() const {
  return CplabParser::RuleConstant_declaration;
}


std::any CplabParser::Constant_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CplabParserVisitor*>(visitor))
    return parserVisitor->visitConstant_declaration(this);
  else
    return visitor->visitChildren(this);
}

CplabParser::Constant_declarationContext* CplabParser::constant_declaration() {
  Constant_declarationContext *_localctx = _tracker.createInstance<Constant_declarationContext>(_ctx, getState());
  enterRule(_localctx, 4, CplabParser::RuleConstant_declaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(69);
    match(CplabParser::Const);
    setState(70);
    basic_type();
    setState(71);
    constant_definition();
    setState(76);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CplabParser::Comma) {
      setState(72);
      match(CplabParser::Comma);
      setState(73);
      constant_definition();
      setState(78);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(79);
    match(CplabParser::Semicolon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Basic_typeContext ------------------------------------------------------------------

CplabParser::Basic_typeContext::Basic_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CplabParser::Basic_typeContext::Int() {
  return getToken(CplabParser::Int, 0);
}

tree::TerminalNode* CplabParser::Basic_typeContext::Float() {
  return getToken(CplabParser::Float, 0);
}

tree::TerminalNode* CplabParser::Basic_typeContext::Char() {
  return getToken(CplabParser::Char, 0);
}


size_t CplabParser::Basic_typeContext::getRuleIndex() const {
  return CplabParser::RuleBasic_type;
}


std::any CplabParser::Basic_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CplabParserVisitor*>(visitor))
    return parserVisitor->visitBasic_type(this);
  else
    return visitor->visitChildren(this);
}

CplabParser::Basic_typeContext* CplabParser::basic_type() {
  Basic_typeContext *_localctx = _tracker.createInstance<Basic_typeContext>(_ctx, getState());
  enterRule(_localctx, 6, CplabParser::RuleBasic_type);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(81);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 28) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Constant_definitionContext ------------------------------------------------------------------

CplabParser::Constant_definitionContext::Constant_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CplabParser::Constant_definitionContext::Identifier() {
  return getToken(CplabParser::Identifier, 0);
}

tree::TerminalNode* CplabParser::Constant_definitionContext::Equal() {
  return getToken(CplabParser::Equal, 0);
}

CplabParser::Constant_initial_valueContext* CplabParser::Constant_definitionContext::constant_initial_value() {
  return getRuleContext<CplabParser::Constant_initial_valueContext>(0);
}

std::vector<tree::TerminalNode *> CplabParser::Constant_definitionContext::LeftBracket() {
  return getTokens(CplabParser::LeftBracket);
}

tree::TerminalNode* CplabParser::Constant_definitionContext::LeftBracket(size_t i) {
  return getToken(CplabParser::LeftBracket, i);
}

std::vector<tree::TerminalNode *> CplabParser::Constant_definitionContext::IntegerConstant() {
  return getTokens(CplabParser::IntegerConstant);
}

tree::TerminalNode* CplabParser::Constant_definitionContext::IntegerConstant(size_t i) {
  return getToken(CplabParser::IntegerConstant, i);
}

std::vector<tree::TerminalNode *> CplabParser::Constant_definitionContext::RightBracket() {
  return getTokens(CplabParser::RightBracket);
}

tree::TerminalNode* CplabParser::Constant_definitionContext::RightBracket(size_t i) {
  return getToken(CplabParser::RightBracket, i);
}


size_t CplabParser::Constant_definitionContext::getRuleIndex() const {
  return CplabParser::RuleConstant_definition;
}


std::any CplabParser::Constant_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CplabParserVisitor*>(visitor))
    return parserVisitor->visitConstant_definition(this);
  else
    return visitor->visitChildren(this);
}

CplabParser::Constant_definitionContext* CplabParser::constant_definition() {
  Constant_definitionContext *_localctx = _tracker.createInstance<Constant_definitionContext>(_ctx, getState());
  enterRule(_localctx, 8, CplabParser::RuleConstant_definition);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(83);
    match(CplabParser::Identifier);
    setState(89);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CplabParser::LeftBracket) {
      setState(84);
      match(CplabParser::LeftBracket);
      setState(85);
      match(CplabParser::IntegerConstant);
      setState(86);
      match(CplabParser::RightBracket);
      setState(91);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(92);
    match(CplabParser::Equal);
    setState(93);
    constant_initial_value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Constant_initial_valueContext ------------------------------------------------------------------

CplabParser::Constant_initial_valueContext::Constant_initial_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CplabParser::Constant_expressionContext* CplabParser::Constant_initial_valueContext::constant_expression() {
  return getRuleContext<CplabParser::Constant_expressionContext>(0);
}

tree::TerminalNode* CplabParser::Constant_initial_valueContext::LeftBrace() {
  return getToken(CplabParser::LeftBrace, 0);
}

tree::TerminalNode* CplabParser::Constant_initial_valueContext::RightBrace() {
  return getToken(CplabParser::RightBrace, 0);
}

std::vector<CplabParser::Constant_initial_valueContext *> CplabParser::Constant_initial_valueContext::constant_initial_value() {
  return getRuleContexts<CplabParser::Constant_initial_valueContext>();
}

CplabParser::Constant_initial_valueContext* CplabParser::Constant_initial_valueContext::constant_initial_value(size_t i) {
  return getRuleContext<CplabParser::Constant_initial_valueContext>(i);
}

std::vector<tree::TerminalNode *> CplabParser::Constant_initial_valueContext::Comma() {
  return getTokens(CplabParser::Comma);
}

tree::TerminalNode* CplabParser::Constant_initial_valueContext::Comma(size_t i) {
  return getToken(CplabParser::Comma, i);
}


size_t CplabParser::Constant_initial_valueContext::getRuleIndex() const {
  return CplabParser::RuleConstant_initial_value;
}


std::any CplabParser::Constant_initial_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CplabParserVisitor*>(visitor))
    return parserVisitor->visitConstant_initial_value(this);
  else
    return visitor->visitChildren(this);
}

CplabParser::Constant_initial_valueContext* CplabParser::constant_initial_value() {
  Constant_initial_valueContext *_localctx = _tracker.createInstance<Constant_initial_valueContext>(_ctx, getState());
  enterRule(_localctx, 10, CplabParser::RuleConstant_initial_value);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(108);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CplabParser::LeftParenthesis:
      case CplabParser::Plus:
      case CplabParser::Minus:
      case CplabParser::ExclamationMark:
      case CplabParser::Identifier:
      case CplabParser::IntegerConstant:
      case CplabParser::FloatConstant:
      case CplabParser::CharConstant: {
        enterOuterAlt(_localctx, 1);
        setState(95);
        constant_expression();
        break;
      }

      case CplabParser::LeftBrace: {
        enterOuterAlt(_localctx, 2);
        setState(96);
        match(CplabParser::LeftBrace);
        setState(105);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 4147361349632) != 0)) {
          setState(97);
          constant_initial_value();
          setState(102);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == CplabParser::Comma) {
            setState(98);
            match(CplabParser::Comma);
            setState(99);
            constant_initial_value();
            setState(104);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        setState(107);
        match(CplabParser::RightBrace);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_declarationContext ------------------------------------------------------------------

CplabParser::Variable_declarationContext::Variable_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CplabParser::Basic_typeContext* CplabParser::Variable_declarationContext::basic_type() {
  return getRuleContext<CplabParser::Basic_typeContext>(0);
}

std::vector<CplabParser::Variable_definitionContext *> CplabParser::Variable_declarationContext::variable_definition() {
  return getRuleContexts<CplabParser::Variable_definitionContext>();
}

CplabParser::Variable_definitionContext* CplabParser::Variable_declarationContext::variable_definition(size_t i) {
  return getRuleContext<CplabParser::Variable_definitionContext>(i);
}

tree::TerminalNode* CplabParser::Variable_declarationContext::Semicolon() {
  return getToken(CplabParser::Semicolon, 0);
}

std::vector<tree::TerminalNode *> CplabParser::Variable_declarationContext::Comma() {
  return getTokens(CplabParser::Comma);
}

tree::TerminalNode* CplabParser::Variable_declarationContext::Comma(size_t i) {
  return getToken(CplabParser::Comma, i);
}


size_t CplabParser::Variable_declarationContext::getRuleIndex() const {
  return CplabParser::RuleVariable_declaration;
}


std::any CplabParser::Variable_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CplabParserVisitor*>(visitor))
    return parserVisitor->visitVariable_declaration(this);
  else
    return visitor->visitChildren(this);
}

CplabParser::Variable_declarationContext* CplabParser::variable_declaration() {
  Variable_declarationContext *_localctx = _tracker.createInstance<Variable_declarationContext>(_ctx, getState());
  enterRule(_localctx, 12, CplabParser::RuleVariable_declaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(110);
    basic_type();
    setState(111);
    variable_definition();
    setState(116);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CplabParser::Comma) {
      setState(112);
      match(CplabParser::Comma);
      setState(113);
      variable_definition();
      setState(118);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(119);
    match(CplabParser::Semicolon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_definitionContext ------------------------------------------------------------------

CplabParser::Variable_definitionContext::Variable_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CplabParser::Variable_definitionContext::Identifier() {
  return getToken(CplabParser::Identifier, 0);
}

std::vector<tree::TerminalNode *> CplabParser::Variable_definitionContext::LeftBracket() {
  return getTokens(CplabParser::LeftBracket);
}

tree::TerminalNode* CplabParser::Variable_definitionContext::LeftBracket(size_t i) {
  return getToken(CplabParser::LeftBracket, i);
}

std::vector<tree::TerminalNode *> CplabParser::Variable_definitionContext::IntegerConstant() {
  return getTokens(CplabParser::IntegerConstant);
}

tree::TerminalNode* CplabParser::Variable_definitionContext::IntegerConstant(size_t i) {
  return getToken(CplabParser::IntegerConstant, i);
}

std::vector<tree::TerminalNode *> CplabParser::Variable_definitionContext::RightBracket() {
  return getTokens(CplabParser::RightBracket);
}

tree::TerminalNode* CplabParser::Variable_definitionContext::RightBracket(size_t i) {
  return getToken(CplabParser::RightBracket, i);
}

tree::TerminalNode* CplabParser::Variable_definitionContext::Equal() {
  return getToken(CplabParser::Equal, 0);
}

CplabParser::Constant_initial_valueContext* CplabParser::Variable_definitionContext::constant_initial_value() {
  return getRuleContext<CplabParser::Constant_initial_valueContext>(0);
}


size_t CplabParser::Variable_definitionContext::getRuleIndex() const {
  return CplabParser::RuleVariable_definition;
}


std::any CplabParser::Variable_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CplabParserVisitor*>(visitor))
    return parserVisitor->visitVariable_definition(this);
  else
    return visitor->visitChildren(this);
}

CplabParser::Variable_definitionContext* CplabParser::variable_definition() {
  Variable_definitionContext *_localctx = _tracker.createInstance<Variable_definitionContext>(_ctx, getState());
  enterRule(_localctx, 14, CplabParser::RuleVariable_definition);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(121);
    match(CplabParser::Identifier);
    setState(127);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CplabParser::LeftBracket) {
      setState(122);
      match(CplabParser::LeftBracket);
      setState(123);
      match(CplabParser::IntegerConstant);
      setState(124);
      match(CplabParser::RightBracket);
      setState(129);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(132);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CplabParser::Equal) {
      setState(130);
      match(CplabParser::Equal);
      setState(131);
      constant_initial_value();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_definitionContext ------------------------------------------------------------------

CplabParser::Function_definitionContext::Function_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CplabParser::Function_typeContext* CplabParser::Function_definitionContext::function_type() {
  return getRuleContext<CplabParser::Function_typeContext>(0);
}

tree::TerminalNode* CplabParser::Function_definitionContext::Identifier() {
  return getToken(CplabParser::Identifier, 0);
}

tree::TerminalNode* CplabParser::Function_definitionContext::LeftParenthesis() {
  return getToken(CplabParser::LeftParenthesis, 0);
}

tree::TerminalNode* CplabParser::Function_definitionContext::RightParenthesis() {
  return getToken(CplabParser::RightParenthesis, 0);
}

CplabParser::BlockContext* CplabParser::Function_definitionContext::block() {
  return getRuleContext<CplabParser::BlockContext>(0);
}

CplabParser::Function_formal_paramsContext* CplabParser::Function_definitionContext::function_formal_params() {
  return getRuleContext<CplabParser::Function_formal_paramsContext>(0);
}


size_t CplabParser::Function_definitionContext::getRuleIndex() const {
  return CplabParser::RuleFunction_definition;
}


std::any CplabParser::Function_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CplabParserVisitor*>(visitor))
    return parserVisitor->visitFunction_definition(this);
  else
    return visitor->visitChildren(this);
}

CplabParser::Function_definitionContext* CplabParser::function_definition() {
  Function_definitionContext *_localctx = _tracker.createInstance<Function_definitionContext>(_ctx, getState());
  enterRule(_localctx, 16, CplabParser::RuleFunction_definition);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(134);
    function_type();
    setState(135);
    match(CplabParser::Identifier);
    setState(136);
    match(CplabParser::LeftParenthesis);
    setState(138);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 28) != 0)) {
      setState(137);
      function_formal_params();
    }
    setState(140);
    match(CplabParser::RightParenthesis);
    setState(141);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_typeContext ------------------------------------------------------------------

CplabParser::Function_typeContext::Function_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CplabParser::Function_typeContext::Void() {
  return getToken(CplabParser::Void, 0);
}

tree::TerminalNode* CplabParser::Function_typeContext::Int() {
  return getToken(CplabParser::Int, 0);
}

tree::TerminalNode* CplabParser::Function_typeContext::Float() {
  return getToken(CplabParser::Float, 0);
}

tree::TerminalNode* CplabParser::Function_typeContext::Char() {
  return getToken(CplabParser::Char, 0);
}


size_t CplabParser::Function_typeContext::getRuleIndex() const {
  return CplabParser::RuleFunction_type;
}


std::any CplabParser::Function_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CplabParserVisitor*>(visitor))
    return parserVisitor->visitFunction_type(this);
  else
    return visitor->visitChildren(this);
}

CplabParser::Function_typeContext* CplabParser::function_type() {
  Function_typeContext *_localctx = _tracker.createInstance<Function_typeContext>(_ctx, getState());
  enterRule(_localctx, 18, CplabParser::RuleFunction_type);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(143);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 60) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_formal_paramsContext ------------------------------------------------------------------

CplabParser::Function_formal_paramsContext::Function_formal_paramsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CplabParser::Function_formal_paramContext *> CplabParser::Function_formal_paramsContext::function_formal_param() {
  return getRuleContexts<CplabParser::Function_formal_paramContext>();
}

CplabParser::Function_formal_paramContext* CplabParser::Function_formal_paramsContext::function_formal_param(size_t i) {
  return getRuleContext<CplabParser::Function_formal_paramContext>(i);
}

std::vector<tree::TerminalNode *> CplabParser::Function_formal_paramsContext::Comma() {
  return getTokens(CplabParser::Comma);
}

tree::TerminalNode* CplabParser::Function_formal_paramsContext::Comma(size_t i) {
  return getToken(CplabParser::Comma, i);
}


size_t CplabParser::Function_formal_paramsContext::getRuleIndex() const {
  return CplabParser::RuleFunction_formal_params;
}


std::any CplabParser::Function_formal_paramsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CplabParserVisitor*>(visitor))
    return parserVisitor->visitFunction_formal_params(this);
  else
    return visitor->visitChildren(this);
}

CplabParser::Function_formal_paramsContext* CplabParser::function_formal_params() {
  Function_formal_paramsContext *_localctx = _tracker.createInstance<Function_formal_paramsContext>(_ctx, getState());
  enterRule(_localctx, 20, CplabParser::RuleFunction_formal_params);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(145);
    function_formal_param();
    setState(150);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CplabParser::Comma) {
      setState(146);
      match(CplabParser::Comma);
      setState(147);
      function_formal_param();
      setState(152);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_formal_paramContext ------------------------------------------------------------------

CplabParser::Function_formal_paramContext::Function_formal_paramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CplabParser::Basic_typeContext* CplabParser::Function_formal_paramContext::basic_type() {
  return getRuleContext<CplabParser::Basic_typeContext>(0);
}

tree::TerminalNode* CplabParser::Function_formal_paramContext::Identifier() {
  return getToken(CplabParser::Identifier, 0);
}

std::vector<tree::TerminalNode *> CplabParser::Function_formal_paramContext::LeftBracket() {
  return getTokens(CplabParser::LeftBracket);
}

tree::TerminalNode* CplabParser::Function_formal_paramContext::LeftBracket(size_t i) {
  return getToken(CplabParser::LeftBracket, i);
}

std::vector<tree::TerminalNode *> CplabParser::Function_formal_paramContext::RightBracket() {
  return getTokens(CplabParser::RightBracket);
}

tree::TerminalNode* CplabParser::Function_formal_paramContext::RightBracket(size_t i) {
  return getToken(CplabParser::RightBracket, i);
}

std::vector<tree::TerminalNode *> CplabParser::Function_formal_paramContext::IntegerConstant() {
  return getTokens(CplabParser::IntegerConstant);
}

tree::TerminalNode* CplabParser::Function_formal_paramContext::IntegerConstant(size_t i) {
  return getToken(CplabParser::IntegerConstant, i);
}


size_t CplabParser::Function_formal_paramContext::getRuleIndex() const {
  return CplabParser::RuleFunction_formal_param;
}


std::any CplabParser::Function_formal_paramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CplabParserVisitor*>(visitor))
    return parserVisitor->visitFunction_formal_param(this);
  else
    return visitor->visitChildren(this);
}

CplabParser::Function_formal_paramContext* CplabParser::function_formal_param() {
  Function_formal_paramContext *_localctx = _tracker.createInstance<Function_formal_paramContext>(_ctx, getState());
  enterRule(_localctx, 22, CplabParser::RuleFunction_formal_param);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(153);
    basic_type();
    setState(154);
    match(CplabParser::Identifier);
    setState(168);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CplabParser::LeftBracket) {
      setState(155);
      match(CplabParser::LeftBracket);
      setState(157);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CplabParser::IntegerConstant) {
        setState(156);
        match(CplabParser::IntegerConstant);
      }
      setState(159);
      match(CplabParser::RightBracket);
      setState(165);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CplabParser::LeftBracket) {
        setState(160);
        match(CplabParser::LeftBracket);
        setState(161);
        match(CplabParser::IntegerConstant);
        setState(162);
        match(CplabParser::RightBracket);
        setState(167);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

CplabParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CplabParser::BlockContext::LeftBrace() {
  return getToken(CplabParser::LeftBrace, 0);
}

tree::TerminalNode* CplabParser::BlockContext::RightBrace() {
  return getToken(CplabParser::RightBrace, 0);
}

std::vector<CplabParser::Block_itemContext *> CplabParser::BlockContext::block_item() {
  return getRuleContexts<CplabParser::Block_itemContext>();
}

CplabParser::Block_itemContext* CplabParser::BlockContext::block_item(size_t i) {
  return getRuleContext<CplabParser::Block_itemContext>(i);
}


size_t CplabParser::BlockContext::getRuleIndex() const {
  return CplabParser::RuleBlock;
}


std::any CplabParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CplabParserVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

CplabParser::BlockContext* CplabParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 24, CplabParser::RuleBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(170);
    match(CplabParser::LeftBrace);
    setState(174);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4147369742174) != 0)) {
      setState(171);
      block_item();
      setState(176);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(177);
    match(CplabParser::RightBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Block_itemContext ------------------------------------------------------------------

CplabParser::Block_itemContext::Block_itemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CplabParser::DeclarationContext* CplabParser::Block_itemContext::declaration() {
  return getRuleContext<CplabParser::DeclarationContext>(0);
}

CplabParser::StatementContext* CplabParser::Block_itemContext::statement() {
  return getRuleContext<CplabParser::StatementContext>(0);
}


size_t CplabParser::Block_itemContext::getRuleIndex() const {
  return CplabParser::RuleBlock_item;
}


std::any CplabParser::Block_itemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CplabParserVisitor*>(visitor))
    return parserVisitor->visitBlock_item(this);
  else
    return visitor->visitChildren(this);
}

CplabParser::Block_itemContext* CplabParser::block_item() {
  Block_itemContext *_localctx = _tracker.createInstance<Block_itemContext>(_ctx, getState());
  enterRule(_localctx, 26, CplabParser::RuleBlock_item);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(181);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CplabParser::Const:
      case CplabParser::Int:
      case CplabParser::Char:
      case CplabParser::Float: {
        enterOuterAlt(_localctx, 1);
        setState(179);
        declaration();
        break;
      }

      case CplabParser::If:
      case CplabParser::While:
      case CplabParser::Break:
      case CplabParser::Continue:
      case CplabParser::Return:
      case CplabParser::Semicolon:
      case CplabParser::LeftParenthesis:
      case CplabParser::LeftBrace:
      case CplabParser::Plus:
      case CplabParser::Minus:
      case CplabParser::ExclamationMark:
      case CplabParser::Identifier:
      case CplabParser::IntegerConstant:
      case CplabParser::FloatConstant:
      case CplabParser::CharConstant: {
        enterOuterAlt(_localctx, 2);
        setState(180);
        statement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

CplabParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CplabParser::Left_valueContext* CplabParser::StatementContext::left_value() {
  return getRuleContext<CplabParser::Left_valueContext>(0);
}

tree::TerminalNode* CplabParser::StatementContext::Equal() {
  return getToken(CplabParser::Equal, 0);
}

CplabParser::ExpressionContext* CplabParser::StatementContext::expression() {
  return getRuleContext<CplabParser::ExpressionContext>(0);
}

tree::TerminalNode* CplabParser::StatementContext::Semicolon() {
  return getToken(CplabParser::Semicolon, 0);
}

CplabParser::BlockContext* CplabParser::StatementContext::block() {
  return getRuleContext<CplabParser::BlockContext>(0);
}

tree::TerminalNode* CplabParser::StatementContext::Return() {
  return getToken(CplabParser::Return, 0);
}

tree::TerminalNode* CplabParser::StatementContext::If() {
  return getToken(CplabParser::If, 0);
}

tree::TerminalNode* CplabParser::StatementContext::LeftParenthesis() {
  return getToken(CplabParser::LeftParenthesis, 0);
}

CplabParser::ConditionContext* CplabParser::StatementContext::condition() {
  return getRuleContext<CplabParser::ConditionContext>(0);
}

tree::TerminalNode* CplabParser::StatementContext::RightParenthesis() {
  return getToken(CplabParser::RightParenthesis, 0);
}

std::vector<CplabParser::StatementContext *> CplabParser::StatementContext::statement() {
  return getRuleContexts<CplabParser::StatementContext>();
}

CplabParser::StatementContext* CplabParser::StatementContext::statement(size_t i) {
  return getRuleContext<CplabParser::StatementContext>(i);
}

tree::TerminalNode* CplabParser::StatementContext::Else() {
  return getToken(CplabParser::Else, 0);
}

tree::TerminalNode* CplabParser::StatementContext::While() {
  return getToken(CplabParser::While, 0);
}

tree::TerminalNode* CplabParser::StatementContext::Break() {
  return getToken(CplabParser::Break, 0);
}

tree::TerminalNode* CplabParser::StatementContext::Continue() {
  return getToken(CplabParser::Continue, 0);
}


size_t CplabParser::StatementContext::getRuleIndex() const {
  return CplabParser::RuleStatement;
}


std::any CplabParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CplabParserVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

CplabParser::StatementContext* CplabParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 28, CplabParser::RuleStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(217);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(183);
      left_value();
      setState(184);
      match(CplabParser::Equal);
      setState(185);
      expression();
      setState(186);
      match(CplabParser::Semicolon);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(189);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 4146824478720) != 0)) {
        setState(188);
        expression();
      }
      setState(191);
      match(CplabParser::Semicolon);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(192);
      block();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(193);
      match(CplabParser::Return);
      setState(195);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 4146824478720) != 0)) {
        setState(194);
        expression();
      }
      setState(197);
      match(CplabParser::Semicolon);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(198);
      match(CplabParser::If);
      setState(199);
      match(CplabParser::LeftParenthesis);
      setState(200);
      condition();
      setState(201);
      match(CplabParser::RightParenthesis);
      setState(202);
      statement();
      setState(205);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
      case 1: {
        setState(203);
        match(CplabParser::Else);
        setState(204);
        statement();
        break;
      }

      default:
        break;
      }
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(207);
      match(CplabParser::While);
      setState(208);
      match(CplabParser::LeftParenthesis);
      setState(209);
      condition();
      setState(210);
      match(CplabParser::RightParenthesis);
      setState(211);
      statement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(213);
      match(CplabParser::Break);
      setState(214);
      match(CplabParser::Semicolon);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(215);
      match(CplabParser::Continue);
      setState(216);
      match(CplabParser::Semicolon);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

CplabParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CplabParser::Additive_expressionContext* CplabParser::ExpressionContext::additive_expression() {
  return getRuleContext<CplabParser::Additive_expressionContext>(0);
}


size_t CplabParser::ExpressionContext::getRuleIndex() const {
  return CplabParser::RuleExpression;
}


std::any CplabParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CplabParserVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

CplabParser::ExpressionContext* CplabParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 30, CplabParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(219);
    additive_expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Constant_expressionContext ------------------------------------------------------------------

CplabParser::Constant_expressionContext::Constant_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CplabParser::Additive_expressionContext* CplabParser::Constant_expressionContext::additive_expression() {
  return getRuleContext<CplabParser::Additive_expressionContext>(0);
}


size_t CplabParser::Constant_expressionContext::getRuleIndex() const {
  return CplabParser::RuleConstant_expression;
}


std::any CplabParser::Constant_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CplabParserVisitor*>(visitor))
    return parserVisitor->visitConstant_expression(this);
  else
    return visitor->visitChildren(this);
}

CplabParser::Constant_expressionContext* CplabParser::constant_expression() {
  Constant_expressionContext *_localctx = _tracker.createInstance<Constant_expressionContext>(_ctx, getState());
  enterRule(_localctx, 32, CplabParser::RuleConstant_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(221);
    additive_expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConditionContext ------------------------------------------------------------------

CplabParser::ConditionContext::ConditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CplabParser::Logical_or_expressionContext* CplabParser::ConditionContext::logical_or_expression() {
  return getRuleContext<CplabParser::Logical_or_expressionContext>(0);
}


size_t CplabParser::ConditionContext::getRuleIndex() const {
  return CplabParser::RuleCondition;
}


std::any CplabParser::ConditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CplabParserVisitor*>(visitor))
    return parserVisitor->visitCondition(this);
  else
    return visitor->visitChildren(this);
}

CplabParser::ConditionContext* CplabParser::condition() {
  ConditionContext *_localctx = _tracker.createInstance<ConditionContext>(_ctx, getState());
  enterRule(_localctx, 34, CplabParser::RuleCondition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(223);
    logical_or_expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Left_valueContext ------------------------------------------------------------------

CplabParser::Left_valueContext::Left_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CplabParser::Left_valueContext::Identifier() {
  return getToken(CplabParser::Identifier, 0);
}

std::vector<tree::TerminalNode *> CplabParser::Left_valueContext::LeftBracket() {
  return getTokens(CplabParser::LeftBracket);
}

tree::TerminalNode* CplabParser::Left_valueContext::LeftBracket(size_t i) {
  return getToken(CplabParser::LeftBracket, i);
}

std::vector<CplabParser::ExpressionContext *> CplabParser::Left_valueContext::expression() {
  return getRuleContexts<CplabParser::ExpressionContext>();
}

CplabParser::ExpressionContext* CplabParser::Left_valueContext::expression(size_t i) {
  return getRuleContext<CplabParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> CplabParser::Left_valueContext::RightBracket() {
  return getTokens(CplabParser::RightBracket);
}

tree::TerminalNode* CplabParser::Left_valueContext::RightBracket(size_t i) {
  return getToken(CplabParser::RightBracket, i);
}


size_t CplabParser::Left_valueContext::getRuleIndex() const {
  return CplabParser::RuleLeft_value;
}


std::any CplabParser::Left_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CplabParserVisitor*>(visitor))
    return parserVisitor->visitLeft_value(this);
  else
    return visitor->visitChildren(this);
}

CplabParser::Left_valueContext* CplabParser::left_value() {
  Left_valueContext *_localctx = _tracker.createInstance<Left_valueContext>(_ctx, getState());
  enterRule(_localctx, 36, CplabParser::RuleLeft_value);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(225);
    match(CplabParser::Identifier);
    setState(232);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(226);
        match(CplabParser::LeftBracket);
        setState(227);
        expression();
        setState(228);
        match(CplabParser::RightBracket); 
      }
      setState(234);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberContext ------------------------------------------------------------------

CplabParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CplabParser::NumberContext::IntegerConstant() {
  return getToken(CplabParser::IntegerConstant, 0);
}

tree::TerminalNode* CplabParser::NumberContext::FloatConstant() {
  return getToken(CplabParser::FloatConstant, 0);
}

tree::TerminalNode* CplabParser::NumberContext::CharConstant() {
  return getToken(CplabParser::CharConstant, 0);
}


size_t CplabParser::NumberContext::getRuleIndex() const {
  return CplabParser::RuleNumber;
}


std::any CplabParser::NumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CplabParserVisitor*>(visitor))
    return parserVisitor->visitNumber(this);
  else
    return visitor->visitChildren(this);
}

CplabParser::NumberContext* CplabParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 38, CplabParser::RuleNumber);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(235);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3848290697216) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_real_paramsContext ------------------------------------------------------------------

CplabParser::Function_real_paramsContext::Function_real_paramsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CplabParser::ExpressionContext *> CplabParser::Function_real_paramsContext::expression() {
  return getRuleContexts<CplabParser::ExpressionContext>();
}

CplabParser::ExpressionContext* CplabParser::Function_real_paramsContext::expression(size_t i) {
  return getRuleContext<CplabParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> CplabParser::Function_real_paramsContext::Comma() {
  return getTokens(CplabParser::Comma);
}

tree::TerminalNode* CplabParser::Function_real_paramsContext::Comma(size_t i) {
  return getToken(CplabParser::Comma, i);
}


size_t CplabParser::Function_real_paramsContext::getRuleIndex() const {
  return CplabParser::RuleFunction_real_params;
}


std::any CplabParser::Function_real_paramsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CplabParserVisitor*>(visitor))
    return parserVisitor->visitFunction_real_params(this);
  else
    return visitor->visitChildren(this);
}

CplabParser::Function_real_paramsContext* CplabParser::function_real_params() {
  Function_real_paramsContext *_localctx = _tracker.createInstance<Function_real_paramsContext>(_ctx, getState());
  enterRule(_localctx, 40, CplabParser::RuleFunction_real_params);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(237);
    expression();
    setState(242);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CplabParser::Comma) {
      setState(238);
      match(CplabParser::Comma);
      setState(239);
      expression();
      setState(244);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Primary_expressionContext ------------------------------------------------------------------

CplabParser::Primary_expressionContext::Primary_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CplabParser::Primary_expressionContext::LeftParenthesis() {
  return getToken(CplabParser::LeftParenthesis, 0);
}

CplabParser::ExpressionContext* CplabParser::Primary_expressionContext::expression() {
  return getRuleContext<CplabParser::ExpressionContext>(0);
}

tree::TerminalNode* CplabParser::Primary_expressionContext::RightParenthesis() {
  return getToken(CplabParser::RightParenthesis, 0);
}

CplabParser::Left_valueContext* CplabParser::Primary_expressionContext::left_value() {
  return getRuleContext<CplabParser::Left_valueContext>(0);
}

CplabParser::NumberContext* CplabParser::Primary_expressionContext::number() {
  return getRuleContext<CplabParser::NumberContext>(0);
}


size_t CplabParser::Primary_expressionContext::getRuleIndex() const {
  return CplabParser::RulePrimary_expression;
}


std::any CplabParser::Primary_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CplabParserVisitor*>(visitor))
    return parserVisitor->visitPrimary_expression(this);
  else
    return visitor->visitChildren(this);
}

CplabParser::Primary_expressionContext* CplabParser::primary_expression() {
  Primary_expressionContext *_localctx = _tracker.createInstance<Primary_expressionContext>(_ctx, getState());
  enterRule(_localctx, 42, CplabParser::RulePrimary_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(251);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CplabParser::LeftParenthesis: {
        enterOuterAlt(_localctx, 1);
        setState(245);
        match(CplabParser::LeftParenthesis);
        setState(246);
        expression();
        setState(247);
        match(CplabParser::RightParenthesis);
        break;
      }

      case CplabParser::Identifier: {
        enterOuterAlt(_localctx, 2);
        setState(249);
        left_value();
        break;
      }

      case CplabParser::IntegerConstant:
      case CplabParser::FloatConstant:
      case CplabParser::CharConstant: {
        enterOuterAlt(_localctx, 3);
        setState(250);
        number();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Unary_expressionContext ------------------------------------------------------------------

CplabParser::Unary_expressionContext::Unary_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CplabParser::Primary_expressionContext* CplabParser::Unary_expressionContext::primary_expression() {
  return getRuleContext<CplabParser::Primary_expressionContext>(0);
}

CplabParser::Unary_expressionContext* CplabParser::Unary_expressionContext::unary_expression() {
  return getRuleContext<CplabParser::Unary_expressionContext>(0);
}

tree::TerminalNode* CplabParser::Unary_expressionContext::Plus() {
  return getToken(CplabParser::Plus, 0);
}

tree::TerminalNode* CplabParser::Unary_expressionContext::Minus() {
  return getToken(CplabParser::Minus, 0);
}

tree::TerminalNode* CplabParser::Unary_expressionContext::ExclamationMark() {
  return getToken(CplabParser::ExclamationMark, 0);
}

tree::TerminalNode* CplabParser::Unary_expressionContext::Identifier() {
  return getToken(CplabParser::Identifier, 0);
}

tree::TerminalNode* CplabParser::Unary_expressionContext::LeftParenthesis() {
  return getToken(CplabParser::LeftParenthesis, 0);
}

tree::TerminalNode* CplabParser::Unary_expressionContext::RightParenthesis() {
  return getToken(CplabParser::RightParenthesis, 0);
}

CplabParser::Function_real_paramsContext* CplabParser::Unary_expressionContext::function_real_params() {
  return getRuleContext<CplabParser::Function_real_paramsContext>(0);
}


size_t CplabParser::Unary_expressionContext::getRuleIndex() const {
  return CplabParser::RuleUnary_expression;
}


std::any CplabParser::Unary_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CplabParserVisitor*>(visitor))
    return parserVisitor->visitUnary_expression(this);
  else
    return visitor->visitChildren(this);
}

CplabParser::Unary_expressionContext* CplabParser::unary_expression() {
  Unary_expressionContext *_localctx = _tracker.createInstance<Unary_expressionContext>(_ctx, getState());
  enterRule(_localctx, 44, CplabParser::RuleUnary_expression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(262);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(253);
      primary_expression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(254);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 23622320128) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(255);
      unary_expression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(256);
      match(CplabParser::Identifier);
      setState(257);
      match(CplabParser::LeftParenthesis);
      setState(259);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 4146824478720) != 0)) {
        setState(258);
        function_real_params();
      }
      setState(261);
      match(CplabParser::RightParenthesis);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Multiplicative_expressionContext ------------------------------------------------------------------

CplabParser::Multiplicative_expressionContext::Multiplicative_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CplabParser::Unary_expressionContext* CplabParser::Multiplicative_expressionContext::unary_expression() {
  return getRuleContext<CplabParser::Unary_expressionContext>(0);
}

CplabParser::Multiplicative_expressionContext* CplabParser::Multiplicative_expressionContext::multiplicative_expression() {
  return getRuleContext<CplabParser::Multiplicative_expressionContext>(0);
}

tree::TerminalNode* CplabParser::Multiplicative_expressionContext::Asterisk() {
  return getToken(CplabParser::Asterisk, 0);
}

tree::TerminalNode* CplabParser::Multiplicative_expressionContext::Slash() {
  return getToken(CplabParser::Slash, 0);
}

tree::TerminalNode* CplabParser::Multiplicative_expressionContext::Percent() {
  return getToken(CplabParser::Percent, 0);
}


size_t CplabParser::Multiplicative_expressionContext::getRuleIndex() const {
  return CplabParser::RuleMultiplicative_expression;
}


std::any CplabParser::Multiplicative_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CplabParserVisitor*>(visitor))
    return parserVisitor->visitMultiplicative_expression(this);
  else
    return visitor->visitChildren(this);
}


CplabParser::Multiplicative_expressionContext* CplabParser::multiplicative_expression() {
   return multiplicative_expression(0);
}

CplabParser::Multiplicative_expressionContext* CplabParser::multiplicative_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CplabParser::Multiplicative_expressionContext *_localctx = _tracker.createInstance<Multiplicative_expressionContext>(_ctx, parentState);
  CplabParser::Multiplicative_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 46;
  enterRecursionRule(_localctx, 46, CplabParser::RuleMultiplicative_expression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(265);
    unary_expression();
    _ctx->stop = _input->LT(-1);
    setState(272);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Multiplicative_expressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleMultiplicative_expression);
        setState(267);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(268);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 240518168576) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(269);
        unary_expression(); 
      }
      setState(274);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Additive_expressionContext ------------------------------------------------------------------

CplabParser::Additive_expressionContext::Additive_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CplabParser::Multiplicative_expressionContext* CplabParser::Additive_expressionContext::multiplicative_expression() {
  return getRuleContext<CplabParser::Multiplicative_expressionContext>(0);
}

CplabParser::Additive_expressionContext* CplabParser::Additive_expressionContext::additive_expression() {
  return getRuleContext<CplabParser::Additive_expressionContext>(0);
}

tree::TerminalNode* CplabParser::Additive_expressionContext::Plus() {
  return getToken(CplabParser::Plus, 0);
}

tree::TerminalNode* CplabParser::Additive_expressionContext::Minus() {
  return getToken(CplabParser::Minus, 0);
}


size_t CplabParser::Additive_expressionContext::getRuleIndex() const {
  return CplabParser::RuleAdditive_expression;
}


std::any CplabParser::Additive_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CplabParserVisitor*>(visitor))
    return parserVisitor->visitAdditive_expression(this);
  else
    return visitor->visitChildren(this);
}


CplabParser::Additive_expressionContext* CplabParser::additive_expression() {
   return additive_expression(0);
}

CplabParser::Additive_expressionContext* CplabParser::additive_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CplabParser::Additive_expressionContext *_localctx = _tracker.createInstance<Additive_expressionContext>(_ctx, parentState);
  CplabParser::Additive_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 48;
  enterRecursionRule(_localctx, 48, CplabParser::RuleAdditive_expression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(276);
    multiplicative_expression(0);
    _ctx->stop = _input->LT(-1);
    setState(283);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Additive_expressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleAdditive_expression);
        setState(278);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(279);
        _la = _input->LA(1);
        if (!(_la == CplabParser::Plus

        || _la == CplabParser::Minus)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(280);
        multiplicative_expression(0); 
      }
      setState(285);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Relational_expressionContext ------------------------------------------------------------------

CplabParser::Relational_expressionContext::Relational_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CplabParser::Additive_expressionContext* CplabParser::Relational_expressionContext::additive_expression() {
  return getRuleContext<CplabParser::Additive_expressionContext>(0);
}

CplabParser::Relational_expressionContext* CplabParser::Relational_expressionContext::relational_expression() {
  return getRuleContext<CplabParser::Relational_expressionContext>(0);
}

tree::TerminalNode* CplabParser::Relational_expressionContext::Less() {
  return getToken(CplabParser::Less, 0);
}

tree::TerminalNode* CplabParser::Relational_expressionContext::LessEqual() {
  return getToken(CplabParser::LessEqual, 0);
}

tree::TerminalNode* CplabParser::Relational_expressionContext::Greater() {
  return getToken(CplabParser::Greater, 0);
}

tree::TerminalNode* CplabParser::Relational_expressionContext::GreaterEqual() {
  return getToken(CplabParser::GreaterEqual, 0);
}


size_t CplabParser::Relational_expressionContext::getRuleIndex() const {
  return CplabParser::RuleRelational_expression;
}


std::any CplabParser::Relational_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CplabParserVisitor*>(visitor))
    return parserVisitor->visitRelational_expression(this);
  else
    return visitor->visitChildren(this);
}


CplabParser::Relational_expressionContext* CplabParser::relational_expression() {
   return relational_expression(0);
}

CplabParser::Relational_expressionContext* CplabParser::relational_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CplabParser::Relational_expressionContext *_localctx = _tracker.createInstance<Relational_expressionContext>(_ctx, parentState);
  CplabParser::Relational_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 50;
  enterRecursionRule(_localctx, 50, CplabParser::RuleRelational_expression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(287);
    additive_expression(0);
    _ctx->stop = _input->LT(-1);
    setState(294);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Relational_expressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleRelational_expression);
        setState(289);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(290);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 1966080) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(291);
        additive_expression(0); 
      }
      setState(296);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Equal_expressionContext ------------------------------------------------------------------

CplabParser::Equal_expressionContext::Equal_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CplabParser::Relational_expressionContext* CplabParser::Equal_expressionContext::relational_expression() {
  return getRuleContext<CplabParser::Relational_expressionContext>(0);
}

CplabParser::Equal_expressionContext* CplabParser::Equal_expressionContext::equal_expression() {
  return getRuleContext<CplabParser::Equal_expressionContext>(0);
}

tree::TerminalNode* CplabParser::Equal_expressionContext::LogicalEqual() {
  return getToken(CplabParser::LogicalEqual, 0);
}

tree::TerminalNode* CplabParser::Equal_expressionContext::NotEqual() {
  return getToken(CplabParser::NotEqual, 0);
}


size_t CplabParser::Equal_expressionContext::getRuleIndex() const {
  return CplabParser::RuleEqual_expression;
}


std::any CplabParser::Equal_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CplabParserVisitor*>(visitor))
    return parserVisitor->visitEqual_expression(this);
  else
    return visitor->visitChildren(this);
}


CplabParser::Equal_expressionContext* CplabParser::equal_expression() {
   return equal_expression(0);
}

CplabParser::Equal_expressionContext* CplabParser::equal_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CplabParser::Equal_expressionContext *_localctx = _tracker.createInstance<Equal_expressionContext>(_ctx, parentState);
  CplabParser::Equal_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 52;
  enterRecursionRule(_localctx, 52, CplabParser::RuleEqual_expression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(298);
    relational_expression(0);
    _ctx->stop = _input->LT(-1);
    setState(305);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Equal_expressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleEqual_expression);
        setState(300);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(301);
        _la = _input->LA(1);
        if (!(_la == CplabParser::LogicalEqual

        || _la == CplabParser::NotEqual)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(302);
        relational_expression(0); 
      }
      setState(307);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Logical_and_expressionContext ------------------------------------------------------------------

CplabParser::Logical_and_expressionContext::Logical_and_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CplabParser::Equal_expressionContext* CplabParser::Logical_and_expressionContext::equal_expression() {
  return getRuleContext<CplabParser::Equal_expressionContext>(0);
}

CplabParser::Logical_and_expressionContext* CplabParser::Logical_and_expressionContext::logical_and_expression() {
  return getRuleContext<CplabParser::Logical_and_expressionContext>(0);
}

tree::TerminalNode* CplabParser::Logical_and_expressionContext::LogicalAnd() {
  return getToken(CplabParser::LogicalAnd, 0);
}


size_t CplabParser::Logical_and_expressionContext::getRuleIndex() const {
  return CplabParser::RuleLogical_and_expression;
}


std::any CplabParser::Logical_and_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CplabParserVisitor*>(visitor))
    return parserVisitor->visitLogical_and_expression(this);
  else
    return visitor->visitChildren(this);
}


CplabParser::Logical_and_expressionContext* CplabParser::logical_and_expression() {
   return logical_and_expression(0);
}

CplabParser::Logical_and_expressionContext* CplabParser::logical_and_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CplabParser::Logical_and_expressionContext *_localctx = _tracker.createInstance<Logical_and_expressionContext>(_ctx, parentState);
  CplabParser::Logical_and_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 54;
  enterRecursionRule(_localctx, 54, CplabParser::RuleLogical_and_expression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(309);
    equal_expression(0);
    _ctx->stop = _input->LT(-1);
    setState(316);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Logical_and_expressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLogical_and_expression);
        setState(311);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(312);
        match(CplabParser::LogicalAnd);
        setState(313);
        equal_expression(0); 
      }
      setState(318);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Logical_or_expressionContext ------------------------------------------------------------------

CplabParser::Logical_or_expressionContext::Logical_or_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CplabParser::Logical_and_expressionContext* CplabParser::Logical_or_expressionContext::logical_and_expression() {
  return getRuleContext<CplabParser::Logical_and_expressionContext>(0);
}

CplabParser::Logical_or_expressionContext* CplabParser::Logical_or_expressionContext::logical_or_expression() {
  return getRuleContext<CplabParser::Logical_or_expressionContext>(0);
}

tree::TerminalNode* CplabParser::Logical_or_expressionContext::LogicalOr() {
  return getToken(CplabParser::LogicalOr, 0);
}


size_t CplabParser::Logical_or_expressionContext::getRuleIndex() const {
  return CplabParser::RuleLogical_or_expression;
}


std::any CplabParser::Logical_or_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CplabParserVisitor*>(visitor))
    return parserVisitor->visitLogical_or_expression(this);
  else
    return visitor->visitChildren(this);
}


CplabParser::Logical_or_expressionContext* CplabParser::logical_or_expression() {
   return logical_or_expression(0);
}

CplabParser::Logical_or_expressionContext* CplabParser::logical_or_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CplabParser::Logical_or_expressionContext *_localctx = _tracker.createInstance<Logical_or_expressionContext>(_ctx, parentState);
  CplabParser::Logical_or_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 56;
  enterRecursionRule(_localctx, 56, CplabParser::RuleLogical_or_expression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(320);
    logical_and_expression(0);
    _ctx->stop = _input->LT(-1);
    setState(327);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Logical_or_expressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLogical_or_expression);
        setState(322);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(323);
        match(CplabParser::LogicalOr);
        setState(324);
        logical_and_expression(0); 
      }
      setState(329);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool CplabParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 23: return multiplicative_expressionSempred(antlrcpp::downCast<Multiplicative_expressionContext *>(context), predicateIndex);
    case 24: return additive_expressionSempred(antlrcpp::downCast<Additive_expressionContext *>(context), predicateIndex);
    case 25: return relational_expressionSempred(antlrcpp::downCast<Relational_expressionContext *>(context), predicateIndex);
    case 26: return equal_expressionSempred(antlrcpp::downCast<Equal_expressionContext *>(context), predicateIndex);
    case 27: return logical_and_expressionSempred(antlrcpp::downCast<Logical_and_expressionContext *>(context), predicateIndex);
    case 28: return logical_or_expressionSempred(antlrcpp::downCast<Logical_or_expressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool CplabParser::multiplicative_expressionSempred(Multiplicative_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CplabParser::additive_expressionSempred(Additive_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CplabParser::relational_expressionSempred(Relational_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CplabParser::equal_expressionSempred(Equal_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CplabParser::logical_and_expressionSempred(Logical_and_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CplabParser::logical_or_expressionSempred(Logical_or_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

void CplabParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  cplabparserParserInitialize();
#else
  ::antlr4::internal::call_once(cplabparserParserOnceFlag, cplabparserParserInitialize);
#endif
}
