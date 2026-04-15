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

// ====================================

std::vector<int> generateJacobsthal(int n)
{
    std::vector<int> jacob;
    jacob.push_back(1);
    jacob.push_back(3);
    while (jacob.back() < n)
    {
        int next = jacob.back() + 2 * jacob[jacob.size() - 2];
        jacob.push_back(next);
    }
    return jacob;
}


// A

std::vector<int> PmergeMe::Merge(std::vector<int> ArrOne, std::vector<int> ArrTwo)
{
    std::vector<int> ArrContent;
    int i = 0;
    int j = 0;
    // ArrContent.insert(ArrContent.begin(), ArrTwo[0]);
    
    std::vector<int> jacobSeq = generateJacobsthal(ArrTwo.size());
    std::vector<bool> isInserted(ArrTwo.size(), false);
    
    while (i < jacobSeq.size())
    {
        size_t targetidx = jacobSeq[i] - 1;
        if (targetidx > ArrTwo.size())
            targetidx = ArrTwo.size() - 1;
        
        int k = targetidx;
        while (k >= 0)
        {
            if (ArrTwo[k] <= ArrOne[k] && !isInserted[k])
            {
                ArrOne.insert(ArrOne.begin() + k , ArrTwo[k]);
                isInserted[k] = true;
            }
            k--;
        }
        i++;
    }
    return ArrOne;
}

std::vector<int> PmergeMe::MergeSort(std::vector<int> Array)
{
    if (Array.size() == 1)
        return Array;
    std::vector<int> ArrOne(Array.begin(), (Array.begin() + (Array.size() / 2)));
    std::vector<int> ArrTwo(Array.begin() + (Array.size() / 2), Array.end());
    std::cout << Array[0] << std::endl;
    std::vector<std::pair<int, int>> pair;
    
    int i = -1; 
    int j; 

    while (++i < std::min(ArrOne.size(), ArrTwo.size()))
        pair.push_back({ArrOne[i], ArrTwo[i]});

    ArrOne = MergeSort(ArrOne);

    i = 0;
    j = 0;

    while (i < ArrOne.size())
    {
        j = 0;
        while (j < pair.size())
        {
            if (ArrOne[i] == pair[j].first)
            {
                ArrTwo[j] = pair[j].second;
                break;
            }
            j++;
        }
        i++;
    }

    i = 0;
    std::cout << "ArrOne : ";
    while (i < ArrOne.size())
        std::cout << "[ " << ArrOne[i++] << " ]";
    
    i = 0;
    std::cout << "\nArrTwo : ";
    while (i < ArrTwo.size())
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



// std::vector<int> PmergeMe::MergeSort(std::vector<int> Array)
// {
//     if (Array.size() <= 1)
//         return Array;

//     std::vector<int> winners, losers;
//     std::vector<std::pair<int, int>> pairs;

//     for (size_t i = 0; i + 1 < Array.size(); i += 2)
//     {
//         if (Array[i] > Array[i + 1])
//         {
//             winners.push_back(Array[i]);
//             pairs.push_back({Array[i], Array[i + 1]});
//         }
//         else
//         {
//             winners.push_back(Array[i + 1]);
//             pairs.push_back({Array[i + 1], Array[i]});
//         }
//     }

//     int stray = -1;
//     if (Array.size() % 2 != 0)
//         stray = Array.back();

//     std::vector<int> sortedWinners = MergeSort(winners);
//     std::vector<int> result = sortedWinners;
//     std::vector<int> sortedLosers;

//     for (int win : sortedWinners)
//     {
//         for (auto &p : pairs)
//         {
//             if (p.first == win)
//             {
//                 sortedLosers.push_back(p.second);
//                 break;
//             }
//         }
//     }
//     result.insert(result.begin(), sortedLosers[0]);
//     std::vector<int> jacobSeq = generateJacobsthal(sortedLosers.size());
//     std::vector<bool> inserted(sortedLosers.size(), false);
//     inserted[0] = true; 

//     for (size_t k = 0; k < jacobSeq.size(); k++)
//     {
//         int targetIdx = jacobSeq[k] - 1;
//         if (targetIdx >= (int)sortedLosers.size())
//             targetIdx = sortedLosers.size() - 1;

//         for (int i = targetIdx; i >= 0; i--)
//         {
//             if (!inserted[i])
//             {
//                 auto it = std::lower_bound(result.begin(), result.end(), sortedLosers[i]);
//                 result.insert(it, sortedLosers[i]);
//                 inserted[i] = true;
//             }
//         }
//     }

//     if (stray != -1)
//     {
//         auto it = std::lower_bound(result.begin(), result.end(), stray);
//         result.insert(it, stray);
//     }

//     return result;
// }


PmergeMe::~PmergeMe()
{
}