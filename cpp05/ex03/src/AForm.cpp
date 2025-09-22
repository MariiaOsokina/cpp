/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 11:54:42 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/22 23:11:54 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute):
		_name(name), _isSigned(false), _gradeToSign(gradeToSign),
		_gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	std::cout << "\033[32m" << "AForm constructor called." << "\033[0m" << std::endl;
}

AForm::AForm(const AForm &other): 
		_name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign),
		_gradeToExecute(other._gradeToExecute)
{
	std::cout << "\033[32m" << "AForm copy constructor called." << "\033[0m" << std::endl;
}

// Attention! It is a private member
AForm & AForm::operator = (const AForm &other)
{
	std::cout << "\033 [32m" << "Form copy assignment operator called." << "\033[0m" << std::endl;
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return *this;
}

AForm::~AForm()
{
	std::cout << "\033[32m" << "AForm destructor called." << "\033[0m" << std::endl;
}

//Getters
const	std::string &AForm::getName() const
{
	return this->_name;
}

int		AForm::getGradeToSign() const
{
	return this->_gradeToSign;
}

int		AForm::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

bool	AForm::getIsSigned() const
{
	return this->_isSigned;
}

//Other member functions
void	AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade()<= this->_gradeToSign)
		this->_isSigned = true;
	else
		throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() ==  false)
		throw FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	this->_executeAction();
}

// Nested exception classes
const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed.";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
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
