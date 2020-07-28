/*************************************************************************
	> File Name: 10.class_method.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 日  7/26 19:43:27 2020
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

class Point {
public :
    Point() {
        cout << "constructor : " << this << endl;
        Point::total_cnt += 1;
        seek_cnt = 0;
    }
    Point(const Point &a) : Point() {
        //拷贝构造函数。会先调用默认构造函数
        cout << "copy constructor : " << this << endl;
        this->x = a.x;
        this->y = a.y;
    }
    Point(double z) : Point() {
        //转换构造函数。会先调用默认构造函数
        cout << "convert constructor : " << this << endl;
        this->x = 99, this->y = 99;
    }
    Point(int x, int y) : Point() {
        //有参构造函数。会先调用默认构造函数
        cout << "param constructor : " << this << endl;
        this->x = x;
        this->y = y;
    }

    void operator=(const Point &a) {
        //赋值运算符。会先调用默认构造函数
        cout << "operator= : " << this << endl;
        this->x = a.x, this->y = a.y;
        return ;
    }

    void set(int x, int y) {
        this->x = x, this->y = y;
    }
    
    void seek() const {
        seek_cnt += 1;
        cout << x << " " << y << endl;
    }
    
    int S() const { return seek_cnt; }

    static int T() { return Point::total_cnt; } //类方法，所有对象共享一个,访问方法Point::

    ~Point() {
        //析构函数
        cout << "destructor : " << this << endl;
        Point::total_cnt -= 1;
    }
    
private:
    int x, y;
    mutable int seek_cnt; //如果想在const函数中修改一变量，就在声明变量时前面加一个mutable
    static int total_cnt; //类属性，在类外初始化，所有对象共享一个
};

int Point::total_cnt = 0;

void test() {
    Point a;
    cout << Point::T() << endl;
    return ;
}

int main() {
    Point a; //调用默认构造函数, total_cnt++
    cout << a.T() << endl; //调用类方法, total_cnt = 1

    //在test函数中：先调用默认构造函数, total_cnt++
    //再调用类方法 total_cnt = 2
    test(); //函数结束调用析构函数析构掉test中的a, total_cnt--, total_cnt = 1
    
    Point b; //调用默认构造函数, total_cnt++
    cout << b.T() << endl; //调用类方法， total_cnt = 2;

    Point c(3, 4); //先调用默认构造函数 total_cnt++，再调用有参构造函数
    cout << c.T() << endl; //total_cnt = 3

    Point d(3.4); //先调用默认构造函数 total_cnt++, 再调用转换构造函数
    cout << d.T() << endl; //total_cnt = 4

    //重点理解：5.6（先会调用默认构造函数 total_cnt++）调用转换构造函数生成匿名对象
    //再调用赋值运算符赋值给c 
    //赋值结束，5.6生成的匿名对象调用析构函数 total_cnt--
    c = 5.6;
    cout << c.T() << endl; //total_cnt = 4

    cout << &a << endl;
    cout << &b << endl;
    cout << &c << endl;
    cout << &d << endl;
    d.seek();
    c.seek();

    const Point e(6, 7); //const类型的类不能修改，只能调用const修饰的方法
    e.seek();
    e.seek();
    e.seek();
    e.seek();
    cout << e.S() << endl;
    return 0;
}
