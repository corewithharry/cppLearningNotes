/*************************************************************************
	> File Name: Chain.h
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年08月29日 星期六 16时24分24秒
 ************************************************************************/

#ifndef _CHAIN_H
#define _CHAIN_H

#include <AST.h>
#include <ExprTreeEvaluator.h>

class Handler :  public ExprTreeEvaluator {
public:
    Handler();
    virtual bool isValid(int) = 0;
    virtual int do_it(haizei::ASTNode, ExprTreeEvaluator*) = 0;
    Handler *next;
};

class PrintHandle : public Handler {
public:
    // printHandle();
    bool isValid(int);
    int do_it(haizei::ASTNode, ExprTreeEvaluator *);
};

class IdHandle : public Handler {
public:
    // idHandler();
    bool isValid(int);
    int do_it(haizei::ASTNode, ExprTreeEvaluator*);
};

class DefHandle : public Handler {
public:
    bool isValid(int);
    int do_it(haizei::ASTNode, ExprTreeEvaluator*);
};

class ExprHandle : public Handler {
public:
    // exprHandle();
    bool isValid(int);
    int do_it(haizei::ASTNode, ExprTreeEvaluator*);
};

class BlockHandle : public Handler {
public:
    // blockHandle();
    bool isValid(int);
    int do_it(haizei::ASTNode, ExprTreeEvaluator*);
};

class ChainMaster {
public:
    static Handler *getSingleChain();   
private:
    static Handler *head;
};


#endif
