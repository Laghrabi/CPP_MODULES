/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 19:23:43 by claghrab          #+#    #+#             */
/*   Updated: 2026/08/19 19:44:03 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) {
    this->_operands = other._operands;
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        this->_operands = other._operands;
    }
    return *this;
}

RPN::~RPN() {}

int RPN::executeOperation(int a, int b, char op) const {
    if (op == '+') return (a + b);
    if (op == '-') return (a - b);
    if (op == '*') return (a * b);
    if (op == '/') {
        if (b == 0)
            throw std::runtime_error("Error");
        return (a / b);
    }
    throw std::runtime_error("Error");
}

void RPN::evaluate(const std::string& expression) {
    try {
        for (size_t i = 0; i < expression.length(); ++i) {
            char c = expression[i];

            if (c == ' ') {
                continue;
            }
            else if (std::isdigit(c)) {
                _operands.push(c - '0');
            } 
            else if (c == '+' || c == '-' || c == '*' || c == '/') {
                if (_operands.size() < 2) {
                    throw std::runtime_error("Error");
                }
                
                int b = _operands.top();
                _operands.pop();
                int a = _operands.top();
                _operands.pop();
                int result = executeOperation(a, b, c);
                _operands.push(result);
            }
            else {
                throw std::runtime_error("Error");
            }
        }

        if (_operands.size() != 1)
            throw std::runtime_error("Error");

        std::cout << _operands.top() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}
