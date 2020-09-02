/*************************************************************************
	> File Name: handle.h
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年09月02日 星期三 09时28分02秒
 ************************************************************************/

#ifndef _HANDLE_H
#define _HANDLE_H
#include <AST.h>
#include <memory>
#include <master.h>

namespace haizei {

class IHandle {
public:
	IHandle(IHandle *);
    virtual bool Test(const ASTNode &) const = 0;
    virtual std::shared_ptr<IMaster> getMaster() const = 0;
	IHandle *next() const;
private:
	IHandle *__next;
};

class ExprHandle : public IHandle {
public:
	ExprHandle(IHandle *);
    bool Test(const ASTNode &) const;
	virtual std::shared_ptr<IMaster> getMaster() const;
};

class ControBlockHandle : public IHandle {
public:
	ControBlockHandle(IHandle *);
    bool Test(const ASTNode &) const;
	virtual std::shared_ptr<IMaster> getMaster() const;
};

class ControNoBlockHandle : public IHandle {
public:
	ControNoBlockHandle(IHandle *);
    bool Test(const ASTNode &) const;
	virtual std::shared_ptr<IMaster> getMaster() const;
};

class PrintHandle : public IHandle {
public:
	PrintHandle(IHandle *);
    bool Test(const ASTNode &) const;
	virtual std::shared_ptr<IMaster> getMaster() const;
};

}
#endif
