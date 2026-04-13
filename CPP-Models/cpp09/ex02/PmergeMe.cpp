#include "PmergeMe.hpp"


PmergeMe::PmergeMe(char** args, int size) : _args(args), _size(size)
{
}

void PmergeMe::execute()
{
    SplitStr();
}

void PmergeMe::SplitStr()
{
    int i = 1;

    while (i < _size)
    {
        std::string s = _args[i];
        size_t j = 0;
        while (++j < s.length()) {
            if (!std::isdigit(s[j]))
                throw std::runtime_error("Error: Not a positive integer");
        }

        long val = std::atol(_args[i]);
        if (val < 0 || val > 2147483647)
            throw std::runtime_error("Error: Number out of range");

        _arr.push_back(static_cast<int>(val));
        i++;
    }

    std::vector<int>::iterator it = _arr.begin();
    while (it != _arr.end())
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
}

PmergeMe::~PmergeMe()
{

}