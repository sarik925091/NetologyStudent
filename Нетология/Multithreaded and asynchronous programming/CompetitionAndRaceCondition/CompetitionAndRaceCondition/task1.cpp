п»ї#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

using std::chrono_literals::operator""ms;


void clients(std::atomic<int>& data)
{
    while (data != 50)  
    {
        std::this_thread::sleep_for(100ms); // 0,1 sec !!
        data++;
        std::cout << data.load(std::memory_order_seq_cst) << " ";
    }
}

void the_operator(std::atomic<int>& data)
{
    while (data != 0)
    {
        std::this_thread::sleep_for(200ms); // 0,2 sec !!
        data--;
        std::cout << "\033[32m\033[40m" << data.load(std::memory_order_seq_cst) << " " << "\033[0m";
    }
}

int main()
{
    std::atomic<int> data;
    data.store(10, std::memory_order_seq_cst);
    std::thread t_incr(clients, std::ref(data));
    std::thread t_decr(the_operator, std::ref(data));
    t_incr.join();
    t_decr.join();
    return 0;
}


