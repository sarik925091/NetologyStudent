#ifndef EQUILATERAL_TRIANGLE_H
#define EQUILATERAL_TRIANGLE_H

#include "Triangle.h"

class EquilateralTriangle : public Triangle {
public:
    __EXPORT EquilateralTriangle(int a);
    __EXPORT void print_info() override;
};

#endif