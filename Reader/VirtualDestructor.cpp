class BaseClass
{
public:
    BaseClass();
    virtual ~BaseClass() = 0; // Polymorphic classes need virtual destructors

    virtual void doSomething();
private:
    int baseX, baseY;
};

BaseClass::~BaseClass() {} // pure virtual destructor still needs to be implemented

class DerivedClass: public BaseClass
{
public:
    DerivedClass();
    ~DerivedClass();

    virtual void doSomething();
private:
    char *myString;
    int derX, derY;
};

DerivedClass::DerivedClass() {
    myString = new char[128];
}

DerivedClass::~DerivedClass() {
    delete [] myString;
}
