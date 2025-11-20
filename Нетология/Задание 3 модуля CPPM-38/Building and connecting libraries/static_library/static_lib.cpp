#include<iostream>
#include"static_lib.h"

std::string Greater::great(std::string name)
{
	std::string hello{ "hello, " };
	return hello + name;
}