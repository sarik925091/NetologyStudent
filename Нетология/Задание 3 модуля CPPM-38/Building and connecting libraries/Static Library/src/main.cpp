#include<iostream>
#include<string>
#include"Static_lib.h"

int main()
{
	std::cout << "Enter a name" << std::endl;
	std::string name{};
	std::getline(std::cin >> std::ws, name);
	Greeter h;
	std::cout << h.greet(name) << std::endl;
	std::cin.get();
	return 0;
}