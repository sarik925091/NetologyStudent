#ifndef FIGURE_H
#define FIGURE_H

#include"2.myClass for exception.h"

class Figure {
protected:
    int a, b, c, d;
    int A, B, C, D;

public:
    Figure(int a1, int b1, int c1, int A1, int B1, int C1);
    Figure(int a1, int b1, int c1, int d1, int A1, int B1, int C1, int D1);
    virtual void print_info();
};

#endif