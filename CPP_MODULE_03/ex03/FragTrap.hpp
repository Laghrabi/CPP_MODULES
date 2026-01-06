/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 20:20:43 by claghrab          #+#    #+#             */
/*   Updated: 2026/01/06 16:23:45 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include <iostream>
#include "ClapTrap.hpp"

// FragTrap Class
class   FragTrap : virtual public ClapTrap {
        public:
            FragTrap();
		    FragTrap(const FragTrap &other);
		    FragTrap(std::string name);
            FragTrap &operator=(const FragTrap &other);
            ~FragTrap();

            void highFivesGuys(void);
};

#endif