#include <string>
#include <iostream>
using namespace std;

class BaseClass {
    public:
    virtual void doSomething();
};

void BaseClass::doSomething() {
    cout << "base" << endl;
}

class DerivedClass: public BaseClass {
    public:
    virtual void doSomething();
};

void DerivedClass::doSomething() {
    cout << "derived" << endl;
}

int main() {
    BaseClass* b = new BaseClass;
    BaseClass* d = new DerivedClass;

    // override
    b->doSomething();
    d->doSomething();

    return 0;
}
