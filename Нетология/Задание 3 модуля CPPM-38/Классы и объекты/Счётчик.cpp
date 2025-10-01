#include <iostream>
#include <Windows.h>
#include <string>
int userInputInt();
std::string userInputString();

class Counter
{
	int __count = 1;
public:
	Counter() {}
	Counter(int count) { __count = count; }
	~Counter() {}
	int increase() { return ++__count; }
	int decrease() { return --__count; }
	int get_counter() { return __count; }

};

void printResultcounter()
{
	Counter count{};
	std::string x{};

	std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
	std::getline(std::cin >> std::ws, x);
	if ( x == "да" )
	{
		std::cout << "Введите начальное значение счётчика: ";
		count = { userInputInt() };
	}
	while (true)
	{
		std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
		x = userInputString();
		if (x == "+")
			count.increase();
		else if (x == "-")
			count.decrease();
		else if (x == "=")
			std::cout << count.get_counter() << std::endl;
		else if (x == "Х" || "х")
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

int userInputInt()
{
	int x{};
	std::cin >> x;
	return x;
}

std::string userInputString()
{
	std::string x{};
	std::getline(std::cin >> std::ws, x);
	return x;
}