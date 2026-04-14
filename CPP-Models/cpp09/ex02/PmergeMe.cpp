#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **args, int size) : _args(args), _size(size)
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
        while (++j < s.length())
        {
            if (!std::isdigit(s[j]))
                throw std::runtime_error("Error: Not a positive integer");
        }

        long val = std::atol(_args[i]);
        if (val < 0 || val > 2147483647)
            throw std::runtime_error("Error: Number out of range");

        _arr.push_back(static_cast<int>(val));
        i++;
    }

    _arr = MergeSort(_arr);

    std::vector<int>::iterator it = _arr.begin();
    while (it != _arr.end())
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
}

// A

std::vector<int> PmergeMe::Merge(std::vector<int> ArrOne, std::vector<int> ArrTwo)
{
    std::vector<int> ArrContent;
    int i = 0;
    int j = 0;
    while (i < ArrOne.size() && j < ArrTwo.size())
    {
        if (ArrOne[i] < ArrTwo[j])
        {
            std::cout << "  pick [ " << ArrOne[i] << " ] from ArrOne\n";
            ArrContent.push_back(ArrOne[i]);
            i++;
        }
        else
        {
            std::cout << "  pick [ " << ArrTwo[j] << " ] from ArrTwo\n";
            ArrContent.push_back(ArrTwo[j]);
            j++;
        }
    }

    while (i < ArrOne.size())
    {
        std::cout << "  rest [ " << ArrOne[i] << " ] from ArrOne\n";
        ArrContent.push_back(ArrOne[i]);
        i++;
    }
    while (j < ArrTwo.size())
    {
        std::cout << "  rest [ " << ArrTwo[j] << " ] from ArrTwo\n";
        ArrContent.push_back(ArrTwo[j]);
        j++;
    }
    return ArrContent;
}

std::vector<int> PmergeMe::MergeSort(std::vector<int> Array)
{
    if (Array.size() == 1)
        return Array;
    std::vector<int> ArrOne(Array.begin(), (Array.begin() + (Array.size() / 2)));
    std::vector<int> ArrTwo(Array.begin() + (Array.size() / 2), Array.end());

    ArrOne = MergeSort(ArrOne);
    ArrTwo = MergeSort(ArrTwo);

    int i = 0;
    std::cout << "ArrOne : ";
    while (i < (int)ArrOne.size())
        std::cout << "[ " << ArrOne[i++] << " ]";
    i = 0;
    std::cout << "\nArrTwo : ";
    while (i < (int)ArrTwo.size())
        std::cout << "[ " << ArrTwo[i++] << " ]";
    std::cout << "\n";

    std::vector<int> result = Merge(ArrOne, ArrTwo);

    i = 0;
    std::cout << "Merged : ";
    while (i < (int)result.size())
        std::cout << "[ " << result[i++] << " ]";
    std::cout << "\n---\n";

    return (result);
}

PmergeMe::~PmergeMe()
{
}