#include "Rhombus.h"
#include <iostream>

Rhombus::Rhombus(std::string name, int a, int b, int c, int d, int A, int B, int C, int D)
    : Quadrangle(name, a, b, c, d, A, B, C, D)    //Ромб (все стороны равны, углы A,C и B,D попарно равны)
{
    if (a != b && b != c && c != d && d != a && A != C && B != D) { throw MyClassExcp("стороны не равны, углы A,C и B,D не равны"); }
}

void Rhombus::print_info() 
{
    std::cout << "Ромб (стороны " << a << ", " << b << ", " << c << ", " << d << ";" << "углы " << A << ", " << B << ", " << C << "," << D << ")" << std::endl;
}