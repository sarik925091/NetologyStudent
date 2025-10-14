#include <iostream>
#include <Windows.h>

class Figure
{
private:
	std::string name;
	int sides_count;
public:
	Figure() : sides_count(0), name("Фигура") {}
	Figure(int sidesCount, std::string Name) : sides_count(sidesCount), name(Name)
	{
	}

	int get_sides_count() const { return sides_count; }
	virtual std::string get_name() const { return name; }
	virtual void print_info() const
	{
		std::cout <<  name << ": " << sides_count << std::endl;
	}
};


class Triangle: public Figure
{
public:
	Triangle() : Figure(3, "Треугольник")
	{}

};

class Quadrangle: public Figure
{
public:
	Quadrangle() : Figure(4, "Четырёхугольник")
	{}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "Количество сторон: " << std::endl;
	Figure f;
	f.print_info();
	Triangle t;
	Figure* triangle{ &t };
	triangle->print_info();
	Quadrangle q;
	Figure* quadrangle{ &q };
	quadrangle->print_info();
	

	return 0;
}