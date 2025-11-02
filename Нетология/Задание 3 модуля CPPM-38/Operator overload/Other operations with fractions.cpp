#include <iostream>
#include <stdexcept>

class Fraction {
private:
    int numerator;
    int denominator;
public:
    Fraction(int num, int denom) : numerator(num), denominator(denom) {}

    Fraction operator+(const Fraction& other) const 
    {
        return Fraction(numerator * other.denominator + other.numerator * denominator,denominator * other.denominator);
    }

    Fraction operator-(const Fraction& other) const 
    {
        return Fraction(numerator * other.denominator - other.numerator * denominator,denominator * other.denominator);
    }

    Fraction operator*(const Fraction& other) const 
    {
        return Fraction(numerator * other.numerator,denominator * other.denominator);
    }

    Fraction operator/(const Fraction& other) const 
    {
        if (other.numerator == 0) {
            throw std::invalid_argument("Division by zero.");
        }
        return Fraction(numerator * other.denominator,denominator * other.numerator);
    }

    Fraction operator-() const        //Унарный минус! Eng(Unary minus)
    {
        return Fraction(-numerator, denominator);
    }

    Fraction& operator++() 
    {
        numerator += denominator;
        return *this;
    }
    
    Fraction operator++(int) 
    {
        Fraction temp = *this;
        numerator += denominator;
        return temp;
    }
    
    Fraction& operator--() 
    {
        numerator -= denominator;  
        return *this;
    }

    Fraction operator--(int) 
    {
        Fraction temp = *this;
        numerator -= denominator;
        return temp;
    }

    Fraction& operator+=(const Fraction& other) 
    {
        *this = *this + other;
        return *this;
    }

    Fraction& operator-=(const Fraction& other) 
    {
        *this = *this - other;
        return *this;
    }

    Fraction& operator*=(const Fraction& other) 
    {
        *this = *this * other;
        return *this;
    }

    Fraction& operator/=(const Fraction& other) {
        *this = *this / other;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Fraction& f) 
    {
        os << f.numerator;
        if (f.denominator != 1) 
        {
            os << "/" << f.denominator;
        }
        return os;
    }

    int getNum() const { return numerator; }
    int getDeNum() const { return denominator; }
};

int userInput();
void printResult(Fraction& n1, Fraction& n2);

void getValue()
{
    int num1, denum1, num2, denum2;
    std::cout << "Enter the numerator of the fraction 1: ";
    num1 = userInput();
    std::cout << "Enter the denumerator of the fraction 1: ";
    denum1 = userInput();
    std::cout << "Enter the numerator of the fraction 2: ";
    num2 = userInput();
    std::cout << "Enter the denumerator of the fraction 2: ";
    denum2 = userInput();

    Fraction n1{ num1,denum1 };
    Fraction n2{ num2,denum2 };
    printResult(n1, n2);
}

void printResult(Fraction& n1, Fraction& n2)
{
    std::cout << n1.getNum() << "/" << n1.getDeNum() << " + " << n2.getNum() << "/" << n2.getDeNum() << " = " << n1 + n2 << std::endl;
    std::cout << n1.getNum() << "/" << n1.getDeNum() << " - " << n2.getNum() << "/" << n2.getDeNum() << " = " << n1 - n2 << std::endl;
    std::cout << n1.getNum() << "/" << n1.getDeNum() << " * " << n2.getNum() << "/" << n2.getDeNum() << " = " << n1 * n2 << std::endl;
    std::cout << n1.getNum() << "/" << n1.getDeNum() << " / " << n2.getNum() << "/" << n2.getDeNum() << " = " << n1 / n2 << std::endl;
    std::cout << "++" << n1.getNum() << "/" << n1.getDeNum() << " * " << n2.getNum() << "/" << n2.getDeNum() << " = " << (++n1) * n2 << std::endl;
    std::cout << "The value of the fraction is 1 = " << ++n1 << std::endl;
    std::cout << n1.getNum() << "/" << n1.getDeNum() << "--" << " * " << n2.getNum() << "/" << n2.getDeNum() << " = " << (n1--) * n2 << std::endl;
    std::cout << "The value of the fraction is 1 = " << (n1--) << std::endl;
}

int main()
{
    getValue();

    return 0;
}

int userInput()
{
    int i{};
    std::cin >> i;
    return i;
}