#ifndef SQUARE_H
#define SQUARE_H

#include "Quadrangle.h"

class Square : public Quadrangle {
public:
    Square(std::string name, int a, int b, int c, int d, int A, int B, int C, int D);
    void print_info() override;
};

#endif