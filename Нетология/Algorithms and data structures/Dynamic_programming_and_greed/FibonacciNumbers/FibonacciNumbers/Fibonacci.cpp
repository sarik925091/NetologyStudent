#include <iostream>

int fibonacci(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;
    std::cout << "Enter the number of Fibonacci numbers: ";
    std::cin >> n;

    std::cout << "Fibonacci numbers: " << std::endl;
    for (int i = 0; i < n; ++i) 
    {
        std::cout << fibonacci(i) << " ";
    }

    /*Для вычисления одного fibonacci(i) :
    Рекурсивный алгоритм имеет экспоненциальную сложность O(2 ^ n), так как :
    Каждый вызов порождает два новых рекурсивных вызова(кроме базовых случаев)
    В каждый момент времени в стеке находится не более n вызовов
    Сложность по памяти : O(n) в худшем случае*/

    return 0;
}
