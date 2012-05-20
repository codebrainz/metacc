#include "MetaCLexer.h"
#include "MetaCParser.h"

int main(int argc, char *argv[])
{

  pANTLR3_INPUT_STREAM input;
  pMetaCLexer lex;
  pANTLR3_COMMON_TOKEN_STREAM tokens;
  pMetaCParser parser;

  input = antlr3FileStreamNew((pANTLR3_UINT8)argv[1], ANTLR3_ENC_UTF8);
  lex = MetaCLexerNew(input);
  tokens = antlr3CommonTokenStreamSourceNew(ANTLR3_SIZE_HINT, TOKENSOURCE(lex));
  parser = MetaCParserNew(tokens);

  parser->expr(parser);

  parser->free(parser);
  tokens->free(tokens);
  lex->free(lex);
  input->close(input);

  return 0;
}
