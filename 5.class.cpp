/*************************************************************************
	> File Name: 5.class.cpp
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年07月25日 星期六 16时20分44秒
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

class  People {
    friend int main(); //友元函数
    int x, y;
public:
    void set(int x);
    void say();
};

struct People2 {
    int x, y;
};

void People::set(int x) {
    cout << "set function: " << this << endl;
    this->x = x;
    return ;
} 

void People::say() {
    cout << x << " " << y << endl;
    return ;
}


int main() {
    People a;
    People2 b;
    a.set(3);
    a.y = 18432;
    a.say();
    cout << "a object: " << &a << endl;
    b.x = 4;
    cout << b.x << endl;
    return 0;
}
