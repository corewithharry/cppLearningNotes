/*************************************************************************
	> File Name: 11.RVO.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 日  7/26 21:10:50 2020
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
    People(string name) {
        cout << "param constructor" << endl;
        this->name = name;
    }
    People(const People &a) {
        cout << "copy constructor" << endl;
        this->name = a.name;
    }

private:
    string name;
};

People func() {
    People temp_a("hug");
    return temp_a;
}

int main() {
    People a = func();
    return 0;
}
