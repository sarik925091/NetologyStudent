#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Figure.h"

class Triangle : public Figure {
public:
    Triangle(std::string name, int a, int b, int c, int A, int B, int C);
    virtual void print_info() override;
};

#endif