#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main() 
{
    std::string text;
    std::cout << "[IN]: ";
    std::getline(std::cin, text);

    std::unordered_map<char, int> freq;
    for (char c : text) 
    {
        ++freq[c];
    }
    
    std::vector<std::pair<char, int>> items(freq.begin(), freq.end());
    
    std::sort(items.begin(), items.end(),
        [](const auto& a, const auto& b) 
        {
            return a.second > b.second;
        });

    for (const auto& p : items) 
    {
        std::cout << p.first << ": " << p.second << std::endl;
    }

    return 0;
}