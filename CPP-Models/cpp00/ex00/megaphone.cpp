/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:49:06 by dkhalfao          #+#    #+#             */
/*   Updated: 2025/09/04 13:49:07 by dkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
    int i = 1, j;

    if (ac > 1)
    {
        while (i < ac)
        {
            j = 0;
            while (av[i][j])
            {
                av[i][j] = toupper(av[i][j]);
                j++;
            }
            i++;
        }
        i = 1;
        while (i < ac)
        {
            std::cout << av[i];
            i++;
        }
        std::cout << "\n";
        return 0;
    }
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    return 1;
}