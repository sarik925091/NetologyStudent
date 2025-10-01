#include <iostream>
#include <Windows.h>

void MonthNameByNumber();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	MonthNameByNumber();

	return 0;
}

enum Month
{
	January = 1,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
};

int userInput()
{
	int x{};
	std::cout << "Введите номер месяца: ";
	std::cin >> x;
	return x;
}
void MonthNameByNumber()
{
	int x{};
	while (true)
	{
		x = userInput();
        switch (x) 
        {
        case January:
            std::cout << "Январь" << std::endl;
            break;
        case February:
            std::cout << "Февраль" << std::endl;
            break;
        case March:
            std::cout << "Март" << std::endl;
            break;
        case April:
            std::cout << "Апрель" << std::endl;
            break;
        case May:
            std::cout << "Май" << std::endl;
            break;
        case June:
            std::cout << "Июнь" << std::endl;
            break;
        case July:
            std::cout << "Июль" << std::endl;
            break;
        case August:
            std::cout << "Август" << std::endl;
            break;
        case September:
            std::cout << "Сентябрь" << std::endl;
            break;
        case October:
            std::cout << "Октябрь" << std::endl;
            break;
        case November:
            std::cout << "Ноябрь" << std::endl;
            break;
        case December:
            std::cout << "Декабрь" << std::endl;
            break;
        default:
            if (x >= 13) 
            {
                std::cout << "Введите корректный номер!" << std::endl;
                continue;
            }
        }
        if (x == 0 )
        {
            std::cout << "До свидания!" << std::endl;
            break;
        }
	}
}