#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<int>& fill_v(std::vector<int>& val, size_t capacity)
{
    val.clear();
    val.reserve(capacity);
    for (size_t i = 0; i < capacity; ++i)
        val.push_back(std::rand() % 10);
    return val;
}

void sum_v(const std::vector<int>& src, std::vector<int>& dst,
    size_t start, size_t end)
{
    for (size_t i = start; i < end; ++i)
        dst[i] = src[i] + src[i];
}

double thread_f(const std::vector<int>& v1, std::vector<int>& v2,
    size_t size_, int t_qty)
{
    v2.resize(size_);

    std::vector<std::thread> threads;
    auto start = std::chrono::steady_clock::now();

    size_t chunk = size_ / t_qty;
    size_t remainder = size_ % t_qty;
    size_t current_start = 0;

    for (int i = 0; i < t_qty; ++i)
    {
        size_t current_end = current_start + chunk + (i < remainder ? 1 : 0);
        threads.emplace_back(sum_v, std::cref(v1), std::ref(v2),
            current_start, current_end);
        current_start = current_end;
    }

    for (auto& t : threads)
        t.join();

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    return elapsed.count();
}

void print_result(std::vector<int>& v1, std::vector<int>& v2)
{
    using namespace std;
    cout << thread::hardware_concurrency() << endl;

    cout << "1 THREAD ";
    cout << thread_f(fill_v(v1, 1000), v2, 1000, 1) << "\t";
    cout << thread_f(fill_v(v1, 10'000), v2, 10'000, 1) << "\t";
    cout << thread_f(fill_v(v1, 100'000), v2, 100'000, 1) << "\t";
    cout << thread_f(fill_v(v1, 1'000'000), v2, 1'000'000, 1) << endl;

    cout << "2 THREAD ";
    cout << thread_f(fill_v(v1, 1000), v2, 1000, 2) << "\t";
    cout << thread_f(fill_v(v1, 10'000), v2, 10'000, 2) << "\t";
    cout << thread_f(fill_v(v1, 100'000), v2, 100'000, 2) << "\t";
    cout << thread_f(fill_v(v1, 1'000'000), v2, 1'000'000, 2) << endl;

    cout << "4 THREAD ";
    cout << thread_f(fill_v(v1, 1000), v2, 1000, 4) << "\t";
    cout << thread_f(fill_v(v1, 10'000), v2, 10'000, 4) << "\t";
    cout << thread_f(fill_v(v1, 100'000), v2, 100'000, 4) << "\t";
    cout << thread_f(fill_v(v1, 1'000'000), v2, 1'000'000, 4) << endl;

    cout << "8 THREAD ";
    cout << thread_f(fill_v(v1, 1000), v2, 1000, 8) << "\t";
    cout << thread_f(fill_v(v1, 10'000), v2, 10'000, 8) << "\t";
    cout << thread_f(fill_v(v1, 100'000), v2, 100'000, 8) << "\t";
    cout << thread_f(fill_v(v1, 1'000'000), v2, 1'000'000, 8) << endl;

}

int main()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    std::vector<int> v1, v2;
    print_result(v1, v2);
}