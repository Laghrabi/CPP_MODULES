/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 18:11:12 by claghrab          #+#    #+#             */
/*   Updated: 2026/01/08 18:17:11 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << "Cure Type Constructor" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other)
{
    std::cout << "Cure Copy Constructor" << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
    std::cout << "Cure Assignation operator called" << std::endl;
    if (this != &other)
        AMateria::operator=(other);
    return (*this);
}

Cure::~Cure()
{
    std::cout << "Cure Destructor" << std::endl;
}

AMateria* Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
