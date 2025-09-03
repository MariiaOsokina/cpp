/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 09:45:20 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/03 12:15:39 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* _fixed_point_number is integer scaled by a power of 2;
That scaling factor is 2^_number_of_fractional_bits, in this case, 256 (2^8 ).

real value=_fixed_point_number​/256

for example,

If number = 5.25:
_fixed_point_number = int(5.25 * 256);
_fixed_point_number = int(1344.0);
_fixed_point_number = 1344;
So, real value=1344/256​=5.25
*/

#include "../include/Fixed.hpp"
#include <climits>

Fixed::Fixed(): _fixed_point_number(0)
{
	std::cout << "Default constructor called" << std::endl;
}



Fixed::Fixed(const int number)
{
	long long temp_value = static_cast<long long>(number)
		<< _number_of_fractional_bits;
	_fixed_point_number = _getCappedValue(temp_value);
}

Fixed::Fixed(const float number)
{
	float temp_value = number *
		(1 << _number_of_fractional_bits); //bitwise can be only with int
	_fixed_point_number = _getCappedValue(temp_value);
}

int Fixed::_getCappedValue(long long value)
{
	if (value > INT_MAX)
	{
		std::cerr << "Overflow! Capping value at INT_MAX." << std::endl;
		return (INT_MAX);		
	}
	else if (value < INT_MIN)
		return (INT_MIN);
	else
		return (static_cast<int>(value));
}

int Fixed::_getCappedValue(float value)
{
	if (value > static_cast<float>(INT_MAX))
	{
		std::cerr << "Overflow! Capping value at INT_MAX." << std::endl;
		return (INT_MAX);
	}
	else if (value < static_cast<float>(INT_MIN))
		return (INT_MIN);
	else
		return static_cast<int>(roundf(value));
}

Fixed::Fixed (const Fixed &other)
{
	std::cout << "Copy constructor called" <<std::endl;
	this->_fixed_point_number = other.getRawBits();
};

Fixed & Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" <<std::endl;
	if (this != &other)
		this->_fixed_point_number = other.getRawBits();
	return (*this);
};

Fixed::~Fixed()
{
	std::cout << "Destructor called" <<std::endl;
};

int	Fixed::getRawBits( void ) const
{
	return (_fixed_point_number);
};

void	Fixed::setRawBits( int const raw )
{
	this->_fixed_point_number = raw;
};

float Fixed::toFloat(void) const
{
	float float_value;

	float_value = static_cast <float> (_fixed_point_number) /
		(1 << _number_of_fractional_bits);
	return (float_value);
};

int Fixed::toInt(void) const
{
	int	int_value = _fixed_point_number >> _number_of_fractional_bits;
	return (int_value);
};

/*
Operator overloading:
operators (like +/-/</= ) are special keywords in C++ and normally work with built-in types (int, float, etc.).
But you can overload them so they also work with the class objects.
To do this, we write a function that redefines each operator that we want to use with our class
*/

std::ostream& operator<<(std::ostream& os, Fixed const& fixed)
{
	os << fixed.toFloat();
	return (os);
}
