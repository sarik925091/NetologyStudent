п»ї#include <iostream>
#include <future>
#include <vector>
#include <algorithm>

template<class InputIter, class Func>
void parallel_for_each_(InputIter first, InputIter last, Func func)
{
    auto size = std::distance(first, last);

    if (size <= 100) 
    {
        std::for_each(first, last, func);
        return;
    }

    InputIter middle = first;
    std::advance(middle, size / 2);

    auto f1 = std::async(std::launch::async, parallel_for_each_<InputIter, Func>,
        first, middle, func);

    auto f2 = std::async(std::launch::async, parallel_for_each_<InputIter, Func>,
        middle, last, func);

    f1.get();
    f2.get();
}

int main() {
    std::vector<int> v(1000, 5);

    parallel_for_each_(v.begin(), v.end(), [](int& x) {
        x *= 2;
        });

    for (int x : v) {
        std::cout << x << ' ';
    }
}

