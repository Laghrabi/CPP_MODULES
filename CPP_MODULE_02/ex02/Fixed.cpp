/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 13:37:34 by claghrab          #+#    #+#             */
/*   Updated: 2025/12/29 18:34:41 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

/**
 * @brief Default constructor.
 * * Initializes the fixed-point number value to 0.
 */
Fixed::Fixed()
{
    _fixedPointValue = 0;
}

/**
 * @brief Copy constructor.
 * * Creates a new Fixed object as a copy of an existing one.
 * * @param other The Fixed object to copy.
 */
Fixed::Fixed(const Fixed& other)
{
    *this = other;
}

/**
 * @brief Integer constructor.
 * * Converts a constant integer to a fixed-point value.
 * It shifts the integer bits to the left by the number of fractional bits (8).
 * * @param value The integer value to convert.
 */
Fixed::Fixed(const int value)
{
	_fixedPointValue = value << _fractionalBits;
}

/**
 * @brief Floating-point constructor.
 * * Converts a constant float to a fixed-point value.
 * It multiplies the float by (1 << fractional_bits) and rounds the result
 * to the nearest integer to preserve accuracy.
 * * @param value The float value to convert.
 */
Fixed::Fixed(const float value)
{
	_fixedPointValue = roundf(value * (1 << _fractionalBits));
}

/**
 * @brief Copy assignment operator.
 * * Assigns the value of one Fixed object to another.
 * * @param other The source Fixed object.
 * @return Fixed& A reference to the current object.
 */
Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        this->_fixedPointValue = other.getRawBits();
    return (*this);
}

/**
 * @brief Destructor.
 * * Destroys the Fixed object.
 */
Fixed::~Fixed() {}

/**
 * @brief Gets the raw fixed-point value.
 * * @return int The raw value of the fixed-point number.
 */
int Fixed::getRawBits(void) const
{
    return (this->_fixedPointValue);
}

/**
 * @brief Sets the raw fixed-point value.
 * * @param raw The raw integer value to set.
 */
void Fixed::setRawBits(int const raw)
{
    this->_fixedPointValue = raw;
}

/**
 * @brief Converts the fixed-point value to an integer.
 * * Shifts the bits to the right to discard the fractional part.
 * * @return int The integer representation of the fixed-point number.
 */
int	Fixed::toInt(void) const
{
	return (_fixedPointValue >> _fractionalBits);
}

/**
 * @brief Converts the fixed-point value to a floating-point number.
 * * Divides the raw value by (1 << fractional_bits) to retrieve the decimal part.
 * * @return float The floating-point representation.
 */
float	Fixed::toFloat(void) const
{
	return ((float)_fixedPointValue / (float)(1 << _fractionalBits));
}

/**
 * @brief Output stream operator overload.
 * * Inserts the floating-point representation of the Fixed object into the output stream.
 * * @param o The output stream.
 * @param Fixed The Fixed object to print.
 * @return std::ostream& The output stream.
 */
std::ostream & operator<<(std::ostream & o, Fixed const & Fixed)
{
    o << Fixed.toFloat();
    return o;
}

/**
 * @brief Greater than operator.
 * @return true if this object is greater than the other.
 */
bool Fixed::operator>(const Fixed& fixed) const
{
    return (this->getRawBits() > fixed.getRawBits());
}

/**
 * @brief Less than operator.
 * @return true if this object is less than the other.
 */
bool Fixed::operator<(const Fixed& fixed) const
{
    return (this->getRawBits() < fixed.getRawBits());
}

/**
 * @brief Greater than or equal to operator.
 * @return true if this object is greater than or equal to the other.
 */
bool Fixed::operator>=(const Fixed& fixed) const
{
    return (this->getRawBits() >= fixed.getRawBits());
}

/**
 * @brief Less than or equal to operator.
 * @return true if this object is less than or equal to the other.
 */
bool Fixed::operator<=(const Fixed& fixed) const
{
    return (this->getRawBits() <= fixed.getRawBits());
}

