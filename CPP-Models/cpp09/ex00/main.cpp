#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{

    if (ac != 2)
    {
        std::cerr << "Error: The input should be : ./btc {file}.csv\n";
        return 1;
    }


    try
    {
        BitcoinExchange Btc(av[1]);
        BitcoinExchange Btc2("input3.txt");
        Btc2 = Btc;
        Btc2.Result();      

    } catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}