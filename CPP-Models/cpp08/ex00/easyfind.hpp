#pragma once
#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::const_iterator easyfind(const T& c, int value)
{
    typename T::const_iterator it = std::find(c.begin(), c.end(), value);
    if (it == c.end())
        throw std::runtime_error("easyfind: value not found");
    return it;
}
