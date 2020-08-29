/*************************************************************************
	> File Name: ExprTreeEvaluator.h
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年08月29日 星期六 09时12分17秒
 ************************************************************************/

#ifndef _EXPRTREEEVALUATOR_H
#define _EXPRTREEEVALUATOR_H

#include <AST.h>
#include <string>
#include <map>

class ExprTreeEvaluator {
public:
    ExprTreeEvaluator();
    ExprTreeEvaluator(ExprTreeEvaluator *);
    int run(haizei::ASTNode);
    void def_param(std::string, int);
    void set_param(std::string, int);
    int get_param(std::string);
    ExprTreeEvaluator *next;

private:
    std::map<std::string,int> memory;
};

#endif
