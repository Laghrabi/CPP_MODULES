/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 13:25:11 by claghrab          #+#    #+#             */
/*   Updated: 2026/01/01 18:10:34 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed {
		private:
			int					_fixedPointValue;
			static const int	_fractionalBits;
		public:
			Fixed();
            Fixed(const int value);
            Fixed(const float value);
			Fixed(const Fixed& other);
			Fixed& operator=(const Fixed& other);
			~Fixed();

			int		getRawBits( void ) const;
			void	setRawBits( int const raw );
            float   toFloat(void) const;
            int     toInt(void) const;

			bool operator>(const Fixed& fixed) const;
			bool operator<(const Fixed& fixed) const;
			bool operator>=(const Fixed& fixed) const;
			bool operator<=(const Fixed& fixed) const;
			bool operator==(const Fixed& fixed) const;
			bool operator!=(const Fixed& fixed) const;

			Fixed operator+(const Fixed& fixed) const;
			Fixed operator-(const Fixed& fixed) const;
			Fixed operator*(const Fixed& fixed) const;
			Fixed operator/(const Fixed& fixed) const;

			Fixed & operator++( void );
			Fixed & operator--( void );
			Fixed operator++( int );
			Fixed operator--( int );

			static Fixed& min(Fixed& a, Fixed& b);
			static Fixed& max(Fixed& a, Fixed& b);
			static const Fixed& min(const Fixed& a, const Fixed& b);
			static const Fixed& max(const Fixed& a, const Fixed& b);
        };
		
std::ostream& operator<<(std::ostream& o, Fixed const & Fixed);

#endif