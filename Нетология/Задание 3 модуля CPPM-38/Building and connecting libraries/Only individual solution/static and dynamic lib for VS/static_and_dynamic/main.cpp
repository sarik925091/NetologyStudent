#include<iostream>
#include<string>
#include"dynamic_lib.h"
#include"static_lib.h"

int main()
{
	std::cout << "Enter a name" << std::endl;
	std::string name{};
	std::getline(std::cin >> std::ws, name);
	Greater h;
	std::cout << h.great(name) << std::endl;
	Leaver l;
	std::cout << l.leave(name) << std::endl;
	
	//std::cin.get();
	return 0;
}