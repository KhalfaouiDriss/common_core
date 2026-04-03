#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cstddef>

template <typename T>
void fct(T const &x)
{
    std::cout << x << std::endl;
}

template <typename T, typename F>
void iter(T *array, std::size_t length, F func)
{
    if (!array)
        return;
    for (std::size_t i = 0; i < length; ++i)
        func(array[i]);
}

template <typename T, typename F>
void iter(T const *array, std::size_t length, F func)
{
    if (!array)
        return;
    for (std::size_t i = 0; i < length; ++i)
        func(array[i]);
}

#endif