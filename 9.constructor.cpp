/*************************************************************************
	> File Name: 9.constructor.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 日  7/26 18:14:38 2020
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

class People {
public :
    People() {
        cout << "默认构造函数" << endl;
    }
    //People() = default; //默认构造函数
    People(string name) {
        //有参构造函数（因为形参只有一个，也叫转换构造函数）
        cout << "param constructor" << endl;
        this->name = name;
    }
    People(int x) {
        //同上
        cout << "int param constructor" << endl;
        this->x = x;
    }
    People(const People &a) {
        //拷贝构造函数，这里的参数必须是引用
        //否则，形参也会调用拷贝构造函数，会发生无限循环的调用
        cout << "copy constructor" << endl;
        this->name = a.name;
        this->x = a.x;
    }
    void operator=(const People &a) {
        //赋值运算符
        cout << "operator =" << endl;
        this->name = a.name;
        this->x = a.x;
        return ;
    }
    ~People() {
        //析构函数
        cout << "destructor" << endl;
    }
    string name;
    int x;
};

void incr(int &a) {
    //引用小示例
    a += 1;
    return ;
}

int add(People a, People b) {
    return a.x + b.x;
}

int main() {
    People f; //调用默认构造函数 
    int n = 7;
    incr(n);
    cout << n << endl;
    
    //4, 5会自动调用转换构造函数，先转换成People对象. add函数结束并调用两次析构函数
    cout << add(4, 5) << endl; 

    People a("hug"); //调用(一个参数的)有参构造函数(转换构造函数)
    People b = string("hug"); //同上
    People c(543); //同上
    People d = 678; //同上
    cout << a.name << endl;
    cout << b.name << endl;
    cout << c.x << endl;
    cout << d.x << endl;

    //c = 987重点理解：987会先调用转换构造函数生成一个对象赋值给C, 
    //赋值给C时注意！！这时候调用的不是转换构造函数也不是拷贝构造函数
    //因为此时的C已不再是初次定义，因此它这次调用的是 赋值运算符函数！
    //赋值给C之后，987生成的匿名对象会再调用析构函数。
    c = 987;
    cout << c.x << endl;

    d = string("xiaoming"); //调用有参构造函数(转换构造函数)
    cout << d.name << endl;

    People e = a; //调用拷贝构造函数
    cout << e.name << endl;
    cout << e.x << endl;

    c = a; //c不是首次定义，此时调用赋值运算符函数
    cout << c.name << endl;
    cout << c.x << endl;
    return 0;
}
