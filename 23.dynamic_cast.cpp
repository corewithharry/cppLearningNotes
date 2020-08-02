/*************************************************************************
	> File Name: 23.dynamic_cast.cpp
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年08月01日 星期六 20时26分51秒
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

class A {
 public:
    virtual ~A() {}
 private:
    
};

class B : public A {
 public:
    void sayB() {
        cout << "this is class B, x = " << x << endl;
    }
    int x;
};

class C : public A {
 public:
    void sayC() {
        cout << "this is class C, x =" << x << endl;
    }
    double x;
};

class D : public A {
 public:
    void sayD() {
        cout << "this is class D, x =" << x << endl;
    }
    string x;
};

int my_dynamic_cast(A *ta) {
    char **pa = (char **)(ta);
    char **pb = (char **)(new B());
    char **pc = (char **)(new C());
    char **pd = (char **)(new D());
    int ret = -1;
    if (pa[0] == pb[0]) ret = 0;
    else if (pa[0] == pc[0]) ret = 1;
    else if (pa[0] == pd[0]) ret = 2;
    return ret;
}


int main() {
    srand(time(0));
    A *pa;
    B *pb;
    C *pc;
    D *pd;
    switch (rand() % 3) {
        case 0: pb = new B(); pa = pb; pb->x = 254; break;
        case 1: pc = new C(); pa = pc; pc->x = 565.5; break;
        case 2: pd = new D(); pa = pd; pd->x = "hell world"; break;
    }
    if ((pb = dynamic_cast<B *>(pa))) {
        //转换失败返回NULL;
        cout << "class B :";
        pb->sayB();
    } else if ((pc = dynamic_cast<C *>(pa))) {
        cout << "class C :";
        pc->sayC();
    } else if ((pd = dynamic_cast<D *>(pa))) {
        cout << "class D :";
        pd->sayD();
    }
    switch (my_dynamic_cast(pa)) {
        case 0: ((B *)(pa))->sayB(); break;
        case 1: ((C *)(pa))->sayC(); break;
        case 2: ((D *)(pa))->sayD(); break;
    }
    return 0;
}
