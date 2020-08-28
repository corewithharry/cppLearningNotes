/*************************************************************************
	> File Name: ExprTreeEvaluator.h
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年08月27日 星期四 14时18分23秒
 ************************************************************************/

#ifndef _EXPRTREEEVALUATOR_H
#define _EXPRTREEEVALUATOR_H

#include <hythonLexer.h>
#include <hythonParser.h>
#include <cassert>
#include <map>
#include <string>
#include <iostream>
using std::map;
using std::string;
using std::cout;
using std::endl;

class ExprTreeEvaluator {
    map<string,int> memory;
public:
    ExprTreeEvaluator() : next(nullptr) {}
    ExprTreeEvaluator(ExprTreeEvaluator *next) : next(next) {}
    int run(pANTLR3_BASE_TREE);
    void def_param(string, int);
    void set_param(string, int);
    int get_param(string);
    ExprTreeEvaluator *next;
};
pANTLR3_BASE_TREE getChild(pANTLR3_BASE_TREE, unsigned);
const char* getText(pANTLR3_BASE_TREE tree);

#endif
