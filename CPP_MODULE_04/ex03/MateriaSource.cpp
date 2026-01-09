/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 21:07:33 by claghrab          #+#    #+#             */
/*   Updated: 2026/01/08 21:35:49 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource Default Constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        _templates[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & other)
{
    std::cout << "MateriaSource Copy Constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (other._templates[i])
            _templates[i] = other._templates[i]->clone();
        else
            _templates[i] = NULL;
    }
}

MateriaSource & MateriaSource::operator=(MateriaSource const & other)
{
    std::cout << "MateriaSource Copy Assignment Operator called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (_templates[i])
                delete _templates[i];
            _templates[i] = NULL;
        }
        for (int i = 0; i < 4; i++)
        {
            if (other._templates[i])
                _templates[i] = other._templates[i]->clone();
            else
                _templates[i] = NULL;
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource Destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (_templates[i])
            delete _templates[i];
    }
}

void    MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return ;
    for (int i = 0; i < 4; i++)
    {
        if (_templates[i] == NULL)
        {
            _templates[i] = m;
            return ;
        }
    }
    delete m;
    std::cout << "MateriaSource memory is full!" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_templates[i] && _templates[i]->getType() == type)
            return (_templates[i]->clone());
    }
    return (NULL);
}
