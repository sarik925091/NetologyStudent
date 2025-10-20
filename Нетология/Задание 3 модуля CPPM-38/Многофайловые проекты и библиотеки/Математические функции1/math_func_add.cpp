#include<iostream>
#include<cmath>
#include"mathematicalfunction.h"


double addition(double x, double y)
{
	return x + y;
}

double subtraction(double x, double y)
{
	return x - y;
}

double multiplication(double x, double y)
{
	return x * y;
}

double division(double x, double y)
{
	return x / y;
}

double exponentiation(double base, double exponent)
{
	return pow(base, exponent);
}

double userInput1()
{
	double a;
	std::cout << "Введите первое число: ";
	std::cin >> a;
	return a;
}
double userInput2()
{
	double b;
	std::cout << "Введите второе число: ";
	std::cin >> b;
	return b;
}
double userInput3()
{
	double c;
	std::cout << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
	std::cin >> c;
	return c;
}