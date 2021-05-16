
class MyClass {
public:
    MyClass();
    ~MyClass();

    MyClass(const MyClass& other);
    MyClass& operator=(const MyClass& other);
};

MyClass::MyClass() : /* fill in initializer list. */ {

}

MyClass::MyClass(const MyClass& other) {
    copyOther(other);
}

MyClass& MyClass::operator=(const MyClass& other) {
    if (this != &other) {
        clear();
        // Note: When we cover inheritance, there's one more step here
        copyOther(other);
    }
    return *this;
}
