#include<iostream>
#include<string>
#include"dynamic_lib.h"

int main()
{
	std::cout << "Enter a name" << std::endl;
	std::string name{};
	std::getline(std::cin >> std::ws, name);
	Leaver l;
	std::cout << l.leave(name) << std::endl;
	std::cin.get();
	return 0;
}