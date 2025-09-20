/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:03:10 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/21 00:48:32 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"

void	testSigningForm(AForm &form)
{
	
	std::cout << "\n\033[33m" << "- Test of signing:" << "\033[0m" << std::endl;
	std::cout << form << std::endl;

	int grades[] = {150, form.getGradeToSign() + 1, form.getGradeToSign(), form.getGradeToSign() - 1, 1};

	for (int i = 0 ; i < 5; i++)
	{
		try
		{
			Bureaucrat b("Bob", grades[i]);
			std::cout << b << std::endl;
			b.signForm(form);
		}
		catch (const std::exception& e)
		{
			std::cerr << "\033[31m" << "Error: " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << std::endl;
	}
}

void	testExecutingForm(AForm &form)
{
	
	std::cout << "\n\033[33m" << "- Test of executing:" << "\033[0m" << std::endl;
	std::cout << form << std::endl;

	int grades[] = {150, form.getGradeToExecute() + 1, form.getGradeToExecute(), form.getGradeToExecute() - 1, 1};

	for (int i = 0 ; i < 5; i++)
	{
		try
		{
			Bureaucrat b("Bob", grades[i]);
			std::cout << b << std::endl;
			b.executeForm(form);
		}
		catch (const std::exception& e)
		{
			std::cerr << "\033[31m" << "Error: " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << std::endl;
	}
}

void	testShrubberyCreationForm()
{
	std::cout << "\n\033[33m" << "TEST: ShrubberyCreationForm" << "\033[0m" << std::endl;


	ShrubberyCreationForm shForm1("home");
	testSigningForm(shForm1);
	testExecutingForm(shForm1);

	ShrubberyCreationForm shFormNotSinged("garden");
	testExecutingForm(shFormNotSinged);
	std::cout << std::endl;
}

void	testRobotomyRequestForm()
{
	std::cout << "\n\033[33m" << "TEST: RobotomyRequestForm" << "\033[0m" << std::endl;


	RobotomyRequestForm robForm1("home");
	testSigningForm(robForm1);
	testExecutingForm(robForm1);

	RobotomyRequestForm robFormNotSinged("garden");
	testExecutingForm(robFormNotSinged);
	std::cout << std::endl;
}

void	testPresidentialPardonForm()
{
	std::cout << "\n\033[33m" << "TEST: PresidentialPardonForm" << "\033[0m" << std::endl;


	PresidentialPardonForm presForm1("home");
	testSigningForm(presForm1);
	testExecutingForm(presForm1);

	PresidentialPardonForm presFormNotSinged("garden");
	testExecutingForm(presFormNotSinged);
	std::cout << std::endl;
}


int main (void)
{
	testShrubberyCreationForm();
	testRobotomyRequestForm();
	testPresidentialPardonForm();

	return 0;
}
