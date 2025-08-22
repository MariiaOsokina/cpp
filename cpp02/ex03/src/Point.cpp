/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:02:32 by mosokina          #+#    #+#             */
/*   Updated: 2025/08/22 22:50:10 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

Point::Point(): _x(Fixed(0)), _y(Fixed(0))
{};

Point::Point(const float x, const float y): _x(Fixed(x)), _y(Fixed(y))
{};

Point::Point (const Point &other): _x(Fixed(other._x)), _y(Fixed(other._y))
{};

// Point& Point::operator=(const Point &other)
// {
// 	if (this != &other)
// 	{
// 		this->_x = other._x;
// 		this->_y = other._y;
// 	}
// 	return (*this);
// };


// Constructor with float parameters
// Initializes const members _x and _y with the given values
Point::Point(const float x, const float y): _x(Fixed(x)), _y(Fixed(y))
{}

// Copy constructor
// Initializes const members _x and _y with the values from the other object
Point::Point (const Point &other): _x(other._x), _y(other._y)
{}

// Copy assignment operator
// This function cannot modify const members, so it's best to delete it to prevent misuse.
// It is good practice to explicitly delete this operator when it's not possible to implement correctly.
Point& Point::operator=(const Point &other) {
    // A const member variable cannot be reassigned after construction.
    // The copy assignment operator is logically invalid for this class design.
    // The compiler will not allow this assignment anyway, so deleting it is the
    // clearest way to indicate it's not supported.
    // You should remove the function definition from the .cpp file and add `Point& operator=(const Point &other) = delete;`
    // to the class declaration in the header file.
    // However, if you must keep the function, this is the best you can do:
    (void)other; // Cast to void to suppress unused parameter warnings
    return *this;
}
Point::~Point(){};

float	Point::getX(void) const
{
	return (this->_x.toFloat());
};

float	Point::getY(void) const
{
	return (this->_y.toFloat());
};

