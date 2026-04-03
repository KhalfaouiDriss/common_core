#include "iter.hpp"
#include <string>

int main()
{
    char arr1[] = "driss";
    ::iter(arr1, 5, fct<char>);

    std::string arr2[] = {"driss", "adam", "mohammed"};
    ::iter(arr2, 3, fct<std::string>);

    int arr3[] = {1, 2, 3, 4};
    ::iter(arr3, 4, fct<int>);

    return 0;
}