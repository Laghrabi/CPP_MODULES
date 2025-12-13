/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:25:52 by claghrab          #+#    #+#             */
/*   Updated: 2025/12/12 17:25:51 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void    Zombie::announce()
{
    std::cout << name << ": "
              << " BraiiiiiiinnnzzzZ..."
              << std::endl;
}

Zombie::Zombie()
{
    std::cout << "A zombie is born" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << this->name << " is destroyed" << std::endl;
}


void    Zombie::setname(std::string str)
{
    name = str;
}
