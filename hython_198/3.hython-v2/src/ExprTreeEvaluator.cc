/*************************************************************************
	> File Name: main.cpp
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年08月24日 星期一 09时53分59秒
 ************************************************************************/
#include <cassert>
#include <ExprTreeEvaluator.h>
#include <AST.h>
#include <string>
#include <iostream>
#include <memory>
#include <parameter.h>
#include <single.h>

namespace haizei {

ExprTreeEvaluator::ExprTreeEvaluator() {}

int ExprTreeEvaluator::run(haizei::ASTNode tree) {
    std::shared_ptr<Parameter> p = std::make_shared<Parameter>();
    return MasterChainSingle::run(tree, p);
}

} //end of haizei

