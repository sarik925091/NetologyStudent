#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

#include "Quadrangle.h"

class Parallelogram : public Quadrangle {
public:
    Parallelogram(std::string name, int a, int b, int c, int d, int A, int B, int C, int D);
    void print_info() override;
};

#endif