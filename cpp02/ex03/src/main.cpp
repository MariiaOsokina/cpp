/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 09:56:49 by mosokina          #+#    #+#             */
/*   Updated: 2025/08/26 19:19:47 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include "../include/Point.hpp"

void	testPoint( Point const a, Point const b, Point const c, Point const testPoint)
{
	std::cout << "Test: Point with coordinates (" << testPoint.getX() << "," << testPoint.getY() <<")" << std::endl;
	if (bsp(a, b, c, testPoint))
		std::cout << "point is inside the triangle." << std::endl;
	else
		std::cout << "point is out of the triangle." << std::endl;
}

int	main(void)
{
	Point const a(0.0f , 0.0f);
	Point const b(5.0f , 0.0f);
	Point const c(0.0f , 5.0f);

	Point const insidePoint1(1.0f, 1.0f);
	Point const insidePoint2(2.0f, 2.0f);
	Point const outsidePoint1(1.0f, 6.0f);
	Point const outsidePoint2(-1.5f, 2.0f);
	Point const onVertexPoint(5.0f, 0.0f);
	Point const onEdgePoint(0.0f, 2.5f);

	testPoint(a, b, c, insidePoint1);
	testPoint(a, b, c, insidePoint2);
	testPoint(a, b, c, outsidePoint1);
	testPoint(a, b, c, outsidePoint2);
	testPoint(a, b, c, onVertexPoint);
	testPoint(a, b, c, onEdgePoint);

	return 0;
}
