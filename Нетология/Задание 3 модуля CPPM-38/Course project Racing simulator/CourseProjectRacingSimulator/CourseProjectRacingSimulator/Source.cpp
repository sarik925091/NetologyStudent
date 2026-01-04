#include<iostream>
#include<Windows.h>
#include <algorithm>
#include <vector>
#include <string>
#include"source.h"
#include"AllTerrainBoots.h"
#include"Broomstick.h"
#include"Camel.h"
#include"Centaur.h"
#include"Eagle.h"
#include"MagicCarpet.h"
#include"swiftCamel.h"
#include"calculate.h"

#define ASSIGN_QTYTS(arr, value, size) \
    for (size_t i = 0; i < size; ++i) \
    { \
		if (arr[i] != value) \
		{ \
			if (arr[i] == 0) \
			{ \
				arr[i] = value; \
				break; \
			} \
			else if (arr[i] != 0) \
			{ \
				continue; \
			} \
		} \
		else if (arr[i] == value) \
		{ \
			std::cout << "этот вид тс уже зарегистрирован!" << std::endl; \
			break; \
		} \
    }

struct Variable 
{
	int value;
	std::string name;

	Variable() : value(0), name("") {}
	Variable(int v, std::string n) : value(v), name(n) {}
};

bool operator!=(const Variable & var, int num) 
{
	return var.value != num;
}

bool operator==(const Variable & var, int num) 
{
	return var.value == num;
}
bool operator<(const Variable& a, const Variable& b) 
{
	return a.value < b.value;
}

void printResult(int camel, int allTerrainBoots, int centaur, int swiftCamel, int magicCarpet, int eagle, int broomstick)
{
	Variable variables[7] = 
	{
		{camel, "Верблюд. Время: "},
		{allTerrainBoots, "Ботинки-вездеходы. Время: "},
		{centaur, "Кентавр. Время: "},
		{swiftCamel, "Верблюд-быстроход. Время: "},
		{magicCarpet, "Ковёр-самолёт. Время: "},
		{eagle, "Орёл. Время: "},
		{broomstick, "Метла. Время: "}
	};
	
	std::vector<Variable> nonZeroVars;

	for (size_t i = 0; i < 7; ++i) 
	{
		if (variables[i] != 0) 
		{
			nonZeroVars.push_back(variables[i]);
		}
		else if (variables[i] == 0) 
		{
			continue;
		}
	}

	std::sort(nonZeroVars.begin(), nonZeroVars.end());

	for (const auto& var : nonZeroVars) 
	{
		std::cout << var.name << var.value << std::endl;
	}
	std::cout << std::endl;
}

