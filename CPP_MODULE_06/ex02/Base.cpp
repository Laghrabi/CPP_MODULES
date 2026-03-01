/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 16:21:48 by claghrab          #+#    #+#             */
/*   Updated: 2026/03/01 17:22:06 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base* generate(void)
{
    int     choice;
    Base*   ptr;

    choice = std::rand() % 3;
    
    if (choice == 0)
        ptr = new A();
    else if (choice == 1)
        ptr = new B();
    else
        ptr = new C();
    return (ptr);
}

void    identify(Base* p)
{
    A*  testA = dynamic_cast<A*>(p);
    if (testA != NULL) {
        std::cout << "A" << std::endl;
        return ;
    }
    
    B*  testB = dynamic_cast<B*>(p);
    if (testB != NULL) {
        std::cout << "B" << std::endl;
        return ;
    }
    
    C*  testC = dynamic_cast<C*>(p);
    if (testC != NULL) {
        std::cout << "C" << std::endl;
        return ;
    }
}

void identify(Base& p)
{
    try {
        dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return ;
    } catch (std::exception& e) {}
    
    try {
        dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return ;
    } catch (std::exception& e) {}
    
    try {
        dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return ;
    } catch (std::exception& e) {}
}
