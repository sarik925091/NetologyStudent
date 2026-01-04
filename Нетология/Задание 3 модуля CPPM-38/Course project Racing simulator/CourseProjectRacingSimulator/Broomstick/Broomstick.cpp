#include"Broomstick.h"

double Broomstick::getSpeed() { return speed; }
double Broomstick::getDistanceReductionForEvery1000(double distance)
{
	if (distance != 0.0)
	{
		distanceReduction = (distance / 1000.0);
	}
	return distanceReduction; 
}
