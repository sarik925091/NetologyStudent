#include<iostream>
#include <vector>
#include <stdexcept>

template<typename T>
class Table
{
    std::vector<std::vector<T>> arr;
public:
    Table(size_t rows, size_t cols) : arr(rows, std::vector<T>(cols)) {}

    std::vector<T>& operator[](size_t row)
    {
        return arr[row];
    }

    const std::vector<T>& operator[](size_t row) const
    {
        return arr[row];
    }

};

int main()
{
    auto test = Table<int>(2, 3);
    test[0][0] = 4;
    std::cout << test[0][0];
    return 0;
}