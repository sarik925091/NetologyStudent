#include <iostream>
#include <Windows.h>
#include <string>

int userInputInt();
std::string userInputString();

struct Adress
{
	std::string cityName;
	std::string streetName;
	int houseNumber;
	int apartmentNumber;
	int index;
};

void printStruct(Adress& a)
{
	std::cout << "\n\n" << std::endl;
	std::cout << "�����: " << a.cityName << std::endl;
	std::cout << "�����: " << a.streetName << std::endl;
	std::cout << "����� ����: " << a.houseNumber << std::endl;
	std::cout << "����� ��������: " << a.apartmentNumber << std::endl;
	std::cout << "������: " << a.index << std::endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	Adress a;
	std::cout << "�����: ";
	a.cityName = userInputString();
	
	std::cout << "�����: ";
	a.streetName = userInputString();

	std::cout << "����� ����: ";
	a.houseNumber = userInputInt();

	std::cout << "����� ��������: ";
	a.apartmentNumber = userInputInt();

	std::cout << "������: ";
	a.index = userInputInt();

	printStruct(a);

	return 0;
}

std::string userInputString()
{
	std::string x{};
	std::getline(std::cin >> std::ws, x);
	return x;
}

int userInputInt()
{
	int x{};
	std::cin >> x;
	return x;
}
