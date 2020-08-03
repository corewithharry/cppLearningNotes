/*************************************************************************
	> File Name: 27.nullptr.cpp
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年08月02日 星期日 20时06分22秒
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


int f(int x) {
    cout << "output in valu: " << x << endl;
    return 0;
}

int f(int *x) {
    cout << "output address: " << x << endl;
    return 0;
}


int main() {
    printf("%lld\n", (long long)nullptr);
    cout << sizeof(NULL) << endl;
    int n = 123, *p = &n;
    f(n);
    f(p);
    f(nullptr);
    f((int)NULL);
    return 0;
}
