#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array
{
private:
    unsigned int _size;
    T* _elements;

public:
    class OutOfRangeException : public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return "Array index out of bounds";
        }
    };

    Array() : _size(0), _elements(new T[0]) {}

    Array(unsigned int n) : _size(n), _elements(new T[n]()) {}

    Array(const Array& other) : _size(other._size), _elements(new T[other._size])
    {
        unsigned int i = -1; 
        while (++i < _size)
            _elements[i] = other._elements[i];
    }

    Array& operator=(const Array& other)
    {
        if (this != &other)
        {
            T* newElements = new T[other._size];
            unsigned int i = -1;
            while (++i < other._size)
                newElements[i] = other._elements[i];
            delete[] _elements;
            _elements = newElements;
            _size = other._size;
        }
        return *this;
    }

    T& operator[](unsigned int index)
    {
        if (index >= _size)
            throw OutOfRangeException();
        return _elements[index];
    }

    const T& operator[](unsigned int index) const
    {
        if (index >= _size)
            throw OutOfRangeException();
        return _elements[index];
    }

    unsigned int size() const
    {
        return _size;
    }

    ~Array()
    {
        delete[] _elements;
    }
};

template <typename T>
std::ostream & operator<<(std::ostream & o, Array<T> const & arr) {
    for (unsigned int i = 0; i < arr.size(); i++) {
        o << arr[i] << " ";
    }
    return o;
}

#endif