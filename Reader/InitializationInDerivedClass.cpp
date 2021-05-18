#include <string>
#include <vector>
using namespace std;

class Base
{
public:
    Base() : myInt(137), myString("Base string") {}
    virtual ~Base();
private:
    int myInt;
    string myString;
};

class Derived: public Base {
private:
    vector<int> myVector;
};
