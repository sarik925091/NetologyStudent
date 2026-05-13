п»ї
#include <iostream>
#include <thread>
#include <chrono>

using std::chrono_literals::operator""ms;


void clients(int& var)
{
    while (var != 50)
    {
        //std::this_thread::sleep_for(100ms); // 0,1 sec !!
        var++;
        std::cout << var << " ";
    }
}

void the_operator(int& var)
{
    while (var != 0)
    {
        //std::this_thread::sleep_for(200ms); // 0,2 sec !!
        var--;
        std::cout << "\033[32m\033[40m" << var << " " << "\033[0m";
    }
}

int main()
{
    int data = 10;
    std::thread t_incr(clients, std::ref(data));
    std::thread t_decr(the_operator, std::ref(data));
    t_incr.join();
    t_decr.join();
    return 0;
}

