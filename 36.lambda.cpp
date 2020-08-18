/*************************************************************************
	> File Name: 36.lambda.cpp
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年08月17日 星期一 09时57分38秒
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
#include <functional>
using namespace std;


int mul(int a, int b) {
    return a * b;
}
int add(int a, int b) {
    return a + b;
}


int main() {
    //可调用对象：函数、函数对象、lambda表达式
    
    int n = 10000;
    auto a = [=](int a, int b) { return a + b + n; };  //lambda是个对象就是个值，赋值语句不要忘加分号
    
    n = 1000000;
    auto b = [n](int a, int b) { return a + b + n; };
    //每一个 lambda 表达式类型都不同
    cout << typeid(a).name() << endl;
    cout << typeid(b).name() << endl;
    cout << a(1, 2) << endl;
    cout << b(1, 2) << endl;


    //返回值后置，指定返回值类型
    auto c = [](int a, int b) -> double { 
        double c = 12.5;
        if (rand() % 2) {
            return c;
        } else {
            return a + b; 
        }
    };


    //lambda 表达式可以传入可调用对象也可返回可调用对象
    auto d = [](function<int(int, int)> a, function<int(int, int)> b) {
        return [=](int x) {
            return a(x, x) + b(x, x);
        };
    };
    auto e = d(a, b);
    cout << e(12) << endl;


    auto f = d(add, mul);
    cout << f(3) << endl;
    return 0;
}
