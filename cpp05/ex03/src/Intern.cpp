/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:01:31 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/22 23:18:38 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"

Intern::Intern()
{
	std::cout << "\033[32m"<< "Intern default constructor called." << "\033[0m" << std::endl;
}

Intern::Intern(const Intern &other)
{
	(void)other;
	std::cout << "\033[32m" << "Intern copy constructor called." << "\033[0m" << std::endl;
}

Intern &Intern::operator= (const Intern &other)
{
	(void)other;
	std::cout << "\033[32m" << "Intern copy assignment operator called." << "\033[0m" << std::endl;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "\033[32m" << "Intern destructor called." << "\033[0m" << std::endl;
}

AForm *Intern::makeForm(const std::string &nameForm, const std::string &target)
{
	int	i;

	std::string formNames[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	AForm *(Intern::*fptr[3])(const std::string &target) = {&Intern::_createRobotomyRequestForm, &Intern::_createPresidentialPardonForm, &Intern::_createShrubberyCreationForm};
	i = 0;
	while (i < 3)
	{
		if (nameForm == formNames[i])
		{
			std::cout << "Intern creates " << nameForm << std::endl;
			return (this->*fptr[i])(target);
		}
		i ++;
	}
	throw InvalidForm();
}

const char* Intern::InvalidForm::what() const throw()
{
	return "Invalid Form name.\nAvailable forms: robotomy request, presidential pardon, shrubbery creation";
}

AForm* Intern::_createRobotomyRequestForm(const std::string& target)
{
	return new RobotomyRequestForm(target);
}


AForm* Intern::_createPresidentialPardonForm(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::_createShrubberyCreationForm(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}
