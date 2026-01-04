#pragma once

#ifndef SWIFTCAMEL_EXPORTS
#define SWIFTCAMEL_EXPORTS_LIB __declspec(dllexport)
#else
#define SWIFTCAMEL_EXPORTS_LIB __declspec(dllimport)
#endif
class SWIFTCAMEL_EXPORTS_LIB SwiftCamel
{
private:
	int speed{ 40};
	int drivingTime{ 10 };
	int restFirst{ 5 };
	double restSecond{ 6.5 };
	int restAllSubsequent{ 8 };
public:
	int getSpeed();
	int getDrivingTime();
	int getRestFirst();
	double getRestSecond();
	int getRestAllSubsequent();
};