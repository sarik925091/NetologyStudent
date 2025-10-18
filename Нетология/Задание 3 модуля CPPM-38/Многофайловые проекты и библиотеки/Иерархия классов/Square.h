#ifndef SQUARE_H
#define SQUARE_H

#include "Quadrangle.h"

class Square : public Quadrangle {
public:
    Square(int a);
    void print_info() override;
};

#endif