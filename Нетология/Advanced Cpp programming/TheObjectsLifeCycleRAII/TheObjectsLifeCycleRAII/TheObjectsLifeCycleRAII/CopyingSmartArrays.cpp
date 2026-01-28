#include<iostream>
#include<exception>

class smart_array
{
private:
	int* arr;
	int size;
	int count;
public:
	smart_array(int size) : count(0)
	{
		arr = new int[size] {};
		this->size = size;
	}
	void add_element(int n)
	{
		if (arr[size - 1] != 0)
		{
			throw std::exception("Index outside the array, the array is overflowing!");
		}
		else
		{
			for (size_t i = 0; i < size; ++i)
			{
				if (arr[i] == 0)
				{
					arr[i] = n;
					++count;
					break;
				}
				else
				{
					continue;
				}
			}
		}
	}
	int get_element(int i)
	{
		if (i >= size)
		{
			throw std::exception("Index outside the array!");
		}
		else
		{
			return arr[i];
		}
	}

	smart_array& operator=(const smart_array& other) 
	{
		if (this != &other) 
		{ 
			delete[] arr; 
			
			count = other.count;
			size = other.size;
			arr = new int[size];

			for (size_t i = 0; i < size; ++i)
			{
				arr[i] = other.arr[i];
			}
		}
		return *this;
	}

	~smart_array()
	{
		delete[] arr;
	}
};

int main()
{
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);

		smart_array new_array(2);
		new_array.add_element(44);
		new_array.add_element(34);

		arr = new_array;
		std::cout << new_array.get_element(0) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}