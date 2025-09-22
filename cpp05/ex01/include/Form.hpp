/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 23:21:39 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/22 22:39:03 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#include "../include/Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <iomanip>

/* Forward declaration for solving a "circular dependency" (a closed loop) */
class Bureaucrat; 

class Form
{
	public:
		Form(const std::string &name, int gradeToSign, int gradeToExecute);
		Form(const Form &other);
		~Form();

		//Getters
		const std::string &getName() const;
		int	getGradeToSign() const;
		int	getGradeToExecute() const;
		bool getIsSigned() const;

		//Other member functions
		void beSigned(const Bureaucrat &b);

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
		Form &operator = (const Form &other); // Attention! It's private (as const attr)
		const	std::string _name;
		bool	_isSigned;
		const	int _gradeToSign;
		const	int _gradeToExecute;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
