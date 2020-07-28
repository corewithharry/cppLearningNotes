/*************************************************************************
	> File Name: 15.operator3.cpp
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年07月27日 星期一 20时05分22秒
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
public :
    A() {
        arr = new int[10];
    }
    A(const A &a) : A() {
        //深拷贝，系统默认拷贝构造是浅拷贝()
        for (int i = 0; i < 10; i++) {
            this->arr[i] = a.arr[i];
        }
        this->x = a.x;
        this->y = a.y;
    }

    int x, y;
    int *arr;
};

class B {
public:
    B() : obj(nullptr){
        arr = new int[10];
        arr[3] = 9972;
    }
    B(A *obj) : B() {
        this->obj = obj;
    }


    int operator()(int a, int b){
        return a + b;
    }
    int &operator[](int ind) {
        //返回引用,返回的是ind处的变量
        return arr[ind];
    }
    
    void operator[](const char *msg) {
        cout << msg << endl;
        return ;
    }

    A *operator->() {
        return obj;
    }
    A &operator*() {
        return *obj;
    }


    ~B() {
        delete arr;
    }

private:
    int *arr;
    A *obj;
};


ostream &operator<<(ostream &out, const A &a) {
    out << "A(" << a.x << ", " << a.y << ")";
    return out;
}

//主函数中是外部表现，类中是内部实现
int main() {
    B add;
    cout << add(3, 5) << endl; //函数对象(像函数的对象)，重载()
    add[3] = 787; //数组对象, 重载[]
    cout << add[3] << endl;
    add["hello world"];

    A a, b(a); //浅拷贝
    a.x = 87, a.y = 852;
    B p = &a; //指针对象
    cout << p->x << " " << p->y << endl;
    cout << *p << endl;

    a.arr[3] = 111;
    b.arr[3] = 222;
    cout << a.arr[3] << endl;
    cout << b.arr[3] << endl;
    cout << sizeof(a) << endl;
    return 0;
}
