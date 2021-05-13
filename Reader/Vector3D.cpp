#include <iostream>

class Vector3D {
public:

    Vector3D& operator += (const Vector3D& other);
    const Vector3D operator + (const Vector3D& other) const;
    Vector3D& operator -= (const Vector3D& other);
    Vector3D& operator *= (double scaleFactor);
    Vector3D& operator /= (double scaleFactor);
    const Vector3D operator- () const;

private:
    static const int NUM_COORDINATES = 3;
    double coordinates[NUM_COORDINATES];
};

const Vector3D Vector3D::operator + (const Vector3D& other) const {
    Vector3D result = *this;
    result += other;
    return result;
}

Vector3D& Vector3D::operator += (const Vector3D& other) {
    for (int i = 0; i < NUM_COORDINATES; ++i)
        coordinates[i] += other.coordinates[i];
    return *this;
}

Vector3D& Vector3D::operator -= (const Vector3D& other) {
    *this += -other;
    return *this;
}

Vector3D& Vector3D::operator *= (double scaleFactor) {
    for (int k = 0; k < NUM_COORDINATES; ++k)
        coordinates[k] *= scaleFactor;
    return *this;
}

Vector3D& Vector3D::operator /= (double scaleFactor) {
    // operator*= (1.0 / scaleFactor);
    *this *= 1.0 / scaleFactor;
    return *this;
}

const Vector3D Vector3D::operator- () const {
    Vector3D result;
    for (int i = 0; i < NUM_COORDINATES; ++i)
        result.coordinates[i] = -coordinates[i];
    return result;
}
