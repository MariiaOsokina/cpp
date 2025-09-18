/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 23:21:48 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/18 17:55:03 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute):
		_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form constructor called." << std::endl;
}

Form::Form(const Form &other): _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) 
{
	std::cout << "Form copy constructor called." << std::endl;
}

Form & Form::operator = (const Form &other)
{
	std::cout << "Form copy assignment operator called." << std::endl;
	if (this != &other)
	{
		//???
	}
	return *this;
}

Form::~Form()
{
	std::cout << "Form destructor called."<< std::endl;
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
	(void)b;
	return ;
}

// Nested exception classes

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high! Must be between 1 and 150.";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low! Must be between 1 and 150.";
}

// Overload the insertion (<<) operator
std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form with name: " << form.getName() << std::endl;
	os << "is it signed: " << (form.getIsSigned() ? "YES" : "NO") << std::endl;
	os << "grade required to sign: " << form.getGradeToSign() << std::endl;
	os << "grade required to execute: " << form.getGradeToExecute() << std::endl;
	os << "------------------------------" << std::endl;
	return os;
}

