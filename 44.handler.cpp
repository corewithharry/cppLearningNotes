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
    class IHandler {
    public:
        IHandler() : next(nullptr) {}
        virtual bool is_valid(int x) = 0;
        virtual ICar* do_it() = 0;
        IHandler *next;
    };
    virtual void run() = 0;
protected:
    ICar() {}
    ~ICar() {}
};



class BenzCar : public ICar {
    BenzCar() {}
public:
    class Factory : public ICar::IFactory, public ICar::IHandler {
    public:
        virtual ICar *create() {
            return new BenzCar();
        }
        virtual bool is_valid(int x) {
            return x == 0;
        }
        virtual ICar* do_it() {
            return this->create();
        }
    };
    virtual void run() {
        cout << "BenzCar run" << endl;
    }
};
class BmwCar : public ICar {
    BmwCar() {}
public:
    class Factory : public ICar::IFactory, public ICar::IHandler {
    public:
        virtual ICar *create() {
            return new BmwCar();
        }
        virtual bool is_valid(int x) {
            return x == 1;
        }
        virtual ICar* do_it() {
            return this->create();
        }
    };
    virtual void run() {
        cout << "BmwCar run" << endl;
    }
};
class AudiCar : public ICar {
    AudiCar() {}
public:
    class Factory : public ICar::IFactory, public ICar::IHandler {
    public:
        virtual ICar *create() {
            return new AudiCar();
        }
        virtual bool is_valid(int x) {
            return x == 2;
        }
        virtual ICar* do_it() {
            return this->create();
        }
    };
    virtual void run() {
        cout << "AudiCar run" << endl;
    }
};

class ChainMaster {
public:
    static ICar::IHandler *getInstance() {
        if (head == nullptr) {
            buildChain();
        }
        return head;
    }
private:
    static ICar::IHandler *head;
    static void buildChain() {
        head = new BmwCar::Factory();
        head->next = new AudiCar::Factory();
        head->next->next = new BenzCar::Factory();
        return ;
    }
};

ICar::IHandler *ChainMaster::head = nullptr;

int main() {
    srand(time(0));
    ICar *cars[10];
    for (int i = 0; i < 10; i++) {
        int req = rand() % 3;
        for (auto p = ChainMaster::getInstance(); p; p = p->next) {
            if (p->is_valid(req)) {
                cars[i] = p->do_it();
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        cars[i]->run();
    }
    return 0;
}
