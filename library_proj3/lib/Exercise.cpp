#include "Exercise.h"

using namespace miit::algebra;

Exercise::Exercise(size_t rows, size_t cols, Generator* gen)
    : matrix(rows, cols), generator(gen) {}

const Matrix& Exercise::getMatrix() const {
    return matrix;
}
