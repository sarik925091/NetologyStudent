#include "EquilateralTriangle.h"
#include <iostream>

EquilateralTriangle::EquilateralTriangle(int a)
    : Triangle(a, a, a, 60, 60, 60) {
}

void EquilateralTriangle::print_info() {
    std::cout << "Равносторонний треугольник: " << std::endl;
    std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
    std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << std::endl;
    std::cout << std::endl;
}