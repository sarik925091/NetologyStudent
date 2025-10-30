#ifndef ISOSCELES_TRIANGLE_H
#define ISOSCELES_TRIANGLE_H

#include "Triangle.h"

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(std::string name, int a, int b, int c, int A, int B, int C);
    void print_info() override;
};

#endif