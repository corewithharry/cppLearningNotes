#include <AST.h>
#include <master.h>
#include <single.h>
#include <iostream>
#include <stdexcept>

namespace haizei {

int ExprMaster::run(ASTNode &node, std::shared_ptr<Parameter> &p) {
    #define BOP(op)  MasterChainSingle::run(node[0], p) op MasterChainSingle::run(node[1], p)
    #define MR(a, b) MasterChainSingle::run(a, b)
    switch(node.type()) {
        case DEF: {
            int k = node.size();
            int init_val = 0;
            for (int i = 0; i < k; i++) {
                std::string var(node[i].text());
                init_val = 0;
                if (node[i].size() == 1) {
                    init_val = MR(node[i][0], p);
                }
                //std::cout << "def param val : " << var << " = " << init_val << std::endl;
                p->def_param(var, init_val);
            }
            return init_val;
        }
        case INT: {
            std::string s = node.text();
            if(s[0] == '-') {
                return -atoi(s.c_str() + 1);
            }
            else {
                return atoi(s.c_str());
            }
        }
        case ID: {
            return p->get_param(node.text());
        }
        case PLUS: return BOP(+);
        case MINUS: return BOP(-);
        case TIMES: return BOP(*);
        case DIV: return BOP(/);
        case MOD: return BOP(%);
        case OR: return BOP(||);
        case AND: return BOP(&&);
        case GT: return BOP(>);
        case LITTLE: return BOP(<);
        case EQ: return BOP(==);
        case GE: return BOP(>=);
        case LE: return BOP(<=);
        case NE: return BOP(!=);
        case ASSIGN: {
            std::string var(node[0].text());
            p->get_param(var);
            int val = MR(node[1], p);
            p->set_param(var, val);
            return val;
        }
    }
    #undef MR
    #undef BOP
    throw std::runtime_error(
        std::string(typeid(*this).name()) 
        + "Unhandled token: #" 
        + std::to_string(node.type())
    );
    return 0;
}


int ControBlockMaster::run(ASTNode &tree, std::shared_ptr<Parameter> &p) {
    #define MR(a, b) MasterChainSingle::run(a, b)
    std::shared_ptr<Parameter> newp = std::make_shared<Parameter>(p);
    switch (tree.type()) {
        case FOR: {
            for(MR(tree[0], newp); MR(tree[1], newp); MR(tree[2], newp)) {
                MR(tree[3], newp);
            }
            return 0;
        } break;
        case BLOCK: {
            for (int i = 0; i < tree.size(); i++) {
                int val = MR(tree[i], newp);
            }
            return 0;
        } break;
    }
    #undef MR
    throw std::runtime_error(
        std::string(typeid(*this).name()) + 
        " Unhandled token: #" + 
        std::to_string(tree.type())
    );
    return 0;
}


int ControNoBlockMaster::run(ASTNode &tree, std::shared_ptr<Parameter> &p) {
    #define MR(a, b) MasterChainSingle::run(a, b)
    switch (tree.type()) {
        case IF: {
            if (MR(tree[0], p)) {
                MR(tree[1], p);
            } else if (tree.size() == 3) {
                MR(tree[2], p);
            }
            return 0;
        }
        case WHILE: {
            while (MR(tree[0], p)) {
                MR(tree[1], p);
            }
            return 0;
        }
        case DOWHILE: {
            do {
                MR(tree[1], p);
            } while (MR(tree[0], p));
            return 0;
        }
    }
    throw std::runtime_error(
        std::string(typeid(*this).name()) + 
        " Unhandled token: #" + 
        std::to_string(tree.type())
    );
    #undef MR
    return 0;
}

int PrintMaster::run(ASTNode &tree, std::shared_ptr<Parameter> &p) {
    #define MR(a, b) MasterChainSingle::run(a, b)
    switch (tree.type()) {
        case PRINT:
            for (int i = 0; i < tree.size(); i++) {
                i && std::cout << " ";
                std::cout << MR(tree[i], p);
            }
    }
    std::cout << std::endl;
    #undef MR
    return 0;
}

}
