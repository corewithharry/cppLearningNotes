/*************************************************************************
	> File Name: 16.inherit_permission.cpp
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年07月28日 星期二 18时53分16秒
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

class Animal {
 public:
    Animal(string name, int age) : __name(name), age(age) {}
    void say() {
        cout << "my name is: " << __name  << "my age is: " << age << endl;
    }
 protected:
    string __name;

 private:
    int age;
};



class Cat : public Animal {
 public :
    Cat() = delete;
    Cat(string name, int age) : Animal(name, age) {}

};

class Bat : protected Animal {
 public:
    Bat() = delete;
    Bat(string name, int age) : Animal(name, age) {}
    void say() {
        //this->Animal::say();
        Animal::say();
        cout << "Bat name: " << __name << endl;
        //cout << "Bat age: " << age << endl; //访问不了
    }
};

int main() {
    Cat a("kitty", 29); 
    a.say();
    Bat b("hug", 16384);
    b.say();
    return 0;
}
