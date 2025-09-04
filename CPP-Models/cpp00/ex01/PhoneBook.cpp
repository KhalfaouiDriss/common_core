/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:48:19 by dkhalfao          #+#    #+#             */
/*   Updated: 2025/09/04 13:48:21 by dkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
    if(!std::getline(std::cin, FirstName))
        return 2;
    std::cout << "Last Name : ";
    if(!std::getline(std::cin, LastName))
        return 2;
    std::cout << "Nick Name : ";
    if(!std::getline(std::cin, NickName))
        return 2;
    std::cout << "Phone Number : ";
    if(!std::getline(std::cin, PhoneNumber))
        return 2;
    std::cout << "Darkest Secret : ";
    if(!std::getline(std::cin, DarkestSecret))
        return 2;
    if(isNumber(PhoneNumber) || FirstName.empty() || LastName.empty() || NickName.empty() || PhoneNumber.empty() || DarkestSecret.empty())
    {
        std::cin.ignore(1000, '\n');
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
        std::cout << "Insert Place : " << i + 1 << std::endl;
        std::cout << "enter the command : ";
        if(!std::getline(std::cin, cmd))
        {
            std::cout << std::endl;
            break;
        }

        else if(cmd == "ADD" || cmd == "A")
        {
            if(!add(PB[i], i))
            {
                i++;
                if(i > 7)
                    i = 0;
            }
            else
            {
                std::cin.ignore(1000, '\n');
                break;
            }
        }
        else if(cmd == "SEARCH" || cmd == "S")
        {
            std::cout << "enter the index : ";
            std::cin >> SearchFor;

            if((SearchFor < 1 || SearchFor > 8))
                std::cout << "Invalid Index" << std::endl;
            else
                PB[SearchFor - 1].Display();
            std::cin.ignore(100, '\n');      
            
        }
        else if(cmd == "EXIT")
            return 0;
        else
            std::cout << "Invalid Command" << std::endl;  
    }
    return 1;
}
