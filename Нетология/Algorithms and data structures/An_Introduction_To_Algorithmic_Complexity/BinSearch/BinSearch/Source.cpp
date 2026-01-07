#include<iostream>
#include<cassert>


int userInput()
{
	int x;
	std::cout << "Enter a reference point: ";
	std::cin >> x;
	return x;
}
void printResult(int count, int userNum)
{
	std::cout << "The number of elements in the array is greater than " << userNum << ": " << count << std::endl;

}

int pointOfReference(int* arr, int userNum , int size)
{
    int left = 0;
    int right = size;  

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > userNum) {
            right = mid;  
        }
        else {
            left = mid + 1;  
        }
    }

    return size - left;
}

void testPointOfReferenc(int* arr, int userNum, int size, int count)
{                                            
	assert(pointOfReference(arr, userNum, size) == count); 
}                                                         

int main()
{
	const int size{ 9 };
	int arr[size]{ 14, 16, 19, 32, 32, 32, 56, 69, 72, };

	int userNum = userInput();

	int count = pointOfReference(arr, userNum, size);
	printResult(count, userNum);
	testPointOfReferenc(arr, userNum, size, count);

	return 0;
}