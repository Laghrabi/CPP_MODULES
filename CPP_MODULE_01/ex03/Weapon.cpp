/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 14:42:47 by claghrab          #+#    #+#             */
/*   Updated: 2025/12/13 14:48:36 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weapon)
{
	setType(weapon);
}

void	Weapon::setType(std::string input)
{
	type = input;
}

const std::string& Weapon::getType()
{
	return (type);
}
