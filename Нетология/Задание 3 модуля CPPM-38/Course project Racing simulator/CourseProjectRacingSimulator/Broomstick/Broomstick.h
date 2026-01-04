#pragma once

#ifndef BROOMSTICK_EXPORTS
#define BROOMSTICK_LIB __declspec(dllexport)
#else
#define BROOMSTICK_LIB __declspec(dllimport)
#endif
class BROOMSTICK_LIB Broomstick
{
private:
	double speed{ 20.0 };
	double distanceReduction{0};
	
public:
	double getSpeed();
	double getDistanceReductionForEvery1000(double distance);
	
};
