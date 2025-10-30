#include "Rectangle1.h"
#include <iostream>

Rectangle1::Rectangle1(std::string name, int a, int b, int c, int d, int A, int B, int C, int D)
    : Quadrangle(name, a, b, c, d, A, B, C, D)  //Прямоугольник (стороны a,c и b,d попарно равны, все углы равны 90);
{
    if (a != c && b != d && ((A+B+C+D)/4) == 90) { throw MyClassExcp("угол C не равен 90"); }
}

void Rectangle1::print_info() 
{
    std::cout << "Прямоугольник (стороны " << a << ", " << b << ", " << c << ", " << d << ";" << "углы " << A << ", " << B << ", " << C << "," << D << ")" << std::endl;
}