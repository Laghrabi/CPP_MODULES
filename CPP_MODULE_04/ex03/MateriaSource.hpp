/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 20:46:35 by claghrab          #+#    #+#             */
/*   Updated: 2026/01/08 21:06:08 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

// MateriaSource Class
class   MateriaSource : public IMateriaSource {
    private:
        AMateria* _templates[4];
    public:
        MateriaSource();
        MateriaSource(MateriaSource const & other);
        MateriaSource & operator=(MateriaSource const & other);
        virtual ~MateriaSource();

        void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);
};


#endif