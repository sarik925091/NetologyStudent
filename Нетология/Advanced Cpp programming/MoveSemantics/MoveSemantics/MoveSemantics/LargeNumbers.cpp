#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

class big_integer 
{
private:
    std::vector<char> digits;
    bool negative;

    // Module comparison: returns true if |this| < |other|
    bool abs_less(const big_integer& other) const 
    {
        if (digits.size() != other.digits.size())
            return digits.size() < other.digits.size();
        for (size_t i = digits.size(); i-- > 0; ) 
        {
            if (digits[i] != other.digits[i])
                return digits[i] < other.digits[i];
        }
        return false;
    }

    // Addition of modules (|a| + |b|) without considering the sign
    static big_integer abs_add(const big_integer& a, const big_integer& b) 
    {
        big_integer result;
        result.digits.clear();
        size_t max_size = std::max(a.digits.size(), b.digits.size());
        result.digits.reserve(max_size + 1);

        int carry = 0;
        for (size_t i = 0; i < max_size || carry; ++i) 
        {
            int sum = carry;
            if (i < a.digits.size()) sum += a.digits[i];
            if (i < b.digits.size()) sum += b.digits[i];
            result.digits.push_back(sum % 10);
            carry = sum / 10;
        }
        result.negative = false; 
        result.normalize();
        return result;
    }

    // Subtraction of modules (|a| - |b|) if |a| >= |b|
    static big_integer abs_sub(const big_integer& a, const big_integer& b) 
    {
        big_integer result;
        result.digits.clear();
        result.digits.reserve(a.digits.size());

        int borrow = 0;
        for (size_t i = 0; i < a.digits.size(); ++i) 
        {
            int diff = a.digits[i] - borrow;
            if (i < b.digits.size()) diff -= b.digits[i];
            if (diff < 0) 
            {
                diff += 10;
                borrow = 1;
            }
            else 
            {
                borrow = 0;
            }
            result.digits.push_back(diff);
        }
        // borrow after the last iteration should be 0 (guaranteed by the condition |a| >= |b|)
        result.negative = false;
        result.normalize();
        return result;
    }

    void normalize() 
    {
        while (digits.size() > 1 && digits.back() == 0) 
        {
            digits.pop_back();
        }

        if (digits.size() == 1 && digits[0] == 0) 
        {
            negative = false;
        }
    }

public:

    big_integer() : digits(1, 0), negative(false) {}

    big_integer(const std::string& str) 
    {
        if (str.empty()) 
        {
            throw std::invalid_argument("Empty string");
        }

        size_t start = 0;
        if (str[0] == '-') 
        {
            negative = true;
            start = 1;
        }
        else 
        {
            negative = false;
        }

        while (start < str.size() && str[start] == '0') 
        {
            ++start;
        }

        if (start == str.size()) 
        {
            digits.push_back(0);
            negative = false;
            return;
        }

        digits.clear();
        for (auto it = str.rbegin(); it != str.rend() - start; ++it) 
        {
            char ch = *it;
            if (ch < '0' || ch > '9') 
            {
                throw std::invalid_argument("Invalid character in big number string");
            }
            digits.push_back(ch - '0');
        }
    }

    big_integer(const big_integer&) = default;

    big_integer(big_integer&& other) noexcept
        : digits(std::move(other.digits)), negative(other.negative) 
    {
    }

    big_integer& operator=(const big_integer&) = default;

    big_integer& operator=(big_integer&& other) noexcept 
    {
        if (this != &other) 
        {
            digits = std::move(other.digits);
            negative = other.negative;
        }
        return *this;
    }
    
    ~big_integer() = default;


    friend big_integer operator+(const big_integer& a, const big_integer& b) 
    {
        if (a.negative == b.negative) 
        {
            big_integer result = abs_add(a, b);
            result.negative = a.negative; 
            return result;
        }

        if (a.abs_less(b)) 
        {
            big_integer result = abs_sub(b, a);
            result.negative = b.negative;
            return result;
        }
        else 
        {
            big_integer result = abs_sub(a, b);
            result.negative = a.negative;
            return result;
        }
    }


    friend big_integer operator*(const big_integer& a, int b) 
    {
        bool res_negative = a.negative ^ (b < 0); // Defining the sign
        long long abs_b = std::llabs(static_cast<long long>(b));

        big_integer result;
        result.digits.clear();
        result.digits.reserve(a.digits.size() + 10);

        long long carry = 0;
        for (char digit : a.digits) 
        {
            long long product = digit * abs_b + carry;
            result.digits.push_back(product % 10);
            carry = product / 10;
        }
        while (carry) 
        {
            result.digits.push_back(carry % 10);
            carry /= 10;
        }

        result.negative = res_negative;
        result.normalize(); 
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const big_integer& num) 
    {
        if (num.negative && !(num.digits.size() == 1 && num.digits[0] == 0)) 
        {
            os << '-';
        }
        for (auto it = num.digits.rbegin(); it != num.digits.rend(); ++it) 
        {
            os << static_cast<int>(*it);
        }
        return os;
    }
};

int main() 
{
    try 
    {
        auto number1 = big_integer("114575");
        auto number2 = big_integer("78524");
        auto sum_pos = number1 + number2;
        std::cout << number1 << " + " << number2 << " = " << sum_pos << std::endl; // 193099

        auto number3 = big_integer("-12345");
        auto number4 = big_integer("6789");
        auto sum_mixed = number3 + number4;
        std::cout << number3 << " + " << number4 << " = " << sum_mixed << std::endl; // -5556

        auto mul1 = number1 * 3;
        std::cout << number1 << " * 3 = " << mul1 << std::endl; // 343725
    }
    catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}