/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 15:55:16 by claghrab          #+#    #+#             */
/*   Updated: 2025/12/31 16:15:42 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << "ScavTrap Default Constructor called" << std::endl;
	HitPts = 100;
	EnergyPts = 50;
	AtkDmg = 20;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << "ScavTrap Constructor for the name " << name << " called" << std::endl;
	HitPts = 100;
	EnergyPts = 50;
	AtkDmg = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other)
{
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "ScavTrap Copy Assignment Operator called" << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Deconstructor for " << name << " called" << std::endl;
}

void    ScavTrap::attack(const std::string& target)
{
	if (EnergyPts > 0 && HitPts > 0)
	{
		std::cout << "ScarvTrap " << name << " attacks " << target << ", causing " << AtkDmg << " points of damage!" << std::endl;
		EnergyPts--;
	}
	else if (EnergyPts == 0)
		std::cout << "ScavTrap " << name << " is not able to attack " << target << ", because he has no energy points left." << std::endl;
	else
		std::cout << "ScavTrap " << name << " is not able to attack " << target << ", because he has not enough hit points." << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}
