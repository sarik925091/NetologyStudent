#include"Broomstick.h"

double Broomstick::getSpeed() { return speed; }
double Broomstick::getDistanceReductionForEvery1000(double distance)
{
    if (distance >= 1000.0)
    {
        // Для 5600: 5600/1000 * 0.01 = 5.6 * 0.01 = 0.056 (5.6%)
        distanceReduction = (distance / 1000.0) * 0.01;
    }
    else
    {
        distanceReduction = 0.0;
    }
    return distanceReduction;
}
