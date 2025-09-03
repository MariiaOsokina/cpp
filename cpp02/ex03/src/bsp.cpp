/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 09:38:41 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/03 13:03:39 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

/*Binary Space Partitioning:
The BSP algorithm for a triangle works by checking if a point is on the same side of all three
edges. The side of a line is determined by the sign of the cross product of two vectors.

1. Define a Plane for Each Edge

2. Test the Point:
For edge AB and point P, the cross product is:
(Bx - Ax)(Py - Ay) - (By - Ay)(Px - Ax)

3. Check the Sign of cross products: 
If all three cross products have the same sign (either all positive or all negative,
depending on the vertex ordering), the point is inside the triangle.
If any cross product is zero, the point is on an edge.
*/

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed d1 = (b.getX() - a.getX()) * (point.getY() - a.getY())
		- (b.getY() - a.getY()) * (point.getX() - a.getX()); // for vecAB and vecAP
	Fixed d2 = (c.getX() - b.getX()) * (point.getY() - b.getY())
		- (c.getY() - b.getY()) * (point.getX() - b.getX()); // for vecBC and vecBP
	Fixed d3 = (a.getX() - c.getX()) * (point.getY() - c.getY())
		- (a.getY() - c.getY()) * (point.getX() - c.getX()); // for vecCA and vecCP
	if (d1 == 0 || d2 == 0 || d3 == 0)// Point is on an edge
		return (false);
	bool sameSign = (d1 > 0 && d2 > 0 && d3 > 0) || (d1 < 0 && d2 < 0 && d3 < 0);
	return (sameSign);
}
