/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:41:03 by mosokina          #+#    #+#             */
/*   Updated: 2025/10/02 13:36:07 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/iter.hpp"

#include <iostream>
#include <string> 

void	printDay(const std::string& day)
{
	std::cout << "Today is " << day << std::endl;
}

void	printInt(const int& number)
{
	std::cout << number << std::endl;
}

void    countCicleArea(const int& radius)
{
	const double PI = 3.14159265358979323846; 
	double area = PI * (double)radius * (double)radius;
	std::cout << "Radius: " << radius << ", Area: " << area << std::endl;
}

void    increment(int& num)
{
	num++;
}

int main(void)
{
	std::cout << "\n\033[33m" << "TEST1: String Array" << "\033[0m" << std::endl;
	const std::size_t lenghtDays = 7;
	std::string days[lenghtDays] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
	iter(days, lenghtDays, printDay);
	std::cout << std::endl;

	std::cout << "\n\033[33m" << "TEST2: Integer Array (Calling countCicleArea)" << "\033[0m" << std::endl;
	const std::size_t lenghRadiuses = 7;
	const int radius[lenghRadiuses] = {1, 42, 7, 100, 0, 120, 10}; 
	iter(radius, lenghRadiuses, countCicleArea);
	std::cout << std::endl;

	std::cout << "\n\033[33m" << "TEST3: Non Const Integer Array  (Calling Increasement)" << "\033[0m" << std::endl;
	const std::size_t lenghtNum = 3;
	int numbers[lenghtNum] = {1, -42, 42};
	std::cout << "Before increasing:" << std::endl;
	iter(numbers, lenghtNum, printInt);
	iter(numbers, lenghtNum, increment);
	std::cout << "After increasing:" << std::endl;
	iter(numbers, lenghtNum, printInt);

	// The following would cause a compiler error, proving const-safety:
	// const int numbersConst[lenghtNum] = {1, -42, 42};
	// iter(numbersConst, lenghtNum, increment);

	return 0;
}
