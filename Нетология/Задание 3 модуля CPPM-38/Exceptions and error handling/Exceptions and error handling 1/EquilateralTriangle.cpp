#include "EquilateralTriangle.h"
#include <iostream>

EquilateralTriangle::EquilateralTriangle(std::string name, int a, int b, int c, int A, int B, int C )
    : Triangle(name, a, b, c, A, B, C) //Равносторонний треугольник: (все стороны равны, все углы равны 60);
{
    if (a != b && b != c && c != a && A!= 60 && B != 60 && C != 60) { throw MyClassExcp("все стороны не равны и все углы не равны 60"); }
}

void EquilateralTriangle::print_info() 
{
    std::cout << "Равносторонний треугольник (стороны " << a << ", " << b << ", " << c << "; " << "углы " << A << ", " << B << ", " << C << ")" << std::endl;
}