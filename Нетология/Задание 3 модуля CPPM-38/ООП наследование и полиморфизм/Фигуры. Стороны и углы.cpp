#include <iostream>
#include <Windows.h>
#include <string>

class Figure
{
private:
	int a, b, c, d;
	int A, B, C, D;
public:
	Figure(int a1, int b1, int c1, int A1, int B1, int C1) :
		a(a1), b(b1), c(c1), A(A1), B(B1), C(C1)
	{
	}
	Figure(int a1, int b1, int c1, int d1, int A1, int B1, int C1, int D1) : 
		a(a1), b(b1), c(c1), d(d1), A(A1), B(B1), C(C1), D(D1)
	{
	}
	virtual void print_info()
	{
	}
};

class Triangle : public Figure                   //Треугольник
{
	int a, b, c;
	int A, B, C;
public:
	Triangle(int a, int b, int c, int A, int B, int C) : Figure(a, b, c, A, B, C), 
		a(a), b(b), c(c), A(A), B(B), C(C)
	{
	}
	virtual void print_info() override
	{
		std::cout << "Треугольник:" << std::endl;
		std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
		std::cout << "Углы: a=" << A << " b=" << B << " c=" << C << std::endl;
		std::cout << std::endl;
	}
};

class RightTriangle : public Triangle                  //Прямоугольный треугольник: (угол C всегда равен 90);
{
	int a, b, c;
	int A, B, C = 90;
public:
	RightTriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, this->C), 
		a(a), b(b), c(c), A(A), B(B)
	{}

	void print_info() override
	{
		std::cout << "Прямоугольный треугольник:" << std::endl;
		std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
		std::cout << "Углы: a=" << A << " b=" << B << " c=" << C << std::endl;
		std::cout << std::endl;
	}
};

class IsoscelesTriangle : public Triangle                   //Равнобедренный треугольник: (стороны a и c равны, углы A и C равны);
{
	int a, b, c = a;
	int A, B, C = A;
public:
	IsoscelesTriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c = a, A, B, C = A),
		a(a), b(b),  A(A), B(B)
	{}
	void print_info() override
	{
		std::cout << "Равнобедренный треугольник:" << std::endl;
		std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
		std::cout << "Углы: a=" << A << " b=" << B << " c=" << C << std::endl;
		std::cout << std::endl;
	}
};

class EquilateralTriangle : public Triangle                 //Равносторонний треугольник: (все стороны равны, все углы равны 60);
{
	int a, b = a, c = b;
	int A = 60, B = A, C = B;   
public:
	EquilateralTriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b = a, c = b, this->A, this->B, this->C),
		a(a)
	{}
	void print_info() override
	{
		std::cout << "Равносторонний треугольник:" << std::endl;
		std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
		std::cout << "Углы: a=" << A << " b=" << B << " c=" << C << std::endl;
		std::cout << std::endl;
	}
};

class Quadrangle : public Figure                //Четырёхугольник
{
	int a, b, c, d;
	int A, B, C, D;
public:
	Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) : Figure(a, b, c, d, A, B, C, D),
		a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D)
	{
	}
	void print_info() override
	{
		std::cout << "Четырёхугольник:" << std::endl;
		std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
		std::cout << "Углы: a=" << A << " b=" << B << " c=" << C << " D=" << D << std::endl;
		std::cout << std::endl;
	}
};

class Rectangle1 : public Quadrangle                         //Прямоугольник (стороны a,c и b,d попарно равны, все углы равны 90);
{
	int a, b, c = a, d = b;
	int A = 90, B = A, C = B, D = C;
public:
	Rectangle1(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c=a, d=b, this->A, this->B, this->C, this->D),
		a(a), b(b)
	{
	}
	void print_info() override
	{
		std::cout << "Прямоугольник:" << std::endl;
		std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
		std::cout << "Углы: a=" << A << " b=" << B << " c=" << C << " D=" << D << std::endl;
		std::cout << std::endl;
	}
};

class Square : public Quadrangle                            //Квадрат (угол C всегда равен 90);
{
	int a, b, c, d;
	int A, B, D, C = 90;
public:
	Square(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c, d, A, B, this->C, D),
		a(a), b(b), c(c), d(d), A(A), B(B), D(D)
	{
	}
	void print_info() override
	{
		std::cout << "Квадрат:" << std::endl;
		std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
		std::cout << "Углы: a=" << A << " b=" << B << " c=" << C << " D=" << D << std::endl;
		std::cout << std::endl;
	}

};

