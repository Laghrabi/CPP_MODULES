/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 01:19:04 by claghrab          #+#    #+#             */
/*   Updated: 2026/01/06 21:43:54 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal()
{
	std::cout << "Dog Default Constructor called" << std::endl;
    _type = "Dog";
    _brain = new(std::nothrow) Brain;
    if (_brain == NULL)
    {
		std::cerr << "Dog Brain allocation failed" << std::endl;
		exit(1);
    }
}

Dog::Dog(const Dog &other): Animal(other)
{
	std::cout << "Dog Copy Constructor called" << std::endl;
    this->_brain = NULL;
	*this = other;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog Assignation operator called" << std::endl;
    if (this != &other)
    {
        this->_type = other._type;
        delete _brain;
        _brain = new(std::nothrow) Brain;
        if (_brain == NULL)
        {
		    std::cerr << "Dog Brain allocation failed" << std::endl;
		    exit(1);
        }
        *_brain = *other._brain;
    }
    return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog Deconstructor called" << std::endl;
    delete _brain;
}

void    Dog::makeSound(void) const
{
    std::cout << this->getType() << " sound is: [Woof]" << std::endl;
}

const std::string& Dog::getIdea(int index) const
{
    return (_brain->getIdea(index));
}

void Dog::setIdea(int index, const std::string& idea)
{
    _brain->setIdea(index, idea);
}
