/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 09:45:20 by mosokina          #+#    #+#             */
/*   Updated: 2025/08/22 10:03:01 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed(): _fixed_point_number(0){};

Fixed::Fixed(const int number)
{
	_fixed_point_number = number << _number_of_fractional_bits;
}

Fixed::Fixed(const float number)
{
	_fixed_point_number = static_cast<int>(roundf(number * (1 << _number_of_fractional_bits))); // bitwise operators only work with integers
}

Fixed::Fixed (const Fixed &other)
{
	this->_fixed_point_number = other.getRawBits();
};

Fixed& Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_fixed_point_number = other.getRawBits();
	return (*this);
};

Fixed::~Fixed(){};

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

bool Fixed::operator>(const Fixed &other) const
{
	return (this->_fixed_point_number > other._fixed_point_number);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->_fixed_point_number < other._fixed_point_number);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->_fixed_point_number >= other._fixed_point_number);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->_fixed_point_number <= other._fixed_point_number);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->_fixed_point_number == other._fixed_point_number);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->_fixed_point_number != other._fixed_point_number);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	float	float_value;

	float_value = this->toFloat() + other.toFloat();
	return (Fixed(float_value));
};

Fixed Fixed::operator-(const Fixed &other) const
{
	float	float_value;

	float_value = this->toFloat() - other.toFloat();
	return (Fixed(float_value));
};

Fixed Fixed::operator*(const Fixed &other) const
{	float	float_value;

	float_value = this->toFloat() * other.toFloat();
	return (Fixed(float_value));
};

Fixed Fixed::operator/(const Fixed &other) const
{
	float	float_value;

	float_value = this->toFloat() / other.toFloat();
	return (Fixed(float_value));
};

/* these operators increase/ decrease the fixed-point value by
the smallest representable step, i.e. ϵ = 1/256.*/

/*++a --a (pre): increment the object then return new value (by reference).
a++ a-- (post): return old value (by copy), then increment the object. */

Fixed &Fixed::operator++(void) 
{
	_fixed_point_number += 1;
	return (*this);
}; 

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_fixed_point_number += 1;
	return (tmp);
}

Fixed &Fixed::operator--(void) 
{
	_fixed_point_number -= 1;
	return (*this);
}; 

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_fixed_point_number -= 1;
	return (tmp);
}

/*
Function overloading = same function name, different parameter lists.
Non-const version: works on normal objects, can be modified through the returned reference.
Const version: works on const objects, returned reference cannot be modified.
This is overloading based on const-ness of parameters and return type.
*/

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (b < a)
		return (b);
	return (a);
};

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (b < a)
		return (b);
	return (a);
};

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (b > a)
		return (b);
	return (a);
};

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (b > a)
		return (b);
	return (a);
};

std::ostream& operator<<(std::ostream& os, Fixed const& fixed)
{
	os << fixed.toFloat();
	return (os);
}
