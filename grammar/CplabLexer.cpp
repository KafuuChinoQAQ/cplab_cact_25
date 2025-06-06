
// Generated from E:/Homework/cplab/cact/grammar/CplabLexer.g4 by ANTLR 4.13.1


#include "CplabLexer.h"


using namespace antlr4;

using namespace cplab_parser;


using namespace antlr4;

namespace {

struct CplabLexerStaticData final {
  CplabLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  CplabLexerStaticData(const CplabLexerStaticData&) = delete;
  CplabLexerStaticData(CplabLexerStaticData&&) = delete;
  CplabLexerStaticData& operator=(const CplabLexerStaticData&) = delete;
  CplabLexerStaticData& operator=(CplabLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag cplablexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
CplabLexerStaticData *cplablexerLexerStaticData = nullptr;

void cplablexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (cplablexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(cplablexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<CplabLexerStaticData>(
    std::vector<std::string>{
      "Const", "Int", "Char", "Float", "Void", "If", "Else", "While", "Break", 
      "Continue", "Return", "Equal", "LogicalEqual", "LogicalAnd", "LogicalOr", 
      "NotEqual", "Less", "LessEqual", "Greater", "GreaterEqual", "Period", 
      "Comma", "Semicolon", "Colon", "LeftParenthesis", "RightParenthesis", 
      "LeftBracket", "RightBracket", "LeftBrace", "RightBrace", "Plus", 
      "Minus", "Pipe", "ExclamationMark", "Asterisk", "Slash", "Percent", 
      "Identifier", "IntegerConstant", "FloatConstant", "CharConstant", 
      "LineComment", "BlockComment", "NewLine", "WhiteSpaces"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,45,386,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,
  	7,42,2,43,7,43,2,44,7,44,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,2,
  	1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,
  	5,1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,
  	1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,1,10,1,10,
  	1,11,1,11,1,12,1,12,1,12,1,13,1,13,1,13,1,14,1,14,1,14,1,15,1,15,1,15,
  	1,16,1,16,1,17,1,17,1,17,1,18,1,18,1,19,1,19,1,19,1,20,1,20,1,21,1,21,
  	1,22,1,22,1,23,1,23,1,24,1,24,1,25,1,25,1,26,1,26,1,27,1,27,1,28,1,28,
  	1,29,1,29,1,30,1,30,1,31,1,31,1,32,1,32,1,33,1,33,1,34,1,34,1,35,1,35,
  	1,36,1,36,1,37,1,37,5,37,214,8,37,10,37,12,37,217,9,37,1,38,1,38,1,38,
  	5,38,222,8,38,10,38,12,38,225,9,38,1,38,1,38,4,38,229,8,38,11,38,12,38,
  	230,1,38,1,38,1,38,4,38,236,8,38,11,38,12,38,237,3,38,240,8,38,1,39,4,
  	39,243,8,39,11,39,12,39,244,1,39,1,39,5,39,249,8,39,10,39,12,39,252,9,
  	39,1,39,1,39,3,39,256,8,39,1,39,4,39,259,8,39,11,39,12,39,260,3,39,263,
  	8,39,1,39,1,39,4,39,267,8,39,11,39,12,39,268,1,39,1,39,3,39,273,8,39,
  	1,39,4,39,276,8,39,11,39,12,39,277,3,39,280,8,39,1,39,4,39,283,8,39,11,
  	39,12,39,284,1,39,1,39,3,39,289,8,39,1,39,4,39,292,8,39,11,39,12,39,293,
  	1,39,1,39,1,39,4,39,299,8,39,11,39,12,39,300,1,39,1,39,5,39,305,8,39,
  	10,39,12,39,308,9,39,1,39,1,39,3,39,312,8,39,1,39,4,39,315,8,39,11,39,
  	12,39,316,1,39,1,39,1,39,1,39,4,39,323,8,39,11,39,12,39,324,1,39,1,39,
  	3,39,329,8,39,1,39,4,39,332,8,39,11,39,12,39,333,3,39,336,8,39,1,40,1,
  	40,1,40,1,40,3,40,342,8,40,1,40,1,40,1,41,1,41,1,41,1,41,5,41,350,8,41,
  	10,41,12,41,353,9,41,1,41,1,41,1,42,1,42,1,42,1,42,5,42,361,8,42,10,42,
  	12,42,364,9,42,1,42,1,42,1,42,1,42,1,42,1,43,1,43,3,43,373,8,43,1,43,
  	3,43,376,8,43,1,43,1,43,1,44,4,44,381,8,44,11,44,12,44,382,1,44,1,44,
  	1,362,0,45,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,
  	25,13,27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,45,23,47,
  	24,49,25,51,26,53,27,55,28,57,29,59,30,61,31,63,32,65,33,67,34,69,35,
  	71,36,73,37,75,38,77,39,79,40,81,41,83,42,85,43,87,44,89,45,1,0,14,3,
  	0,65,90,95,95,97,122,4,0,48,57,65,90,95,95,97,122,1,0,49,57,1,0,48,57,
  	1,0,48,55,2,0,88,88,120,120,3,0,48,57,65,70,97,102,2,0,69,69,101,101,
  	2,0,43,43,45,45,2,0,80,80,112,112,7,0,34,34,39,39,48,48,92,92,110,110,
  	114,114,116,116,2,0,39,39,92,92,2,0,10,10,13,13,2,0,9,9,32,32,421,0,1,
  	1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,
  	0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,
  	1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,
  	0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,
  	0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,
  	1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,0,0,0,65,1,0,
  	0,0,0,67,1,0,0,0,0,69,1,0,0,0,0,71,1,0,0,0,0,73,1,0,0,0,0,75,1,0,0,0,
  	0,77,1,0,0,0,0,79,1,0,0,0,0,81,1,0,0,0,0,83,1,0,0,0,0,85,1,0,0,0,0,87,
  	1,0,0,0,0,89,1,0,0,0,1,91,1,0,0,0,3,97,1,0,0,0,5,101,1,0,0,0,7,106,1,
  	0,0,0,9,112,1,0,0,0,11,117,1,0,0,0,13,120,1,0,0,0,15,125,1,0,0,0,17,131,
  	1,0,0,0,19,137,1,0,0,0,21,146,1,0,0,0,23,153,1,0,0,0,25,155,1,0,0,0,27,
  	158,1,0,0,0,29,161,1,0,0,0,31,164,1,0,0,0,33,167,1,0,0,0,35,169,1,0,0,
  	0,37,172,1,0,0,0,39,174,1,0,0,0,41,177,1,0,0,0,43,179,1,0,0,0,45,181,
  	1,0,0,0,47,183,1,0,0,0,49,185,1,0,0,0,51,187,1,0,0,0,53,189,1,0,0,0,55,
  	191,1,0,0,0,57,193,1,0,0,0,59,195,1,0,0,0,61,197,1,0,0,0,63,199,1,0,0,
  	0,65,201,1,0,0,0,67,203,1,0,0,0,69,205,1,0,0,0,71,207,1,0,0,0,73,209,
  	1,0,0,0,75,211,1,0,0,0,77,239,1,0,0,0,79,335,1,0,0,0,81,337,1,0,0,0,83,
  	345,1,0,0,0,85,356,1,0,0,0,87,375,1,0,0,0,89,380,1,0,0,0,91,92,5,99,0,
  	0,92,93,5,111,0,0,93,94,5,110,0,0,94,95,5,115,0,0,95,96,5,116,0,0,96,
  	2,1,0,0,0,97,98,5,105,0,0,98,99,5,110,0,0,99,100,5,116,0,0,100,4,1,0,
  	0,0,101,102,5,99,0,0,102,103,5,104,0,0,103,104,5,97,0,0,104,105,5,114,
  	0,0,105,6,1,0,0,0,106,107,5,102,0,0,107,108,5,108,0,0,108,109,5,111,0,
  	0,109,110,5,97,0,0,110,111,5,116,0,0,111,8,1,0,0,0,112,113,5,118,0,0,
  	113,114,5,111,0,0,114,115,5,105,0,0,115,116,5,100,0,0,116,10,1,0,0,0,
  	117,118,5,105,0,0,118,119,5,102,0,0,119,12,1,0,0,0,120,121,5,101,0,0,
  	121,122,5,108,0,0,122,123,5,115,0,0,123,124,5,101,0,0,124,14,1,0,0,0,
  	125,126,5,119,0,0,126,127,5,104,0,0,127,128,5,105,0,0,128,129,5,108,0,
  	0,129,130,5,101,0,0,130,16,1,0,0,0,131,132,5,98,0,0,132,133,5,114,0,0,
  	133,134,5,101,0,0,134,135,5,97,0,0,135,136,5,107,0,0,136,18,1,0,0,0,137,
  	138,5,99,0,0,138,139,5,111,0,0,139,140,5,110,0,0,140,141,5,116,0,0,141,
  	142,5,105,0,0,142,143,5,110,0,0,143,144,5,117,0,0,144,145,5,101,0,0,145,
  	20,1,0,0,0,146,147,5,114,0,0,147,148,5,101,0,0,148,149,5,116,0,0,149,
  	150,5,117,0,0,150,151,5,114,0,0,151,152,5,110,0,0,152,22,1,0,0,0,153,
  	154,5,61,0,0,154,24,1,0,0,0,155,156,5,61,0,0,156,157,5,61,0,0,157,26,
  	1,0,0,0,158,159,5,38,0,0,159,160,5,38,0,0,160,28,1,0,0,0,161,162,5,124,
  	0,0,162,163,5,124,0,0,163,30,1,0,0,0,164,165,5,33,0,0,165,166,5,61,0,
  	0,166,32,1,0,0,0,167,168,5,60,0,0,168,34,1,0,0,0,169,170,5,60,0,0,170,
  	171,5,61,0,0,171,36,1,0,0,0,172,173,5,62,0,0,173,38,1,0,0,0,174,175,5,
  	62,0,0,175,176,5,61,0,0,176,40,1,0,0,0,177,178,5,46,0,0,178,42,1,0,0,
  	0,179,180,5,44,0,0,180,44,1,0,0,0,181,182,5,59,0,0,182,46,1,0,0,0,183,
  	184,5,58,0,0,184,48,1,0,0,0,185,186,5,40,0,0,186,50,1,0,0,0,187,188,5,
  	41,0,0,188,52,1,0,0,0,189,190,5,91,0,0,190,54,1,0,0,0,191,192,5,93,0,
  	0,192,56,1,0,0,0,193,194,5,123,0,0,194,58,1,0,0,0,195,196,5,125,0,0,196,
  	60,1,0,0,0,197,198,5,43,0,0,198,62,1,0,0,0,199,200,5,45,0,0,200,64,1,
  	0,0,0,201,202,5,124,0,0,202,66,1,0,0,0,203,204,5,33,0,0,204,68,1,0,0,
  	0,205,206,5,42,0,0,206,70,1,0,0,0,207,208,5,47,0,0,208,72,1,0,0,0,209,
  	210,5,37,0,0,210,74,1,0,0,0,211,215,7,0,0,0,212,214,7,1,0,0,213,212,1,
  	0,0,0,214,217,1,0,0,0,215,213,1,0,0,0,215,216,1,0,0,0,216,76,1,0,0,0,
  	217,215,1,0,0,0,218,240,5,48,0,0,219,223,7,2,0,0,220,222,7,3,0,0,221,
  	220,1,0,0,0,222,225,1,0,0,0,223,221,1,0,0,0,223,224,1,0,0,0,224,240,1,
  	0,0,0,225,223,1,0,0,0,226,228,5,48,0,0,227,229,7,4,0,0,228,227,1,0,0,
  	0,229,230,1,0,0,0,230,228,1,0,0,0,230,231,1,0,0,0,231,240,1,0,0,0,232,
  	233,5,48,0,0,233,235,7,5,0,0,234,236,7,6,0,0,235,234,1,0,0,0,236,237,
  	1,0,0,0,237,235,1,0,0,0,237,238,1,0,0,0,238,240,1,0,0,0,239,218,1,0,0,
  	0,239,219,1,0,0,0,239,226,1,0,0,0,239,232,1,0,0,0,240,78,1,0,0,0,241,
  	243,7,3,0,0,242,241,1,0,0,0,243,244,1,0,0,0,244,242,1,0,0,0,244,245,1,
  	0,0,0,245,246,1,0,0,0,246,250,5,46,0,0,247,249,7,3,0,0,248,247,1,0,0,
  	0,249,252,1,0,0,0,250,248,1,0,0,0,250,251,1,0,0,0,251,262,1,0,0,0,252,
  	250,1,0,0,0,253,255,7,7,0,0,254,256,7,8,0,0,255,254,1,0,0,0,255,256,1,
  	0,0,0,256,258,1,0,0,0,257,259,7,3,0,0,258,257,1,0,0,0,259,260,1,0,0,0,
  	260,258,1,0,0,0,260,261,1,0,0,0,261,263,1,0,0,0,262,253,1,0,0,0,262,263,
  	1,0,0,0,263,336,1,0,0,0,264,266,5,46,0,0,265,267,7,3,0,0,266,265,1,0,
  	0,0,267,268,1,0,0,0,268,266,1,0,0,0,268,269,1,0,0,0,269,279,1,0,0,0,270,
  	272,7,7,0,0,271,273,7,8,0,0,272,271,1,0,0,0,272,273,1,0,0,0,273,275,1,
  	0,0,0,274,276,7,3,0,0,275,274,1,0,0,0,276,277,1,0,0,0,277,275,1,0,0,0,
  	277,278,1,0,0,0,278,280,1,0,0,0,279,270,1,0,0,0,279,280,1,0,0,0,280,336,
  	1,0,0,0,281,283,7,3,0,0,282,281,1,0,0,0,283,284,1,0,0,0,284,282,1,0,0,
  	0,284,285,1,0,0,0,285,286,1,0,0,0,286,288,7,7,0,0,287,289,7,8,0,0,288,
  	287,1,0,0,0,288,289,1,0,0,0,289,291,1,0,0,0,290,292,7,3,0,0,291,290,1,
  	0,0,0,292,293,1,0,0,0,293,291,1,0,0,0,293,294,1,0,0,0,294,336,1,0,0,0,
  	295,296,5,48,0,0,296,298,7,5,0,0,297,299,7,6,0,0,298,297,1,0,0,0,299,
  	300,1,0,0,0,300,298,1,0,0,0,300,301,1,0,0,0,301,302,1,0,0,0,302,306,5,
  	46,0,0,303,305,7,6,0,0,304,303,1,0,0,0,305,308,1,0,0,0,306,304,1,0,0,
  	0,306,307,1,0,0,0,307,309,1,0,0,0,308,306,1,0,0,0,309,311,7,9,0,0,310,
  	312,7,8,0,0,311,310,1,0,0,0,311,312,1,0,0,0,312,314,1,0,0,0,313,315,7,
  	3,0,0,314,313,1,0,0,0,315,316,1,0,0,0,316,314,1,0,0,0,316,317,1,0,0,0,
  	317,336,1,0,0,0,318,319,5,48,0,0,319,320,7,5,0,0,320,322,5,46,0,0,321,
  	323,7,6,0,0,322,321,1,0,0,0,323,324,1,0,0,0,324,322,1,0,0,0,324,325,1,
  	0,0,0,325,326,1,0,0,0,326,328,7,9,0,0,327,329,7,8,0,0,328,327,1,0,0,0,
  	328,329,1,0,0,0,329,331,1,0,0,0,330,332,7,3,0,0,331,330,1,0,0,0,332,333,
  	1,0,0,0,333,331,1,0,0,0,333,334,1,0,0,0,334,336,1,0,0,0,335,242,1,0,0,
  	0,335,264,1,0,0,0,335,282,1,0,0,0,335,295,1,0,0,0,335,318,1,0,0,0,336,
  	80,1,0,0,0,337,341,5,39,0,0,338,339,5,92,0,0,339,342,7,10,0,0,340,342,
  	8,11,0,0,341,338,1,0,0,0,341,340,1,0,0,0,342,343,1,0,0,0,343,344,5,39,
  	0,0,344,82,1,0,0,0,345,346,5,47,0,0,346,347,5,47,0,0,347,351,1,0,0,0,
  	348,350,8,12,0,0,349,348,1,0,0,0,350,353,1,0,0,0,351,349,1,0,0,0,351,
  	352,1,0,0,0,352,354,1,0,0,0,353,351,1,0,0,0,354,355,6,41,0,0,355,84,1,
  	0,0,0,356,357,5,47,0,0,357,358,5,42,0,0,358,362,1,0,0,0,359,361,9,0,0,
  	0,360,359,1,0,0,0,361,364,1,0,0,0,362,363,1,0,0,0,362,360,1,0,0,0,363,
  	365,1,0,0,0,364,362,1,0,0,0,365,366,5,42,0,0,366,367,5,47,0,0,367,368,
  	1,0,0,0,368,369,6,42,0,0,369,86,1,0,0,0,370,372,5,13,0,0,371,373,5,10,
  	0,0,372,371,1,0,0,0,372,373,1,0,0,0,373,376,1,0,0,0,374,376,5,10,0,0,
  	375,370,1,0,0,0,375,374,1,0,0,0,376,377,1,0,0,0,377,378,6,43,0,0,378,
  	88,1,0,0,0,379,381,7,13,0,0,380,379,1,0,0,0,381,382,1,0,0,0,382,380,1,
  	0,0,0,382,383,1,0,0,0,383,384,1,0,0,0,384,385,6,44,0,0,385,90,1,0,0,0,
  	32,0,215,223,230,237,239,244,250,255,260,262,268,272,277,279,284,288,
  	293,300,306,311,316,324,328,333,335,341,351,362,372,375,382,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  cplablexerLexerStaticData = staticData.release();
}

}

CplabLexer::CplabLexer(CharStream *input) : Lexer(input) {
  CplabLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *cplablexerLexerStaticData->atn, cplablexerLexerStaticData->decisionToDFA, cplablexerLexerStaticData->sharedContextCache);
}

CplabLexer::~CplabLexer() {
  delete _interpreter;
}

std::string CplabLexer::getGrammarFileName() const {
  return "CplabLexer.g4";
}

const std::vector<std::string>& CplabLexer::getRuleNames() const {
  return cplablexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& CplabLexer::getChannelNames() const {
  return cplablexerLexerStaticData->channelNames;
}

const std::vector<std::string>& CplabLexer::getModeNames() const {
  return cplablexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& CplabLexer::getVocabulary() const {
  return cplablexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView CplabLexer::getSerializedATN() const {
  return cplablexerLexerStaticData->serializedATN;
}

const atn::ATN& CplabLexer::getATN() const {
  return *cplablexerLexerStaticData->atn;
}




void CplabLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  cplablexerLexerInitialize();
#else
  ::antlr4::internal::call_once(cplablexerLexerOnceFlag, cplablexerLexerInitialize);
#endif
}
