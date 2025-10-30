#include "Quadrangle.h"
#include <iostream>

Quadrangle::Quadrangle(std::string name, int a, int b, int c, int d, int A, int B, int C, int D)
    : Figure(a, b, c, d, A, B, C, D) //Четырёхугольник (стороны и углы произвольные, количество сторон равно 4, сумма углов равна 360);
{
    if (name == "Quadrangle" && A + B + C + D != 360) { throw MyClassExcp("сумма углов не равна 360"); }
}

void Quadrangle::print_info() 
{
    std::cout << "Четырёхугольник (стороны " << a << ", " << b << ", " << c << ", " << d << "; " << "углы " << A << ", " << B << ", " << C << ", " << D << ")" << std::endl;
}