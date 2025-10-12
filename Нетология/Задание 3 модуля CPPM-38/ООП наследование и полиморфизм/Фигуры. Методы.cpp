#include <iostream>
#include <Windows.h>
#include <string>

class Figure                    //фигура (количество сторон равно 0);
{

private:
	int a, b, c, d;
	int A, B, C, D;
public:
	Figure() {};

	Figure(int a1, int b1, int c1, int A1, int B1, int C1) : 
		a(a1), b(b1), c(c1), A(A1), B(B1), C(C1),     d(0), D(0)
	{
	}
	Figure(int a1, int b1, int c1, int d1, int A1, int B1, int C1, int D1) :
		a(a1), b(b1), c(c1), d(d1), A(A1), B(B1), C(C1), D(D1)
	{
	}
	virtual void print_info()
	{
	}
	virtual void checkFigure(std::string& nameFigure)
	{
		if (nameFigure == "triangle")
		{
			if (A + B + C == 180){ std::cout << "правильная" << std::endl; }
			else { std::cout << "неправильная" << std::endl;}
			if (d == 0) { std::cout << "Количество сторон: 3" << std::endl; }
			else { std::cout << "Количество сторон: 4" << std::endl; }
		}
		else if (nameFigure == "rightTriangle")
		{
			if (C == 90) { std::cout << "правильная" << std::endl; }
			else { std::cout << "неправильная" << std::endl; }
			if (d == 0) { std::cout << "Количество сторон: 3" << std::endl; }
			else { std::cout << "Количество сторон: 4" << std::endl; }
		}
		else if (nameFigure == "isoscelesTriangle")
		{
			if (a == c && A == C) { std::cout << "правильная" << std::endl; }
			else { std::cout << "неправильная" << std::endl; }
			if (d == 0) { std::cout << "Количество сторон: 3" << std::endl; }
			else { std::cout << "Количество сторон: 4" << std::endl; }
		}
		else if (nameFigure == "equilateralTriangle")
		{
			if (a == b && b == c && A == 60 && B == A && C == B) { std::cout << "правильная" << std::endl; }
			else { std::cout << "неправильная" << std::endl; }
			if (d == 0) { std::cout << "Количество сторон: 3" << std::endl; }
			else { std::cout << "Количество сторон: 4" << std::endl; }
		}
		else if (nameFigure == "quadrangle")
		{
			if (A + B + C + D == 360) { std::cout << "правильная" << std::endl; }
			else { std::cout << "неправильная" << std::endl; }
			if (d == 0) { std::cout << "Количество сторон: 3" << std::endl; }
			else { std::cout << "Количество сторон: 4" << std::endl; }
		}
		else if (nameFigure == "rectangle1")
		{
			if (a == c && b == d && A + B + C + D == 90) { std::cout << "правильная" << std::endl; }
			else { std::cout << "неправильная" << std::endl; }
			if (d == 0) { std::cout << "Количество сторон: 3" << std::endl; }
			else { std::cout << "Количество сторон: 4" << std::endl; }
		}
		else if (nameFigure == "square")
		{
			if (C == 90) { std::cout << "правильная" << std::endl; }
			else { std::cout << "неправильная" << std::endl; }
			if (d == 0) { std::cout << "Количество сторон: 3" << std::endl; }
			else { std::cout << "Количество сторон: 4" << std::endl; }
		}
		else if (nameFigure == "parallelogram")
		{
			if (a == c && b == d && A == C && B == D ) { std::cout << "правильная" << std::endl; }
			else { std::cout << "неправильная" << std::endl; }
			if (d == 0) { std::cout << "Количество сторон: 3" << std::endl; }
			else { std::cout << "Количество сторон: 4" << std::endl; }
		}
		else if (nameFigure == "rhombus")
		{
			if (a == b && b == c && c == d && A == C && B == D) { std::cout << "правильная" << std::endl; }
			else { std::cout << "неправильная" << std::endl; }
			if (d == 0) { std::cout << "Количество сторон: 3" << std::endl; }
			else { std::cout << "Количество сторон: 4" << std::endl; }
		}
	}
	void check_Figur2()
	{
		std::cout << "Фигура: " << std::endl;
		std::cout << "правильная" << std::endl;
		std::cout << "Количество сторон: 0" << std::endl;
		std::cout << std::endl;
	}
};

class Triangle : public Figure            //Треугольник (стороны и углы произвольные, количество сторон равно 3, сумма углов равна 180);
{
	int a, b, c;
	int A, B, C;
	std::string nameFigure{ "triangle" };
public:
	Triangle(int a, int b, int c, int A, int B, int C) : Figure(a, b, c, A, B, C),
		a(a), b(b), c(c), A(A), B(B), C(C)
	{
	}
	virtual void print_info() override
	{
		std::cout << "Треугольник:" << std::endl;
		Figure::checkFigure(nameFigure);
		std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
		std::cout << "Углы: a=" << A << " b=" << B << " c=" << C << std::endl;
		std::cout << std::endl;
	}
};

