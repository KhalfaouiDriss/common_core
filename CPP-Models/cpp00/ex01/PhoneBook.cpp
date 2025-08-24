#include "PhoneBook.hpp"

void add(PhoneBook &PB, int i)
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
    PB.Set(i + 1 ,FirstName, LastName, NickName, PhoneNumber, DarkestSecret);
}

int main()
{
    std::string cmd;
    
    PhoneBook PB[8] = {};
    int SearchFor;
    int i = 0;

    while (true)
    {
        std::cout << "enter the command : ";
        std::cin >> cmd;

        if(cmd == "ADD")
        {
            add(PB[i], i);
            if(i < 7)
                i++;
        }
        else if(cmd == "SEARCH")
        {
            std::cout << "enter the index : ";
            std::cin >> SearchFor;
            if((SearchFor < 1 || SearchFor > 4))
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
