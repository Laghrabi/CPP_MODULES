/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 18:01:50 by claghrab          #+#    #+#             */
/*   Updated: 2026/01/08 18:17:24 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "Ice Type Constructor" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other)
{
    std::cout << "AMateria Copy Constructor" << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
    std::cout << "Ice Assignation operator called" << std::endl;
    if (this != &other)
        AMateria::operator=(other);
    return (*this);
}

Ice::~Ice()
{
    std::cout << "Ice Destructor" << std::endl;
}

AMateria* Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
