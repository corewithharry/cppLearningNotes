/*************************************************************************
	> File Name: deep_copy.cpp
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年07月30日 星期四 12时43分51秒
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
#include <cstring>
using namespace std;
class A {
 public:
    A() {
        this->arr = new int[100];
    }
    A(const A &obj) : x(obj.x), y(obj.y) {
        this->arr = new int[100];
        memcpy(this->arr, obj.arr, sizeof(int) * 100);
    }

    int *arr;
    int x, y;
};


int main() {
    A a1;
    a1.x = 3, a1.y = 4;
    A a2 = a1;
    cout << "a1.x:" << a1.x << "  a1.y:" << a1.y << endl;
    cout << "a2.x:" << a2.x << "  a2.y:" << a2.y << endl;

    cout << endl;
    a1.x = 555;
    a2.x = 666;
    cout << "a1.x:" << a1.x << "  a1.y:" << a1.y << endl;
    cout << "a2.x:" << a2.x << "  a2.y:" << a2.y << endl;

    a1.arr[0] = 89;
    a2.arr[0] = 79988;
    cout << "a1.arr[0]:" << a1.arr[0] << endl;
    cout << "a2.arr[0]:" << a2.arr[0] << endl;
    return  0;
}
