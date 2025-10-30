#pragma once
#include<iostream>
#include<exception>


class MyClassExcp : public std::exception
{
	std::string exc;
public:
	MyClassExcp(std::string e);
	virtual const char* what() const;

};

