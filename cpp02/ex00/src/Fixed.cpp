/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 09:45:20 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/03 00:20:51 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Ortodax Canonical Form for clases:
new - Copy constructor: needed when an object is first (!) created as a copy of another.
new - Copy assignment operator: needed when an object already (!) exists and you want to copy into it.
*/

#include "../include/Fixed.hpp"

Fixed::Fixed(): _fixed_point_number(0)
{
    std::cout << "Default constructor called" << std::endl;
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
	std::cout << "getRawBits member function called" <<std::endl;
	return (_fixed_point_number);
};

void    Fixed::setRawBits( int const raw )
{
	this->_fixed_point_number = raw;
};
