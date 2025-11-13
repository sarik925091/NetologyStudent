#ifndef FIGURE_H
#define FIGURE_H
#ifndef __EXPORT
#define __EXPORT __declspec(dllexport)
#else
#define EXPORT_DYNAMIC_USER_LIB __declspec(dllimport)
#endif

class Figure {
protected:
    int a, b, c, d;
    int A, B, C, D;

public:
    __EXPORT Figure(int a1, int b1, int c1, int A1, int B1, int C1);
    __EXPORT Figure(int a1, int b1, int c1, int d1, int A1, int B1, int C1, int D1);
    __EXPORT virtual void print_info();
};

#endif