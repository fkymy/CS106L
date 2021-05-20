#include <cstring>
#include <string>
using namespace std;

class Base {
public:
    Base();
    Base(const Base& other);
    Base& operator=(const Base& other);
    virtual ~Base();
private:
};

class Derived: public Base {
public:
    Derived();
    Derived(const Derived& other);
    Derived& operator=(const Derived& other);
    virtual ~Derived();
private:
    char* text;
    void copyOther(const Derived& other);
    void clear();
};

void Derived::copyOther(const Derived& other) {
    text = new char[strlen(other.text) + 1];
    strcpy(text, other.text);
}

void Derived::clear() {
    delete [] text;
    text = 0;
}

Derived::Derived(const Derived& other) : Base(other) {
    copyOther(other);
}

Derived& Derived::operator=(const Derived &other) {
    if (this != &other) {
        clear();
        Base::operator=(other);
        copyOther(other);
    }
    return *this;
}
