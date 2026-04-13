#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    try
    {
        PmergeMe mrg(av, ac);
        mrg.execute();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}