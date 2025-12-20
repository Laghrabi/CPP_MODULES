/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:22:07 by claghrab          #+#    #+#             */
/*   Updated: 2025/12/16 23:52:53 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char *av[])
{
    Harl myHarl;
    std::string input;

    if (ac != 2)
    {
        std::cout << "Wrong Argument." << std::endl;
        return (1);
    }
    input = av[1];
    myHarl.complain(input);
    return (0);
}
