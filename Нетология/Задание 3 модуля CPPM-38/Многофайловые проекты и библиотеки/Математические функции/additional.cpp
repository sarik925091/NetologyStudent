#include<iostream>
#include<cmath>
#include"Header.h"


double Myoperations::addition(double x, double y)
{
	return x + y;
}

double Myoperations::subtraction(double x, double y)
{
	return x - y;
}

double Myoperations::multiplication(double x, double y)
{
	return x * y;
}

double Myoperations::division(double x, double y)
{
	return x / y;
}

double Myoperations::exponentiation(double base, double exponent)
{
	return pow(base, exponent);
}

double Myoperations::userInput1()
{
	double a;
	std::cout << "Введите первое число: ";
	std::cin >> a;
	return a;
}
double Myoperations::userInput2()
{
	double b;
	std::cout << "Введите второе число: ";
	std::cin >> b;
	return b;
}
double Myoperations::userInput3()
{
	double c;
	std::cout << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
	std::cin >> c;
	return c;
}