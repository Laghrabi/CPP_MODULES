/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 16:45:04 by claghrab          #+#    #+#             */
/*   Updated: 2026/04/14 17:38:08 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <exception>
#include <vector>

class	NotFound : public std::exception {
	public:
		virtual const char* what() const throw() {
			return ("Error: Value not found in the container.");
		}
};
  
# endif