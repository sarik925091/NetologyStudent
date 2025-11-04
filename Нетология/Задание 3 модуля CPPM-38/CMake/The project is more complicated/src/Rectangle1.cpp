#include "Rectangle1.h"
#include <iostream>

Rectangle1::Rectangle1(int a, int b)
    : Quadrangle(a, b, a, b, 90, 90, 90, 90) {
}

void Rectangle1::print_info() {
    std::cout << "Прямоугольник:" << std::endl;
    std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
    std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
    std::cout << std::endl;
}