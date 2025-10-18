#include <iostream>
#include <Windows.h>
#include <string>

class Figure
{
protected:
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
	
public:
	Triangle(int a, int b, int c, int A, int B, int C) : Figure(a, b, c, A, B, C) {}
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
	
public:
	RightTriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, 90) {}

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
public:
	IsoscelesTriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c = a, A, B, C = A) {}
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
public:
	EquilateralTriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b = a, c = b, A = 60, B = A, C = B) {}
	void print_info() override
	{
		std::cout << "Равносторонний треугольник: " << std::endl;
		std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
		std::cout << "Углы: a=" << A << " b=" << B << " c=" << C << std::endl;
		std::cout << std::endl;
	}
};

class Quadrangle : public Figure                //Четырёхугольник
{
public:
	Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) : Figure(a, b, c, d, A, B, C, D) {}
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
public:
	Rectangle1(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c = a, d = b, A = 90, B = A, C = B, D = C) {}
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
public:
	Square(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c, d, A, B, C = 90, D) {}
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
public:
	Parallelogram(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c = a, d = b, A, B, C = A, D = B) {}
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
public:
	Rhombus(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b = a, c = b, d = c, A, B, C = A, D = B) {}
	void print_info() override
	{
		std::cout << "Ромб:" << std::endl;
		std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
		std::cout << "Углы: a=" << A << " b=" << B << " c=" << C << " D=" << D << std::endl;
		std::cout << std::endl;
	}
};

void print_info(Figure* figure)
{
	figure->print_info();  
}
 

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	Triangle triangle{ 10,20,30,50,60,70 };
	print_info(&triangle);

	RightTriangle rightTriangle{ 10,20,30,50,60,90 };
	print_info(&rightTriangle);

	IsoscelesTriangle isoscelesTriangle{ 10,20,30,50,60,50 };
	print_info(&isoscelesTriangle);

	EquilateralTriangle equilateralTriangle{ 30,30,30,60,60,60 };
	print_info(&equilateralTriangle);

	Quadrangle quadrangle{ 10,20,30,40,50,60,70,80, };
	print_info(&quadrangle);

	Rectangle1 rectangle1{ 10,20,10,20,90,90,90,90 };
	print_info(&rectangle1);

	Square square{ 20,20,20,20,90,90,90,90 };
	print_info(&square);

	Parallelogram parallelogram{ 20,30,20,30,30,40,30,40 };
	print_info(&parallelogram);

	Rhombus rhombus{ 30,30,30,30,30,40,30,40 };
	print_info(&rhombus);

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
	