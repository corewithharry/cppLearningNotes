/*************************************************************************
	> File Name: 14.operator2.cpp
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年07月27日 星期一 19时21分06秒
************************************************************************/


//重载运算符的方法的参数个数一定要和原来运算符的目数相同
//优先匹配类内重载

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

class Point {
public :
    Point() : __x(0), __y(0) {}
    Point(int x, int y) : __x(x), __y(y) {}
    int x() const { return __x; }
    int y() const { return __y; }
    
    Point operator+(const Point &a) {
        return Point(x() + a.x(), y() + a.y());
    }
    
    Point &operator+=(const Point &a) {
        __x += a.x();
        __y += a.y();
        return *this;
    }

    Point &operator++() {
        //前++
        __x += 1;
        __y += 1;
        return *this;
    }

    Point operator++(int) {
        //后++
        //返回不能是引用，因为方法一结束，temp就没了，所以要返回一个temp的拷贝
        Point temp(*this);
        __x += 1;
        __y += 1;
        return temp;
    }


private:
    int __x, __y;
};


ostream &operator<<(ostream &out, const Point &a) {
    out << "Point (" << a.x() << ", " << a.y() << ")";
    return out;
}



int main() {
    Point a(4, 5), b(3, 4), c(1, 1);
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << a + b << endl;

    cout << "pre incr: " << ++(c += b) << endl;
    //++(c += b);
    cout << c << endl;
    cout << "after incr: " << c++ << endl;

    int n = 6, m = 7;
    (n += m)++;
    cout << n << endl;
    return 0;
}
