#include<iostream>
#include<vector>
#include<utility>

template<typename T>
void move_vectors(T& src, T& dest)
{
	dest = std::move(src);
}

int main()
{
	std::vector <std::string> one = { "test_string1", "test_string2" };
	std::vector <std::string> two;

	std::cout << one.size() << std::endl;
	std::cout << two.size() << std::endl;

	move_vectors(one, two);

	std::cout << one.size() << std::endl;
	std::cout << two.size() << std::endl;

	return 0;
}