/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:11:49 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/22 22:31:05 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default_name"), _grade(150)
{
	std::cout << "\033[32m"<< "Bureaucrat default constructor called." << "\033[0m" << std::endl;
}

/*if an exception is thrown in a constructor, the object is not fully created.
The constructor is immediately exited, and the object's memory is deallocated.
The program immediately jumps out of the constructor and looks for a catch block.*/

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name), _grade(grade)
{
	std::cout << "\033[32m" << "Bureaucrat constructor called." << "\033[0m" << std::endl;
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name)
{
	std::cout << "\033[32m" << "Bureaucrat copy constructor called." << "\033[0m" << std::endl;
	this->_grade = other._grade;
}

// Attention! It is a private member
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
	std::cout << "\033[32m" << "Bureaucrat destructor called." << "\033[0m" << std::endl;
}

const std::string &Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::increaseGrade()
{
	std::cout << "increaseGrade called."<< std::endl;
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade --;
}

void Bureaucrat::decreaseGrade()
{
	std::cout << "decreaseGrade called."<< std::endl;
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade ++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high! Must be between 1 and 150.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low! Must be between 1 and 150.";
}

std::ostream& operator<<(std::ostream& os, Bureaucrat const& other)
{
	os << other.getName() << ", bureaucrat grade " << other.getGrade() << ".";
	return os;
}
