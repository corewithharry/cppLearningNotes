/*************************************************************************
	> File Name: 30.template.cpp
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年08月06日 星期四 11时46分10秒
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

class A {
public:
    A(int x) : x(x) {}
    int x;
};


class B {
public:
    B(int y) : y(y) {}
    int y;
};

int operator+(const A &a, const B &b) {
    return a.x + b.y;
}

namespace haizei {
template<typename T, typename U>
//decltype(T() + U()) add(T a, U b ) {
// 当T 和 U 没有默认的构造函数的时候就会报错，下面这样写就解决了
auto add(T a, U b ) -> decltype(a + b) {
    return a + b;
}

//特化函数模板
template<>
int add(int a, int b) {
    cout << "add int : " << a << " " << b << endl;
    return a + b;
}
//偏特化函数模板
template<typename T, typename U>
auto add(T *a, U *b) -> decltype(*a + *b) {
    return add(*a, *b); //防止a, b是多重指针
}




template<typename T, typename U>
auto max(T a, U b) -> decltype(a + b) {
    return (a < b ? b : a);
}

template<typename T, typename U>
auto min(T a, U b) -> decltype(a + b) {
    return (a < b ? a : b);
}

    

class PrintAny {
public:
    template<typename T>
    void operator()(const T &a) {
        cout << a << endl;
    }
};



template<typename T>
class FoolPrintAny {
public:
    void operator()(const T &a) {
        cout << a << endl;
    }   
};
template<>
class FoolPrintAny<int> {
public:
    void operator()(const int &a) {
        cout << "naughty : " << 2 * a << endl;
    }   
};


//变参模板函数
template<typename T> //变参模板函数边界，这个放上面
void printAny(const T &a) {
    cout << a << " " << endl;
    return ;
}
template<typename T, typename ...ARGS>
void printAny(const T &a, ARGS... args) {
    cout << a << " ";
    printAny(args...);
    return ;
}

//****************************实现ARG（解析变参列表的类模板）***************

template<int n, typename T, typename ...ARGS>
struct ARG {
    typedef typename ARG<n - 1, ARGS...>::__type __type;
};

template<typename T, typename ...ARGS>
struct ARG<0, T, ARGS...> {
    typedef T __type;
};

template<typename T>
struct ARG<0, T> {
    typedef T __type;
};

//***************************************************************************


//变参模板类
//设计一个模板类ARG来解析变参类型
template<typename T, typename ...ARGS> class Test;
template<typename T, typename ...ARGS> //Test的偏特化
class Test<T(ARGS...)> {
public:
    T operator()(ARGS... args) {
        return add<T>(args...);
    }
private:
    template<typename T1, typename U, typename ...US>
    T1 add(U a, US... args) {
        return a + add<T>(args...);
    }
    template<typename T1, typename U>
    T1 add(U a) {
        return a;
    }
};

/**************模板函数作为参数传递是，自动类型推导**/
template<typename T, typename U>
T test_param_func(U a) {
    return T(a * 2);
}

void func2(int (*func)(double)) {
    cout << func(2.3) << endl;
}

} // END OF haizei






int main() {
    haizei::func2(haizei::test_param_func);
    A a(1000);
    B b(646);
    cout << a + b << endl;
    cout << haizei::add(a, b) << endl;
    cout << haizei::add(4, 3) << endl;
    cout << haizei::add(4.2, 3.6) << endl;
    cout << haizei::add(4.5, 3) << endl;
    cout << haizei::add(3, 4.5) << endl;

    //max也是模板实现的, 但是标准库中的max只支持两种同类型参数
    cout << haizei::max(4, 5) << endl;
    cout << haizei::max(4.6, 3) << endl;
    cout << haizei::max(55, 88.8) << endl;

    cout << haizei::min(4.5, 3) << endl;
    cout << haizei::min(55, 88.8) << endl;

    haizei::PrintAny print;
    print(123);
    print(56456);
    print(554.2);
    print("hello world");
    print("hello haizei");
    print(&a);

    haizei::FoolPrintAny<string> f;
    f("hello world");
    haizei::FoolPrintAny<int> f2; //特化模板类
    f2(123);

    int n = 45, m = 57;
    int *p = &n, *q = &m;
    cout << haizei::add(n, m) << endl; //调用特化模板函数
    cout << haizei::add(p, q) << endl; 

    haizei::printAny(123, 34.5, "hello world", &a);

    haizei::Test<int(int, int)> f3;
    cout << f3(3, 4) << endl;

    haizei::Test<int(int, int, int, int)> f4;   //()外的int是返回值类型
    cout << f4(1, 2, 3, 4) << endl; //累加求和
    
    haizei::Test<int(int, int, int, int, int)> f5;
    cout << f5(1, 2, 3, 4, 5) << endl; //累加求和

    return 0;
}
