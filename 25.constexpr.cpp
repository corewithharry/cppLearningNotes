/*************************************************************************
	> File Name: 25.constexpr.cpp
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年08月02日 星期日 18时56分37秒
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

constexpr int f(int x) {
    //c++11 constexpr不能修饰递归函数
    return 3 * x * x + x;
}

class A {
 public:
    constexpr A(int x, int y) : x(x), y(y) {}
    int x, y;

};


int main() {
    const int a = 123;
    cout << a << endl;
    
    int b;
    cin >> b;
    const int c = 2 * b; //const: 运行期状态

    int n;
    cin >> n;
    //constexpr int m = 2 * n; //constexpr 修饰:编译器常量
    constexpr int m = 2 * 123;
    cout << m << endl;

    constexpr int x = f(12);


    constexpr A t(2, 3); //初始化一个编译器的常量对象, 把构造函数前加constexpr
    cout << t.x << ", " << t.y << endl;

    return 0;
}
