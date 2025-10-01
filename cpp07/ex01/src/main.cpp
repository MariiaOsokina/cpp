/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:41:03 by mosokina          #+#    #+#             */
/*   Updated: 2025/10/01 16:57:48 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/iter.hpp"

#include <iostream>
#include <string> 
#include <cstddef>


void	printDay(const std::string& day)
{
	std::cout << "Today is " << day << std::endl;
}

void    countCicleArea(const int& radius)
{
	const double PI = 3.14159265358979323846; 
	double area = PI * (double)radius * (double)radius;
	std::cout << "The area of a circle with radius " << radius << " is " << area << std::endl;
}

void    increment(int& num)
{
	num++;
}

int main(void)
{
	// String Array Test
	const size_t lenghtDays = 7;
	std::string days[lenghtDays] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
	iter(days, lenghtDays, printDay);
	std::cout << std::endl;

	// Integer Array Test (Calling countCicleArea)
	const size_t lenghRadiuses = 7;
	const int radius[lenghRadiuses] = {1, 42, 7, 100, 0, 120, 10}; 
	iter(radius, lenghRadiuses, countCicleArea);

	
	// Non Const Integer Array  (Calling Increasement)
	
	const size_t lenghtNum = 3;
	int numbers[lenghtNum] = {1, -42, 42};
	iter(numbers, lenghtNum, increment);
	
	return 0;
}