/**
 * @brief Equality operator.
 * @return true if the two objects have identical raw values.
 */
bool Fixed::operator==(const Fixed& fixed) const
{
    return (this->getRawBits() == fixed.getRawBits());
}

/**
 * @brief Inequality operator.
 * @return true if the two objects have different raw values.
 */
bool Fixed::operator!=(const Fixed& fixed) const
{
    return (this->getRawBits() != fixed.getRawBits());
}

/**
 * @brief Addition operator.
 * @return A new Fixed object containing the sum.
 */
Fixed Fixed::operator+(const Fixed& fixed) const
{
    Fixed _new;
    
    _new.setRawBits(this->getRawBits() + fixed.getRawBits());
    return (_new);
}

/**
 * @brief Subtraction operator.
 * @return A new Fixed object containing the difference.
 */
Fixed Fixed::operator-(const Fixed& fixed) const
{
    Fixed _new;
    
    _new.setRawBits(this->getRawBits() - fixed.getRawBits());
    return (_new);
}

/**
 * @brief Multiplication operator.
 * * Multiplies the raw values as long long to prevent overflow, 
 * then shifts right to return to the correct fixed-point scale.
 * * @return A new Fixed object containing the product.
 */
Fixed Fixed::operator*(const Fixed& fixed) const
{
    Fixed _new;
    
    _new.setRawBits((long long)(this->getRawBits() * fixed.getRawBits()) >> _fractionalBits);
    return (_new);
}

/**
 * @brief Division operator.
 * * Shifts the dividend left first to preserve precision, then divides.
 * * @return A new Fixed object containing the quotient.
 */
Fixed Fixed::operator/(const Fixed& fixed) const
{
    Fixed _new;
    
    _new.setRawBits((long long)((this->getRawBits()  << _fractionalBits) / fixed.getRawBits()));
    return (_new);
}

/**
 * @brief Pre-increment operator (++i).
 * * Increases the raw value by 1 (which is epsilon in fixed-point).
 * * @return Fixed& Reference to the modified object.
 */
Fixed& Fixed::operator++(void)
{
    _fixedPointValue++;
    return (*this);
}

/**
 * @brief Pre-decrement operator (--i).
 * * Decreases the raw value by 1.
 * * @return Fixed& Reference to the modified object.
 */
Fixed& Fixed::operator--(void)
{
    _fixedPointValue--;
    return (*this);
}

/**
 * @brief Post-increment operator (i++).
 * * Creates a copy of the current state, increments the actual object,
 * and returns the copy.
 * * @param int Unused parameter to differentiate from pre-increment.
 * @return Fixed The value of the object before incrementing.
 */
Fixed Fixed::operator++(int)
{
    Fixed   _old = *this;
    
    _fixedPointValue++;
    return (_old);
}

/**
 * @brief Post-decrement operator (i--).
 * * Creates a copy of the current state, decrements the actual object,
 * and returns the copy.
 * * @param int Unused parameter to differentiate from pre-decrement.
 * @return Fixed The value of the object before decrementing.
 */
Fixed Fixed::operator--(int)
{
    Fixed   _old = *this;
    
    _fixedPointValue--;
    return (_old);
}

/**
 * @brief Static min function (non-const).
 * * @param a First Fixed number.
 * @param b Second Fixed number.
 * @return Fixed& Reference to the smaller number.
 */
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)
        return (a);
    return (b);
}

/**
 * @brief Static max function (non-const).
 * * @param a First Fixed number.
 * @param b Second Fixed number.
 * @return Fixed& Reference to the larger number.
 */
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
        return (a);
    return (b);
}

/**
 * @brief Static min function (const).
 * * @param a First Fixed number.
 * @param b Second Fixed number.
 * @return const Fixed& Reference to the smaller number.
 */
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a < b)
        return (a);
    return (b);
}

/**
 * @brief Static max function (const).
 * * @param a First Fixed number.
 * @param b Second Fixed number.
 * @return const Fixed& Reference to the larger number.
 */
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a > b)
        return (a);
    return (b);
}
