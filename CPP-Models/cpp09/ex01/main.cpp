#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    try
    {
        RPN calc(av[1]);
        calc.execute();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}