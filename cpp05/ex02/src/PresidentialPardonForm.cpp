/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 15:22:07 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/19 15:29:29 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target):
		AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "\033[32m" << "PresidentialPardonForm constructor called." << "\033[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other):
		AForm(other), _target(other._target)
{
	std::cout << "\033[32m" << "PresidentialPardonForm copy constructor called." << "\033[0m" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "\033[32m" << "PresidentialPardonForm destructor called." << "\033[0m" << std::endl;
}

void PresidentialPardonForm::_executeAction() const
{
	std::cout << this->_target << "has been pardoned by Zaphod Beeblebrox." << std::endl;
}
