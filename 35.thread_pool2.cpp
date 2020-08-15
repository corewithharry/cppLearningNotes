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
    : is_running(false), max_threads_num(n), m_mutex(), m_cond() {}
    
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
        //向任务队列中取任务 
        //cout << "worker: I am worker!" << endl;
        while (is_running) {
            //只要线程池没有停止，每个线程都会反复的执行下面三个步骤：
            /*
                1、取任务
                2、执行任务
                3、释放任务
            */
            Task *t = this->getOneTask();
            if (t == nullptr) break;
            (*t)();
            delete t;
        }
        return ;
    }

    void stop() {
        if (is_running == false) return ;
        //当任务都处理完毕，现在的所有线程都会处于 wait 中在等待着任务，我们此时就可以结束线程池了。
        do {
            //要结束线程池，就得先抢到锁，停止，并告诉所有等待任务的线程不要再取了。
            unique_lock<mutex> lock(m_mutex);
            is_running = false;
            m_cond.notify_all();
        } while (0);

        //上面使用 do-while 是限定 lock 的作用域，出了{}会自动释放锁，好让那些 wait 的线程收到通知后在抢到锁
        //下面就可以等着回收这些线程了
        for (int i = 0; i < this->max_threads_num; i++) {
            threads[i]->join();
            delete threads[i];
        }
        threads.clear();
        /*
        //停止任务队列。 可以把任务队列清空
        do {
            unique_lock<mutex> lock(m_mutex);
            while (!task_queue.empty()) task_queue.pop();
        } while (0);
        */
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
    //取任务操作设置为私有，只希望worker中调用
    Task *getOneTask() {
        unique_lock<mutex> lock(m_mutex); //抢碗
        while (is_running && task_queue.empty()) {
            /*
                如果是 if(task_queue.empty()) 会出错
                因为，addOneTask 抢到 wait 释放的锁后，开始放任务，有可能连续连续抢到两次锁放了两个任务，
                条件变量就会+2，就会放出两个信号让等待中的线程来接收
                但此时如果新进来的线程，一进来就判断到队列不空，它就会取走一个任务，并且也没有给cond-1！
                另一个任务正常地让等待中的一个线程取到了

                但是在等待信号中的另一个线程仍然可以正好收到cond大于0的信号，它会去队列取任务，殊不知任务已经
                被新进来的线程取走了，于是就会出现段错误

                改成while循环后，等待中的线程收到信号时它会再去判断一下队列是否为空，此时要时真不空就可以去取任务了
            */

            //cout << this_thread::get_id() << "wait to task..." << endl;
            //等待任务，直到队列中存在任务
            m_cond.wait(lock);  //1、添加任务可能会满足 2、stop时会满足(所以while中添加个条件)
            //wait: 临时释放锁并等待通知，让加任务的去抢到锁后添加任务并发个通知。这里收到通知后会再次自动抢到锁
        }
        //这下面还是拿到锁的
        if (is_running == false) return nullptr; //停止了
        //cout << this_thread::get_id() << "take one task..." << endl;
        Task *t = task_queue.front(); 
        task_queue.pop();
        return t;
    }
    bool is_running;
    int max_threads_num;
    vector<thread *> threads; //线程池
    queue<Task *> task_queue;
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
    for (int i = 0; i < 1000000; i++) ;
    tp.stop();
    return 0;
}
