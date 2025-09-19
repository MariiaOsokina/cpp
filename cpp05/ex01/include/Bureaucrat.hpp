/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:11:52 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/19 11:47:31 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "../include/Form.hpp"

#include <string>
#include <iostream>

/* Forward declaration for solving a "circular dependency" (a closed loop) */
class Form;

/*NESTED CLASS: is a class defined inside another class, 
Exception classes should be nested.*/

class Bureaucrat
{
	public:

		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);

		//The Rule of Three
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();
		
		//Getters
		const std::string &getName() const;
		int getGrade() const;

		//Other member functions
		void increaseGrade();
		void decreaseGrade();
		void signForm(Form &form);

		// Nested exception classes
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

	private:
		// Attention! It's private as it doesn't copy const attribues from "other" object
		Bureaucrat &operator = (const Bureaucrat &other);
		const std::string _name;
		int	_grade;
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const& other);

#endif