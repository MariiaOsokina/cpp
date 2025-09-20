/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 15:23:48 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/19 19:05:23 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target):
		AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "\033[32m" << "RobotomyRequestForm constructor called." << "\033[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other):
		AForm(other), _target(other._target)
{
	std::cout << "\033[32m" << "RobotomyRequestForm copy constructor called." << "\033[0m" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "\033[32m" << "RobotomyRequestForm destructor called." << "\033[0m" << std::endl;
}

void RobotomyRequestForm::_executeAction() const
{
	std::cout << "* Drilling noises... *" << std::endl;
	if (rand() % 2 == 0)
		std::cout << this->_target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy for " << this->_target << " failed." << std::endl;
}
