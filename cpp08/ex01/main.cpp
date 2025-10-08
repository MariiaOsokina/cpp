/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:58:51 by mosokina          #+#    #+#             */
/*   Updated: 2025/10/08 14:21:00 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <iostream>
#include <string>
#include <cstdlib> // for std::srand
#include <ctime>   // for std::time


static int getRandomNumber()
{
	return std::rand();
}

void largeTest()
{
	std::srand(std::time(NULL));

	std::cout << "\n\033[33m" << "Large Test (10,000 Numbers)" << "\033[0m" << std::endl;
	const unsigned int largeSize = 10000;	
	std::vector<int> largeVec(largeSize);
	std::generate(largeVec.begin(), largeVec.end(), getRandomNumber);
	Span largeSp(largeSize);
	try
	{
		largeSp.addRange(largeVec.begin(), largeVec.end());
		std::cout << "Successfully inserted 10,000 numbers using addRange()." << std::endl;
		std::cout << "Shortest Span: " << largeSp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << largeSp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: "<< "Large test failed with exception: " << e.what() << '\n';
	}
}

void testNoSpan()
{
	std::cout << "\n\033[33m" << "No Span Test" << "\033[0m" << std::endl;

	try
	{
		Span sp = Span(1);
		sp.addNumber(42);
		sp.printStorage();
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const Span::NoSpanException& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
}

void testFullSpan()
{
	std::cout << "\n\033[33m" << "Full Span Test" << "\033[0m" << std::endl;	
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.printStorage();

		std::cout << "Attempting to add 6th number..." << std::endl;
		sp.addNumber(42); //out of range
		sp.printStorage();
	}
	catch(const Span::FullSpanException& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
}

int main()
{
	std::cout << "\n\033[33m" << "Main Test" << "\033[0m" << std::endl;	

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	sp.printStorage();
    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

	largeTest();
	testNoSpan();
	testFullSpan();

	return 0;
}
