/*************************************************************************
	> File Name: 41.shared_ptr.cpp
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年08月20日 星期四 15时30分02秒
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
namespace haizei {


template<typename T>
class shared_ptr {
public:
    shared_ptr() : ptr(nullptr), pcnt(nullptr) {}
    shared_ptr(T *ptr) : ptr(ptr), pcnt(new int(1)) {}
    shared_ptr(const shared_ptr<T> &p) : ptr(p.ptr), pcnt(p.pcnt) { 
        *pcnt += 1; 
        cout << "拷贝构造" << endl;
    }
    shared_ptr<T> &operator=(shared_ptr<T> &p) {
        cout << "赋值运算符" << endl;
        this->use_count_des();
        this->ptr = p.ptr;
        this->pcnt = p.pcnt;
        *pcnt += 1;
        return *this;
    }

    int use_count() { return (pcnt ? *pcnt : 0); }
    T &operator*() { return *(this->ptr); }
    T *operator->() { return this->ptr; }
    ~shared_ptr() {
        this->use_count_des();
    }
    
private:
    void use_count_des() {
         if (pcnt) {
            *pcnt -= 1;
            if (*pcnt == 0) {
                delete pcnt;
                delete ptr;
            }
        }       
    }
    T *ptr;
    int *pcnt; // 记录当前指向的对象有多少个智能指针指向
};

    
class A {
public:
    A() : x(123), y(456) {
        cout << this << "constructor" << endl;
    }
    int x, y;
    ~A() {
        cout << this << "destructor" << endl;
    }
    haizei::shared_ptr<A> p;
};


} //end of namespace haizei

int main() {
    haizei::shared_ptr<haizei::A> p(new haizei::A()), q = p;
    haizei::shared_ptr<haizei::A> k(new haizei::A());
    cout << p->x << " " << p->y << endl;
    cout << q->x << " " << q->y << endl;
    cout << p.use_count() << endl; //2
    q = k;
    cout << p.use_count() << endl; //1
    //p = k;
    //cout << p.use_count() << endl;
   
    //环形引用
    p->p = k;
    k->p = p;
    return 0;
}
