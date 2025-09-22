/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:03:10 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/22 22:44:48 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"


/*EXCEPTIONS: flow
1. Code inside try { ... } executes.
2. If no exception is thrown → catch is skipped.
3. If an exception is thrown (e.g., throw ...;) → execution jumps immediately to the matching catch.
4. If no matching catch is found → the program calls std::terminate() (usually crashes).*/

void	test1(void)
{
	try
	{
		std::cout << "\033[33m" << "Test1: successful creation and printing" << "\033[0m" << std::endl;
		Bureaucrat b("Anna", 75);
		std::cout << b << std::endl;
		b.increaseGrade();
		std::cout << "After increasing grade: " << b << std::endl;
		b.decreaseGrade();
		std::cout << "After decreasing grade: " << b << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "\033[31m" << "Caught an unexpected exception: " << e.what() << "\033[0m" << std::endl;;
	}
}

void	test2(void)
{
	std::cout << "\033[33m" << "Test2:  instantiate a Bureaucrat with an invalid grade (low and high) "
					<< "\033[0m" << std::endl;
	try
	{
		Bureaucrat b1("John", 200);
	}
	catch(const std::exception& e)
	{
		std::cerr << "\033[31m" << "Error: " << e.what() << "\033[0m" << std::endl;
	}
	
	try
	{
		Bureaucrat b2("Bill", -5);
	}
	catch(const std::exception& e)
	{
		std::cerr << "\033[31m" << "Error: " << e.what() << "\033[0m" << std::endl;
	}
}

void	test3(void)
{
	std::cout << "\033[33m" << "Test3: grade goes out of range after its increasement / decreasement"
					<< "\033[0m" << std::endl;
	try
	{
		Bureaucrat b1("Bob", 150);
		std::cout << b1 << std::endl;
		b1.decreaseGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << "\033[31m" << "Error: " << e.what() << "\033[0m" << std::endl;
	}
	try
	{
		Bureaucrat b2("Sam", 1);
		std::cout << b2 << std::endl;
		b2.increaseGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << "\033[31m" << "Error: " << e.what() << "\033[0m" << std::endl;
	}
}

void test4(void)
{
	std::cout << "\033[33m" << "Test4: Copy constructor" << "\033[0m" << std::endl;
	try
	{
		Bureaucrat b1("Original", 50);
		std::cout << b1 << std::endl;

		Bureaucrat b2(b1);
		std::cout << "Copied bureaucrat (b2): " << b2 << std::endl;
		b1.increaseGrade();
		std::cout << "Original after grade increase: " << b1 << std::endl;
		std::cout << "Copied bureaucrat (b2) remains unchanged: " << b2 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "\033[31m" << "Caught an unexpected exception: " << e.what() << "\033[0m" << std::endl;
	}
}

int main (void)
{
	test1();
	test2();
	test3();
	test4();

	return 0;
}
