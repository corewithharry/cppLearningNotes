/*************************************************************************
	> File Name: 26.final.cpp
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年08月02日 星期日 19时49分20秒
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


class A : public map<int, int> {
 public:
    virtual void say() {
        cout << "Claa A : hello world" << endl;
    }
};


class B final : public A {
    //加上final, 此类不能再被继承
 public:
    void say() final override {
        //加上final, 子类就不能在重写此方法
        cout << "Class B : hell world" << endl;
    }
};

/*
class C : public B {
 public:
    //void say() {
    //    cout <, "Class B : hell world" << endl;
    //}
};
*/


int main() {
    A a;
    a[55] = 569;
    a[215] = 545;
    for (auto x : a) {
        cout << x.first << " " << x.second << endl;
    }
    cout << endl;
    return 0;
}
