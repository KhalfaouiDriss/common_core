/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalfaoui47 <khalfaoui47@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:48:54 by dkhalfao          #+#    #+#             */
/*   Updated: 2025/09/06 14:37:08 by khalfaoui47      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK
#define PHONEBOOK

#include <iostream>

class PhoneBook
{
    private:
        int id;
        std::string FirstName;
        std::string LastName;
        std::string NickName;
        std::string PhoneNumber;
        std::string DarkestSecret;
    public:
        void Set(int _id, std::string _FirstName, std::string _LastName, 
            std::string _NickName, std::string _PhoneNumber, std::string _DarkestSecret);
        void Display();
};



#endif
