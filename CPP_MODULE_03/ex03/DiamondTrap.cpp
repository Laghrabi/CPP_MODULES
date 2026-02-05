/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:14:42 by claghrab          #+#    #+#             */
/*   Updated: 2026/01/04 14:51:10 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_trap")
{
    std::cout << "DiamondTrap Default Constructor called" << std::endl;
    this->name = "default";
    this->HitPts = 100;
    this->EnergyPts = 50;
    this->AtkDmg = 30;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_trap"), ScavTrap(name), FragTrap(name)
{
    std::cout << "DiamondTrap Constructor for the name " << name << " called" << std::endl;
    this->name = name;
    this->HitPts = 100;
    this->EnergyPts = 50;
    this->AtkDmg = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other): ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	std::cout << "DiamondTrap Copy Constructor called" << std::endl;
	*this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    std::cout << "DiamondTrap Assignation operator called" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
        this->name = other.name;
    }
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Deconstructor for " << name << " called" << std::endl;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "Hello i am a DiamondTrap named " << name
    << " and i am originated from the ClapTrap named "
    << ClapTrap::name << "."
    << std::endl;
}
