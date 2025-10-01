#include <iostream>
#include <Windows.h>
#include <string>

struct BankAccount
{
	int ID;
	std::string name;
	double amount;
};

void newBalance(BankAccount& userAccount);
int userInputInt();
std::string userInputString();
double userInputDouble();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	BankAccount userAccount;

	std::cout << "¬ведите номер счЄта: ";
	userAccount.ID = userInputInt();

	std::cout << "¬ведите им€ владельца: ";
	userAccount.name = userInputString();

	std::cout << "¬ведите баланс: ";
	userAccount.amount = userInputDouble();

	std::cout << "¬ведите новый баланс: ";
	newBalance(userAccount);

	std::cout << "¬аш счЄт: " << userAccount.ID << ", " << userAccount.name << ", " << userAccount.amount << std::endl;

	return 0;
}

void newBalance(BankAccount& userAccount)
{
	userAccount.amount = userInputDouble();
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

double userInputDouble()
{
	double x{};
	std::cin >> x;
	return x;
}