void calculatingTheTime(int* arr, int distance)
{
	int camel{}, allTerrainBoots{}, centaur{}, swiftCamel{};
	int magicCarpet{}, eagle{}, broomstick{};
	for (size_t i = 0; i < 7; ++i)
	{
		switch (arr[i])
		{
		case 1: allTerrainBoots = allTerrainBootslCalculate(distance);
			break;
		case 2: broomstick = broomstickCalculate(distance);
			break;
		case 3: camel = camelCalculate(distance);
			break;
		case 4: centaur = centaurCalculate(distance);
			break;
		case 5: eagle = eagleCalculate(distance);
			break;
		case 6: swiftCamel = swiftCamelCalculate(distance);
			break;
		case 7: magicCarpet = magicCarpetCalculate(distance);
			break;
		case 0:
			break;
		default: 
			break;
		}
	}
	printResult(camel, allTerrainBoots, centaur, swiftCamel, magicCarpet, eagle, broomstick);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (true)
	{
		int typeRace = typeOfRaceInput();
		int distance = distanceLength();
		int registrationOfferB = registrationOfferBegin();
		int registrationOfferA;
		int registrationTS{};
		int offerAnd{};
		int qtyTS[7]{};
		while (1)
		{
			registrationTS = registrationTrasnport();
			
			if (typeRace == 1)
			{
				switch (registrationTS)
				{
				case 1: std::cout << "Ботинки-вездеходы успешно зарегистрирован!" << std::endl;
					ASSIGN_QTYTS(qtyTS, registrationTS, 7);
					break;
				case 3: std::cout << "Верблюд успешно зарегистрирован!" << std::endl;
					ASSIGN_QTYTS(qtyTS, registrationTS, 7);
					break;
				case 4: std::cout << "Кентавр успешно зарегистрирован!" << std::endl;
					ASSIGN_QTYTS(qtyTS, registrationTS, 7);
					break;
				case 6: std::cout << "Верблюд-быстроход успешно зарегистрирован!" << std::endl;
					ASSIGN_QTYTS(qtyTS, registrationTS, 7);
					break;
				case 0: 
					break;
				default: std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
					break;
				}
			}
			else if (typeRace == 2)
			{
				switch (registrationTS)
				{
				case 2: std::cout << "Метла успешно зарегистрирован!" << std::endl;
					ASSIGN_QTYTS(qtyTS, registrationTS, 7);
					break;
				case 5: std::cout << "Орёл успешно зарегистрирован!" << std::endl;
					ASSIGN_QTYTS(qtyTS, registrationTS, 7);
					break;
				case 7: std::cout << "Ковёр-самолёт успешно зарегистрирован!" << std::endl;
					ASSIGN_QTYTS(qtyTS, registrationTS, 7);
					break;
				case 0: 
					break;
				default: std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
					break;
				}
				
			}
			else if (typeRace == 3)
			{
				switch (registrationTS)
				{
				case 1: std::cout << "Ботинки-вездеходы успешно зарегистрирован!" << std::endl;
					ASSIGN_QTYTS(qtyTS, registrationTS, 7);
					break;
				case 2: std::cout << "Метла успешно зарегистрирован!" << std::endl;
					ASSIGN_QTYTS(qtyTS, registrationTS, 7);
					break;
				case 3: std::cout << "Верблюд успешно зарегистрирован!" << std::endl;
					ASSIGN_QTYTS(qtyTS, registrationTS, 7);
					break;
				case 4: std::cout << "Кентавр успешно зарегистрирован!" << std::endl;
					ASSIGN_QTYTS(qtyTS, registrationTS, 7);
					break;
				case 5: std::cout << "Орёл успешно зарегистрирован!" << std::endl;
					ASSIGN_QTYTS(qtyTS, registrationTS, 7);
					break;
				case 6: std::cout << "Верблюд-быстроход успешно зарегистрирован!" << std::endl;
					ASSIGN_QTYTS(qtyTS, registrationTS, 7);
					break;
				case 7: std::cout << "Ковёр-самолёт успешно зарегистрирован!" << std::endl;
					ASSIGN_QTYTS(qtyTS, registrationTS, 7);
					break;
				case 0:
					break;
				default: std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
					break;
				}
			}
			
			if (registrationTS == 0)
			{
				if (qtyTS[0] == 0 && qtyTS[1] == 0)
				{
					std::cout << "На гонку должно быть зарегистрировано хотя бы два вида ТС" << std::endl;
					continue;
				}
				else if (qtyTS[0] != 0 && qtyTS[1] != 0)
				{
					registrationOfferA = registrationOfferAfter();
					if (registrationOfferA == 2)
					{
						calculatingTheTime(qtyTS, distance);
						break;
					}
					else if (registrationOfferA == 1)
					{
						continue;
					}
				}
			}
		}
		offerAnd = offerAtTheEnd();
		if (offerAnd == 1)
		{
			continue;
		}
		else if (offerAnd == 2)
		{
			break;
		}
	}
	return 0;
}



	/*switch (registrationTS)
	{
			case 1: std::cout << "Ботинки-вездеходы успешно зарегистрирован!" << std::endl;
				break;
			case 2: std::cout << "Метла успешно зарегистрирован!" << std::endl;
				break;
			case 3: std::cout << "Верблюд успешно зарегистрирован!" << std::endl;
				break;
			case 4: std::cout << "Кентавр успешно зарегистрирован!" << std::endl;
				break;
			case 5: std::cout << "Орёл успешно зарегистрирован!" << std::endl;
				break;
			case 6: std::cout << "Верблюд-быстроход успешно зарегистрирован!" << std::endl;
				break;
			case 7: std::cout << "Ковёр-самолёт успешно зарегистрирован!" << std::endl;
				break;
			case 0: std::cout << "Закончить регистрацию!" << std::endl;
				break;
			default: std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
				break;
	}*/