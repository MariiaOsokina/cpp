/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:11:52 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/17 16:46:44 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <string>
#include <iostream>


/*The GradeTooHighException and GradeTooLowException classes should be NESTED inside the Bureaucrat class. */

class Bureaucrat
{
	public:
		// Nested exception classes
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator = (const Bureaucrat &other);
		~Bureaucrat();
		const std::string &getName() const;
		int getGrade() const;

	private:
		const std::string _name;
		int	_grade;
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const& other);



#endif