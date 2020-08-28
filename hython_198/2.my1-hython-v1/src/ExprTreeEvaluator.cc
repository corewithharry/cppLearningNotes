/*************************************************************************
	> File Name: ExprTreeEvaluator.cpp
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年08月27日 星期四 14时21分30秒
 ************************************************************************/
#include <ExprTreeEvaluator.h>

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

int ExprTreeEvaluator::run(pANTLR3_BASE_TREE tree)
{
    pANTLR3_COMMON_TOKEN tok = tree->getToken(tree);
    if(tok) {
        switch(tok->type) {
        case INT: {
            const char* s = getText(tree);
            if(s[0] == '~') {
                return -atoi(s+1);
            }
            else {
                return atoi(s);
            }
        }
        case ID: {
            string var(getText(tree));
            return get_param(var);
        }
        case PLUS:
            return run(getChild(tree,0)) + run(getChild(tree,1));
        case MINUS:
            return run(getChild(tree,0)) - run(getChild(tree,1));
        case TIMES:
            return run(getChild(tree,0)) * run(getChild(tree,1));
        case DIV:
            return run(getChild(tree,0)) / run(getChild(tree,1));
        case MOD:
            return run(getChild(tree,0)) % run(getChild(tree,1));
        case BLOCK: {
            ExprTreeEvaluator new_this(this);
            int k = tree->getChildCount(tree);
            for (int i = 0; i < k; i++) {
                int val = new_this.run(getChild(tree, i));
                cout << "Block Value : " << val << endl;
            }
            return 0;
        }
        
        case PRINT: {
            int k = tree->getChildCount(tree);
            int val = 0;
            for (int i = 0; i < k; i++) {
                pANTLR3_BASE_TREE child = getChild(tree, i);
                string var(getText(child));
                val = this->run(child);
                //cout << "print: " << var << " = " << val << endl;
                cout << val << endl;
            }
            return val;
        }

        case IF : {
            int condition = run(getChild(tree, 0));
            if (condition) {
                return run(getChild(tree, 1));
            } else {
                if (tree->getChildCount(tree) == 3) {
                    return run(getChild(tree, 2));
                } else return 0;
            }
        }
        case OR : {
            int left = run(getChild(tree, 0));
            if (tree->getChildCount(tree) == 1) {
                return left;
            }
            int right = run(getChild(tree, 1));
            return (left || right);
        }
        case AND : {
            int left = run(getChild(tree, 0));
            if (tree->getChildCount(tree) == 1) {
                return left;
            }
            int right = run(getChild(tree, 1));
            return (left && right);
        }
        case GE : {
            int left = run(getChild(tree, 0));
            if (tree->getChildCount(tree) == 1) {
                return left;
            }
            int right = run(getChild(tree, 1));
            return (left >= right);
        }
        case NE : {
            int left = run(getChild(tree, 0));
            if (tree->getChildCount(tree) == 1) {
                return left;
            }
            int right = run(getChild(tree, 1));
            return (left != right);
        }
        case LITTLE : {
            int left = run(getChild(tree, 0));
            if (tree->getChildCount(tree) == 1) {
                return left;
            }
            int right = run(getChild(tree, 1));
            return (left < right);
        }
        case LE : {
            int left = run(getChild(tree, 0));
            if (tree->getChildCount(tree) == 1) {
                return left;
            }
            int right = run(getChild(tree, 1));
            return (left <= right);
        }
        case GT : {
            int left = run(getChild(tree, 0));
            if (tree->getChildCount(tree) == 1) {
                return left;
            }
            int right = run(getChild(tree, 1));
            return (left > right);
        }
        case EQ : {
            int left = run(getChild(tree, 0));
            if (tree->getChildCount(tree) == 1) {
                return left;
            }
            int right = run(getChild(tree, 1));
            return (left == right);
        }

        case FOR : {
            
        }
        case WHILE : {

        }
        case DOWHILE : {

        }

        
        case DEF: {
            int k = tree->getChildCount(tree);
            int init_val = 0;
            for (int i = 0; i < k; i++) {
                pANTLR3_BASE_TREE child = getChild(tree, i);
                string var(getText(child));
                init_val = 0;
                if (child->getChildCount(child) == 1) {
                    init_val = run(getChild(child, 0));
                }
                cout << "def param val : " << var << " = " << init_val << endl;
                this->def_param(var, init_val);
            }
            return init_val;
        } break;
        case ASSIGN: {
            string var(getText(getChild(tree,0)));
            get_param(var);
            int val = run(getChild(tree,1));
            set_param(var, val);
            return val;
        }
        default:
            cout << "Unhandled token: #" << tok->type << '\n';
            return -1;
        }
    } else {
        int k = tree->getChildCount(tree);
        int r = 0;
        for(int i = 0; i < k; i++) {
            r = run(getChild(tree, i));
            cout << "Evaluator result: " << r << endl;
        }
        return r;
    }
    return 0;
}

pANTLR3_BASE_TREE getChild(pANTLR3_BASE_TREE tree, unsigned i) {
    assert(i < tree->getChildCount(tree));
    return (pANTLR3_BASE_TREE) tree->getChild(tree, i);
}

const char* getText(pANTLR3_BASE_TREE tree) {
    return (const char*) tree->getText(tree)->chars;
}

