/*************************************************************************
	> File Name: main.cpp
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年08月24日 星期一 09时53分59秒
 ************************************************************************/
#include <ExprTreeEvaluator.h>

int main(int argc, char* argv[]) {
  pANTLR3_INPUT_STREAM input;
  phythonLexer lex;
  pANTLR3_COMMON_TOKEN_STREAM tokens;
  phythonParser parser;

  assert(argc > 1);
  input = antlr3FileStreamNew((pANTLR3_UINT8)argv[1],ANTLR3_ENC_8BIT);
  lex = hythonLexerNew(input);
  tokens = antlr3CommonTokenStreamSourceNew(ANTLR3_SIZE_HINT, TOKENSOURCE(lex));
  parser = hythonParserNew(tokens);

  hythonParser_prog_return r = parser->prog(parser);
  pANTLR3_BASE_TREE tree = r.tree;

  ExprTreeEvaluator eval;
  int rr = eval.run(tree);
  cout << "Evaluator result: " << rr << '\n';

  parser->free(parser);
  tokens->free(tokens);
  lex->free(lex);
  input->close(input);

  return 0;
}
