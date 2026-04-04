#include "Array.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

#define MAX_VAL 750

int main(int, char**)
{

    Array<int> arr[10];

    std::cout << arr[2] << std::endl;

    // Array<int> numbers(MAX_VAL);
    // int* mirror = new int[MAX_VAL];
    // std::srand(std::time(NULL));
    // for (int i = 0; i < MAX_VAL; i++)
    // {
    //     const int value = std::rand();
    //     numbers[i] = value;
    //     mirror[i] = value;
    // }

    // {
    //     Array<int> tmp = numbers;
    //     Array<int> test(tmp);
    // }

    // for (int i = 0; i < MAX_VAL; i++)
    // {
    //     if (mirror[i] != numbers[i])
    //     {
    //         std::cerr << "didn't save the same value!!" << std::endl;
    //         delete[] mirror;
    //         return 1;
    //     }
    // }
    // try
    // {
    //     numbers[-2] = 0;
    // }
    // catch (const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    // try
    // {
    //     numbers[MAX_VAL] = 0;
    // }
    // catch (const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    // for (int i = 0; i < MAX_VAL; i++)
    //     numbers[i] = std::rand();
    // delete[] mirror;
    // return 0;
}