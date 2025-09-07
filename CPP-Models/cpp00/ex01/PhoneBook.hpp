/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:48:54 by dkhalfao          #+#    #+#             */
/*   Updated: 2025/09/06 16:15:58 by dkhalfao         ###   ########.fr       */
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
