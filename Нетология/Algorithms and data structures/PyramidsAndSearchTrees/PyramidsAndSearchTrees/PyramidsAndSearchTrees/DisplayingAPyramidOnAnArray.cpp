#include <iostream>
#include <cmath>

void print_pyramid(const int* arr, int size) 
{
    std::cout << "Pyramid: " << std::endl;

    for (int i = 0; i < size; ++i)
    {
        int level = static_cast<int>(log2(i + 1));

        if (i == 0) 
        {
            std::cout << level << " root " << arr[i] << std::endl;
            continue;
        }

        int parent_index = (i - 1) / 2;
        int parent_value = arr[parent_index];

        if (i % 2 == 1)
        {
            std::cout << level << " left(" << parent_value << ") " << arr[i] << std::endl;
        }
        else
        {
            std::cout << level << " right(" << parent_value << ") " << arr[i] << std::endl;
        }
    }
}

void print_array(const int* arr, int size) 
{
    std::cout << "The original array: ";
    for (int i = 0; i < size; ++i) 
    {
        std::cout << arr[i];
        if (i < size - 1) std::cout << " ";
    }
    std::cout << std::endl;
}


void test1() 
{
    std::cout << "=== Test 1 ===" << std::endl;
    int arr[] = { 1, 3, 6, 5, 9, 8 };
    int size = sizeof(arr) / sizeof(arr[0]);

    print_array(arr, size);
    print_pyramid(arr, size);
    std::cout << std::endl;
}

void test2() 
{
    std::cout << "=== Test 2 ===" << std::endl;
    int arr[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
    int size = sizeof(arr) / sizeof(arr[0]);

    print_array(arr, size);
    print_pyramid(arr, size);
    std::cout << std::endl;
}

void test3() 
{
    std::cout << "=== Test 3 ===" << std::endl;
    int arr[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
    int size = sizeof(arr) / sizeof(arr[0]);

    print_array(arr, size);
    print_pyramid(arr, size);
    std::cout << std::endl;
}

int main() 
{
    test1();
    test2();
    test3();

    return 0;
}