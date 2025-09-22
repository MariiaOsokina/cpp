/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:03:10 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/22 22:52:02 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

void	test1(void)
{
	try
	{
		std::cout << "\n\033[33m" << "Test1: successful creation and printing of Form" << "\033[0m" << std::endl;
		Form testForm("Test Form", 100, 50);
		std::cout << testForm << std::endl; // Test operator<< overload
	}
	catch (const std::exception& e)
	{
		std::cerr << "\033[31m" << "Caught an unexpected exception: " << e.what() << "\033[0m" << std::endl;
	}
}

void	test2(void)
{
	std::cout << "\n\033[33m" << "Test2:  instantiate a Form with an invalid grade (low and high) "
					<< "\033[0m" << std::endl;
	try
	{
		Form f1("F1", 200, 50);
	}
	catch(const std::exception& e)
	{
		std::cerr << "\033[31m" << "Error: " << e.what() << "\033[0m" << std::endl;
	}
	
	try
	{
		Form f2("F2", 50, 200);
	}
	catch(const std::exception& e)
	{
		std::cerr << "\033[31m" << "Error: " << e.what() << "\033[0m" << std::endl;
	}

	try
	{
		Form f3("F2", -50, 100);
	}
	catch(const std::exception& e)
	{
		std::cerr << "\033[31m" << "Error: " << e.what() << "\033[0m" << std::endl;
	}
	try
	{
		Form f3("F2", 50, -50);
	}
	catch(const std::exception& e)
	{
		std::cerr << "\033[31m" << "Error: " << e.what() << "\033[0m" << std::endl;
	}
}

void	test3(void)
{
	std::cout << "\n\033[33m" << "Test3: testing signForm function"
					<< "\033[0m" << std::endl;
	Form testForm("Test Form", 100, 50);
	std::cout << testForm << std::endl;

	Bureaucrat b1("Bob", 5);
	std::cout << b1 << std::endl;
	b1.signForm(testForm);
	std::cout << testForm << std::endl;

	Bureaucrat b2("Sam", 120);
	std::cout << b2 << std::endl;
	b2.signForm(testForm);
	std::cout << testForm << std::endl;
}

void test4(void)
{
	std::cout << "\n\033[33m" << "Test4: Copy constructor" << "\033[0m" << std::endl;
	try
	{
		Form f1("Original", 50, 10);
		std::cout << f1 << std::endl;

		Form f2(f1);
		std::cout << "Copied form (f2): \n" << f2 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "\033[31m" << "Error: " << e.what() << "\033[0m" << std::endl;
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
