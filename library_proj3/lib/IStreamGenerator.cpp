#include "IStreamGenerator.h"

using namespace miit::algebra;

IStreamGenerator::IStreamGenerator(std::istream& in) : in(in) {}

int IStreamGenerator::generate() {
    int value = 0;
    in >> value;
    return value;
}
