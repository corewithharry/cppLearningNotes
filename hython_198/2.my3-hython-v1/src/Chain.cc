/*************************************************************************
	> File Name: Chain.cpp
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年08月29日 星期六 16时25分40秒
 ************************************************************************/
#include <Chain.h>
#include <AST.h>
#include <iostream>
#include <ExprTreeEvaluator.h>


Handler::Handler() : next(nullptr) {}

bool PrintHandle::isValid(int type) {
    return type == PRINT;
}
int PrintHandle::do_it(haizei::ASTNode tree, ExprTreeEvaluator *expr) {
    for (int i = 0; i < tree.size(); i++) {
        i && std::cout << " ";
        std::cout << run(tree[i]);
    }
    std::cout << std::endl;
    return 0;
}


bool IdHandle::isValid(int type) {
    return type == ID;
}
int IdHandle::do_it(haizei::ASTNode tree, ExprTreeEvaluator *expr) {
    return get_param(tree.text());
}

bool DefHandle::isValid(int type) {
    return type == DEF;
}
int DefHandle::do_it(haizei::ASTNode tree, ExprTreeEvaluator *expr) {
    int k = tree.size();
    int init_val = 0;
    for (int i = 0; i < k; i++) {
        std::string var(tree[i].text());
        init_val = 0;
        if (tree[i].size() == 1) {
            init_val = run(tree[i][0]);
        }
        //std::cout << "def param val : " << var << " = " << init_val << std::endl;
        this->def_param(var, init_val);
    }
    return init_val;
}

bool ExprHandle::isValid(int type) {
    switch (type) {
        case INT:
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
        case ASSIGN: return 1;
        default:
            return 0;
            break;
    }
}
int ExprHandle::do_it(haizei::ASTNode tree, ExprTreeEvaluator *expr) {
    switch (tree.type()) {
        case INT: {
            std::string s = tree.text();
            if(s[0] == '~') {
                return -atoi(s.c_str() + 1);
            }
            else {
                return atoi(s.c_str());
            }
        }
        case ID: {
            return get_param(tree.text());
        }
        case PLUS:
            return run(tree[0]) + run(tree[1]);
        case MINUS:
            return run(tree[0]) - run(tree[1]);
        case TIMES:
            return run(tree[0]) * run(tree[1]);
        case DIV:
            return run(tree[0]) / run(tree[1]);
        case MOD:
            return run(tree[0]) % run(tree[1]);
        
        case OR: return run(tree[0]) || run(tree[1]);
        case AND: return run(tree[0]) && run(tree[1]);
        case GT: return run(tree[0]) > run(tree[1]);
        case LITTLE: return run(tree[0]) < run(tree[1]);
        case EQ: return run(tree[0]) == run(tree[1]);
        case GE: return run(tree[0]) >= run(tree[1]);
        case LE: return run(tree[0]) <= run(tree[1]);
        case NE: return run(tree[0]) != run(tree[1]);
        case ASSIGN: {
            std::string var(tree[0].text());
            get_param(var);
            int val = run(tree[1]);
            set_param(var, val);
            return val;
        }
        default:
            break;
    }
    return 0;
}

bool BlockHandle::isValid(int type) {
    switch (type) {
        case BLOCK:
        case FOR:
        case WHILE:
        case DOWHILE: return 1;
        default:
            return 0;
            break;
    }
}
int BlockHandle::do_it(haizei::ASTNode tree, ExprTreeEvaluator *expr) {
    switch (tree.type()) {
        case BLOCK: {
            ExprTreeEvaluator new_this(this);
            int k = tree.size();
            for (int i = 0; i < k; i++) {
                int val = new_this.run(tree[i]);
                //std::cout << "Block Value : " << val << std::endl;
            }
            return 0;
        } break;
        case FOR: {
            ExprTreeEvaluator new_this(this);
            for (new_this.run(tree[0]); new_this.run(tree[1]); new_this.run(tree[2])) {
                new_this.run(tree[3]);
            }
            return 0;
        }
        case WHILE: {
            while (run(tree[0])) {
                run(tree[1]);
            }
            return 0;
        } 
        case DOWHILE: {
            do {
                run(tree[1]);
            } while (run(tree[0]));
            return 0;
        }
        case ASSIGN: {
            std::string var(tree[0].text());
            get_param(var);
            int val = run(tree[1]);
            set_param(var, val);
            return val;
        }
        default:
            break;
    }
    return 0;
}


Handler *ChainMaster::head = nullptr;
Handler *ChainMaster::getSingleChain() {
    if (head == nullptr) {
        head = new PrintHandle();
        head->next = new IdHandle();
        head->next->next = new DefHandle();
        head->next->next->next = new ExprHandle();
        head->next->next->next->next = new BlockHandle(); 
    }
    return head;
}
