#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>


class PmergeMe
{
private:
    std::vector<int> _arr;
    char** _args;
    int _size;
public:
    PmergeMe(char** args, int size);
    void execute();
    void SplitStr();
    ~PmergeMe();
};
