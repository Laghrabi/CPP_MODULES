/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:29:03 by claghrab          #+#    #+#             */
/*   Updated: 2025/12/13 15:54:06 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

#include <iostream>
#include "Weapon.hpp"

class HumanB {
    private:
        Weapon      *weapon;
        std::string name;
    public:
        HumanB(std::string name);
        void setWeapon(Weapon &weapon);
        void attack();
};

#endif