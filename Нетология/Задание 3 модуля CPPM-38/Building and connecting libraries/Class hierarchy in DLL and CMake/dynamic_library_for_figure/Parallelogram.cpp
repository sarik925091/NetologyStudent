#include "Parallelogram.h"
#include <iostream>

Parallelogram::Parallelogram(int a, int b, int A, int B)
    : Quadrangle(a, b, a, b, A, B, A, B) {
}

void Parallelogram::print_info() {
    std::cout << "Параллелограмм:" << std::endl;
    std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
    std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
    std::cout << std::endl;
}