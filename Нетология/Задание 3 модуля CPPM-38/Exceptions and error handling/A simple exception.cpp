#include <iostream>
#include <Windows.h>
#include <string>
#include <exception>

int function(std::string str, int forbidden_length)
{
	if (str.length() == forbidden_length)
	{
		return static_cast<int>(str.length());
	}
	else
	{
		throw "bad_length";
	}
}

int userInputInt();
std::string userInPutString();

int main()
{
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int foribdenLenght{ userInputInt() };
	std::string src{ userInPutString() };
	

	while (10)
	{
		try
		{
			if (src.length() == function(src, foribdenLenght))
			{
				std::cout << "You have entered a word of forbidden length! Goodbye" << std::endl;
				break;
			}
		}
		catch (...)
		{
			std::cout << "The length of the word " << src << " is " << src.length() << std::endl;
			src = userInPutString();
			continue;
		}
	}
	return 0;
}

int userInputInt()
{
	int x;
	std::cout << "Enter the forbidden length: ";
	std::cin >> x;
	return x;
}

std::string userInPutString()
{
	std::string y;
	std::cout << "enter the words: ";
	std::getline(std::cin >> std::ws, y);
	return y;
}