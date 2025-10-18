#include "RightTriangle.h"
#include <iostream>

RightTriangle::RightTriangle(int a, int b, int c,int A, int B) : Triangle(a, b, c, A, B, 90) 
{
}

void RightTriangle::print_info() 
{
    std::cout << "Равнобедренный треугольник:" << std::endl;
    std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
    std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << std::endl;
    std::cout << std::endl;
}