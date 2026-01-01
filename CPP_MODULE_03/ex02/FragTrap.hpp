/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 20:20:43 by claghrab          #+#    #+#             */
/*   Updated: 2025/12/31 20:43:25 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include <iostream>
#include "ClapTrap.hpp"

// FragTrap Class
class   FragTrap : public ClapTrap {
        public:
            FragTrap();
		    FragTrap(const FragTrap &copy);
		    FragTrap(std::string name);
            FragTrap &operator=(const FragTrap &src);
            ~FragTrap();

            void highFivesGuys(void);
};

#endif