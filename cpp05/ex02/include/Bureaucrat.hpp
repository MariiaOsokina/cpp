/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:11:52 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/22 22:54:08 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "../include/AForm.hpp"

#include <string>
#include <iostream>

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();
		
		//Getters
		const std::string &getName() const;
		int getGrade() const;

		//Other member functions
		void increaseGrade();
		void decreaseGrade();
		void signForm(AForm &form);
		void executeForm(AForm const & form) const;

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
		Bureaucrat &operator = (const Bureaucrat &other); // Attention! It's private (as const attr)
		const std::string _name;
		int	_grade;
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const& other);

#endif