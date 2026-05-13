#include <iostream>
#include <string>
#include <mutex>

class Data
{
private:
    int id;
    double value;
    char symbol;
    std::mutex m;
public:
    Data(int i = 0, double v = 0.0, char s = '\0')
        : id(i), value(v), symbol(s)
    {
    }
    
    Data(Data&& other) noexcept : id(other.id), value(other.value), symbol(other.symbol)
    {
        other.id = 0;
        other.value = 0.0;
        other.symbol = '\0';
    }

    Data& operator=(Data&& other) noexcept
    {
        id = other.id;
        value = other.value;
        symbol = other.symbol;
        other.id = 0;
        other.value = 0.0;
        other.symbol = '\0';
        return *this;
    }

    int         get_Id()     const { return id; }
    double      get_Value()  const { return value; }
    char        get_Symbol() const { return symbol; }
    std::mutex& get_mutex()        { return m; }

};

void swap_lock_guard(Data& d1, Data& d2)
{
    std::lock(d1.get_mutex(), d2.get_mutex());
    std::lock_guard<std::mutex> lk1(d1.get_mutex(), std::adopt_lock);
    std::lock_guard<std::mutex> lk2(d2.get_mutex(), std::adopt_lock);
    Data temp = std::move(d1);
    d1 = std::move(d2);
    d2 = std::move(temp);
}

void swap_unique_lock(Data& d1, Data& d2)
{
    std::unique_lock<std::mutex> lk1(d1.get_mutex(), std::defer_lock);
    std::unique_lock<std::mutex> lk2(d2.get_mutex(), std::defer_lock);
    std::lock(lk1, lk2);
    Data temp = std::move(d1);
    d1 = std::move(d2);
    d2 = std::move(temp);
}

void swap_scoped_lock(Data& d1, Data& d2)
{
    std::scoped_lock sl{d1.get_mutex(), d2.get_mutex()};
    Data temp = std::move(d1);
    d1 = std::move(d2);
    d2 = std::move(temp);
}

int main()
{
    Data d1(5, 4.7, 'r');
    Data d2;
    swap_lock_guard(d1, d2);
    std::cout << d1.get_Id() << " " << d1.get_Value() << " " << d1.get_Symbol() << std::endl;
    std::cout << d2.get_Id() << " " << d2.get_Value() << " " << d2.get_Symbol() << std::endl;

    Data d3(5, 4.7, 'r');
    Data d4;
    swap_unique_lock(d3, d4);
    std::cout << d3.get_Id() << " " << d3.get_Value() << " " << d3.get_Symbol() << std::endl;
    std::cout << d4.get_Id() << " " << d4.get_Value() << " " << d4.get_Symbol() << std::endl;
    
    Data d5(5, 4.7, 'r');
    Data d6;
    swap_scoped_lock(d5, d6);
    std::cout << d5.get_Id() << " " << d5.get_Value() << " " << d5.get_Symbol() << std::endl;
    std::cout << d6.get_Id() << " " << d6.get_Value() << " " << d6.get_Symbol() << std::endl;
    return 0;
}

