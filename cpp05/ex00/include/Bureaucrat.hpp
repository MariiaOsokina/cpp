/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:11:52 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/18 17:42:35 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>


/*NESTED CLASS: is a class defined inside another class, 
Exception classes should be nested. */

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator = (const Bureaucrat &other); //??
		~Bureaucrat();
		
		const std::string &getName() const;
		int getGrade() const;
		void increaseGrade();
		void decreaseGrade();


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
		const std::string _name;
		int	_grade;
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const& other);

#endif