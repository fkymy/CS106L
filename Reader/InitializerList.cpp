#include <iostream>
#include <string>
#include <vector>

class SimpleClass {
public:
    SimpleClass();

    const std::string& getString();

private:
    int myInt;
    std::string myString;
    std::vector<int> myVector;
};

// SimpleClass::SimpleClass() {
//     myInt = 5;
//     myString = "C++";
//     myVector.resize(10);
// }

SimpleClass::SimpleClass() : myInt(5), myString("C++"), myVector(10) {
    // empty constructor
}

const std::string& SimpleClass::getString() { return myString; }

class RationalNumber {
public:
    RationalNumber(int numerator = 0, int denominator = 1);

private:
    int numerator, denominator;
};

RationalNumber::RationalNumber(int numerator, int denominator)
    : numerator(numerator), denominator(denominator) {
    // empty
}

class Counter {
public:
    Counter(int maxValue);

    void increment();
    void decrement();
    int getValue() const;

private:
    int value;
    const int maximum;
};

Counter::Counter(int maxValue) : value(0), maximum(maxValue) {
    // empty
}

class SetWrapper {
public:
    SetWrapper();

private:
    Set<customT> mySet;
};

SetWrapper::SetWrapper() : mySet(MyCallback) {
    // empty
}


int main() {
    SimpleClass myClass;
    std::cout << myClass.getString() << std::endl;
    return 0;
}
