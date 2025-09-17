/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:11:49 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/17 16:48:05 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.h"

// Inside the Bureaucrat class definition in the header file ???

// Define the what() method for the nested exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high! Must be between 1 and 150.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low! Must be between 1 and 150.";
}

/*EXCEPTIONS: involves three main parts: 
1 throw:
When an error occurs, you throw an exception. 
This immediately stops the execution of the current function and looks for a catch block to handle it. 
You can throw any object, but a common practice is to throw an object derived from std::exception.


2 TRY:
You place the code that might throw an exception inside a try block.
if it is exception, then catch.

3 CATCH:
he catch block is where you handle the exception.
*/

Bureaucrat::Bureaucrat(): _name("default_name"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called." << std::endl;
}

/*f an exception is thrown in a constructor, the object is not fully created.
The constructor is immediately exited, and the object's memory is deallocated.
The program immediately jumps out of the constructor and looks for a catch block.*/

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name), _grade(grade)
{
	std::cout << "Bureaucrat constructor called." << std::endl;
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name)
{
	std::cout << "Bureaucrat copy constructor called." << std::endl;
	this->_grade = other._grade;
}

//_name is const can't be chaged by the operator. find solution??

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &other)
{
	std::cout << "Bureaucrat copy assignment operator called." << std::endl;
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called."<< std::endl;
}

const std::string &Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

std::ostream& operator<<(std::ostream& os, Bureaucrat const& other)
{
	os << other.getName() << ", bureaucrat grade " << other.getGrade() << ".";
	return (os);
}


