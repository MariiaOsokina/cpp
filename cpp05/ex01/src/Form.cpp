/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 23:21:48 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/22 22:53:06 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute):
		_name(name), _isSigned(false), _gradeToSign(gradeToSign),
		_gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw Form::GradeTooLowException();
	std::cout << "\033[32m" << "Form constructor called." << "\033[0m" << std::endl;
}

Form::Form(const Form &other):
		_name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign),
		_gradeToExecute(other._gradeToExecute) 
{
	std::cout << "\033[32m" << "Form copy constructor called." << "\033[0m" << std::endl;
}

// Attention! It is a private member
Form & Form::operator = (const Form &other)
{
	std::cout << "\033 [32m" << "Form copy assignment operator called." << "\033[0m" << std::endl;
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return *this;
}

Form::~Form()
{
	std::cout << "\033[32m" << "Form destructor called." << "\033[0m" << std::endl;
}

//Getters
const	std::string &Form::getName() const
{
	return this->_name;
}

int		Form::getGradeToSign() const
{
	return this->_gradeToSign;
}

int		Form::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

bool	Form::getIsSigned() const
{
	return this->_isSigned;
}

//Other member functions
void	Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade()<= this->_gradeToSign)
		this->_isSigned = true;
	else
		throw GradeTooLowException();
}

// Nested exception classes
const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	const int width = 20; // Define a consistent width for the labels

	os << "------------------------------" << std::endl;
	os << "          FORM DATA" << std::endl;
	os << "------------------------------" << std::endl;

	os << std::left << std::setw(width) << "Name:" << form.getName() << std::endl;
	os << std::left << std::setw(width) << "Is it signed:" << (form.getIsSigned() ? "YES" : "NO") << std::endl;
	os << std::left << std::setw(width) << "Grade to sign:" << form.getGradeToSign() << std::endl;
	os << std::left << std::setw(width) << "Grade to execute:" << form.getGradeToExecute() << std::endl;

	os << "------------------------------" << std::endl;
	return os;
}
