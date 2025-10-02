/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:41:03 by mosokina          #+#    #+#             */
/*   Updated: 2025/10/02 23:20:54 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/iter.hpp"

#include <iostream>
#include <string> 

// Template function to be instantiated and passed as the third parameter
template <typename U>
void    displayValue(const U& value) 
{
	std::cout << "Value: " << value << std::endl;
}

// Regular function for const std::string elements
void    printDay(const std::string& day)
{
	std::cout << "Today is " << day << std::endl;
}

// Regular function for const int elements
void    countCicleArea(const int& radius)
{
	const double PI = 3.14159265358979323846; 
	double area = PI * (double)radius * (double)radius;
	std::cout << "Radius: " << radius << ", Area: " << area << std::endl;
}

// Regular function for non-const int elements (allows modification)
void    increment(int& num)
{
	num++;
}

int main(void)
{ 
	std::cout << "\n--- TEST 1: String Array (Regular Function) ---" << std::endl;
	const std::size_t lenghtDays = 7;
	std::string days[lenghtDays] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
	iter(days, lenghtDays, printDay);
	
	std::cout << "\n--- TEST 2: String Array (Function Template) ---" << std::endl;
	iter(days, lenghtDays, displayValue<std::string>);
	std::cout << std::endl;

	std::cout << "--- TEST 3: Const Integer Array (Const Function) ---" << std::endl;
	const std::size_t lenghRadiuses = 7;
	const int radius[lenghRadiuses] = {1, 42, 7, 100, 0, 120, 10}; 
	iter(radius, lenghRadiuses, countCicleArea);
	std::cout << std::endl;

	std::cout << "--- TEST 4: Non-Const Array Modification ---" << std::endl;
	const std::size_t lenghtNum = 3;
	int numbers[lenghtNum] = {1, -42, 42};
	std::cout << "Before increasing:" << std::endl;
	iter(numbers, lenghtNum, displayValue<int>);

	std::cout << "\nCalling increment function..." << std::endl;
	iter(numbers, lenghtNum, increment);
	
	std::cout << "After increasing:" << std::endl;
	iter(numbers, lenghtNum, displayValue<int>);

	/* --- TEST 5: Const-Correctness (Compile-Time Failure) ---
	The following code would cause a compilation error, 
	as 'const int' cannot be passed to 'int&'.*/

	// const int numbersConst[lenghtNum] = {1, -42, 42};
	// iter(numbersConst, lenghtNum, increment);

	return 0;
}
