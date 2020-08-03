/*************************************************************************
	> File Name: 20.inherit_problem.cpp
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年08月03日 星期一 14时39分39秒
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


struct A {
    int x;
};

struct B : virtual public A {
    //加virtual, 虚拟继承, 解决指代不明
    void set(int x) {
        this->x = x;
        cout << "set : " << &this->x << endl;
    }
};

struct C : virtual public A {
    int get() {
        return this->x;
        cout << "get : " << &this->x << endl;
    }  
};

struct D : public B, public C {};


int main() {
    D d;
    cout << sizeof(d) << endl;

    //如果只是普通的多重继承，下面的set和get作用的其实不是同一个x
    //d的存储区中一部分存B的信息，一部分存C的信息，因此两方法作用的x不是同一个
    //这就是指代不明
    //解决：让B,C虚拟继承A
    //实际工作中不提倡多重继承
    d.set(8875);
    cout << d.get() << endl;
    return 0;
}
