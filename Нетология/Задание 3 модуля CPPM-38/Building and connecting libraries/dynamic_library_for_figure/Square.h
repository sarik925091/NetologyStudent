#ifndef SQUARE_H
#define SQUARE_H


#include "Quadrangle.h"

class Square : public Quadrangle {
public:
    __EXPORT Square(int a);
    __EXPORT void print_info() override;
};

#endif