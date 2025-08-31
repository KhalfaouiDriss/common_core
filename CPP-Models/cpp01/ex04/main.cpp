#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av)
{
    if(ac != 4)
        return 1;
    
    std::ifstream infile(av[1]);
    std::ofstream outfile("test.txt");
    std::string line;

    while (std::getline(infile, line))
    {
        outfile << line << "\n";
    }
    
}