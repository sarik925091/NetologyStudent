#pragma once

#ifndef MAGIC_CARPET_EXPORTS
#define MAGIC_CARPET_LIB __declspec(dllexport)
#else
#define MAGIC_CARPET_LIB __declspec(dllimport)
#endif
class MAGIC_CARPET_LIB MagicCarpet
{
private:
	double speed{ 10.0 };
	double distanceReduction5000{ 0.03 };
	double distanceReductionBelow10000{ 0.10 };
	double distanceReduction10000{ 0.05 };
public:
	double getSpeed();
	double getDistanceReduction5000();
	double getDistanceReductionBelow10000();
	double getDistanceReduction10000();
};