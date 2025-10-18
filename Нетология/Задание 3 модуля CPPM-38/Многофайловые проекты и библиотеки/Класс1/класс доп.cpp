#include<iostream>
#include"class.h"
#include<string>

Counter::Counter(int count): __count(count)
{}

int Counter::increase() { return ++__count; }
int Counter::decrease() { return --__count; }
int Counter::get_counter() { return __count; }

int Counter::userInputInt()
{
	int x{};
	std::cin >> x;
	return x;
}

std::string Counter::userInputString()
{
	std::string x{};
	std::getline(std::cin >> std::ws, x);
	return x;
}