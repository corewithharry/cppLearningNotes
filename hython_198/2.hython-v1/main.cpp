/*************************************************************************
	> File Name: main.cpp
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年08月24日 星期一 09时53分59秒
 ************************************************************************/
#include <hythonLexer.h>
#include <hythonParser.h>
#include <cassert>
#include <map>
#include <string>
#include <iostream>
#include <AST.h>
#include <ExprTreeEvaluator.h>

int main(int argc, char* argv[]) {
    assert(argc > 1);
    haizei::ASTNode tree(argv[1]);

    ExprTreeEvaluator eval;
    int rr = eval.run(tree);
    //std::cout << "Evaluator result: " << rr << '\n';
    tree.destroy();
    return 0;
}