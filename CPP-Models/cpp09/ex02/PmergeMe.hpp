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
    std::vector<int> MergeSort(std::vector<int> array);
    static std::vector<int> Merge(std::vector<int> ArrOne, std::vector<int> ArrTwo);
    ~PmergeMe();
};
