#include "Span.hpp"

Span::Span(unsigned int Num) : _Size(Num){}

void Span::addNumber(int ad)
{
    if (_Size == 0)
        throw std::runtime_error("Array is full");
    list.push_back(ad);
}

void Span::addNumbers(std::vector<int> ads)
{
    if (_Size == 0)
        throw std::runtime_error("Array is full");
    std::vector<int>::iterator it = ads.begin();
    while (it != ads.end())
    {
        if (_Size == 0)
            throw std::runtime_error("Out Of Range");
        list.push_back(*it);
        _Size--;
        it++;
    }
}

int Span::shortestSpan()
{
    std::vector<int> tmp = list;
    std::sort(tmp.begin(), tmp.end());
    std::vector<int>::iterator it = tmp.begin();

    int max = 100000;

    while (it != tmp.end() - 1)
    {
        int t = *(it + 1) - *it;
        if (t <= max)
            max = t;
        it++;
    }
    return (max);
}

int Span::longestSpan()
{
    std::vector<int> tmp = list;
    std::sort(tmp.begin(), tmp.end());
    return (*(tmp.end() - 1) - *tmp.begin());
}

Span::~Span()
{
}