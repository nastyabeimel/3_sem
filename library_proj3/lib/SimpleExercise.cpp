#include "SimpleExercise.h"

using namespace miit::algebra;

SimpleExercise::SimpleExercise(size_t rows, size_t cols, Generator* gen)
    : Exercise(rows, cols, gen) {}

void SimpleExercise::Task1() {
    // Заполнение матрицы генератором
    matrix.fillWithGenerator(*generator);
}

void SimpleExercise::Task2() {
    // Сдвиг всех строк матрицы вправо на 1
    matrix >> 1;
}
