#include<iostream>
#include"extended_array.h"
#include<sstream>
#include<cassert>

void test_mean() 
{
	ExtArray<int> v1{0};
	assert(v1.mean() == 0);
}

void test_mean_range()
{
	ExtArray<int> v1{ 4, 2, 7, 3, -5, 0, -3, 1 };
    assert(v1.mean(1, 3) == ((2.0 + 7.0 + 3.0) / 3.0)); // Average of 1,2,3 elements
}

void test_median() 
{
	ExtArray<double> v2{0};
	assert(v2.median() == 0);
}

void test_mode() 
{
	ExtArray<int> v1{0};
    assert(v1.mode() == std::pair(0, 0));
}

template <typename TestFunc>
void RunOneTest(TestFunc tfunc, const std::string& test_name) 
{
	try
	{
		tfunc();
		std::cerr << test_name << " OK" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << test_name << " FAIL: " << e.what() << std::endl;
	}
}

void test_checkSum_bool()
{
    ExtArray<bool> arr{ true, false, true, true, false, true, false };
    // true = 1, false = 0, sum = 4
    assert(arr.checkSum() == static_cast<size_t>(4));

    ExtArray<bool> arr2{};
    assert(arr2.checkSum() == static_cast<size_t>(0));

    ExtArray<bool> arr3{ false, false, false };
    assert(arr3.checkSum() == static_cast<size_t>(0));

    ExtArray<bool> arr4{ true, true, true };
    assert(arr4.checkSum() == static_cast<size_t>(3));
}

void test_checkSum_int()
{
    ExtArray<int> arr{ 1, 0, 1, 1, 0, 1, 0 };
    // the sum of the(unit) = 4
    assert(arr.checkSum() == static_cast<size_t>(4));

    ExtArray<int> arr2{};
    assert(arr2.checkSum() == static_cast<size_t>(0));

    ExtArray<int> arr3{ 0, 0, 0 };
    assert(arr3.checkSum() == static_cast<size_t>(0));

    ExtArray<int> arr4{ 1, 1, 1 };
    assert(arr4.checkSum() == static_cast<size_t>(3));
}

void test_checkSum_int_invalid_content()
{
    ExtArray<int> arr{ 1, 0, 2, 1, 0 };
    bool exception_thrown = false;
    try
    {
        arr.checkSum();
    }
    catch (const std::logic_error& e)
    {
        exception_thrown = true;
        std::string expected_msg = "Integer array must contain only 0 and 1";
        if (std::string(e.what()) != expected_msg)
        {
            throw std::runtime_error("Wrong exception message");
        }
    }
    if (!exception_thrown)
    {
        throw std::runtime_error("Expected std::logic_error for invalid int array content");
    }
}

void test_checkSum_wrong_type()
{
    ExtArray<double> arr1{ 1.0, 2.0, 3.0 };
    bool exception_thrown = false;
    try 
    {
        arr1.checkSum();
    }
    catch (const std::bad_typeid& e) 
    {
        exception_thrown = true;
    }
    if (!exception_thrown) 
    {
        throw std::runtime_error("Expected std::bad_typeid for double array");
    }

    ExtArray<std::string> arr2{ "a", "b", "c" };
    exception_thrown = false;
    try 
    {
        arr2.checkSum();
    }
    catch (const std::bad_typeid& e) 
    {
        exception_thrown = true;
    }
    if (!exception_thrown) 
    {
        throw std::runtime_error("Expected std::bad_typeid for string array");
    }

    ExtArray<char> arr3{ 'a', 'b', 'c' };
    exception_thrown = false;
    try 
    {
        arr3.checkSum();
    }
    catch (const std::bad_typeid& e) 
    {
        exception_thrown = true;
    }
    if (!exception_thrown) 
    {
        throw std::runtime_error("Expected std::bad_typeid for char array");
    }
}

int main()
{
    // task 1
	RunOneTest(test_mean, "mean test");
	RunOneTest(test_median, "median test");
	RunOneTest(test_mode, "mode test");
    
    // task 2
	RunOneTest(test_mean_range, "mean range test");

    // task 3
    RunOneTest(test_checkSum_bool, "checkSum bool test");
    RunOneTest(test_checkSum_int, "checkSum int test");
    RunOneTest(test_checkSum_int_invalid_content, "checkSum int invalid content test");
    RunOneTest(test_checkSum_wrong_type, "checkSum wrong type test");
	return 0;
}