/*************************************************************************
	> File Name: master.h
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年09月02日 星期三 10时09分08秒
 ************************************************************************/

#ifndef _MASTER_H
#define _MASTER_H
#include <AST.h>
#include <memory>
#include <parameter.h>

namespace haizei {
//这些Master负责处理不同的块，主要就是负责运行相应的块
class IMaster {
public:
    virtual int run(ASTNode &, std::shared_ptr<Parameter> &) = 0;
};

class ExprMaster : public IMaster {
public:
    virtual int run(ASTNode &, std::shared_ptr<Parameter> &);
};


class ControBlockMaster : public IMaster {
public:
    virtual int run(ASTNode &, std::shared_ptr<Parameter> &);
};


class ControNoBlockMaster : public IMaster {
public:
    virtual int run(ASTNode &, std::shared_ptr<Parameter> &);
};


class PrintMaster : public IMaster {
public:
    virtual int run(ASTNode &, std::shared_ptr<Parameter> &);
};

}
#endif
