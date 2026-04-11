#pragma once
#include <algorithm>
#include <stdexcept>

template <typename T, typename Y>
typename T::iterator easyfind(T& c, Y value)
{
    typename T::iterator it = std::find(c.begin(), c.end(), value);
    if (it == c.end())
        throw std::runtime_error("easyfind: value not found");
    return it;
}
