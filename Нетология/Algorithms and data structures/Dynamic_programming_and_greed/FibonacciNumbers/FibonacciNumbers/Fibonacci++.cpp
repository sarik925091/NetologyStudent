#include <iostream>
#include <vector>

int fibonacci(int n, std::vector<int>& fib) {
    if (n <= 1) return n;

    if (fib[n] != -1) return fib[n];

    fib[n] = fibonacci(n - 1, fib) + fibonacci(n - 2, fib);
    return fib[n];
}

int main() {
    int n;
    std::cout << "Enter the number of Fibonacci numbers: ";
    std::cin >> n;

    std::vector<int> fib(n + 1, -1);

    std::cout << "Fibonacci numbers: " << std::endl;
    for (int i = 0; i < n; ++i) 
    {
        std::cout << fibonacci(i, fib) << " ";
    }
    
    return 0;
}