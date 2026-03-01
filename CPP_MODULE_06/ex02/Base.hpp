/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 16:15:09 by claghrab          #+#    #+#             */
/*   Updated: 2026/03/01 17:11:50 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <exception>
#include <iostream>
#include <cstdlib>
#include <ctime>

// Base CLass
class Base {
    public:
        virtual ~Base();
};

Base*   generate(void);
void    identify(Base* p);
void    identify(Base& p);

#endif