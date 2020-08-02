/*************************************************************************
	> File Name: 24.auto.cpp
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年08月02日 星期日 18时39分55秒
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


int main() {
    auto a = 123;
    cout << sizeof(a) << endl;
    map<int, int> arr;
    arr[44848798] = 798213;
    arr[12265] = 320;
    arr[65] = 33022;
    for (map<int, int>::iterator iter = arr.begin(); iter != arr.end(); iter++) {
        cout << iter->first << " " << iter->second << endl;
    }
    for (auto iter = arr.begin(); iter != arr.end(); iter++) {
        cout << iter->first << " " << iter->second << endl;
    }
    for (auto x : arr) {
        //c++11新语法
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}
