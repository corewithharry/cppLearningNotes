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
class base{
public: 
    virtual RT operator()(PARAMS...) = 0;
    virtual ~base() {}
};


template<typename RT, typename ...PARAMS> 
class normal_func : public base<RT, PARAMS...>{
public:
    typedef RT (*func_type)(PARAMS...);
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



//RT：返回值类型
template<typename RT, typename ...PARAMS> class function;
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
   base<RT, PARAMS...> *ptr;
};

} //end of haizei;




void f(function<int(int, int)> g) {
    cout << g(3, 4) << endl;
    return ;
}


int add(int a, int b) {
    return a + b;
}

struct MaxClass {
    int operator()(int a, int b) {
        return a > b ? a : b; 
    }
};




/************************统计函数执行次数********************************/
class FunctionCnt {
public:
    FunctionCnt(function<int(int, int)> g) : g(g), __cnt(0) {}
    int operator() (int a, int b) {
        __cnt += 1;
        return g(a, b);
    }
    int cnt() { return __cnt; }
private:
    function<int(int, int)> g;
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


    FunctionCnt add_cnt(add);
    add_cnt(3, 4);
    add_cnt(5, 6);
    add_cnt(4, 8);
    cout << add_cnt.cnt() << endl;
    return 0;
}
