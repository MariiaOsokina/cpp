/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 09:45:20 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/03 12:56:06 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Operator overloading:
operators (like +/-/</= ) are special keywords in C++ and normally work with built-in types (int, float, etc.).
But you can overload them so they also work with the class objects.
To do this, we write a function that redefines each operator that we want to use with our class
*/

#include "../include/Fixed.hpp"
#include <climits>

Fixed::Fixed(): _fixed_point_number(0){}

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
	this->_fixed_point_number = other.getRawBits();
}

Fixed & Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_fixed_point_number = other.getRawBits();
	return (*this);
}

Fixed::~Fixed(){}

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

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	long long temp_value = static_cast<long long>(this->getRawBits()) + other.getRawBits();
	result.setRawBits(result._getCappedValue(temp_value));
	return (result);
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;
	long long temp_value = static_cast<long long>(this->getRawBits()) - other.getRawBits();
	result.setRawBits(result._getCappedValue(temp_value));
	return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	long long temp_value = static_cast<long long>(this->getRawBits()) * other.getRawBits();
	temp_value = temp_value >> _number_of_fractional_bits; // divide the raw product by the scaling factor (256).
	result.setRawBits(result._getCappedValue(temp_value));
	return (result);
};

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;
	if (other.getRawBits() == 0)
	{
		std::cerr << "Error: Division by zero!" << std::endl;
		return Fixed(0);
	}
	long long temp_value = static_cast<long long>(this->getRawBits()) << _number_of_fractional_bits;
	temp_value = temp_value / other.getRawBits();
	result.setRawBits(result._getCappedValue(temp_value));
	return (result);
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
