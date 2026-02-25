#include <iostream>
#include <string>

template<typename T>
class Big_int 
{
private:
    T* data;
public:
    Big_int() : data(new T{}) {}
    Big_int(T n) : data(new T(n)) {}
    Big_int(const Big_int& other) : data(new T(*other.data)) {}
    Big_int(Big_int&& other) noexcept : data(other.data) { other.data = nullptr; }
    ~Big_int() { delete data; }

    Big_int& operator=(const Big_int& other) 
    {
        if (this != &other) {
            *data = *other.data;  
        }
        return *this;
    }

    Big_int& operator=(Big_int&& other) noexcept 
    {
        if (this != &other) {
            delete data;
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }

    Big_int<T> operator+(const Big_int<T>& other) const 
    {
        return Big_int<T>(*data + *other.data);
    }

    Big_int<T> operator*(const Big_int<T>& other) const 
    {
        return Big_int<T>(*data * *other.data);
    }

    T get() const { return *data; }
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Big_int<T>& vec) 
{
    os << vec.get();
    return os;
}

Big_int<int> big_integer(const std::string& str) 
{
    return Big_int<int>(std::stoi(str));
}

int main() 
{
    auto number1 = big_integer("114575");
    auto number2 = big_integer("78524");
    auto result = number1 + number2;
    std::cout << result; // 193099

    return 0;
}