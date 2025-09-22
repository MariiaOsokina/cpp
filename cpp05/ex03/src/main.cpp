/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:03:10 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/22 22:11:54 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/Intern.hpp"

void testForm(const std::string &name)
{
	AForm* formPtr = NULL;

	Intern someRandomIntern;
	Bureaucrat highRankBureaucrat("Bob", 1);
	try
	{
		formPtr = someRandomIntern.makeForm(name, "test_target");
		if (formPtr)
		{
			std::cout << *formPtr << std::endl;
			highRankBureaucrat.signForm(*formPtr);
			highRankBureaucrat.executeForm(*formPtr);
			std::cout << std::endl;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "\033[31m" << "Error: " << e.what() << "\033[0m" << std::endl;
	}
	delete formPtr;
}


int main (void)
{
	std::cout << "\n\033[33m" <<  "TEST 1: Creating a valid form" << "\033[0m" << std::endl;
	testForm("robotomy request");
	testForm("presidential pardon");
	testForm("shrubbery creation");

	std::cout << "\n\033[33m" <<  "TEST 2: Creating an invalid form" << "\033[0m" << std::endl;
	testForm("invalid request");

	return 0;
}
