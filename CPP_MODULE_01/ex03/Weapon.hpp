/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 14:29:19 by claghrab          #+#    #+#             */
/*   Updated: 2025/12/13 14:34:58 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

class Weapon {
    private:
		std::string	type;
	public:
		Weapon(std::string weapon);
		const std::string& getType();
		void setType(std::string input);
};

#endif