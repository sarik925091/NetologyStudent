#ifndef QUADRANGLE_H
#define QUADRANGLE_H

#include "Figure.h"

class Quadrangle : public Figure {
public:
    Quadrangle(std::string name, int a, int b, int c, int d, int A, int B, int C, int D);
    void print_info() override;
};

#endif