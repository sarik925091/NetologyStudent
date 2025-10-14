#include<iostream>
#include<Windows.h>
#include<cmath>
#include"Header.h"
	
void print_Info(Myoperations& op, double input1, double input2, double input3)
{
	if (input3 == 1)
	{
		std::cout << input1 << " + " << input2 << " = " << op.addition(input1, input2) << std::endl;
	}
	else if (input3 == 2)
	{
		std::cout << input1 << " - " << input2 << " = " << op.subtraction(input1, input2) << std::endl;
	}
	else if (input3 == 3)
	{
		std::cout << input1 << " * " << input2 << " = " << op.multiplication(input1, input2) << std::endl;
	}
	else if (input3 == 4)
	{
		std::cout << input1 << " / " << input2 << " = " << op.division(input1, input2) << std::endl;
	}
	else if (input3 == 5)
	{
		std::cout << input1 << " в степени " << input2 << " = " << op.exponentiation(input1, input2) << std::endl;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Myoperations op;
	double in1 = op.userInput1();
	double in2 = op.userInput2();
	double in3 = op.userInput3();
	print_Info(op, in1, in2, in3);
	return 0;
}