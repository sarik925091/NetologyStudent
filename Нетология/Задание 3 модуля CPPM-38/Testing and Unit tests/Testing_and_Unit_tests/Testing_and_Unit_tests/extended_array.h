#pragma once
#include <utility>
#include <initializer_list>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <typeinfo>  
#include <type_traits>

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p) 
{
	os << "(" << p.first << ", " << p.second << ")";
	return os;
}

template <typename T>
class ExtArray
{
private:
	std::vector<T> extended_array;
	size_t _size;

	size_t doCheckSum() const
	{  // This function will be overloaded via enable_if
		return 0;
	}

public:
	ExtArray(std::initializer_list<T> l) : extended_array(l)
	{
		_size = l.size();
	}

	ExtArray(int size) : _size(size)
	{
		extended_array.resize(_size);
	}

	T& operator[](size_t index)
	{
		return extended_array[index];
	}

	size_t size()
	{
		return _size;
	}

	double mean()
	{
		double sum = 0;
		for (size_t i = 0; i < _size; i++)
		{
			sum += extended_array[i];
		}
		return sum / _size;
	}

	double mean(size_t start_index, size_t end_index)
	{
		
		if (start_index >= end_index) 
		{
			throw std::invalid_argument("Start index must be less than end index");
		}

		if (end_index >= extended_array.size()) 
		{
			throw std::out_of_range("End index is out of array bounds");
		}

		double sum = 0;
		size_t count = 0;

		for (size_t i = start_index; i <= end_index; ++i)
		{
			sum += static_cast<double>(extended_array[i]);
			++count;
		}

		return sum / count;
	}

	double median()
	{
		std::vector<T> temp_array;
		std::copy(extended_array.begin(), extended_array.end(), back_inserter(temp_array));
		std::sort(temp_array.begin(), temp_array.end());
		if (_size % 2 == 1)
		{
			return temp_array[_size / 2];
		}
		else
		{
			return static_cast<double>(temp_array[(_size / 2) - 1] + temp_array[_size / 2]) / 2;
		}
	}

	std::pair<T, int> mode()
	{
		T max = extended_array[0], cmax = 0, rmax = 0;
		for (int i = 0; i < _size; i++) 
		{
			if (cmax > rmax) 
			{
				rmax = cmax;
				max = extended_array[i - 1];
			}
			cmax = 0;
			for (int j = i; j < _size; j++)
			{
				if (extended_array[j] == extended_array[i])
				{
					cmax++;
				}
			}
		}
		return std::pair<T, int>(max, rmax);
	}

	size_t checkSumForBool() const 
	{
		size_t count = 0;
		for (bool elem : extended_array) 
		{
			if (elem) 
			{
				++count;
			}
		}
		return count;
	}

	size_t checkSumForInt() const 
	{
		size_t count = 0;
		for (int elem : extended_array) 
		{
			if (elem != 0 && elem != 1) 
			{
				throw std::logic_error("Integer array must contain only 0 and 1");
			}
			if (elem == 1) 
			{
				++count;
			}
		}
		return count;
	}

	size_t checkSum() const
	{
		
		if (!std::is_same<T, bool>::value && !std::is_same<T, int>::value) 
		{
			throw std::bad_typeid();
		}

		
		if constexpr (std::is_same<T, bool>::value) 
		{
			size_t count = 0;
			for (const auto& elem : extended_array) 
			{
				if (elem) 
				{
					++count;
				}
			}
			return count;
		}
		else if constexpr (std::is_same<T, int>::value) 
		{
			size_t count = 0;
			for (const auto& elem : extended_array) 
			{
				
				if (elem != static_cast<T>(0) && elem != static_cast<T>(1)) 
				{
					throw std::logic_error("Integer array must contain only 0 and 1");
				}
				if (elem == static_cast<T>(1)) 
				{
					++count;
				}
			}
			return count;
		}

		return 0;
	}
};

