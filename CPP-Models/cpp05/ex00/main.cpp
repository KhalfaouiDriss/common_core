#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat p("Driss" ,150);
        std::cout << p << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() <<std::endl;
    }
}