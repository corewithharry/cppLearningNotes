/*************************************************************************
	> File Name: 3.cpp
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年08月01日 星期六 16时31分20秒
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
#include <cstring>

using namespace std;

namespace haizei {
class string {
 public:
    string() {
        this->__buff_size = 10;
        this->buff = new char[this->__buff_size];
        this->__length = 0;
    }
    string(const char *str) {
        this->__buff_size = strlen(str) + 1;
        this->buff = new char[this->__buff_size];
        strcpy(this->buff, str);
        this->__length = this->__buff_size - 1;
    }
    const char *c_str() const {
        return buff;
    }
    char &operator[](int ind) {
        return this->buff[ind];
    }

    string operator+(const string &s) {
        int size = __length + s.__length + 1;
        char *temp = new char[size];
        strcpy(temp, this->buff);
        strcat(temp, s.buff);
        return temp; //这里会调用有参构造函数
    }
    int size() {
        return this->__length;
    }

    char &at(int ind) {
        //at是需要判断边界的
        if (ind < 0 || ind >= __length) {
            cout << "String Error : out of range" << endl;
            return __end;
        } 
        return this->operator[](ind);
    }

 private:
    int __length, __buff_size;
    char *buff;
    char __end;
};

}


ostream &operator<<(ostream &out, const haizei::string &s) {
    out << s.c_str();
    return out;
}

int main() {
    haizei::string s1 = "hello world", s2 = ", haizei", s3 = ", harbin.";
    cout << s1 << endl;
    s1[3] = '6';
    cout << s1 << endl;
    cout << s1 + s2 + s3 << endl;
    for (int i = 0; i < s1.size(); i++) {
        cout << s1[i] << endl;
    }
    return 0;
}
