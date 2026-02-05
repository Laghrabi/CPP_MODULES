/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 01:08:44 by claghrab          #+#    #+#             */
/*   Updated: 2026/01/06 21:43:44 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal()
{
	std::cout << "Cat Default Constructor called" << std::endl;
    _type = "Cat";
    _brain = new(std::nothrow) Brain;
    if (_brain == NULL)
    {
		std::cerr << "Cat Brain allocation failed" << std::endl;
		exit(1);
    }
}

Cat::Cat(const Cat &other): Animal(other)
{
	std::cout << "Cat Copy Constructor called" << std::endl;
    this->_brain = NULL;
	*this = other;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat Assignation operator called" << std::endl;
    if (this != &other)
    {
        this->_type = other._type;
        delete _brain;
        _brain = new(std::nothrow) Brain;
        if (_brain == NULL)
        {
		    std::cerr << "Cat Brain allocation failed" << std::endl;
		    exit(1);
        }
        *_brain = *other._brain;
    }
    return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat Deconstructor called" << std::endl;
    delete _brain;
}

void    Cat::makeSound(void) const
{
    std::cout << this->getType() << " sound is: [Meeoow]" << std::endl;
}

const std::string& Cat::getIdea(int index) const
{
    return (_brain->getIdea(index));
}

void    Cat::setIdea(int index, const std::string& idea)
{
    _brain->setIdea(index, idea);
}
