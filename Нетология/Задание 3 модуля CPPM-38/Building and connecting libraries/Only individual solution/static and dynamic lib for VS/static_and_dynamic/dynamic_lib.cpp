#include<iostream>
#include"dynamic_lib.h"

std::string Leaver::leave(std::string name)
{
	std::string hello{ "goodbye, " };
	return hello + name;
}