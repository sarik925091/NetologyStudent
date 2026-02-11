#include <iostream>
#include <vector>
#include <algorithm>

class Sum 
{
    int total = 0;
public:
    void operator()(int value)
    {
        if (value % 3 == 0)
        {
            total += value;
        }
    }
    int get() const { return total; }
};

class Count 
{
    int count = 0;
public:
    void operator()(int value)
    {
        if (value % 3 == 0)
        {
            ++count;
        }
    }
    int get() const { return count; }
};

int get_sum(std::vector<int> v)
{
    Sum s = std::for_each(v.begin(), v.end(), Sum());
    return s.get();
}

int get_count(std::vector<int> v)
{
    Count c = std::for_each(v.begin(), v.end(), Count());
    return c.get();
}

int main() 
{
    std::vector<int> v = { 4, 1, 3, 6, 25, 54 };

    std::for_each(v.begin(), v.end(), [](int x) 
        {
        std::cout << x << ' ';
        });
    std::cout << std::endl;

    std::cout << "[OUT]: get_sum() =  " << get_sum(v) << std::endl;

    std::cout << "[OUT]: get_count() =  " << get_count(v) << std::endl;

    return 0;   
}