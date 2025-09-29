/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:19:20 by dkhalfao          #+#    #+#             */
/*   Updated: 2025/09/29 11:19:21 by dkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string replace(std::string content, const std::string &s1, const std::string &s2)
{
    size_t pos = 0;
    if (s1.empty() || s1 == s2)
        return content;
    while ((pos = content.find(s1, pos)) != std::string::npos)
    {
        content.erase(pos, s1.length());
        content.insert(pos, s2);
        pos += s2.length();
    }
    return content;
}

bool getContent(const char *file, std::string &content)
{
    std::ifstream infile(file);
    if (!infile.is_open())
        return false;

    std::string line;
    content.clear();
    while (std::getline(infile, line))
    {
        content.append(line);
        content.append("\n");
    }
    return true;
}

int main(int ac, char **av)
{
    if (ac != 4)
        return 1;

    std::string content;
    if (!getContent(av[1], content))
    {
        std::cerr << "Cannot open file\n";
        return 1;
    }

    std::string newStr = replace(content, av[2], av[3]);
    std::string newFile = std::string(av[1]) + ".replace";

    std::ofstream outfile(newFile.c_str());
    if (!outfile.is_open())
        return 1;

    outfile << newStr;
}

