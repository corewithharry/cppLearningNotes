/*************************************************************************
	> File Name: 40.visitor2.cpp
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年08月20日 星期四 10时45分40秒
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


class Cat;
class Dog;
class Mouse;
class Bat;


class Animal {
public:
    class IVisitor {
    public:
        virtual void visit(Cat *) = 0;
        virtual void visit(Dog *) = 0;
        virtual void visit(Mouse *) = 0;
        virtual void visit(Bat *) = 0;
    };
    virtual void Accept(IVisitor *) = 0;
    virtual ~Animal() {}
};


class Cat : public Animal {
public:
    virtual void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};

class Dog : public Animal {
public:
    virtual void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};

class Mouse : public Animal {
public:
    virtual void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};

class Bat : public Animal {
public:
    virtual void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};

class AnimalCout: public Animal::IVisitor {
    virtual void visit(Cat *obj) {
        cout << "this is a cat" << endl; 
    }
    virtual void visit(Dog *obj) {
        cout << "this is a dog" << endl; 
    }
    virtual void visit(Mouse *obj) {
        cout << "this is a mouse" << endl; 
    }
    virtual void visit(Bat *obj) {
        cout << "this is a bat" << endl; 
    }
};


//用访问者模式统计子类的数量
class AnimalCnt: public Animal::IVisitor {
public:
    AnimalCnt() : valCat(0), valDog(0), valMouse(0), valBat(0) {}
    virtual void visit(Cat *obj) {
        valCat++;
    }
    virtual void visit(Dog *obj) {
        valDog++;
    }
    virtual void visit(Mouse *obj) {
        valMouse++;
    }
    virtual void visit(Bat *obj) {
        valBat++;
    }
    int valCat, valDog, valMouse, valBat;
};



int main() {
    srand(time(0));
    Animal *arr[10];
    for (int i = 0; i < 10; i++) {
        switch(rand() % 4) {
            case 0: arr[i] = new Cat(); break;
            case 1: arr[i] = new Dog(); break;
            case 2: arr[i] = new Mouse(); break;
            case 3: arr[i] = new Bat(); break;
        }
    }


    AnimalCout vis;
    AnimalCnt cnt;
    for (int i = 0; i < 10; i++) {
        //写 if 的缺点
        //1、整加个子类，忘记添加分支，代码不会报错
        //2、多次判断效率低
        /*if (dynamic_cast<Cat *>(arr[i])) {
            cout << "this is a cat" << endl; 
        } else if (dynamic_cast<Dog *>(arr[i])) {
            cout << "this is a dog" << endl; 
        } else if (dynamic_cast<Mouse *>(arr[i])) {
            cout << "this is a mouse" << endl; 
        } else if (dynamic_cast<Bat *>(arr[i])) {
            cout << "this is a bat" << endl; 
        } else {
            cout << "error" << endl;
        }
        */
        arr[i]->Accept(&vis);
        arr[i]->Accept(&cnt);
    }
    
    cout << "cat: " << cnt.valCat << endl;
    cout << "dog: " << cnt.valDog << endl;
    cout << "mouse: " << cnt.valMouse << endl;
    cout << "bat: " << cnt.valBat << endl;
    return 0;
}
