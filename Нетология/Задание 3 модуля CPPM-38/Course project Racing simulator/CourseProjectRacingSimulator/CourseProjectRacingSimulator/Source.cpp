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

void printResult(int camel, int allTerrainBoots, int centaur, int swiftCamel, int magicCarpet, int eagle, int broomstick)
{
	std::vector<std::pair<int, std::string>> variables;

	if (camel != 0) variables.push_back({ camel, "Верблюд" });
	if (allTerrainBoots != 0) variables.push_back({ allTerrainBoots, "Ботинки-вездеходы" });
	if (centaur != 0) variables.push_back({ centaur, "Кентавр" });
	if (swiftCamel != 0) variables.push_back({ swiftCamel, "Верблюд-быстроход" });
	if (magicCarpet != 0) variables.push_back({ magicCarpet, "Ковёр-самолё" });
	if (eagle != 0) variables.push_back({ eagle, "Орёл" });
	if (broomstick != 0) variables.push_back({ broomstick, "Метла" });
	

	// Сортировка по убыванию значений
	std::sort(variables.begin(), variables.end(),
		[](const auto& x, const auto& y) {
			return x.first < y.first;
		});

	// Вывод с именами переменных
	for (const auto& [value, name] : variables) {
		std::cout << name << " = " << value << std::endl;
	}
}

void calculatingTheTime(int* arr, int distance)
{
	int camel, allTerrainBoots, centaur, swiftCamel;
	int magicCarpet, eagle, broomstick;
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

	while (2)
	{
		int typeRace = typeOfRaceInput();
		int distance = distanceLength();
		int registrationOfferB = registrationOfferBegin();
		int registrationOfferA;
		int registrationTS{};
		int qtyTS[7]{};
		while (true)
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
					}
					else if (registrationOfferA == 1)
					{
						continue;
					}
				}
			}
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