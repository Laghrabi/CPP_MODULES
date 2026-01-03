/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:04:50 by claghrab          #+#    #+#             */
/*   Updated: 2026/01/03 17:12:11 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

// DiamondTrap Class
class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string name;
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &copy);
		DiamondTrap &operator=(const DiamondTrap &src);
		~DiamondTrap();

		void attack(const std::string &target);
		void whoAmI(void);
        void debug();
};

#endif