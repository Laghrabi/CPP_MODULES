/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 12:55:05 by claghrab          #+#    #+#             */
/*   Updated: 2025/12/31 14:26:34 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("default"), HitPts(10), EnergyPts(10), AtkDmg(0)
{
	std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), HitPts(10), EnergyPts(10), AtkDmg(0)
{
    std::cout << "ClapTrap Constructor for the name " << name << " called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "ClapTrap Copy Constructor called" << std::endl;
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "ClapTrap Assignation operator called" << std::endl;
    if (this != &other)
    {
        this->name = other.name;
        this->HitPts = other.HitPts;
        this->EnergyPts = other.EnergyPts;
        this->AtkDmg = other.AtkDmg;
    }
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Deconstructor for " << name << " called" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (EnergyPts > 0 && HitPts > 0)
	{
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << AtkDmg << " points of damage!" << std::endl;
		EnergyPts--;
	}
	else if (EnergyPts == 0)
		std::cout << "ClapTrap " << name << " is not able to attack " << target << ", because he has no energy points left." << std::endl;
	else
		std::cout << "ClapTrap " << name << " is not able to attack " << target << ", because he has not enough hit points." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (HitPts > amount)
		HitPts -= amount;
    else if (HitPts > 0)
        HitPts = 0;
	else
	{
        std::cout << "ClapTrap " << name << " is already dead, stop beating it." << std::endl;
		return ;
	}
    std::cout << "ClapTrap " << name << " was attacked and lost " << amount << " hit points, he now has " << HitPts << " hit points." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (EnergyPts > 0 && HitPts > 0)
	{
		HitPts += amount;
		std::cout << "ClapTrap " << name << " repaired itself and gained " << amount << " of hit points, he now has " << HitPts << " hit points." << std::endl;
		EnergyPts--;
	}
	else if (EnergyPts == 0)
		std::cout << "ClapTrap " << name << " is not able to repair itself, because he doesn't have enough energy points." << std::endl;
	else
		std::cout << "ClapTrap " << name << " is not able to repair itself, because he doesn't have enough hit points." << std::endl;
}
