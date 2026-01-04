#pragma once
#include<iostream>

int typeOfRaceInput()
{
	std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl;
	std::cout << "1. Гонка для наземного транспорта" << std::endl;
	std::cout << "2. Гонка для воздушного транспорта" << std::endl;
	std::cout << "3. Гонка для наземного и воздушного транспорта" << std::endl;
	int x{};
	std::cout << "Выберите тип гонки: ";
	std::cin >> x;
	std::cout << std::endl;
	return x;
}

int distanceLength()
{
	int dist{};
	std::cout << "Укажите длину дистанции (должна быть положительна): ";
	std::cin >> dist;
	std::cout << std::endl;
	return dist;
}

int registrationOfferBegin()
{
	std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства" << std::endl;
	std::cout << "1. Зарегистрировать транспорт " << std::endl;
	int x{};
	std::cout << "Выберите действие : ";
	std::cin >> x;
	std::cout << std::endl;
	return x;
}

int registrationTrasnport()
{
	std::cout << "1. Ботинки-вездеходы" << std::endl;
	std::cout << "2. Метла" << std::endl;
	std::cout << "3. Верблюд" << std::endl;
	std::cout << "4. Кентавр" << std::endl;
	std::cout << "5. Орёл" << std::endl;
	std::cout << "6. Верблюд-быстроход" << std::endl;
	std::cout << "7. Ковёр-самолёт" << std::endl;
	std::cout << "0. Закончить регистрацию" << std::endl;
	int transport{};
	std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: ";
	std::cin >> transport;
	std::cout << std::endl;
	return transport;
}

int registrationOfferAfter()
{
	std::cout << "1. Зарегистрировать транспорт" << std::endl;
	std::cout << "2. Начать гонку" << std::endl;
	int x{};
	std::cout << "Выберите действие: ";
	std::cin >> x;
	std::cout << std::endl;
	return x;
}

int offerAtTheEnd()
{
	std::cout << "1. Провести ещё одну гонку" << std::endl;
	std::cout << "2. Выйти" << std::endl;
	int x{};
	std::cout << "Выберите действие: ";
	std::cin >> x;
	std::cout << std::endl;
	return x;
}