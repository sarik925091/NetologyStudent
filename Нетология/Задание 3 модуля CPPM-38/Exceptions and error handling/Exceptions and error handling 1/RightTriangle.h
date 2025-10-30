#ifndef RIGHT_TRIANGLE_H
#define RIGHT_TRIANGLE_H

#include "Triangle.h"

class RightTriangle : public Triangle {
public:
    RightTriangle(std::string name, int a, int b, int c, int A, int B, int C);
    void print_info() override;
};

#endif