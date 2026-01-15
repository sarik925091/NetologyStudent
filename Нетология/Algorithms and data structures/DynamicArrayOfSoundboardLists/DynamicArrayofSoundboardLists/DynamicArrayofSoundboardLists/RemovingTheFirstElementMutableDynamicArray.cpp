#include <iostream>
#include <string>

void print_dynamic_array(int* arr, int logical_size, int actual_size) 
{
    for (int i = 0; i < actual_size; i++) 
    {
        if (i < logical_size) 
        {
            std::cout << arr[i];
        }
        else 
        {
            std::cout << "_";
        }

        if (i != actual_size - 1) 
        {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

void remove_dynamic_array_head(int*& arr, int& logical_size, int& actual_size)
{

    if (logical_size <= 0)
    {
        return;
    }

    int new_logical_size = logical_size - 1;

    if (new_logical_size <= actual_size / 3) 
    {

        int new_actual_size = std::max(1, actual_size / 3);

        int* new_arr = new int[new_actual_size];

        for (int i = 1; i < logical_size; i++) 
        {
            new_arr[i - 1] = arr[i];
        }

        logical_size = new_logical_size;
        actual_size = new_actual_size;

        delete[] arr;
        arr = new_arr;
    }
    else 
    {

        for (int i = 1; i < logical_size; i++) {
            arr[i - 1] = arr[i];
        }

        logical_size = new_logical_size;
    }
}

int main() 
{
    int actual_size, logical_size;

    std::cout << "Enter the actual size of the array: ";
    std::cin >> actual_size;

    std::cout << "Enter the logical size of the array: ";
    std::cin >> logical_size;

    if (logical_size > actual_size)
    {
        std::cout << "Mistake! The logical size of the array cannot exceed the actual size!" << std::endl;
        return 1;
    }

    int* arr = new int[actual_size];

    for (int i = 0; i < logical_size; i++) 
    {
        std::cout << "Enter arr[" << i << "]: ";
        std::cin >> arr[i];
    }

    std::cout << "Dynamic array: ";
    print_dynamic_array(arr, logical_size, actual_size);

    std::string answer;
    while (true) 
    {
        std::cout << "Delete the first element? ";
        std::cin >> answer;

        if (answer == "Yes" || answer == "yes" || answer == "YES" || answer == "Y" || answer == "y")
        {
            if (logical_size == 0) 
            {
                std::cout << "The first element cannot be deleted because the array is empty. Goodbye!" << std::endl;
                break;
            }

            remove_dynamic_array_head(arr, logical_size, actual_size);

            std::cout << "Dynamic array: ";
            print_dynamic_array(arr, logical_size, actual_size);
        }
        else if (answer == "нет" || answer == "Нет" || answer == "НЕТ" || answer == "н") 
        {
            std::cout << "Thanks! Your dynamic array: ";
            print_dynamic_array(arr, logical_size, actual_size);
            break;
        }
        else 
        {
            std::cout << "Please enter YES or NO." << std::endl;
        }
    }

    delete[] arr;

    return 0;
}