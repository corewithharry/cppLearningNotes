/*************************************************************************
	> File Name: 28.left_right_value.cpp
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年08月02日 星期日 20时24分12秒
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

#define TEST(a, f) { \
    cout << #a <<  " : " << #f << " "; \
    f(a); \
}

void f2(int &x) {
    cout << "left value" << endl;
}

void f2(int &&x) {
    cout << "right value" << endl;
}

void f(int &x) {
    cout << "left value" << endl;
    TEST(x, f2);
}

void f(int &&x) {
    cout << "right value" << endl;

    //在f内部，这里x就是左值了，（可以放=左边）
    //TEST(x, f2); //这里就会按左值调用f2
    
    TEST(forward<int &&>(x), f2); //向前传递

    TEST(move(x), f2); //强制变成右值
}


int test_func(const int &&x) {
    //x += 1;
    cout << x << endl;
    return 0;
}


int main() {
    //表达式的返回结果可以放在等号左边则为左值
    int a, b = 1, c = 3;
    (++a) = b + c;
    cout << a << endl;
    (a++);
    (a = b) = c;
    cout << a << " " << b << endl;
    int arr[10];
    arr[3] = 12;
    (a += 3) = 67;
    cout << a << endl;
    TEST(a += 3, f);
    TEST(1 + 4, f);
    TEST(b + c, f);
    TEST(a++, f);
    TEST(++a, f);

    test_func(123);
    test_func(move(a));
    return 0;
}
