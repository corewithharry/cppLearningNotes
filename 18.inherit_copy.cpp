/*************************************************************************
	> File Name: 18.inherit_copy.cpp
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年07月28日 星期二 20时45分14秒
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
    A() {
        cout << "class A constructor" << endl;
        this->x = 0x01020304;
    }
    A(const A &a) {
        cout << "class A copy constructor" << this << endl;
    }
    int x;
};

class B : public A {
 public:
    B() {
        this->y = 0x05060708;
        cout << "class B constructor" << endl;
    }
    B(const B &b) : A(b) {
        //要显示的调用父类的构造，否则默认是调用默认构造
        cout << "class B copy constructor" << this << endl;
    }
    int y;
};


int main() {
    B b1;
    B b2(b1);
    const char *msg = (const char *)(&b1);
    for (int i = 0; i < sizeof(B); i++) {
        printf("%X", msg[i]);
    }
    cout << endl;
    return 0;
}
