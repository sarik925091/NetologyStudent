#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
	std::vector<int> v = { 1, 1, 2, 5, 6, 1, 2, 4 };

	std::cout << "[IN]: ";
	for (auto el : v)
	{
		std::cout << el << " ";
	}
	std::cout << std::endl;

	std::sort(v.begin(), v.end(), [](int val1, int val2) {return val1 < val2; });
	auto it = std::unique(v.begin(), v.end());
	v.erase(it, v.end());

	std::cout << "[OUT]: ";
	for (auto el : v)
	{
		std::cout << el << " ";
	}

	return 0;
}