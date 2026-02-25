#include <iostream>
#include<memory>

template<typename T>
class Unique_ptr
{
    T* ptr_;
public:
    Unique_ptr() : ptr_(nullptr) {}
    explicit Unique_ptr(T* ptr) : ptr_(ptr) {}
    Unique_ptr(std::unique_ptr<T> ptr) : ptr_(ptr.release()) {}
    ~Unique_ptr() { delete ptr_; }
    Unique_ptr(const Unique_ptr& ptr) = delete;

    Unique_ptr& operator=(Unique_ptr& ptr) = delete;
    T& operator*() { return *ptr_; }

    T* release() noexcept
    {
        T* temp = ptr_;
        ptr_ = nullptr;
        return temp;
    }
    T* get() const { return ptr_; }
};

int main()
{
    Unique_ptr<int> ob = std::make_unique<int>(10);

    std::cout << ob.get() << " -- " << *ob << std::endl;
    auto ptr = ob.release();
    std::cout << ob.get() << std::endl;

    delete ptr;
    
    return 0;
}