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
#include <queue>
#include <condition_variable>
#include <mutex>

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


class ThreadPool {
public:
    ThreadPool(int n = 5) 
    : max_threads_num(n), m_mutex(), m_cond() {}
    
    void start() {
        //初始化线程池对象
        for (int i = 0; i < this->max_threads_num; i++) {
            threads.push_back(new thread(&ThreadPool::worker, this));
        }
    }
    void worker() {
        thread::id id = this_thread::get_id();
        is_running[id] = true;
        while (is_running[id]) {
            //只要线程池没有停止，每个线程都会反复的执行下面三个步骤：
            /*
                1、取任务
                2、执行任务
                3、释放任务
            */
            Task *t = this->getOneTask();
            (*t)();
            delete t;
        }
        return ;
    }

    void stop() {
        for (int i = 0; i < this->max_threads_num; i++) {
            this->addOneTask(&ThreadPool::stop_task, this);
        }
        for (int i = 0; i < this->max_threads_num; i++) {
            threads[i]->join();
            delete threads[i];
        }
        threads.clear();
        return ;
    }
    
    template<typename T, typename ...ARGS>
    void addOneTask(T func, ARGS...args) {
        //设置为公有
        unique_lock<mutex> lock(m_mutex); //lock构造完就占到锁了，这个局部变量释放时会自动解锁
        this->task_queue.push(new Task(func, forward<ARGS>(args)...));
        m_cond.notify_one(); //通知一次(cond + 1)，会有一个线程抢到通知
        return ; 
    }

private:
    void stop_task() {
        thread::id id = this_thread::get_id();
        is_running[id] = false;
        return;
    }
    //取任务操作设置为私有，只希望worker中调用
    Task *getOneTask() {
        unique_lock<mutex> lock(m_mutex); //抢碗
        while (task_queue.empty()) {
            m_cond.wait(lock); 
        }
        Task *t = task_queue.front(); 
        task_queue.pop();
        return t;
    }
    int max_threads_num;
    vector<thread *> threads; //线程池
    queue<Task *> task_queue;
    map<std::thread::id, bool> is_running;

    mutex m_mutex;
    condition_variable m_cond;
};


void task_func(int x) {
    cout << "Task func" << x << endl;
    return ;
}
void thread_func1(int a, int b) {
    cout << a << " + " << b << " = " << a + b << endl;
    return ;
}
void thread_func2(int &n) {
    n += 1;
    return ;
}




/******************统计区间内素数数量***************/
int cnt = 0;
int is_prime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}
void count_prime(int l, int r) {
    for (int i = l; i <= r; i++) {
        if (is_prime(i)) __sync_fetch_and_add(&cnt, 1);
    }
    return ;
}



int main() {

    Task t1(thread_func1, 3, 4);
    Task t2(thread_func1, 5, 6);
    Task t3(thread_func1, 9, 7);
    t1(), t2(), t3();

    int n = 0;
    Task t4(thread_func2, n);
    t4();
    t4();
    t4();
    cout << n << endl;

    ThreadPool tp(6);
    tp.start();

    tp.addOneTask(task_func, 126);
    tp.addOneTask(task_func, 532);
    tp.addOneTask(task_func, 798);
    tp.addOneTask(task_func, 100);
    tp.addOneTask(task_func, 989);
    tp.stop();
    tp.addOneTask(task_func, 100);
    tp.addOneTask(task_func, 100);
    tp.addOneTask(task_func, 100);


    /*************用多线程处理任务****************/
    ThreadPool tp2(5);
    tp2.start();
    for (int i = 0, j = 1; i < 5; i++, j += 200000) {
        tp2.addOneTask(count_prime, j, j + 200000 - 1);
    }
    tp2.stop();
    cout << cnt << endl;
    return 0;
}
