#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>

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
};

void writeFile(Address* arrayAdress, int row);

void readFile()
{
	std::ifstream file("in3.txt");
	if (!(file.is_open())) 
	{
		//std::cerr << "Error: " << strerror(errno);
		std::cerr << "Failed to open file IN" << std::endl;
		return;
	}

	int row{};
	Address* addresses = new Address[row];
	for (int i = 0; i < row; ++i) {
		std::string city, street;
		int house, apartment;
		file >> city >> street >> house >> apartment;
		addresses[i] = Address(city, street, house, apartment);
	}
	file.close();
	writeFile(addresses, row);
	delete[] addresses;
}

void writeFile(Address* addresses,int row)
{
	std::ofstream file("out3.txt");
	if (!(file.is_open()))
	{
		std::cerr << "Failed to open file OUT" << std::endl;
		return;
	}

	file << row << std::endl;
	for (int i(row - 1); i >= 0; --i)
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
