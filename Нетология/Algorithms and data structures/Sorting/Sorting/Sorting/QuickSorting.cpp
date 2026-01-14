#include <iostream>
#include <utility>


int partition(int* arr, int low, int high) 
{
    int mid = low + (high - low) / 2;
    int pivot = arr[mid];

    std::swap(arr[mid], arr[high]);

    int i = low - 1;

    for (int j = low; j < high; j++) 
    {
        if (arr[j] < pivot) 
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quick_sort_helper(int* arr, int low, int high) 
{
    if (low < high) 
    {
        int pivot_index = partition(arr, low, high);

        quick_sort_helper(arr, low, pivot_index - 1);
        quick_sort_helper(arr, pivot_index + 1, high);
    }
}

void quick_sort(int* arr, int size) 
{
    if (size <= 1) return; 

    quick_sort_helper(arr, 0, size - 1);
}

void print_array(int* arr, int size) 
{
    for (int i = 0; i < size; i++) 
    {
        std::cout << arr[i];
        if (i < size - 1) 
        {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

int main() 
{

    int arr1[] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
    int arr2[] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
    int arr3[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size3 = sizeof(arr3) / sizeof(arr3[0]);

    // Тест 1
    std::cout << "The original array: ";
    print_array(arr1, size1);

    quick_sort(arr1, size1);

    std::cout << "Sorted array: ";
    print_array(arr1, size1);
    std::cout << std::endl;

    // Тест 2
    std::cout << "The original array: ";
    print_array(arr2, size2);

    quick_sort(arr2, size2);

    std::cout << "Sorted array: ";
    print_array(arr2, size2);
    std::cout << std::endl;

    // Тест 3
    std::cout << "The original array: ";
    print_array(arr3, size3);

    quick_sort(arr3, size3);

    std::cout << "Sorted array: ";
    print_array(arr3, size3);

    return 0;
}