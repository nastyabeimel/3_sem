#include <cassert>
#include <iostream>
#include "Matrix.h"
#include "RandomGenerator.h"
#include "SimpleExercise.h"

using namespace miit::algebra;

void test_matrix_fill_and_shift() {
    Matrix m(2, 3);
    m.fill(5);
    for (size_t i = 0; i < m.getRows(); ++i)
        for (size_t j = 0; j < m.getCols(); ++j)
            assert(m(i, j) == 5);
    m << 1;
    assert(m(0, 0) == 5 && m(0, 1) == 5 && m(0, 2) == 5); // сдвиг не меняет значения
    m >> 2;
    assert(m(1, 0) == 5 && m(1, 1) == 5 && m(1, 2) == 5);
}

void test_random_generator() {
    RandomGenerator gen(1, 3);
    int v = gen.generate();
    assert(v >= 1 && v <= 3);
}

void test_exercise_task1_task2() {
    RandomGenerator gen(1, 2);
    SimpleExercise ex(2, 2, &gen);
    ex.Task1();
    const Matrix& m = ex.getMatrix();
    for (size_t i = 0; i < m.getRows(); ++i)
        for (size_t j = 0; j < m.getCols(); ++j)
            assert(m(i, j) == 1 || m(i, j) == 2);
    int before = m(0, 0);
    ex.Task2();
    // после сдвига вправо первый элемент изменится
    assert(m(0, 0) != before || m(1, 0) != before);
}

int main() {
    test_matrix_fill_and_shift();
    test_random_generator();
    test_exercise_task1_task2();
    std::cout << "Все тесты пройдены успешно!" << std::endl;
    return 0;
}
