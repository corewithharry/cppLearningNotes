/*************************************************************************
	> File Name: 17.inherit_constructor.cpp
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年07月28日 星期二 19时55分36秒
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

class D {
 public:
    D() { cout << "D constructor" << endl; }
    ~D() {
        cout << "D destructor" << endl;
    }
};


class A {
 public:
    A() = delete;
    A(int x, int y) { cout << "A constructor" << endl; }
    ~A() {
        cout << "A destructor" << endl;
    }
};

class B {
 public:
    B() { cout << "B constructor" << endl; }
    ~B() {
        cout << "B destructor" << endl;
    }
};

class C : public D {
 public:
    C() : a(3, 4), b() { cout << "C constructor" << endl; } //显示的写出来初始化列表
    ~C() {
        cout << "C destructor" << endl;
    }
 private:
    B b;
    A a;
};


int main() {
    C c;
    return 0;
}
