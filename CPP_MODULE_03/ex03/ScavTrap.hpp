/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 14:33:40 by claghrab          #+#    #+#             */
/*   Updated: 2026/01/06 16:15:25 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include <iostream>
#include "ClapTrap.hpp"

// ScavTrap Class
class	ScavTrap : virtual public ClapTrap {
		public:
			ScavTrap();
			ScavTrap(std::string name);
        	ScavTrap(const ScavTrap& other);
        	ScavTrap& operator= (const ScavTrap& other);
        	~ScavTrap ( void );

        	void attack( const std::string& target );
        	void guardGate( void );
};

#endif