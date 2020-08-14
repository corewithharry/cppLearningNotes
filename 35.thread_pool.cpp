/*************************************************************************
	> File Name: 35.thread_pool.cpp
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年08月13日 星期四 16时08分19秒
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
#include <thread>
using namespace std;

/*
 封装一个任务类，
 通过 bind 将 方法(函数)名和参数绑定在一起, 完成一个任务的封装
*/
class Task {
public:
    template<typename T, typename ...ARGS>
    Task(T func, ARGS... args) {
        //forward 使参数按照原来的类型向前传递
        this->func = std::bind(func, forward<ARGS>(args)...);
    }
    void operator()(){
        this->func();
        return ;
    }

private:
    function<void()> func;
};

void thread_func1(int a, int b) {
    cout << a << " + " << b << " = " << a + b << endl;
    return ;
}
void thread_func2(int &n) {
    n += 1;
    return ;
}



class ThreadPool {
public:
    ThreadPool(int n = 5) 
    : is_running(false), max_threads_num(n) {  }
    
    void start() {
        if (is_running) return ;
        is_running = true;

        //初始化线程池对象
        for (int i = 0; i < this->max_threads_num; i++) {
            //以成员方法作为入口, 参数不要忘记隐藏的this
            //正常函数传入到 thread()中，直接传入函数名即函数指针，但传入成员方法需要对方法取地址
            threads.push_back(new thread(&ThreadPool::worker, this));
        }
    }
    void worker() {
        //成员含有一个隐藏参数 this!
        cout << "worker: I am worker!" << endl;
    }
    void stop() {
        if (is_running == false) return ;
        is_running = false;
        for (int i = 0; i < this->max_threads_num; i++) {
            threads[i]->join();
            delete threads[i];
        }
        threads.clear();
        return ;
    }
private:
    bool is_running;
    int max_threads_num;
    vector<thread *> threads; //线程池
};




int main() {
    Task t1(thread_func1, 3, 4);
    Task t2(thread_func1, 5, 6);
    Task t3(thread_func1, 9, 7);
    t1(), t2(), t3();

    int n = 0;
    Task t4(thread_func2, ref(n));
    t4();
    t4();
    t4();
    cout << n << endl;

    ThreadPool tp(6);
    tp.start();
    tp.stop();
    return 0;
}
