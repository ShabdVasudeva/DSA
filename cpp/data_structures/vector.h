#include <iostream>
#include <stdexcept>
#include <cstddef>
#include <initializer_list>

using namespace std;

template <typename T>
class vector {
private:
    T* data;
    size_t _size;
    size_t _capacity;

    void resize(size_t new_capacity)
    {
        T* new_data = new T[new_capacity];
        for(size_t i=0; i<_size; ++i)
        {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        _capacity = new_capacity;
    }

public:
    vector(): data(nullptr), _size(0), _capacity(0) {}
    vector(std::initializer_list<T> init)
    {
        _size = init.size();
        _capacity = _size;
        data = new T[_capacity];

        size_t i = 0;
        for (const T& val : init)
        {
            data[i++] = val;
        }
    }

    ~vector()
    {
        delete[] data;
    }
   
    void push_back(const T& value)
    {
        if (_size == _capacity)
        {
            size_t new_capacity = (_capacity == 0) ? 1 : _capacity * 2;
            resize(new_capacity);
        }
        data[_size++] = value;
    }

    void pop_back()
    {
        if (_size > 0)
        {
            --_size;
        }
    }

    bool empty() { return (_size == 0); }

    size_t size() { return _size; }

    size_t capacity() { return _capacity; }

    T& operator[](size_t index)
    {
        if (index >= _size)
        {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    const T& operator[](size_t index) const
    {
        if (index >= _size)
        {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    template <typename U>
    friend ostream& operator<<(ostream& os, const vector<U>& v) 
    {
        os << "{";
        for (size_t i=0; i<v._size; i++)
        {
            if (i > 0)
            {
                os << ",";
            }
            
            os << v[i];
        }
        os << "}";
        return os;
    }
};