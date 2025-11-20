#include "Rhombus.h"
#include <iostream>

Rhombus::Rhombus(int a, int A, int B)
    : Quadrangle(a, a, a, a, A, B, A, B) {
}

void Rhombus::print_info() {
    std::cout << "Ромб:" << std::endl;
    std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
    std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
    std::cout << std::endl;
}