/*************************************************************************
	> File Name: 471.大整数乘法.cpp
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年07月30日 星期四 17时51分27秒
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
#include <cmath>
#include <cstring>
using namespace std;

struct BigInt {
    BigInt() {
        num.push_back(0);
    }
    BigInt operator*(const BigInt &a) {
        BigInt c;
        for (int i = 0; i < num.size(); i++) {
            for (int j = 0; j < a.num.size(); j++) {
                if (i + j == c.num.size()) c.num.push_back(0);
                c.num[i + j] += num[i] * a.num[j];
            }
        }
        c.proccess_digit();
        return c;
    }

    void operator=(const string &str) {
        num.clear();
        for (int i = str.size() - 1; i >= 0; i--) {
            num.push_back(str[i] - '0');
        }
        return ;
    }
    
    void proccess_digit() {
        while (num.size() > 1 && num[num.size() - 1] == 0) num.pop_back();
        for (int i = 0; i < num.size(); i++) {
            if (num[i] < 10) continue;
            if (i + 1 == num.size()) num.push_back(0);
            num[i + 1] += num[i] / 10;
            num[i] %= 10;
        }    
    }

    vector<int> num; 
};

ostream &operator<<(ostream &out, const BigInt &a) {
    for (int i = a.num.size() - 1; i >= 0; i--) out << a.num[i];
    return out;
}



int main() {
    BigInt a, b;
    string str_a, str_b;
    cin >> str_a >> str_b;
    a = str_a;
    b = str_b;
    cout << a * b << endl;
    return 0;
}
