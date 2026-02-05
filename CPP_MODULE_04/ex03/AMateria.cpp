/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:36:30 by claghrab          #+#    #+#             */
/*   Updated: 2026/01/08 22:04:04 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type)
{
    std::cout << "AMateria Type Constructor" << std::endl;
}

AMateria::AMateria(const AMateria& other)
{
    std::cout << "AMateria Copy Constructor" << std::endl;
    *this = other;
}

AMateria&   AMateria::operator=(const AMateria& other)
{
    std::cout << "AMateria Assignation operator called" << std::endl;
    if (this != &other)
        _type = other._type;
    return (*this);
}

AMateria::~AMateria()
{
    std::cout << "AMateria Destructor" << std::endl;
}

std::string const & AMateria::getType() const
{
    return (_type);
}

void    AMateria::use(ICharacter& target)
{
    (void)target;
}
