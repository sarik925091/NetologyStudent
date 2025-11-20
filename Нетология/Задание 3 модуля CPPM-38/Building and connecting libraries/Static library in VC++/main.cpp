#include<iostream>
#include<string>
#include"static_lib.h"

int main()
{
	std::cout << "Enter a name" << std::endl;
	std::string name{};
	std::getline(std::cin >> std::ws, name);
	Greater h;
	std::cout << h.great(name) << std::endl;
	
	return 0;
}