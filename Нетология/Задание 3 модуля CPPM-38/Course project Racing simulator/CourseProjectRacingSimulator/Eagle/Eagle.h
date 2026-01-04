#pragma once

#ifndef EAGLE_CARPET_EXPORTS
#define EAGLE_CARPET_LIB __declspec(dllexport)
#else
#define EAGLE_CARPET_LIB __declspec(dllimport)
#endif
class EAGLE_CARPET_LIB Eagle
{
private:
	double speed{ 8 };
	double distanceReduction{ 0.06 };

public:
	double getSpeed();
	double getDistanceReduction();
};