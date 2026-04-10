#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>


class Span
{
private:
    unsigned int _Size;
    std::vector<int> list;
public:
    Span(unsigned int Num);
    void addNumber(int ad);
    void addNumbers(std::vector<int> ads);
    int shortestSpan();
    int longestSpan();

    ~Span();
};


