#include "PhoneBook.hpp"

int isNumber(std::string Number)
{
    int i = 0;

    while (Number[i])
    {
        if(Number[i] < '0' || Number[i] > '9')
            return 1;
        i++;
    }
    return 0;
}

int add(PhoneBook &PB, int i)
{
    std::string FirstName;
    std::string LastName;
    std::string NickName;
    std::string PhoneNumber;
    std::string DarkestSecret;

    std::cout << "First Name : ";
    std::cin >> FirstName;
    std::cout << "Last Name : ";
    std::cin >> LastName;
    std::cout << "Nick Name : ";
    std::cin >> NickName;
    std::cout << "Phone Number : ";
    std::cin >> PhoneNumber;
    std::cout << "Darkest Secret : ";
    std::cin >> DarkestSecret;
    if(isNumber(PhoneNumber))
    {
        std::cout << "* Error : Add New Contact Not complet\n";
        return 1;
    }
    PB.Set(i + 1 ,FirstName, LastName, NickName, PhoneNumber, DarkestSecret);
    std::cout << "* Add New Contact Succass\n";
    return 0;
}

int main()
{
    std::string cmd;
    
    PhoneBook PB[8] = {};
    int SearchFor;
    int i = 0;

    while (true)
    {
        std::cout << "Contact Count : " << i << "\nenter the command : ";
        std::cin >> cmd;

        if(cmd == "ADD")
        {
            if(!add(PB[i], i))
            {
                if(i < 7)
                    i++;
            }
        }
        else if(cmd == "SEARCH")
        {
            std::cout << "enter the index : ";
            std::cin >> SearchFor;
            if((SearchFor < 1 || SearchFor > 8))
                std::cout << "Invalid Index" << std::endl;
            else
                PB[SearchFor - 1].Display();
        }
        else if(cmd == "EXIT")
            break;
        else
            std::cout << "Invalid Command" << std::endl;
    }
    
}
