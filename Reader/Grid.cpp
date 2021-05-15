#include <cstddef>
#include <vector>

template <typename T> class grid {
public:
    /* Constructors, destructors */
    grid();
    grid(size_t rows, size_t cols);

    /* Resizing operations */
    void clear();
    void resize(size_t rows, size_t cols);

    /* Query operations */
    size_t numRows() const;
    size_t numCols() const;
    bool empty() const;
    size_t size() const;

    /* Element access */
    T& getAt(size_t row, size_t col);
    const T& getAt(size_t row, size_t col) const;

private:
    std::vector<T> elems;
    size_t rows;
    size_t cols;
};
