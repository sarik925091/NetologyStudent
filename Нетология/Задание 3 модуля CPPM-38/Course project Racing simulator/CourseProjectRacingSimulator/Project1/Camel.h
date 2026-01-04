#pragma once
#ifndef CAMEL_EXPORTS
#define CAMEL_EXPORTS_LIB __declspec(dllexport)
#else
#define CAMEL_EXPORTS_LIB __declspec(dllimport)
#endif

class CAMEL_EXPORTS_LIB Camel
{
private:
	int speed{10};
	int drivingTime{30};
	int restFirst{5};
	int restAllSubsequent{8};
public:
	int getSpeed();
	int getDrivingTime();
	int getRestFirst();
	int getRestAllSubsequent();
};