/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 00:09:15 by claghrab          #+#    #+#             */
/*   Updated: 2026/03/15 23:44:04 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array {
    private:
        T               *_arr;
        unsigned int    _size;
    public:
        Array();
        Array(unsigned int n);
		Array(Array const &other);
        Array&	operator=(Array const &other);
		~Array();

        T&	        operator[](unsigned int index);
		const T&	operator[](unsigned int index) const;

		unsigned int	size() const;

		class OutOfBounds : public std::exception {
			public:
				virtual const char *what() const throw();
		};
    
};

# include "Array.tpp"

#endif