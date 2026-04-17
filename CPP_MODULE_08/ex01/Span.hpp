/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 13:33:37 by claghrab          #+#    #+#             */
/*   Updated: 2026/04/16 16:12:54 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <exception>
# include <climits>

// Span Class
class	Span {
	private:
		unsigned int _N;
		std::vector<int> _myVector;
	
	public:
		Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void			addNumber(int n);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		
		class SpanFullException : public std::exception {
			virtual const char* what() const throw() {
				return ("Error: Maximum capacity of Span reached.");
			}
		};
		
		class NoSpanFoundException : public std::exception {
			virtual const char* what() const throw() {
				return ("Error: Not enough elements to find a span.");
			}
		};
};

#endif