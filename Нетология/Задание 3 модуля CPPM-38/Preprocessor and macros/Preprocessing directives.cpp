#include<iostream>


#define MODE 1

#ifndef MODE

#error MODE is not defined

#endif // !MODE

#if MODE == 1

int add(int a, int b) 
{
	return a + b;
}

#endif // MODE

int userInput1();
int userInput2();

int main()
{
	if (MODE == 0)
	{
		std::cout << "I work in training mode" << std::endl;
	}
	else if (MODE == 1)
	{
		std::cout << "I'm working in combat mode" << std::endl;
		int num1 = userInput1();
		int num2 = userInput2();
		std::cout << "The result of the addition: " << add(num1, num2) << std::endl;
	}
	else
	{
		std::cout << "Unknown mode \nShutting down" << std::endl;
		return 0;
	}

	return 0;
}

int userInput1()
{
	int x;
	std::cout << "Enter the number 1: ";
	std::cin >> x;
	return x;
}

int userInput2()
{
	int x;
	std::cout << "Enter the number 2: ";
	std::cin >> x;
	return x;
}