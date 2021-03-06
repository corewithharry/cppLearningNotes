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
#include <Chain.h>

ExprTreeEvaluator::ExprTreeEvaluator() : next(nullptr) {}
ExprTreeEvaluator::ExprTreeEvaluator(ExprTreeEvaluator *next) : next(next) {}

void ExprTreeEvaluator::def_param(std::string name, int val) {
    if (memory.find(name) != memory.end()) {
        #ifdef DEBUG
        for (auto x : memory) {
            std::cout << "debug log(memory): " << x.first << " " << x.second << std::endl;
        }
        #endif
        throw std::runtime_error("param redefined : " + name);
    }
    memory[name] = val;
    return ;
}

void ExprTreeEvaluator::set_param(std::string name, int val) {
    if (memory.find(name) == memory.end()) {
        if (this->next) {
            this->next->set_param(name, val);
            return ;
        }
        throw std::runtime_error("unknown redefined : " + name);
    }
    memory[name] = val;
    return ;
}

int ExprTreeEvaluator::get_param(std::string name) {
    if (memory.find(name) == memory.end()) {
        if (this->next) return this->next->get_param(name);
        throw std::runtime_error("unknown param : " + name);
    }
    return memory[name];
}

int ExprTreeEvaluator::run(haizei::ASTNode tree) {
    int t = 0;
    if (tree.hasToken()) {
        for (Handler *p = ChainMaster::getSingleChain(); p; p = p->next) {
            if (p->isValid(tree.type())) {
                t = p->do_it(tree, this);
                break;
            }
        }
        for (int i = 0; i < tree.size(); i++) {
            t = run(tree[i]);
        }
    } else {
        int k = tree.size();
        for(int i = 0; i < k; i++) {
            t = run(tree[i]);
        }
        // for (int i = 0; i < tree.size(); i++) {
        //     for (Handler *p = ChainMaster::getSingleChain(); p; p = p->next) {
        //         if (p->isValid(tree[i].type())) {
        //             // std::cout << "run before" << p << std::endl;
        //             int t = p->do_it(tree[i], this);
        //             // std::cout << "run end" << std::endl;
        //             return t;
        //         }
        //     }
        // }
    }
    
    /*
    if(tree.hasToken()) {
        switch(tree.type()) {
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
        case BLOCK: {
            ExprTreeEvaluator new_this(this);
            int k = tree.size();
            for (int i = 0; i < k; i++) {
                int val = new_this.run(tree[i]);
                //std::cout << "Block Value : " << val << std::endl;
            }
            return 0;
        } break;
        case PRINT: {
            for (int i = 0; i < tree.size(); i++) {
                i && std::cout << " ";
                std::cout << run(tree[i]);
            }
            std::cout << std::endl;
            return 0;
        } break;
        case DEF: {
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
        } break;
        case OR: return run(tree[0]) || run(tree[1]);
        case AND: return run(tree[0]) && run(tree[1]);
        case GT: return run(tree[0]) > run(tree[1]);
        case LITTLE: return run(tree[0]) < run(tree[1]);
        case EQ: return run(tree[0]) == run(tree[1]);
        case GE: return run(tree[0]) >= run(tree[1]);
        case LE: return run(tree[0]) <= run(tree[1]);
        case NE: return run(tree[0]) != run(tree[1]);
        case IF: {
            if (run(tree[0])) {
                run(tree[1]);
            } else if (tree.size() == 3) {
                run(tree[2]);
            }
            return 0;
        }
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
            std::cout << "Unhandled token: #" << tree.type() << '\n';
            return -1;
        }
    } else {
        int k = tree.size();
        int r = 0;
        for(int i = 0; i < k; i++) {
            r = run(tree[i]);
            //std::cout << "Evaluator result: " << r << std::endl;
        }
        return r;
    }
    */
    return t;
}
