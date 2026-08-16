#include <iostream>
#include <future>
#include <xutility>
#include <thread>

template<class Type_arr, class Iter>
void parallel_Select_Sort(std::promise<Type_arr> Promise, Iter Begin, Iter End)
{
	for (Iter i = Begin; i < End-1; i++)
	{
		Iter min_index = i;
		auto min_f = std::async([&](){
			for (Iter j = i+1; j < End; j++)
			{
				if ((*j) < (*min_index))
				{
					min_index = j;
				}
			}
			});
		min_f.wait();

		if (min_index != i)
		{
			std::swap(*i, *min_index);
		}
	}
	Type_arr res(Begin, End);
	Promise.set_value(res);
}



int main()
{
	std::vector<int> vec = { 4,9,4,8,4,2,7,2,4,2,7,5,1,45,12,3,82,9 };
	std::promise<std::vector<int>> Promise;
	auto future = Promise.get_future();
	
	parallel_Select_Sort<std::vector<int>, decltype(vec.begin())>(std::move(Promise), vec.begin(), vec.end());
	auto res = future.get();
	for (const auto& el : res)
	{
		std::cout << el << " ";
	}

	return 0;
}