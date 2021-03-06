/*************************************************************************
	> File Name: main.cpp
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年08月24日 星期一 09时53分59秒
 ************************************************************************/
#include <hythonLexer.h>
#include <hythonParser.h>
#include <cassert>
#include <map>
#include <string>
#include <iostream>
#include <AST.h>
using std::map;
using std::string;
using std::cout;
using std::endl;


class ExprTreeEvaluator {
    map<string,int> memory;
public:
    ExprTreeEvaluator() : next(nullptr) {}
    ExprTreeEvaluator(ExprTreeEvaluator *next) : next(next) {}
    int run(haizei::ASTNode);
    void def_param(string, int);
    void set_param(string, int);
    int get_param(string);
    ExprTreeEvaluator *next;
};


int main(int argc, char* argv[]) {
    assert(argc > 1);
    haizei::ASTNode tree(argv[1]);

    ExprTreeEvaluator eval;
    int rr = eval.run(tree);
    cout << "Evaluator result: " << rr << '\n';
    tree.destroy();
    return 0;
}


void ExprTreeEvaluator::def_param(string name, int val) {
    if (memory.find(name) != memory.end()) {
        #ifdef DEBUG
        for (auto x : memory) {
            cout << "debug log(memory): " << x.first << " " << x.second << endl;
        }
        #endif
        throw std::runtime_error("param redefined : " + name);
    }
    memory[name] = val;
    return ;
}


void ExprTreeEvaluator::set_param(string name, int val) {
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


int ExprTreeEvaluator::get_param(string name) {
    if (memory.find(name) == memory.end()) {
        if (this->next) return this->next->get_param(name);
        throw std::runtime_error("unknown param : " + name);
    }
    return memory[name];
}


int ExprTreeEvaluator::run(haizei::ASTNode tree) {
    if(tree.hasToken()) {
        switch(tree.type()) {
        case INT: {
            string s = tree.text();
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
                cout << "Block Value : " << val << endl;
            }
            return 0;
        }

        case PRINT: {
            for (int i = 0; i < tree.size(); i++) {
                cout << run(tree[i]) << endl;
            }
            return 0;
        }
        case GT: 
            return run(tree[0]) > run(tree[1]);
        case LITTLE: 
            return run(tree[0]) < run(tree[1]);
        case EQ: 
            return run(tree[0]) == run(tree[1]);
        case GE: 
            return run(tree[0]) >= run(tree[1]);
        case LE: 
            return run(tree[0]) <= run(tree[1]);
        case NE: 
            return run(tree[0]) == run(tree[1]);
        case AND:
            return run(tree[0]) && run(tree[1]);
        case OR:
            return run(tree[0]) || run(tree[1]);
        
        case IF: {
            if (run(tree[0])) {
                return run(tree[1]);
            } else {
                if (tree.size() == 3) {
                    return run(tree[2]);
                }
            }
            return 0;
        }
        case FOR: {
            ExprTreeEvaluator new_this(this);
            new_this.run(tree[0]);
            while (new_this.run(tree[1])) {
                new_this.run(tree[2]);
                new_this.run(tree[3]);
            }
        }
        case WHILE: {
            ExprTreeEvaluator new_this(this);
            while (new_this.run(tree[0])) {
                new_this.run(tree[1]);
            }
        }
        case DOWHILE: {
            ExprTreeEvaluator new_this(this);
            do {
                new_this.run(tree[1]);
            } while (new_this.run(tree[0]));
        }



        case DEF: {
            int k = tree.size();
            int init_val = 0;
            for (int i = 0; i < k; i++) {
                string var(tree[i].text());
                init_val = 0;
                if (tree[i].size() == 1) {
                    init_val = run(tree[i][0]);
                }
                cout << "def param val : " << var << " = " << init_val << endl;
                this->def_param(var, init_val);
            }
            return init_val;
        } break;
        case ASSIGN: {
            string var(tree[0].text());
            get_param(var);
            int val = run(tree[1]);
            set_param(var, val);
            return val;
        }
        default:
            cout << "Unhandled token: #" << tree.type() << '\n';
            return -1;
        }
    } else {
        int k = tree.size();
        int r = 0;
        for(int i = 0; i < k; i++) {
            r = run(tree[i]);
            cout << "Evaluator result: " << r << endl;
        }
        return r;
    }
    return 0;
}

