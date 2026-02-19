#include <iostream>
#include <algorithm>   
#include <stdexcept>   

template<typename T>
class Vector {
private:
    T* data;
    size_t size_;      
    size_t capacity_;  

public:
    
    using iterator = T*;
    using const_iterator = const T*;
    
    Vector() : data(nullptr), size_(0), capacity_(0) {}

    explicit Vector(size_t n) : data(new T[n]), size_(n), capacity_(n) 
    {
    }

    Vector(size_t n, const T& val) : data(new T[n]), size_(n), capacity_(n) 
    {
        for (size_t i = 0; i < n; ++i)
            data[i] = val;
    }

    Vector(std::initializer_list<T> vals)
        : data(new T[vals.size()]), size_(vals.size()), capacity_(vals.size()) 
    {
        std::copy(vals.begin(), vals.end(), data);
    }

    Vector(const Vector& other)
        : data(new T[other.size_]), size_(other.size_), capacity_(other.size_) 
    {
        std::copy(other.data, other.data + other.size_, data);
    }

    Vector& operator=(const Vector& other) 
    {
        if (this != &other) 
        {
            delete[] data;                              
            size_ = other.size_;
            capacity_ = other.size_;
            data = new T[capacity_];
            std::copy(other.data, other.data + other.size_, data);
        }
        return *this;
    }

    ~Vector() 
    {
        delete[] data;
    }

    T& operator[](size_t index) 
    {
        return data[index];
    }

    const T& operator[](size_t index) const 
    {
        return data[index];
    }

    T& at(size_t index) 
    {
        if (index >= size_)
            throw std::out_of_range("Vector::at");
        return data[index];
    }

    const T& at(size_t index) const 
    {
        if (index >= size_)
            throw std::out_of_range("Vector::at");
        return data[index];
    }

    iterator begin() { return data; }
    const_iterator begin() const { return data; }
    iterator end() { return data + size_; }
    const_iterator end() const { return data + size_; }

    size_t size() const { return size_; }
    size_t capacity() const { return capacity_; }

    void push_back(const T& val) 
    {
        if (size_ >= capacity_) 
        {
            size_t new_cap = (capacity_ == 0) ? 1 : capacity_ * 2;
            reserve(new_cap); 
        }
        data[size_++] = val;
    }

    void reserve(size_t new_cap) 
    {
        if (new_cap <= capacity_) return;
        T* new_data = new T[new_cap];
        for (size_t i = 0; i < size_; ++i)
        {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity_ = new_cap;
    }

    void clear() 
    {
        size_ = 0;
    }

};

int main() 
{
    Vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    std::cout << "v1 size = " << v1.size() << ", capacity = " << v1.capacity() << std::endl;

    Vector<int> v2 = { 1, 2, 3, 4 }; 
    std::cout << "v2: ";
    for (auto x : v2) std::cout << x << ' ';
    std::cout << std::endl;

    Vector<int> v3(5, 42);         
    std::cout << "v3[2] = " << v3[2] << std::endl;

    Vector<int> v4 = v2;
    v4.push_back(100);
    std::cout << "v4 size = " << v4.size() << std::endl;

    return 0;
}