class RightTriangle : public Triangle                  //Прямоугольный треугольник: (угол C всегда равен 90);
{
	int a, b, c;
	int A, B, C;
	std::string nameFigure_RT{ "rightTriangle" };
public:
	RightTriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C),
		a(a), b(b), c(c), A(A), B(B), C(C)
	{
	}

	void print_info() override
	{
		std::cout << "Прямоугольный треугольник:" << std::endl;
		Figure::checkFigure(nameFigure_RT);
		std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
		std::cout << "Углы: a=" << A << " b=" << B << " c=" << C << std::endl;
		std::cout << std::endl;
	}
};

class IsoscelesTriangle : public Triangle                   //Равнобедренный треугольник: (стороны a и c равны, углы A и C равны);
{
	int a, b, c ;
	int A, B, C ;
	std::string nameFigure_IT{ "isoscelesTriangle" };
public:
	IsoscelesTriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C),
		a(a), b(b),c(c), A(A), B(B), C(C)
	{
	}
	void print_info() override
	{
		std::cout << "Равнобедренный треугольник:" << std::endl;
		Figure::checkFigure(nameFigure_IT);
		std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
		std::cout << "Углы: a=" << A << " b=" << B << " c=" << C << std::endl;
		std::cout << std::endl;
	}
};

class EquilateralTriangle : public Triangle                 //Равносторонний треугольник: (все стороны равны, все углы равны 60);
{
	int a, b, c;
	int A ,B, C;
	std::string nameFigure_ET{ "equilateralTriangle" };
public:
	EquilateralTriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c , A, B, C),
		a(a), b(b), c(c), A(A), B(B), C(C)
	{
	}
	void print_info() override
	{
		std::cout << "Равносторонний треугольник:" << std::endl;
		Figure::checkFigure(nameFigure_ET);
		std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
		std::cout << "Углы: a=" << A << " b=" << B << " c=" << C << std::endl;
		std::cout << std::endl;
	}
};

class Quadrangle : public Figure    //Четырёхугольник (стороны и углы произвольные, количество сторон равно 4, сумма углов равна 360);
{
	int a, b, c, d;
	int A, B, C, D;
	std::string nameFigure{ "quadrangle" };
public:
	Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) : Figure(a, b, c, d, A, B, C, D),
		a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D)
	{
	}
	void print_info() override
	{
		std::cout << "Четырёхугольник:" << std::endl;
		Figure::checkFigure(nameFigure);
		std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
		std::cout << "Углы: a=" << A << " b=" << B << " c=" << C << " D=" << D << std::endl;
		std::cout << std::endl;
	}
};

class Rectangle1 : public Quadrangle                         //Прямоугольник (стороны a,c и b,d попарно равны, все углы равны 90);
{
	int a, b, c, d;
	int A, B, C, D;
	std::string nameFigure_RQ{ "rectangle1" };
public:
	Rectangle1(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c, d, A, B, C, D),
		a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D)
	{
	}
	void print_info() override
	{
		std::cout << "Прямоугольник:" << std::endl;
		Figure::checkFigure(nameFigure_RQ);
		std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
		std::cout << "Углы: a=" << A << " b=" << B << " c=" << C << " D=" << D << std::endl;
		std::cout << std::endl;
	}
};

class Square : public Quadrangle                            //Квадрат (угол C всегда равен 90);
{
	int a, b, c, d;
	int A, B, C, D;
	std::string nameFigure_SQ{ "square" };
public:
	Square(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c, d, A, B, C, D),
		a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D)
	{
	}
	void print_info() override
	{
		std::cout << "Квадрат:" << std::endl;
		Figure::checkFigure(nameFigure_SQ);
		std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
		std::cout << "Углы: a=" << A << " b=" << B << " c=" << C << " D=" << D << std::endl;
		std::cout << std::endl;
	}
};

class Parallelogram : public Quadrangle                  //Параллелограмм (стороны a,c и b,d попарно равны, углы A,C и B,D попарно равны);
{
	int a, b, c, d;
	int A, B, C, D;
	std::string nameFigure_PQ{ "parallelogram" };
public:
	Parallelogram(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c, d, A, B, C, D),
		a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D)
	{
	}
	void print_info() override
	{
		std::cout << "Параллелограмм:" << std::endl;
		Figure::checkFigure(nameFigure_PQ);
		std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
		std::cout << "Углы: a=" << A << " b=" << B << " c=" << C << " D=" << D << std::endl;
		std::cout << std::endl;
	}
};

class Rhombus : public Quadrangle                        //Ромб (все стороны равны, углы A,C и B,D попарно равны).
{
	int a, b, c, d;
	int A, B, C, D;
	std::string nameFigure_RQ{ "Rhombus" };
public:
	Rhombus(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c, d, A, B, C, D),
		a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D)
	{
	}
	void print_info() override
	{
		std::cout << "Ромб:" << std::endl;
		Figure::checkFigure(nameFigure_RQ);
		std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
		std::cout << "Углы: a=" << A << " b=" << B << " c=" << C << " D=" << D << std::endl;
		std::cout << std::endl;
	}

};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Figure f_figure;
	f_figure.check_Figur2();

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
