/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:47:34 by claghrab          #+#    #+#             */
/*   Updated: 2026/01/06 21:44:53 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>
#include <string>
#include <new>
#include <cstdlib>

// Brain Class
class	Brain {
	private:
		std::string _ideas[100];
	public:
		Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		~Brain();

		const std::string&	getIdea(int index) const;
    	void				setIdea(int index, const std::string& idea);
};

#endif