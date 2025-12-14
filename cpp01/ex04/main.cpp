/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:46:19 by claghrab          #+#    #+#             */
/*   Updated: 2025/12/13 18:34:44 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

int main(int ac, char **av)
{
    size_t i;
    std::ifstream infile(av[1]);
    std::string s1 = av[2], s2 = av[3];
    std::stringstream buffer;
    std::string content;
    
    if (ac < 4)
    {
        std::cerr << "Wrong Arguments" << std::endl;
        return (1);
    }
    if (infile.is_open() == false)
    {
        std::cerr << "Error: Could not open input file." << std::endl;
        return (1);
    }
    else
    {
        i = 0;
        buffer << infile.rdbuf();
        content = buffer.str();
        while (content.find(s1, i) != std::string::npos)
        {
            
        }
    }
}