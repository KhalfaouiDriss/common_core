#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat p("saad" ,151);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() <<std::endl;
    }
}