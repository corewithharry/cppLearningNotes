/*************************************************************************
	> File Name: 34.turing.cpp
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年08月13日 星期四 14时26分02秒
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
#include <cmath>
using namespace std;

template<int n>
struct IsEven {
    static constexpr int r = !(n % 2);
};

template<int a, int b>
struct Add {
    static constexpr int r = a + b;
};




//模板实现递归(循环)
template<int n>
struct Sum {
    static constexpr int r = n + Sum<n - 1>::r;
};
template<>
struct Sum<0> {
    static constexpr int r = 0;
};


template<int n>
struct Factorial {
    static constexpr int r = n * Factorial<n - 1>::r;
};
template<>
struct Factorial<1> {
    static constexpr int r = 1;
};



/*****************************判断素数1******************/
template<int n, int i>
struct getNextN {
    static constexpr int r = (i * i > n ? 0 : n);
};

template<int n, int i>
struct getNextI {
    static constexpr int r = (n % i == 0 ? 0 : i + 1);
};

template<int n, int i>
struct IsTest {
    static constexpr int r = IsTest<getNextN<n, i>::r, getNextI<n, i>::r>::r;
};

template<int i>
struct IsTest<0, i> {
    static constexpr int r = 1;
};

template<int i>
struct IsTest<2, i> {
    static constexpr int r = 1;
};

template<int n>
struct IsTest<n, 0> {
    static constexpr int r = 0;
};

//入口
template<int n>
struct IsPrime {
    static constexpr int r = IsTest<n, 2>::r;
};
/*******************************************************/

/*********************判断素数2*****************
template<int n, int m>
struct Check{
    static constexpr bool r = (n % m != 0) && Check<n, m-1>::r;
};

template<int n>
struct Check<n, 2>{
    static constexpr bool r = (n % 2 != 0);
};

template<int n>
struct IsPrime{
    static constexpr int r = Check<n, (int)sqrt(n)>::r;
};
**********************************************/


/******求 n 内素数和****/
template<int n>
struct SumPrime {
    static constexpr int r = (n * IsPrime<n>::r) + SumPrime<n - 1>::r;
};
template<>
struct SumPrime<1> {
    static constexpr int r = 0;
};
/************************/


//输出n以内的所有素数
template<int i, int x>
struct getNextK {
    static constexpr int r = (i > x ? 0 : 1);
};
template<int x, int k , int i>
struct __output {
    static void run() {
        if (IsPrime<i>::r) {
            cout << i << endl;
        }
        __output<x, getNextK<i + 1, x>::r, i + 1>::run();
    };
};
template<int x, int i>
struct __output<x, 0 , i> {
    static void run() {
        return ;
    }
};
template<int x>
struct print_prime {
    static void output() {
        __output<x, 1 , 2>::run();
        return ;
    }
};




int main() {
    cout << IsEven<123>::r << endl;
    cout << IsEven<124>::r << endl;
    cout << Add<5, 7>::r << endl;
    cout << Sum<10>::r << endl;
    cout << Sum<100>::r << endl;
    cout << Factorial<5>::r << endl;
    cout << Factorial<10>::r << endl;

    const int m = 9973;
    cout << IsPrime<m>::r << endl;
    cout << IsPrime<87>::r << endl;
    cout << IsPrime<1537>::r <<endl;
    cout << IsPrime<65>::r << endl;

    print_prime<20>::output();
    return 0;
}
