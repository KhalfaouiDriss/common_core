/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:19:48 by dkhalfao          #+#    #+#             */
/*   Updated: 2025/09/29 11:19:49 by dkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain(std::string level) {
    if (level == "DEBUG") {
        std::cout << "[ DEBUG ]\n";
        std::cout << "I love having extra bacon for my burger." << std::endl;
    } else if (level == "INFO") {
        std::cout << "[ INFO ]\n";
        std::cout << "Adding extra bacon costs more money." << std::endl;
    } else if (level == "WARNING") {
        std::cout << "[ WARNING ]\n";
        std::cout << "I think I deserve some extra bacon for free." << std::endl;
    } else if (level == "ERROR") {
        std::cout << "[ ERROR ]\n";
        std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
    }
}