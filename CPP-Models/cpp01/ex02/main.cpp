/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:18:37 by dkhalfao          #+#    #+#             */
/*   Updated: 2025/09/29 11:18:38 by dkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    // Adress : 
    std::string *stringPTR = &str;
    // Referance : 
    std::string &stringREF = str;

    std::cout << "The memory address : \n";
    std::cout << "The memory address of the string variable : " <<  &str << std::endl;
    std::cout << "The memory address held by stringPTR : " << stringPTR << std::endl;
    std::cout << "The memory address held by stringREF : " << &stringREF << std::endl;
    
    std::cout << "The value : \n";
    std::cout << "The value of the string variable : " << str << std::endl;
    std::cout << "The value pointed to by stringPTR : " << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF : " << stringREF << std::endl;
}