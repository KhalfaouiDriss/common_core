/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:19:56 by dkhalfao          #+#    #+#             */
/*   Updated: 2025/09/29 11:19:57 by dkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./harlFilter <level>" << std::endl;
        return 1;
    }

    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;

    while (i < 4 && levels[i] != argv[1])
        i++;

    Harl harl;

    switch (i) {
        case 0:
            harl.complain("DEBUG");
            break;
        case 1:
            harl.complain("INFO");
            break;
        case 2:
            harl.complain("WARNING");
            break;
        case 3:
            harl.complain("ERROR");
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
    return 0;
}