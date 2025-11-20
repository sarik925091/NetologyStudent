#ifndef RHOMBUS_H
#define RHOMBUS_H


#include "Quadrangle.h"

class Rhombus : public Quadrangle {
public:
    __EXPORT Rhombus(int a, int A, int B);
    __EXPORT void print_info() override;
};

#endif