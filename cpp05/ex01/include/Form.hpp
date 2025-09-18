/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 23:21:39 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/18 17:49:17 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#include "../include/Bureaucrat.hpp"
#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
	public:
		//Conctructor
		Form(const std::string &name, int gradeToSign, int gradeToExecute);

		//Rule of Three
		Form(const Form &other);
		Form &operator = (const Form &other); //???
		~Form();

		//Getters
		const	std::string &getName() const;
		int		getGradeToSign() const;
		int		getGradeToExecute() const;
		bool	getIsSigned() const;

		//Other member functions
		void	beSigned(const Bureaucrat &b);

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
		const	std::string _name;
		bool	_isSigned;
		const	int _gradeToSign;
		const	int _gradeToExecute;
};

// Overload the insertion (<<) operator
std::ostream& operator<<(std::ostream& os, const Form& form);

#endif