/*************************************************************************
	> File Name: 42.singleton2.cpp
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年08月22日 星期六 16时08分25秒
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
#include <cstring>
#include <mutex>
using namespace std;

class Singleton {
public:
    //普通方法只有实例化后才能访问、而（静态）类方法不实例化对象就可以访问
    static Singleton* getInstance() {
        //饿汉模式就不需要判断直接返回
        //懒汉模式是非线程安全的，需要加锁
        //双重验证，这样只有第一次会加锁，如果没有外层判断、则每次进来都会加锁
        if (single == nullptr) {
            unique_lock<mutex> lock(m_mutex);
            if (single == nullptr) {
                single = new Singleton();
            }
        }
        return single;
    }


private:
    static Singleton *single; //私有的不能让外界访问到，避免被修改
    static std::mutex m_mutex;
    Singleton() {}
    Singleton(const Singleton &) = default;
    ~Singleton() {}
};

Singleton *Singleton::single = nullptr;
std::mutex Singleton::m_mutex;
//Singleton *Singleton::single = new Singleton();


int main() {
    Singleton *p = Singleton::getInstance();
    //delete p; 析构设为private

    return 0;
}
