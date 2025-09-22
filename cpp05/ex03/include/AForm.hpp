/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 11:20:06 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/22 22:38:04 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "../include/Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <iomanip>

/* Forward declaration for solving a "circular dependency" (a closed loop) */
class Bureaucrat; 

class AForm
{
	public:
		AForm(const std::string &name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &other);
		virtual ~AForm(); //virtual

		//Getters
		const std::string &getName() const;
		int	getGradeToSign() const;
		int	getGradeToExecute() const;
		bool getIsSigned() const;

		//Other member functions
		void beSigned(const Bureaucrat &b);
		void execute(Bureaucrat const & executor) const;

		// Nested exception classes
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
		class	FormNotSignedException : public std::exception {
			public:
				const char* what() const throw();
		};

	protected:
		virtual void _executeAction() const = 0; // Pure virtual function

	private:
		AForm &operator = (const AForm &other); // Attention! It's private (as const attr)
		const	std::string _name;
		bool	_isSigned;
		const	int _gradeToSign;
		const	int _gradeToExecute;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
