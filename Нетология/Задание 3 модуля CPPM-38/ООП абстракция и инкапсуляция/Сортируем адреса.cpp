#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include <algorithm>

class Address
{
private:
	std::string __cityName{};
	std::string __streetName{};
	int __houseNumber{};
	int __apartmentNumber{};
public:
	Address() {}
	Address(std::string cityName, std::string streetName, int houseNumber, int apartmentNumber)
	{
		__cityName = cityName;
		__streetName = streetName;
		__houseNumber = houseNumber;
		__apartmentNumber = apartmentNumber;
	}

	void set_cityName(std::string cityName) { __cityName = cityName; }
	void set_streetName(std::string streetName) { __streetName = streetName; }
	void set_houseNumber(int houseNumber) { __houseNumber = houseNumber; }
	void set_apartmentNumber(int apartmentNumber) { __apartmentNumber = apartmentNumber; }

	std::string get_cityName() const { return __cityName; }
	std::string get_streetName() const { return __streetName; }
	int get_houseNumber() const { return __houseNumber; }
	int get_apartmentNumber() const { return __apartmentNumber; }
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
	std::ifstream file("in1.txt");
	if (!(file.is_open()))
	{
		std::cerr << "Failed to open file" << std::endl;
		return;
	}

	int row{};
	file >> row;
	Address* arrayAdress(new Address[row]);
	std::string city, street;
	int house, apartment;
	for (size_t i = 0; i < row; ++i)
	{
		file >> city >> street >> house >> apartment;
		arrayAdress[i].set_cityName(city);
		arrayAdress[i].set_streetName(street);
		arrayAdress[i].set_houseNumber(house);
		arrayAdress[i].set_apartmentNumber(apartment);
	}
	file.close(); 
	sortingAddress(arrayAdress, row);
	writeFile(arrayAdress, row);
	delete[] arrayAdress;
}

void sortingAddress(Address* addresses, int row)
{
	std::sort(addresses, addresses +row, compareByFirstLetter);
}

void writeFile(Address* arrayAdress, int row)
{
	std::ofstream file("out1.txt");
	if (!(file.is_open()))
	{
		std::cerr << "Failed to open file" << std::endl;
		return;
	}

	file << row << std::endl;
	for (int i = 0; i < row; ++i)
	{
		file << arrayAdress[i].get_cityName() << ",";
		file << arrayAdress[i].get_streetName() << ",";
		file << arrayAdress[i].get_houseNumber() << ",";
		file << arrayAdress[i].get_apartmentNumber() << std::endl;
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
