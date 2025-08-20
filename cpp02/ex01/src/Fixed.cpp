/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 09:45:20 by mosokina          #+#    #+#             */
/*   Updated: 2025/08/20 12:23:43 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Copy constructor: needed when an object is first (!) created as a copy of another.
Copy assignment operator: needed when an object already (!) exists and you want to copy into it.
*/

/*
Operator overloading:
operators (like +/-/</= ) are special keywords in C++ and normally work with built-in types (int, float, etc.).
But you can overload them so they also work with the class objects.
To do this, we write a function that redefines each operator that we want to use with our class
*/

/*
_fixed_point_number is integer scaled by a power of 2;
That scaling factor is 2^_number_of_fractional_bits.
scaling factor = 256 because _number_of_fractional_bits = 8

real value=_fixed_point_number​/256

for example,

If number = 5.25:
_fixed_point_number = int(5.25 * 256);
_fixed_point_number = int(1344.0);
_fixed_point_number = 1344;
So, real value=1344/256​=5.25
*/

#include "../include/Fixed.hpp"

Fixed::Fixed(): _fixed_point_number(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number)
{
	_fixed_point_number = number << _number_of_fractional_bits;
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float number)
{
	_fixed_point_number = static_cast<int>(roundf(number * (1 << _number_of_fractional_bits))); // bitwise operators only work with integers
	std::cout << "Float constructor called" << std::endl;
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

int     Fixed::getRawBits( void ) const
{
	return (_fixed_point_number);
};

void    Fixed::setRawBits( int const raw )
{
	this->_fixed_point_number = raw;
};

float Fixed::toFloat(void) const
{
	float float_value;

	float_value = static_cast <float> (_fixed_point_number) / (1 << _number_of_fractional_bits);
	return (float_value);
};


int Fixed::toInt(void) const
{
	int	int_value;

	int_value = _fixed_point_number >> _number_of_fractional_bits;
	return (int_value);
};

std::ostream& operator<<(std::ostream& os, Fixed const& fixed)
{
	os << fixed.toFloat();
	return (os);
}

