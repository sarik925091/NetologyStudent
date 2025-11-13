#pragma once
#include<iostream>
#ifndef EXPORT_DYNAMIC_USER_LIB
#define __Leaver __declspec(dllexport)
#else
#define __Leaver __declspec(dllimport)
#endif

class Leaver
{
public:
	__Leaver std::string leave(std::string name);
};
