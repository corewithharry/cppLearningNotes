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

namespace haizei {

class ExprTreeEvaluator {
public:
	ExprTreeEvaluator();
	int run(haizei::ASTNode);
};

}

#endif
