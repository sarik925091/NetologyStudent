#include<iostream>
#include<exception>
class smart_array
{
private:
	int* arr;
	int size;
	int count;
public:
	smart_array(int size): count(0)
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
	~smart_array()
	{
		delete[] arr;
	}
};

int main()
{
	try 
	{
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		std::cout << arr.get_element(0) << std::endl;
	}
	catch (const std::exception& ex) 
	{
		std::cout << ex.what() << std::endl;
	}
	return 0;
}