#include <iostream>
#include <Windows.h>
#include<string>
#include"class.h"

void printResultcounter()
{
	Counter count;
	std::string x;

	std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
	std::getline(std::cin >> std::ws, x);
	if (x == "да")
	{
		std::cout << "Введите начальное значение счётчика: ";
		count = { count.userInputInt() };
	}
	while (true)
	{
		std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
		x = count.userInputString();
		if (x == "+")
			count.increase();
		else if (x == "-")
			count.decrease();
		else if (x == "=")
			std::cout << count.get_counter() << std::endl;
		else if (x == "Х" || x == "х")
		{
			std::cout << "До свидания!" << std::endl;
			break;
		}
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printResultcounter();

	return 0;
}