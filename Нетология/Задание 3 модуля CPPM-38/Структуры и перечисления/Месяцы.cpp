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
	std::cout << "������� ����� ������: ";
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
            std::cout << "������" << std::endl;
            break;
        case February:
            std::cout << "�������" << std::endl;
            break;
        case March:
            std::cout << "����" << std::endl;
            break;
        case April:
            std::cout << "������" << std::endl;
            break;
        case May:
            std::cout << "���" << std::endl;
            break;
        case June:
            std::cout << "����" << std::endl;
            break;
        case July:
            std::cout << "����" << std::endl;
            break;
        case August:
            std::cout << "������" << std::endl;
            break;
        case September:
            std::cout << "��������" << std::endl;
            break;
        case October:
            std::cout << "�������" << std::endl;
            break;
        case November:
            std::cout << "������" << std::endl;
            break;
        case December:
            std::cout << "�������" << std::endl;
            break;
        default:
            if (x >= 13) 
            {
                std::cout << "������� ���������� �����!" << std::endl;
                continue;
            }
        }
        if (x == 0 )
        {
            std::cout << "�� ��������!" << std::endl;
            break;
        }
	}
}