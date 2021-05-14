class Matrix {
public:
    Matrix& operator *= (double scalar);

private:
    static const int MATRIX_SIZE = 3;
    double entries[MATRIX_SIZE][MATRIX_SIZE];
};

// const Matrix Matrix::operator * (double scalar) const {
//     Matrix result = *this;
//     result *= scalar;
//     return result;
// }

const Matrix operator * (double scalar, const Matrix& matrix) {
    Matrix result = matrix;
    matrix *= scalar;
    return result;
}

const Matrix operator * (const Matrix& matrix, double scalar) {
    return scalar * matrix;
}

