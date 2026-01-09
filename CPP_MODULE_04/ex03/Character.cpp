/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 18:44:50 by claghrab          #+#    #+#             */
/*   Updated: 2026/01/08 20:42:32 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
    std::cout << "Character default constructor called" << std::endl;
    _name = "default";
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

Character::Character(std::string const & name)
{
    _name = name;
    std::cout << "Character " << _name << " created" << std::endl;
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}


Character::Character(Character const & other)
{
    std::cout << "Character Copy Constructor called" << std::endl;
    _name = other._name;
    for (int i = 0; i < 4; i++)
    {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
}

Character& Character::operator=(Character const & other)
{
    std::cout << "Character Assignation operator called" << std::endl;
    if (this != &other)
    {
        _name = other._name;
        for (int i = 0; i < 4; i++)
        {
            if (_inventory[i])
                delete _inventory[i];
            _inventory[i] = NULL;
        }
        for (int i = 0; i < 4; i++)
        {
            if (other._inventory[i])
                _inventory[i] = other._inventory[i]->clone();
            else
                _inventory[i] = NULL;
        }
    }
    return (*this);
}

Character::~Character()
{
    std::cout << "Character " << _name << " destroyed" << std::endl;
     for (int i = 0; i < 4; i++)
        {
            if (_inventory[i])
                delete _inventory[i];
        }
}

std::string const & Character::getName() const
{
    return (_name);
}

void    Character::equip(AMateria* m)
{
    if (!m)
        return ;
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i] == NULL)
        {
            _inventory[i] = m;
            return ;
        }
    }
}

void    Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && _inventory[idx] != NULL)
        _inventory[idx]->use(target);
}

void    Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && _inventory[idx] != NULL)
        _inventory[idx] = NULL;
}

