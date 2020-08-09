/*************************************************************************
	> File Name: 31.function.cpp
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年08月08日 星期六 15时25分38秒
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


namespace haizei {

template<typename RT, typename ...PARAMS> 
class base {
public: 
    virtual RT operator()(PARAMS...) = 0;
    virtual ~base() {}
};


//把函数抽象为另一个函数对象的类的实现
template<typename RT, typename ...PARAMS> 
class normal_func : public base<RT, PARAMS...>{
public:
    typedef RT (*func_type)(PARAMS...);  //函数指针
    normal_func(func_type func) : ptr(func) {}
    virtual RT operator()(PARAMS... args) override {
        return this->ptr(args...);
    }
private:
    func_type ptr;
};



template<typename C, typename RT, typename ...PARAMS> 
class functor : public base<RT, PARAMS...>{
public:
    functor(C &func) : ptr(func) {}
    virtual RT operator()(PARAMS... args) override {
        return this->ptr(args...);
    }
private:
    C &ptr;
};




template<typename RT, typename ...PARAMS> class function; //RT：返回值类型, PARAMS...:变参列表
template<typename RT, typename ...PARAMS>
class function<RT(PARAMS...)> {
public:
    function(RT (*func)(PARAMS...)) : ptr(new normal_func<RT, PARAMS...>(func)) {} //普通函数

    template<typename T>
    function(T &&a) : ptr(new functor<typename remove_reference<T>::type, RT, PARAMS...>(a)){} //函数对象

    RT operator()(PARAMS... args) {
        return this->ptr->operator()(args...);
    }
    ~function() {
        delete ptr;
    }
private:
    base<RT, PARAMS...> *ptr;  //“ 函数对象(把函数对象和函数都抽象化为另一个函数对象)” 的指针
};

} //end of haizei;




void f(function<int(int, int)> g) {
    cout << g(3, 4) << endl;
    return ;
}


int add(int a, int b) {
    return a + b;
}


double add2(int a, double b, float c) {
    return a + b + c;
}

void print() {
    cout << "hello world!" << endl;
    return ;
}



struct MaxClass {
    int operator()(int a, int b) {
        return a > b ? a : b; 
    }
};




/************************统计函数执行次数********************************/
/*
class FunctionCnt {
public:
    FunctionCnt(function<int(int, int)> g) : g(g), __cnt(0) {}
    int operator()(int a, int b) {
        __cnt += 1;
        return g(a, b);
    }
    int cnt() { return __cnt; }
private:
    function<int(int, int)> g;
    int __cnt;
};
************************************************************************/

template<typename T, typename ...ARGS> class FunctionCnt; 
template<typename T, typename ...ARGS> 
class FunctionCnt<T(ARGS...)> {
public:
    FunctionCnt() : __cnt(0) {}
    FunctionCnt(function<T(ARGS...)> g) : g(g), __cnt(0) {}
    T operator()(ARGS... args) {
        __cnt += 1;
        return g(args...);
    }
    int cnt() { return __cnt; }
private:
    function<T(ARGS...)> g;
    int __cnt;
};



int main() {
    MaxClass max;
    f(add);
    f(max);
    haizei::function<int(int, int)> g1(add);
    haizei::function<int(int, int)> g2(max);
    cout << g1(3, 4) << endl;
    cout << g2(3, 4) << endl;


    FunctionCnt<int(int, int)> add_cnt(add);
    add_cnt(3, 4);
    add_cnt(5, 6);
    add_cnt(4, 8);
    cout << add_cnt.cnt() << endl;


    FunctionCnt<double(int, double, float)> add2_cnt(add2);
    add2_cnt(3.5, 66, 53.1);
    add2_cnt(3.87, 22, 7.1);
    add2_cnt(66.57, 23, 9.3);
    add2_cnt(78.1, 88, 8.3);
    add2_cnt(96.36, 51, 99.31);
    cout << add2_cnt.cnt() << endl;

    FunctionCnt<void()> print_cnt(print);
    print_cnt();
    print_cnt();
    print_cnt();
    print_cnt();
    print_cnt();
    print_cnt();
    cout << print_cnt.cnt() << endl;
    return 0;
}
