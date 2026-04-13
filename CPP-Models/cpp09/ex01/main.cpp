#include "RPN.hpp"

int main(int ac, char **av)
{
    try
    {
        RPN calc(av[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}