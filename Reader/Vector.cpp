#include <cstddef>
#include <algorithm>

template <typename T> class Vector {
public:
    Vector();
    Vector(const Vector& other);
    Vector& operator=(const Vector& other);
    ~Vector();

    typedef T* iterator;
    typedef const T* const_iterator;

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

    void clear();
    void copyOther(const Vector& other);

private:
    T* array;
    size_t allocatedLength;
    size_t logicalLength;
    static const size_t kStartSize = 16;
};

template <typename T> Vector<T>::Vector() {
    allocatedLength = kStartSize;
    logicalLength = 0;
    array = new T[allocatedLength];
}

template <typename T> Vector<T>::~Vector() {
    clear();
}

template <typename T> Vector<T>::Vector(const Vector& other) {
    copyOther(other);
}

template <typename T> Vector<T>& Vector<T>::operator=(const Vector& other) {
    if (this != &other) {
        clear();
        copyOther(other);
    }
    return *this;
}

template <typename T> void Vector<T>::clear() {
    delete [] array;
}

template <typename T> void Vector<T>::copyOther(const Vector<T> &other) {
    logicalLength = other.logicalLength;
    allocatedLength = other.allocatedLength;

    array = new T[allocatedLength];
    // for (size_t i = 0; i < logicalLength; ++i)
    //     array[i] = other.array[i];
    std::copy(other.begin(), other.end(), array);
}

