/*************************************************************************
	> File Name: 39.singleton.cpp
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年08月18日 星期二 17时57分33秒
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
#include <mutex>
using namespace std;

class HttpServer {
public:
    static HttpServer *getInstance() {
        if (instance == nullptr) {
            /* //懒汉模式，
            unique_lock<mutex> lock(m_mutex);
            if (instance == nullptr) {
                instance = new HttpServer();
            }
            */
        }
        return instance;
    }

private:
    static HttpServer *instance;
    static mutex m_mutex;
    HttpServer() {}
    HttpServer(const HttpServer &) = delete;
    ~HttpServer() {}
};

HttpServer *HttpServer::instance = new HttpServer(); //饿汉模式
//mutex HttpServer::m_mutex;


int main() {
    HttpServer *t1 = HttpServer::getInstance();
    HttpServer *t2 = HttpServer::getInstance();

    cout << t1 << " " << t2 << endl;
    return 0;
}