class Parallelogram : public Quadrangle                  //Параллелограмм (стороны a,c и b,d попарно равны, углы A,C и B,D попарно равны);
{
	int a, b, c = a, d = b;
	int A, B, C = A, D = B;
public:
	Parallelogram(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c=a, d=b, A, B, C=A, D=B),
		a(a), b(b), A(A), B(B)
	{
	}
	void print_info() override
	{
		std::cout << "Параллелограмм:" << std::endl;
		std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
		std::cout << "Углы: a=" << A << " b=" << B << " c=" << C << " D=" << D << std::endl;
		std::cout << std::endl;
	}
};

class Rhombus : public Quadrangle                        //Ромб (все стороны равны, углы A,C и B,D попарно равны).
{
	int a, b = a, c = b, d = c;
	int A, B, C = A, D = B;
public:
	Rhombus(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c, d, A, B, C = A, D = B),
		a(a), A(A), B(B)
	{
	}
	void print_info() override
	{
		std::cout << "Ромб:" << std::endl;
		std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
		std::cout << "Углы: a=" << A << " b=" << B << " c=" << C << " D=" << D << std::endl;
		std::cout << std::endl;
	}

};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	Triangle triangle{ 10,20,30,50,60,70 };
	Figure* f_triangle{ &triangle };
	f_triangle->print_info();

	RightTriangle rightTriangle{ 10,20,30,50,60,90 };
	Figure* f_rightTriangle{ &rightTriangle };
	f_rightTriangle->print_info();

	IsoscelesTriangle isoscelesTriangle{ 10,20,30,50,60,50 };
	Figure* f_isoscelesTriangle{ &isoscelesTriangle };
	f_isoscelesTriangle->print_info();

	EquilateralTriangle equilateralTriangle{ 30,30,30,60,60,60 };
	Figure* f_equilateralTriangle{ &equilateralTriangle };
	f_equilateralTriangle->print_info();

	Quadrangle quadrangle{ 10,20,30,40,50,60,70,80, };
	Figure* f_quadrangle{ &quadrangle };
	f_quadrangle->print_info();

	Rectangle1 rectangle1{ 10,20,10,20,90,90,90,90 };
	Figure* f_rectangle1{ &rectangle1 };
	f_rectangle1->print_info();

	Square square{ 20,20,20,20,90,90,90,90 };
	Figure* f_square{ &square };
	f_square->print_info();

	Parallelogram parallelogram{ 20,30,20,30,30,40,30,40 };
	Figure* f_parallelogram{ &parallelogram };
	f_parallelogram->print_info();

	Rhombus rhombus{ 30,30,30,30,30,40,30,40 };
	Figure* f_rhombus{ &rhombus };
	f_rhombus->print_info();

	return 0;
}

//Triangle:
//Sides: a = 10 b = 20 c = 30
//Angles : A = 50 B = 60 C = 70
//
//Right Triangle :
//Sides: a = 10 b = 20 c = 30
//Angles : A = 50 B = 60 C = 90
//
//Isosceles Triangle :
//Sides: a = 10 b = 20 c = 10
//Angles : A = 50 B = 60 C = 50
//
//Equilateral Triangle :
//Sides: a = 30 b = 30 c = 30
//Angles : A = 60 B = 60 C = 60
//
//Quadrilateral :
//	Sides : a = 10 b = 20 c = 30 d = 40
//	Angles : A = 50 B = 60 C = 70 D = 80
//
//	Rectangle :
//	Sides : a = 10 b = 20 c = 10 d = 20
//	Angles : A = 90 B = 90 C = 90 D = 90
//
//	Square :
//	Sides : a = 20 b = 20 c = 20 d = 20
//	Angles : A = 90 B = 90 C = 90 D = 90
//
//	Parallelogram :
//	Sides : a = 20 b = 30 c = 20 d = 30
//	Angles : A = 30 B = 40 C = 30 D = 40
//
//	Rhombus :
//	Sides : a = 30 b = 30 c = 30 d = 30
//	Angles : A = 30 B = 40 C = 30 D = 40
	