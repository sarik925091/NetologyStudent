#include"2.myClass for exception.h"
#include<iostream>

MyClassExcp::MyClassExcp(std::string e) : exc(e) {}

const char* MyClassExcp::what() const
{
	return exc.c_str();
}