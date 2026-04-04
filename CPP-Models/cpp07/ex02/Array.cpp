#ifndef ARRAY_TPP
#define ARRAY_TPP

template <typename T>
class Array
{
private:
    unsigned int _size;
    T* _elements;
public:
    Array() : _size(0), _elements(NULL) {}
    Array(unsigned int n)
    {
        _elements = new T[n]();
    }
    // Array(const Array& other)
    // {
        
    // }
    // Array& operator=(const Array& other)
    // {
        
    // }

    T* operator[](const unsigned int i)
    {
        if (i < 0 || i >= _size)
            throw 1;
        return _elements[i];
    }


    // ~Array();
};


#endif