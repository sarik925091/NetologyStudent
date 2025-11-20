#pragma once
#include<iostream>
#ifndef EXPORT_DLL
#define EXPORT_DYNAMIC_USER_LIB __declspec(dllexport)
#else
#define EXPORT_DYNAMIC_USER_LIB __declspec(dllimport)
#endif

class Leaver
{
public:
	EXPORT_DYNAMIC_USER_LIB std::string leave(std::string name);
};
