#include <iostream>
#include <string>

int main()
{
	std::string name;
	std::cout << "Enter a name:" << std::endl;
	std::getline(std::cin >> std::ws, name);
	std::cout << "Hello " << name << std::endl;
	std::cin.get();
	return 0;
}