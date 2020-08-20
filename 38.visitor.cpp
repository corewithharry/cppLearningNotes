/*************************************************************************
	> File Name: 38.visitor.cpp
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年08月17日 星期一 17时32分58秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

class B;
class C;
class D;
class E;

class A {
public:
    class IVisitor {
    public:
        virtual void visit(B *) = 0;
        virtual void visit(C *) = 0;
        virtual void visit(D *) = 0;
        virtual void visit(E *) = 0;
    };
    virtual void Accept(IVisitor *) = 0;
    virtual ~A() {}
};

class B : public A {
public:
    void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};
class C : public A {
public:
    void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};

class D : public A {
public:
    void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};
class E : public A {
public:
    void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};


class OutputVisitor : public A::IVisitor {
    virtual void visit(A *obj) {
        cout << "class A father" << endl;
    }
    virtual void visit(B *obj) {
        cout << "class B object" << endl;
    }
    virtual void visit(C *obj) {
        cout << "class C object" << endl;
    }
    virtual void visit(D *obj) {
        cout << "class D object" << endl;
    }
    virtual void visit(E *obj) {
        cout << "class E object" << endl;
    }
};



int main() {
    A *arr[10];
    for (int i = 0; i < 10; i++) {
        switch (rand() % 4) {
            case 0: arr[i] = new B(); break;
            case 1: arr[i] = new C(); break;
            case 2: arr[i] = new D(); break;
            case 3: arr[i] = new E(); break;
        }
    }
    OutputVisitor vis;
    for (int i = 0; i < 10; i++) {
        arr[i]->Accept(&vis);
    }

    return 0;
}
