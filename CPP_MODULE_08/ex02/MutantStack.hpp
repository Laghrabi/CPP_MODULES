/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 14:21:02 by claghrab          #+#    #+#             */
/*   Updated: 2026/04/18 15:48:12 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK
#define MUTANTSTACK

# include <iostream>
# include <stack>

// MutantStack Class
template <typename T, typename Container = std::deque<T> >
class	MutantStack : public std::stack<T, Container> {
	public:
		MutantStack();
		MutantStack(const MutantStack& other);
		MutantStack&	operator=(const MutantStack& other);
		~MutantStack();
	
		typedef typename Container::iterator iterator;
		
		typename Container::iterator begin();
		typename Container::iterator end();
};

# include "MutantStack.tpp"

#endif