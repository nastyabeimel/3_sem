#pragma once
#include <vector>
#include <string>
#include <stdexcept>

namespace miit::algebra {
class Matrix {
private:
    std::vector<std::vector<int>> data;
    size_t rows, cols;
public:
    Matrix();
    Matrix(size_t rows, size_t cols);
    Matrix(const Matrix& other);
    Matrix(Matrix&& other) noexcept;
    ~Matrix();
    Matrix& operator=(const Matrix& other);
    Matrix& operator=(Matrix&& other) noexcept;
    std::string toString() const;
    int& operator()(size_t row, size_t col);
    const int& operator()(size_t row, size_t col) const;
    Matrix& operator<<(int shift);
    Matrix& operator>>(int shift);
    size_t getRows() const;
    size_t getCols() const;
    void fill(int value);
    void fillWithGenerator(class Generator& gen);
};
}
