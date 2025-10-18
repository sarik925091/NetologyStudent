#include "RightTriangle.h"
#include <iostream>

RightTriangle::RightTriangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A) 
{
}

void RightTriangle::print_info() 
{
    std::cout << "Равнобедренный треугольник:" << std::endl;
    std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
    std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << std::endl;
    std::cout << std::endl;
}