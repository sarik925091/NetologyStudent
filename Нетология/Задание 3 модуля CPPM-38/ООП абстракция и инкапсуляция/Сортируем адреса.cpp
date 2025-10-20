#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include <algorithm>

class Address
{
private:
	std::string city;
	std::string street;
	int house;
	int apartment;

public:
	Address() {};
	Address(std::string city, std::string street, int house, int apartment)
		: city(city), street(street), house(house), apartment(apartment)
	{
	}

	std::string toString() const
	{
		return city + ", " + street + "," +
			std::to_string(house) + ", " +
			std::to_string(apartment);
	}
	std::string get_cityName() const { return city; }
};

void writeFile(Address* arrayAdress, int row);
void sortingAddress(Address* addresses, int row);

bool compareByFirstLetter(const Address& a, const Address& b)
{
	if (a.get_cityName()[0] != b.get_cityName()[0]) {
		return a.get_cityName()[0] < b.get_cityName()[0];
	}
	return a.get_cityName() < b.get_cityName();
}

void readFile()
{
	std::ifstream file("in2.txt");
	if (!(file.is_open()))
	{
		//std::cerr << "Error: " << strerror(errno);
		std::cerr << "Failed to open file IN" << std::endl;
		return;
	}

	int row{};
	file >> row;
	Address* addresses = new Address[row];
	for (int i = 0; i < row; ++i) {
		std::string city, street;
		int house, apartment;
		file >> city >> street >> house >> apartment;
		addresses[i] = Address(city, street, house, apartment);
	}
	file.close();

	sortingAddress(addresses, row);
	delete[] addresses;
}

void sortingAddress(Address* addresses, int row)
{
	std::sort(addresses, addresses + row, compareByFirstLetter);
	writeFile(addresses, row);
}

void writeFile(Address* addresses, int row)
{
	std::ofstream file("out2.txt");
	if (!(file.is_open()))
	{
		std::cerr << "Failed to open file OUT" << std::endl;
		return;
	}

	file << row << std::endl;
	for (int i = 0; i < row; ++i)
	{
		file << addresses[i].toString() << std::endl;
	}
	file.close();
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	readFile();

	return 0;
}
