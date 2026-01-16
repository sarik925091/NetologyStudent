#include <iostream>
#include <string>
#include <cmath>

void print_pyramid(const int* arr, int size) 
{
    std::cout << "Pyramid:" << std::endl;

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

std::string get_position_info(const int* arr, int index) 
{
    if (index < 0) return "";

    std::string result;
    int level = static_cast<int>(log2(index + 1));

    if (index == 0) 
    {
        result = std::to_string(level) + " root " + std::to_string(arr[index]);
    }
    else 
    {
        int parent_index = (index - 1) / 2;
        int parent_value = arr[parent_index];

        if (index % 2 == 1) 
        {
            result = std::to_string(level) + " left(" + std::to_string(parent_value) + ") " + std::to_string(arr[index]);
        }
        else 
        {
            result = std::to_string(level) + " right(" + std::to_string(parent_value) + ") " + std::to_string(arr[index]);
        }
    }

    return result;
}

bool has_parent(int index) 
{
    return index > 0;
}

bool has_left_child(int index, int size) 
{
    return (2 * index + 1) < size;
}

bool has_right_child(int index, int size) 
{
    return (2 * index + 2) < size;
}

void travel_pyramid(const int* arr, int size) 
{
    print_array(arr, size);
    print_pyramid(arr, size);

    int current_index = 0;
    std::string command;

    std::cout << "You are here: " << get_position_info(arr, current_index) << std::endl;

    while (true) 
    {
        std::cout << "Enter the command: ";
        std::cin >> command;

        if (command == "up") 
        {
            if (has_parent(current_index)) 
            {
                current_index = (current_index - 1) / 2;
                std::cout << "ok" << std::endl;
            }
            else 
            {
                std::cout << "Mistake! A parent is missing" << std::endl;
            }
        }
        else if (command == "left") 
        {
            if (has_left_child(current_index, size)) 
            {
                current_index = 2 * current_index + 1;
                std::cout << "ok" << std::endl;
            }
            else 
            {
                std::cout << "Mistake! The left descendant is missing" << std::endl;
            }
        }
        else if (command == "right") 
        {
            if (has_right_child(current_index, size)) 
            {
                current_index = 2 * current_index + 2;
                std::cout << "ok" << std::endl;
            }
            else 
            {
                std::cout << "Mistake! The right descendant is missing" << std::endl;
            }
        }
        else if (command == "exit") 
        {
            std::cout << "Exit the program." << std::endl;
            break;
        }
        else 
        {
            std::cout << "Unknown team. Available Commands: up, left, right, exit" << std::endl;
        }

        std::cout << "You are here: " << get_position_info(arr, current_index) << std::endl;
    }
}

int main() 
{
    {
        std::cout << "\n=== Test 1 ===" << std::endl;
        int arr[] = { 1, 3, 6, 5, 9, 8 };
        int size = sizeof(arr) / sizeof(arr[0]);
        travel_pyramid(arr, size);
    }

    {
        std::cout << "\n=== Test 2 ===" << std::endl;
        int arr[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
        int size = sizeof(arr) / sizeof(arr[0]);
        travel_pyramid(arr, size);
    }

    {
        std::cout << "\n=== Test 3 ===" << std::endl;
        int arr[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
        int size = sizeof(arr) / sizeof(arr[0]);
        travel_pyramid(arr, size);
    }

    return 0;
}