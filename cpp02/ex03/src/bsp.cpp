/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 09:38:41 by mosokina          #+#    #+#             */
/*   Updated: 2025/08/22 22:50:09 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

/*
Binary Space Partitioning:

1. Define a Plane for Each Edge


2. Test the Point:
For edge AB and point P, the cross product is:
(Bx - Ax)(Py - Ay()) - (By() - Ay())(Px - Ax)

3. Check the Sign of cross products: 
Positive: P is on one side ((e.g., all positive or all negative, depending on the vertex ordering))
Negative: P is on the other side
Zero: P is on the line

*/

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float d1 = (b.getX() - a.getX()) * (point.getY() - a.getY()) - (b.getY() - a.getY()) * (point.getX() - a.getX()); //  cross-product for vecAB and vecAP
	float d2 = (c.getX() - b.getX()) * (point.getY() - b.getY()) - (c.getY() - b.getY()) * (point.getX() - b.getX()); //  cross-product  for vecBC and vecBP
	float d3 = (a.getX() - c.getX()) * (point.getY() - c.getY()) - (a.getY() - c.getY()) * (point.getX() - c.getX()); //  cross-product  for vecCA and vecCP

	// The "> 0" or "< 0" depends on the triangle's winding order.
	// Check if the point is on the same side of all three lines
	bool has_neg = (d1 <= 0) || (d2 <= 0) || (d3 <= 0); //  checks if any of the cross-products are negative.
	bool has_pos = (d1 >= 0) || (d2 >= 0) || (d3 >= 0); // checks if any are positive.
	
	// Return true if all signs are the same (including zeros)
	return !(has_neg && has_pos); 
}
