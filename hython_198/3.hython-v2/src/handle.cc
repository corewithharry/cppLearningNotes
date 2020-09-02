#include <handle.h>
#include <master.h>
#include <AST.h>

namespace haizei {

IHandle::IHandle(IHandle *next) : __next(next) {}
ExprHandle::ExprHandle(IHandle *next) : IHandle(next) {}
ControBlockHandle::ControBlockHandle(IHandle *next) : IHandle(next) {}
ControNoBlockHandle::ControNoBlockHandle(IHandle *next) : IHandle(next) {}
PrintHandle::PrintHandle(IHandle *next) : IHandle(next) {}

IHandle *IHandle::next() const { return __next; }



std::shared_ptr<IMaster> ExprHandle::getMaster() const {
    return std::make_shared<ExprMaster>();
}
std::shared_ptr<IMaster>  ControBlockHandle::getMaster() const {
    return std::make_shared<ControBlockMaster>();
}
std::shared_ptr<IMaster> ControNoBlockHandle::getMaster() const {
    return std::make_shared<ControNoBlockMaster>();
}
std::shared_ptr<IMaster> PrintHandle::getMaster() const {
    return std::make_shared<PrintMaster>();
}



bool ExprHandle::Test(const ASTNode &n) const {
    switch (n.type()) {
        case DEF:
        case INT:
        case ID:
        case PLUS:
        case MINUS:
        case TIMES:
        case DIV:
        case MOD:
        case OR:
        case AND:
        case GT:
        case LITTLE:
        case EQ: 
        case GE: 
        case LE: 
        case NE: 
        case ASSIGN: return true;
    }
    return false;
}

bool ControBlockHandle::Test(const ASTNode &n) const {
    switch(n.type()) {
        case FOR: 
        case BLOCK: return true;
    }
    return false;
}
bool ControNoBlockHandle::Test(const ASTNode &n) const {
    switch(n.type()) {
        case IF:
        case WHILE:
        case DOWHILE: return true;
    }
    return false;
}

bool PrintHandle::Test(const ASTNode &n) const  {
    switch (n.type()) {
        case PRINT: return true;
    }
    return false;
}

}
