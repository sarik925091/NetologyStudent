#pragma once

#ifndef CENTAUR_EXPORTS
#define CENTAUR_EXPORTS_LIB __declspec(dllexport)
#else
#define CENTAUR_EXPORTS_LIB __declspec(dllimport)
#endif

class CENTAUR_EXPORTS_LIB Centaur
{
private:
	int speed{ 15 };
	int drivingTime{ 8 };
	int restAll{ 2 };
public:
	int getSpeed();
	int getDrivingTime();
	int getRestAll();
};