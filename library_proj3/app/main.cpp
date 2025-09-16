
#include <iostream>
#include "Matrix.h"
#include "RandomGenerator.h"
#include "SimpleExercise.h"

using namespace miit::algebra;

int main() {
    // Создаём генератор случайных чисел от 1 до 9
    RandomGenerator randGen(1, 9);
    // Создаём упражнение с матрицей 3x4
    SimpleExercise ex(3, 4, &randGen);
    // Заполняем матрицу
    ex.Task1();
    std::cout << "Матрица после заполнения:\n" << ex.getMatrix().toString() << std::endl;
    // Сдвигаем строки вправо
    ex.Task2();
    std::cout << "Матрица после сдвига вправо:\n" << ex.getMatrix().toString() << std::endl;
    return 0;
}
