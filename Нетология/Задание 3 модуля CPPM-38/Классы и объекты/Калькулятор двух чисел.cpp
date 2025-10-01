#include <iostream>
#include <Windows.h>

double userInputnum1();
double userInputnum2();

class Calculator
{
private:
	double __num1 = 0.0;
	double __num2 = 0.0;
public:
	Calculator() {}
	Calculator(double num1, double num2)
	{
		__num1 = num1;
		__num2 = num2;
	}
	~Calculator() {}

	double add() { return __num1 + __num2; }
	double multiply() { return __num1 * __num2;  }
	double subtract_1_2() { return __num1 - __num2; }
	double subtract_2_1() { return __num2 - __num1; }
	double divide_1_2() { return __num1 / __num2; }
	double divide_2_1() { return __num2 / __num1; }
	bool set_num1(double num1)
	{
		if (num1 != 0)
		{
			__num1 == num1;
			return true;
		}
		else
		{
			return false;
		}
	}
	bool set_num2(double num2)
	{
		if (num2 != 0)
		{
			__num2 == num2;
			return true;
		}
		else
		{
			return false;
		}
	}
};

void printResult()
{
	Calculator twoNumber{};
	while (true)
	{
		twoNumber = { userInputnum1(), userInputnum2() };
		std::cout << "num1 + num2 = " << twoNumber.add() << std::endl;
		std::cout << "num1 - num2 = " << twoNumber.subtract_1_2() << std::endl;
		std::cout << "num2 - num1 = " << twoNumber.subtract_2_1() << std::endl;
		std::cout << "num1 * num2 = " << twoNumber.multiply() << std::endl;
		std::cout << "num1 / num2 = " << twoNumber.divide_1_2() << std::endl;
		std::cout << "num2 / num1 = " << twoNumber.divide_2_1() << std::endl;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printResult();


	return 0;
}

double userInputnum1()
{
	double x{};
	while (true)
	{
		std::cout << "Введите num1: ";
		std::cin >> x;
		if (x == 0)
		{
			std::cout << "Неверный ввод!" << std::endl;
			continue;
		}
		else
		{
			return x;
		}	
	}	
}
double userInputnum2()
{
	double x{};
	while (true)
	{
		std::cout << "Введите num2: ";
		std::cin >> x;
		if (x == 0)
		{
			std::cout << "Неверный ввод!" << std::endl;
			continue;
		}
		else
		{
			return x;
		}
	}
}