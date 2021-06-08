#include <iostream>
using namespace std;

class Base
{
public:
    Base() { fn(); }
    virtual void fn() { cout << "BASE" << endl; }
};

class Derived: public Base
{
public:
    virtual void fun() { cout << "DERIVED" << endl; }
};

int main() {
    Base b;

}
