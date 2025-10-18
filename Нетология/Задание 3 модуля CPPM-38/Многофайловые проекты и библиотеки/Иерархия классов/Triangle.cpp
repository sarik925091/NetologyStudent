#include "Triangle.h"
#include <iostream>

Triangle::Triangle(int a, int b, int c, int A, int B, int C)
    : Figure(a, b, c, A, B, C) {
}

void Triangle::print_info() {
    std::cout << "Треугольник:" << std::endl;
    std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
    std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << std::endl;
    std::cout << std::endl;
}