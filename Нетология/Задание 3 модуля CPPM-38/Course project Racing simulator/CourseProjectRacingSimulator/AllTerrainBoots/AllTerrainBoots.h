#pragma once

#ifndef ALLTERRAINBOTS_EXPORTS
#define ALLTERRAINBOTS_EXPORTS_LIB __declspec(dllexport)
#else
#define ALLTERRAINBOTS_EXPORTS_LIB __declspec(dllimport)
#endif
class ALLTERRAINBOTS_EXPORTS_LIB AllTerrainBoots
{
private:
	int speed{ 6 };
	int drivingTime{ 60 };
	int restFirst{ 10 };
	int restAllSubsequent{ 5 };
public:
	int getSpeed();
	int getDrivingTime();
	int getRestFirst();
	int getRestAllSubsequent();
};