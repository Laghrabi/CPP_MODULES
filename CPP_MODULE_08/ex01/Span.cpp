/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 13:55:27 by claghrab          #+#    #+#             */
/*   Updated: 2026/04/17 09:04:42 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _N(n)
{
    _myVector.reserve(_N);
}

Span::Span(const Span& other)
{
    *this = other;
}

Span&	Span::operator=(const Span& other)
{
    if (this != &other)
	{
		_N = other._N;
		_myVector = other._myVector;
	}
	return (*this);
}

Span::~Span() {}

void	Span::addNumber(int n)
{
	if (_myVector.size() >= _N)
		throw Span::SpanFullException();
	_myVector.push_back(n);
}

unsigned int	Span::longestSpan()
{
	std::vector<int>::iterator max, min;
	
	if (_myVector.size() <= 1)
		throw Span::NoSpanFoundException();
		
	max = std::max_element(_myVector.begin(), _myVector.end());
	min = std::min_element(_myVector.begin(), _myVector.end());
	
	return (*max - *min);
}

unsigned int	Span::shortestSpan()
{
	unsigned int				minSpan;
	std::vector<int>::iterator	it;
	
	if (_myVector.size() <= 1)
		throw Span::NoSpanFoundException();
	
	std::sort(_myVector.begin(), _myVector.end());

	minSpan = UINT_MAX;

	for (it = _myVector.begin(); it != _myVector.end() - 1; ++it)
	{
		if ((*(it + 1) - *it) < minSpan)
			minSpan = (*(it + 1) - *it);
	}
	return (minSpan);
}
