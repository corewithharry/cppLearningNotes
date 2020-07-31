/*************************************************************************
	> File Name: IntArray.cpp
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年07月31日 星期五 22时58分04秒
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
#include <ctime>
using namespace std;

class IntArray {
 public:
    IntArray(int n) : n(n) {
        this->arr = new int[n];
    }

    IntArray(IntArray &obj) : n(obj.n){
        this->arr = new int[n];
        for (int i = 0; i < n; i++) {
            this->arr[i] = obj[i];
        }
    }

    int &operator[](int ind) {
        if (ind >= 0) { 
            return this->arr[ind];
        } else {
            return this->arr[this->n + ind];
        }
    }

    void operator+=(int num) {
        for (int i = 0; i < n; i++) {
            this->arr[i] += num;
        }
        return ;
    }

    IntArray operator++(int x) {
        //后++, 无论后++还是前++都是要加的。所以要提前拷贝一份返回加之前的样子.
        IntArray temp(*this);
        for (int i = 0; i < this->n; i++) {
            this->arr[i] += 1;
        }
        return temp;
    }

    IntArray &operator++() {
        for (int i = 0; i < this->n; i++) {
            this->arr[i] += 1;
        }
        return *this;
    }

    friend ostream &operator<<(ostream &, const IntArray &);
    ~IntArray() {
        delete[] this->arr;
    }
 private:
    int *arr, n;
};

ostream &operator<<(ostream &out, const IntArray &a) {
    out << "[ ";
    for (int i = 0; i < a.n; i++) {
        out << a.arr[i] << " ";
    }
    out << "]";
    return out;
}



int main() {
    srand(time(0));
    IntArray a(10);
    for (int i = 0; i < 10; i++) {
        a[i] = rand() % 100; //！！这里要注意一下如何重载[], a[i]返回值应该是arr[i]这个变量的引用
    }
    cout << a << endl; //输出数组中所有的元素
    cout << a[4] << endl;
    cout << a[-2] << endl; //输出倒数第2位的值
    a += 5; //给数组的所有元素都加5
    cout << a << endl; //输出数组中所有的元素
    cout << (a++) << endl; //给数组中所有元素都加1
    cout << (++a) << endl; //给数组中所有元素都加1
    return 0;
}
