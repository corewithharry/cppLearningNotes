/*************************************************************************
	> File Name: 32.bind.cpp
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年08月13日 星期四 11时17分58秒
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

int add(int a, int b) {
    cout << a << " + " << b << " = " << a + b << endl;
    return a + b;
}

int add2(int a, int b, int c) {
    cout << a << "  " << b << "  " << c << endl;
    return a + b;
}

int add_cnt(function<int(int, int)> func, int &n, int a, int b) {
    n += 1;
    return func(a, b);
}


int main() {
    //从一种传参形式的函数变成另一种传参函数
    //bind是模板方法

    // _1 代表传参（）中的第一个参数
    // _2 代表传参中的第二个参数
    function<int(int)> f1 = bind(add, 5, placeholders::_1);
    f1(3), f1(4), f1(5);
    function<int(int, int)> f2 = bind(add, placeholders::_2, placeholders::_1);
    f2(3, 4), f2(5, 6), f2(7, 8);

    function<int(int, int)> f3 = bind(add2, placeholders::_2, 6, placeholders::_1);
    f3(9, 10);

    function<int(int, int, int)> f4 = bind(add2, placeholders::_1, placeholders::_3, placeholders::_2);
    f4(1, 2, 3);

    //绑定一个可以统计函数执行次数的方法
    int n = 0;
    /*
    因为 bind 是模板方法，我们在传第二个参数时，它并不知道 n 是一个引用，它会拷贝一个 n 给 add_cnt 的第二个
    参数 n, 因此统计函数执行次数时输出的结果是 0
    解决办法：
        在 n 传入时加 ref, ref()方法指明 n 是一个引用
    */

    function<int(int, int)> f5 = bind(add_cnt, add, ref(n), placeholders::_1, placeholders::_2);
    f5(89, 54);
    f5(55, 25);
    f5(77, 14);
    cout << n << endl;
    return 0;
}
