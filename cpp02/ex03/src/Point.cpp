/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:02:32 by mosokina          #+#    #+#             */
/*   Updated: 2025/08/26 18:58:05 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

Point::Point(): _x(Fixed(0)), _y(Fixed(0))
{};

Point::Point(const float x, const float y): _x(Fixed(x)), _y(Fixed(y))
{};

Point::Point (const Point &other): _x(other._x), _y(other._y)
{};

// Copy assignment operator
// This function cannot modify const members, so it's best to delete it to prevent misuse.
// It is good practice to explicitly delete this operator when it's not possible to implement correctly.
Point& Point::operator=(const Point &other)
{
	(void)other; // Cast to void to suppress unused parameter warnings
	return *this;
}

Point::~Point(){};

Fixed	Point::getX(void) const
{
	return (this->_x);
};

Fixed	Point::getY(void) const
{
	return (this->_y);
};

