/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:03:10 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/19 15:13:31 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"


void	test1(void)
{
	try
	{
		std::cout << "\n\033[33m" << "Test1: ShrubberyCreationForm successul" << "\033[0m" << std::endl;
		ShrubberyCreationForm shForm("target2");
		std::cout << shForm << std::endl;

		Bureaucrat b1("Bob", 130);
		std::cout << b1 << std::endl;
		b1.signForm(shForm);
		std::cout << shForm << std::endl;
		b1.executeForm(shForm);
	}
	catch (const std::exception& e)
	{
		std::cerr << "\033[31m" << "Error: " << e.what() << "\033[0m" << std::endl;
	}
}

int main (void)
{
	test1();

	return 0;
}
