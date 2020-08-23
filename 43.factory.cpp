/*************************************************************************
	> File Name: 44.factory.cpp
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年08月23日 星期日 09时14分34秒
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
#include <ctime>
using namespace std;

class ICar {
public:
    class IFactory {
    public:
        virtual ICar *create() = 0;
    };
    virtual void run() = 0;
protected:
    ICar() {}
    ~ICar() {}
};



class BenzCar : public ICar {
    BenzCar() {}
public:
    class Factory : public ICar::IFactory {
    public:
        virtual ICar *create() {
            return new BenzCar();
        }
    };
    virtual void run() {
        cout << "BenzCar run" << endl;
    }
};
class BmwCar : public ICar {
    BmwCar() {}
public:
    class Factory : public ICar::IFactory {
    public:
        virtual ICar *create() {
            return new BmwCar();
        }
    };
    virtual void run() {
        cout << "BmwCar run" << endl;
    }
};
class AudiCar : public ICar {
    AudiCar() {}
public:
    class Factory : public ICar::IFactory {
    public:
        virtual ICar *create() {
            return new AudiCar();
        }
    };
    virtual void run() {
        cout << "AudiCar run" << endl;
    }
};

ICar::IFactory *fac[3] = {new BenzCar::Factory(), new BmwCar::Factory(), new AudiCar::Factory()};


int main() {
    srand(time(0));
    ICar *cars[10];
    for (int i = 0; i < 10; i++) {
        cars[i] = fac[rand() % 3]->create();
    }
    for (int i = 0; i < 10; i++) {
        cars[i]->run();
    }
    return 0;
}
