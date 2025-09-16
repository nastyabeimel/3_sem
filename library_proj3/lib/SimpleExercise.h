#pragma once
#include "Exercise.h"

namespace miit::algebra {
class SimpleExercise : public Exercise {
public:
    SimpleExercise(size_t rows, size_t cols, Generator* gen);
    void Task1() override;
    void Task2() override;
};
}
