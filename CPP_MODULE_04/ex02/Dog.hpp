/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 01:17:11 by claghrab          #+#    #+#             */
/*   Updated: 2026/01/06 21:43:52 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"

// Cat Class
class	Dog : public Animal {
	private:
		Brain* _brain;
	public:
		Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		~Dog();

		void	makeSound(void) const;
		const std::string& getIdea(int index) const;
    	void setIdea(int index, const std::string& idea);
};

#endif