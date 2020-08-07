/*************************************************************************
	> File Name: lambda.cpp
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年08月07日 星期五 15时45分19秒
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


auto add = [](int a, int b) -> long long {
    return a + b;
};


auto Data = [](int a, int b) {
    return [=](auto func) {
        //[]中 = 是值捕获，把外部的变量再拷贝一份
        return func(a, b);
    };
};

auto First = [](int a, int b) {
    return a;
};
auto Second = [](int a, int b) {
    return b;
};
auto Add = [](int a, int b) {
    return a + b;
};
auto Max = [](int a, int b) {
    return max(a, b);
};


/*
function<int()> Temp_Func() {
    int a = 23;
    return [=]() -> int {
        return a;
    };
}
*/


int main() {
    cout << add(2, 4) << endl;
    
    auto a = Data(rand() % 1000, rand() % 1000); 
    cout << a(First) << endl;
    cout << a(Second) << endl;
    cout << a(Add) << endl;
    cout << a(Max) << endl;
    return 0;
}
