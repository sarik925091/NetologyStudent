#include "IsoscelesTriangle.h"
#include <iostream>

IsoscelesTriangle::IsoscelesTriangle(std::string name, int a, int b, int c, int A, int B, int C)
    : Triangle(name, a, b, c, A, B, C) //Равнобедренный треугольник: (стороны a и c равны, углы A и C равны);
{
    if (a != c && A != C) { throw MyClassExcp("стороны a и c, углы A и C не равны"); }
}

void IsoscelesTriangle::print_info() 
{
    std::cout << "Равнобедренный треугольник (стороны " << a<< ", " << b << ", " << c << "; " << "углы " << A << ", " << B << ", " << C << ")" << std::endl;
}