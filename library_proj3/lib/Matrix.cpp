#include "Matrix.h"
#include "Generator.h"
#include <sstream>
#include <algorithm>

using namespace miit::algebra;

Matrix::Matrix() : rows(0), cols(0) {}

Matrix::Matrix(size_t r, size_t c) : rows(r), cols(c), data(r, std::vector<int>(c, 0)) {}

Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols), data(other.data) {}

Matrix::Matrix(Matrix&& other) noexcept : rows(other.rows), cols(other.cols), data(std::move(other.data)) {
    other.rows = 0; other.cols = 0;
}

Matrix::~Matrix() {}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        rows = other.rows;
        cols = other.cols;
        data = other.data;
    }
    return *this;
}

Matrix& Matrix::operator=(Matrix&& other) noexcept {
    if (this != &other) {
        rows = other.rows;
        cols = other.cols;
        data = std::move(other.data);
        other.rows = 0; other.cols = 0;
    }
    return *this;
}

std::string Matrix::toString() const {
    std::ostringstream oss;
    for (const auto& row : data) {
        for (int v : row) oss << v << ' ';
        oss << '\n';
    }
    return oss.str();
}

int& Matrix::operator()(size_t row, size_t col) {
    if (row >= rows || col >= cols) throw std::out_of_range("Matrix index out of range");
    return data[row][col];
}

const int& Matrix::operator()(size_t row, size_t col) const {
    if (row >= rows || col >= cols) throw std::out_of_range("Matrix index out of range");
    return data[row][col];
}

Matrix& Matrix::operator<<(int shift) {
    for (auto& row : data) std::rotate(row.begin(), row.begin() + shift % cols, row.end());
    return *this;
}

Matrix& Matrix::operator>>(int shift) {
    for (auto& row : data) std::rotate(row.begin(), row.end() - shift % cols, row.end());
    return *this;
}

size_t Matrix::getRows() const { return rows; }
size_t Matrix::getCols() const { return cols; }

void Matrix::fill(int value) {
    for (auto& row : data) std::fill(row.begin(), row.end(), value);
}

void Matrix::fillWithGenerator(Generator& gen) {
    for (auto& row : data)
        for (auto& v : row)
            v = gen.generate();
}
