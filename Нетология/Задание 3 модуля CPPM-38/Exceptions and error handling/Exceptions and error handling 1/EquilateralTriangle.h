#ifndef EQUILATERAL_TRIANGLE_H
#define EQUILATERAL_TRIANGLE_H

#include "Triangle.h"

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(std::string name, int a, int b, int c, int A, int B, int C);
    void print_info() override;
};

#endif