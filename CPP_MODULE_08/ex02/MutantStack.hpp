/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 14:21:02 by claghrab          #+#    #+#             */
/*   Updated: 2026/08/15 15:15:10 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK
#define MUTANTSTACK

# include <iostream>
# include <stack>

template <typename T, typename Container = std::deque<T> >
class	MutantStack : public std::stack<T, Container> {
	public:
		MutantStack();
		MutantStack(const MutantStack& other);
		MutantStack&	operator=(const MutantStack& other);
		~MutantStack();
	
		typedef typename Container::iterator iterator;
		typedef typename Container::reverse_iterator reverse_iterator;
		
		iterator				begin();
		iterator				end();
		reverse_iterator		rbegin();
		reverse_iterator		rend();
};

# include "MutantStack.tpp"

#endif