/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:02:05 by mosokina          #+#    #+#             */
/*   Updated: 2025/08/22 22:49:21 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &other);
		Point &operator = (const Point &other);

		~Point();

		float	getX(void) const;
		float	getY(void) const;
	private:
        Fixed const _x;
        Fixed const _y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
