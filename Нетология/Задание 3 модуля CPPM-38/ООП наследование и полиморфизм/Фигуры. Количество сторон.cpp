#include <iostream>
#include <Windows.h>

class Figure
{
private:
	int sides_count;
public:
	Figure(int a) : sides_count(a)
	{
	}

	int get_sides_count() { return sides_count; }
};


class Triangle: public Figure
{
public:
	Triangle(int c) : Figure(c) 
	{}
};

class Quadrangle: public Figure
{
public:
	Quadrangle(int d) : Figure(d) 
	{}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Figure figure{ 0 };
	Quadrangle quadrangle{ 4 };
	Triangle triangle{ 3 };
	std::cout << "Количество сторон:" << std::endl;
	std::cout << "Фигура: " << figure.get_sides_count() << std::endl;
	std::cout << "Треугольник: " << triangle.get_sides_count() << std::endl;
	std::cout << "Четырёхугольник: " << quadrangle.get_sides_count() << std::endl;

	return 0;
}