#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <mutex>
#include <sstream>      
#include <iomanip>      
#include <Windows.h>

class consol_parameter
{
public:
    static void SetColor(int text, int background)
    {
        SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
    }
    static void SetPosition(int x, int y)
    {
        COORD point;
        point.X = static_cast<SHORT>(x);   
        point.Y = static_cast<SHORT>(y);
        SetConsoleCursorPosition(hStdOut, point);
    }
private:
    static HANDLE hStdOut;
};
HANDLE consol_parameter::hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);



std::mutex console_mutex;

void progress_bar(int thread_num, int bar_length)
{
    std::thread::id tid = std::this_thread::get_id();

    std::ostringstream header;
    header << "thread " << thread_num << ": " << tid << " ";


    int offset = static_cast<int>(header.str().length());

    {
        std::lock_guard<std::mutex> lock(console_mutex);
        consol_parameter::SetPosition(0, thread_num);
        std::cout << header.str();
    }

    auto start = std::chrono::steady_clock::now();


    for (int i = 0; i < bar_length; ++i)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(300));


        std::lock_guard<std::mutex> lock(console_mutex);
        consol_parameter::SetPosition(offset + i, thread_num);
        std::cout << '|';
    }

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed = end - start;


    {
        std::lock_guard<std::mutex> lock(console_mutex);
        consol_parameter::SetPosition(offset + bar_length, thread_num);
        std::cout << "  " << std::fixed << std::setprecision(5)
            << elapsed.count() << " с";
    }
}

int main()
{
    const int num_threads = 4;
    const int bar_length = 25;

    std::vector<std::thread> threads;

    for (int i = 0; i < num_threads; ++i)
        threads.emplace_back(progress_bar, i, bar_length);

    
    for (auto& t : threads)
        t.join();   

    
    consol_parameter::SetPosition(0, num_threads);
    std::cout << std::endl;
    return 0;
}