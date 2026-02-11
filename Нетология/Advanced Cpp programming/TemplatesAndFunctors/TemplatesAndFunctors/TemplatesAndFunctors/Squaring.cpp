#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <cstdlib>

std::vector<int> processInput(std::string& input)
{
    std::vector<int> result;
    std::stringstream ss(input);
    std::string token;

    while (std::getline(ss, token, ','))
    {
        token.erase(0, token.find_first_not_of(' '));
        token.erase(token.find_last_not_of(' ') + 1);

        int num = std::stoi(token);
        result.push_back(num);
    }
    return result;
}

template<typename T>
T squaring(T val)
{
    return (val * val);
}

template<typename V>
std::vector<V> squaring(std::vector<V>& v)
{
    std::vector<V> result = v;
    for (auto& i : result)
    {
        i *= i;
    }
    return result;
}

template<typename T>
T userInputSingle()
{
    T x{};
    std::cout << "[IN]: ";
    std::cin >> x;
    return x;
}

std::string userInputString()
{
    std::string x;
    std::cout << "[IN]: ";
    std::getline(std::cin >> std::ws, x);
    return x;
}

int main()
{

    std::cout << "Single number " << std::endl;
    auto singleNum = userInputSingle<double>();
    std::cout << "[OUT]: " << squaring(singleNum) << std::endl;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Vector of numbers" << std::endl;
    std::string input = userInputString();
    std::vector<int> numbers = processInput(input);
    std::vector<int> squaredNumbers = squaring(numbers);

    std::cout << "[OUT]: ";
    for (size_t i = 0; i < squaredNumbers.size(); ++i)
    {
        std::cout << squaredNumbers[i];
        if (i != squaredNumbers.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;

    return 0;
}