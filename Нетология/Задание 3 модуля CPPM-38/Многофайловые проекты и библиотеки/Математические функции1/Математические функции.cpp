#include <iostream>
#include <Windows.h>
#include <cmath>
#include "mathematicalfunction.h"
	
void print_Info(double input1, double input2, double input3)
{
	if (input3 == 1)
	{
		std::cout << input1 << " + " << input2 << " = " << addition(input1, input2) << std::endl;
	}
	else if (input3 == 2)
	{
		std::cout << input1 << " - " << input2 << " = " << subtraction(input1, input2) << std::endl;
	}
	else if (input3 == 3)
	{
		std::cout << input1 << " * " << input2 << " = " << multiplication(input1, input2) << std::endl;
	}
	else if (input3 == 4)
	{
		std::cout << input1 << " / " << input2 << " = " << division(input1, input2) << std::endl;
	}
	else if (input3 == 5)
	{
		std::cout << input1 << " в степени " << input2 << " = " << exponentiation(input1, input2) << std::endl;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	
	double in1 = userInput1();
	double in2 = userInput2();
	double in3 = userInput3();
	print_Info(in1, in2, in3);
	return 0;
}