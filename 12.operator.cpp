/*************************************************************************
	> File Name: 12.operator.cpp
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年07月27日 星期一 18时29分05秒
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


//自己写一个命名空间
namespace myspace {
class istream {
public:
    //返回对象的引用:为了一直使用这个cin对象，避免再拷贝一份
    istream &operator>>(int &n) {
        //参数传引用，避免再拷贝一份n
        std::cin >> n; //可以用scanf来实现
        return *this;
    }
private:

};

class ostream {
public:
    ostream &operator<<(int &n) {
        std::cout << n;
        return *this;
    }
    ostream &operator<<(const char *msg) {
        std::cout << msg;
        return *this;
    }
private:

};

istream cin;
ostream cout;

};



int main() {
    int n, m;
    myspace::cin >> n >> m; //系统默认为执行 cin.operator>>(n)
    myspace::cout << n << " " <<  m << "\n";
    return 0;
}
