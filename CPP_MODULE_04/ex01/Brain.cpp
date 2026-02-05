/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 19:01:56 by claghrab          #+#    #+#             */
/*   Updated: 2026/01/06 21:45:51 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Default Constructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain Copy Constructor called" << std::endl;
	*this = other;
}

Brain::~Brain()
{
    std::cout << "Brain Deconstructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Brain Assignation operator called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            this->_ideas[i] = other._ideas[i];
    }
    return (*this);
}

const std::string&  Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
        return (this->_ideas[index]);
    static const std::string msg = "Wrong Index.";
    return (msg);
}

void    Brain::setIdea(int index, const std::string& idea)
{
    if (index >= 0 && index < 100)
        this->_ideas[index] = idea;
}
