#pragma once

int camelCalculate(int distanceRace)
{
	Camel camel;
	int restQty = (distanceRace / camel.getSpeed()) / camel.getDrivingTime();
	int restTime = (restQty * camel.getRestAllSubsequent()) - (camel.getRestAllSubsequent() - camel.getRestFirst());
	int timeRace = (distanceRace / camel.getSpeed()) + restTime;
	return timeRace;
}

int allTerrainBootslCalculate(int distanceRace)
{
	AllTerrainBoots allTerrainBoots;
	int restQty = (distanceRace / allTerrainBoots.getSpeed()) / allTerrainBoots.getDrivingTime();
	int restTime = (restQty * allTerrainBoots.getRestAllSubsequent()) - (allTerrainBoots.getRestAllSubsequent() - allTerrainBoots.getRestFirst() );
	int timeRace = (distanceRace / allTerrainBoots.getSpeed()) + restTime;
	return timeRace;
}

int centaurCalculate(int distanceRace)
{
	Centaur centaur;
	int restQty = (distanceRace / centaur.getSpeed()) / centaur.getDrivingTime();
	int restTime = (restQty * centaur.getRestAll());
	int timeRace = (distanceRace / centaur.getSpeed()) + restTime;
	return timeRace;
}

int swiftCamelCalculate(int distanceRace)
{
	SwiftCamel swiftCamel;
	int restQty = (distanceRace / swiftCamel.getSpeed()) / swiftCamel.getDrivingTime();
	int restTime = (restQty * swiftCamel.getRestAllSubsequent()) - (swiftCamel.getRestAllSubsequent() - (swiftCamel.getRestFirst() + swiftCamel.getRestSecond()));
	int timeRace = (distanceRace / swiftCamel.getSpeed()) + restTime;
	return timeRace;
}

int magicCarpetCalculate(int distanceRace)
{
	MagicCarpet magicCarpet;
	if (distanceRace < 1000)
	{
		double timeRace = static_cast<double>(distanceRace) / magicCarpet.getSpeed();
		return static_cast<int>(timeRace);
	}
	else if (distanceRace < 5000)
	{
		double actualDistance = static_cast<double>(distanceRace) * (1.0 - magicCarpet.getDistanceReduction5000());
		double timeRace = actualDistance / magicCarpet.getSpeed();
		return static_cast<int>(timeRace);
	}
	else if (distanceRace < 10000)
	{
		double actualDistance = static_cast<double>(distanceRace) * (1.0 - magicCarpet.getDistanceReduction10000());
		double timeRace = actualDistance / magicCarpet.getSpeed();
		return static_cast<int>(timeRace);
	}
	else if (distanceRace > 10000)
	{
		double actualDistance = static_cast<double>(distanceRace) * (1.0 - magicCarpet.getDistanceReductionBelow10000());
		double timeRace = actualDistance / magicCarpet.getSpeed();
		return static_cast<int>(timeRace);
	}
}

int eagleCalculate(int distanceRace)
{
	Eagle eagle;
	double actualDistance = static_cast<double>(distanceRace) * (1.0 - eagle.getDistanceReduction());
	double timeRace = actualDistance / eagle.getSpeed();
	return static_cast<int>(timeRace);
}

int broomstickCalculate(int distanceRace)
{
	Broomstick broomstick;
	double actualDistance = static_cast<double>(distanceRace) * (1.0 - broomstick.getDistanceReductionForEvery1000(static_cast<double>(distanceRace)));
	double timeRace = actualDistance / broomstick.getSpeed();
	return static_cast<int>(timeRace);
}