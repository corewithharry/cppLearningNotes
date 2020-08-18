/*************************************************************************
	> File Name: 37.sort.cpp
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年08月17日 星期一 14时31分52秒
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

bool cmp(int a, int b) {
    return a > b;
}

struct CMP {
    bool operator()(int a, int b) {
        return a > b;
    }
};


namespace haizei {

template<typename T>
struct less {
    bool operator()(const T &a, const T &b) {
        return a < b;
    }
};

template<typename T>
struct greater {
    bool operator()(const int &a, const int &b) {
        return a > b;
    }
};

} //end of haizei

int main() {
    srand(time(0));
    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 100;
    }
    sort(arr, arr + 10, cmp);
    for (int i = 0; i < 10; i++) cout << arr[i] << " ";
    cout << endl;

    sort(arr, arr + 10, [](int a, int b) { return a > b; });
    for (int i = 0; i < 10; i++) cout << arr[i] << " ";
    cout << endl;
    
    
    sort(arr, arr + 10, CMP());
    for (int i = 0; i < 10; i++) cout << arr[i] << " ";
    cout << endl;

    
    sort(arr, arr + 10, haizei::less<int>());
    for (int i = 0; i < 10; i++) cout << arr[i] << " ";
    cout << endl;

    sort(arr, arr + 10, haizei::greater<int>());
    for (int i = 0; i < 10; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
