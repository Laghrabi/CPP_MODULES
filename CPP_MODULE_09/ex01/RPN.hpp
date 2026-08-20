/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 19:20:08 by claghrab          #+#    #+#             */
/*   Updated: 2026/08/20 16:45:36 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <list>
#include <string>
#include <stdexcept>

class RPN {
    private:
        std::stack<int, std::list<int> > _operands;
        
        int executeOperation(int a, int b, char op) const;

    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();

        void evaluate(const std::string& expression);
};

#endif