/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 12:28:20 by claghrab          #+#    #+#             */
/*   Updated: 2026/01/03 15:35:01 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

// ClapTrap Class
class	ClapTrap {
		protected:
			std::string	name;
			unsigned int			HitPts;
			unsigned int			EnergyPts;
			unsigned int			AtkDmg;
		public:
			ClapTrap();
			ClapTrap(std::string name);
			ClapTrap(const ClapTrap& other);
			ClapTrap& operator=(const ClapTrap& other);
			virtual ~ClapTrap();
			
			void attack(const std::string& target);
        	void takeDamage(unsigned int amount);
        	void beRepaired(unsigned int amount);
};

#endif