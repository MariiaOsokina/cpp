/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 13:53:27 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/22 21:52:04 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"

#include <string>
#include <iostream>

class AForm;

class Intern
{
	public:
		Intern();
		Intern(const Intern &other);
		Intern &operator= (const Intern &other);
		~Intern();

		AForm *makeForm(const std::string &nameForm, const std::string &target);

		class InvalidForm : public std::exception {
			public:
				const char* what() const throw();
		};

	private:
		AForm* _createRobotomyRequestForm(const std::string& target);
		AForm* _createPresidentialPardonForm(const std::string& target);
		AForm* _createShrubberyCreationForm(const std::string& target);

};

#endif