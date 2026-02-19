#include <iostream>
#include <vector>
#include <set>

int userInput()
{
    int x;
    std::cin >> x;
    return x;
}

int main()
{
    std::set<int,std::greater<int>> s;

    std::cout << "[IN]: " << std::endl;
    int QtyInput = userInput();

    for (size_t i = 0; i < QtyInput; ++i)
    {
        s.insert(userInput());
    }
  
    std::cout << "[OUT]: " << std::endl;

    for (auto el : s)
    {
        std::cout << el << std::endl;
    }

    return 0;
}