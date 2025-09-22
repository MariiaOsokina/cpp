/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 11:20:26 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/19 15:21:17 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):
		AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "\033[32m" << "ShrubberyCreationForm constructor called." << "\033[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other):
		AForm(other), _target(other._target)
{
	std::cout << "\033[32m" << "ShrubberyCreationForm copy constructor called." << "\033[0m" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "\033[32m" << "ShrubberyCreationForm destructor called." << "\033[0m" << std::endl;
}

void ShrubberyCreationForm::_executeAction() const
{
	std::ofstream	newFile;
	std::string newFileName = this->_target + "_shrubbery";
	newFile.open(newFileName.c_str());
	if (!newFile.is_open())
		throw std::runtime_error("Error: could not create file.");
	newFile << "       _-_" << "\n";
	newFile << "    /~~   ~~\\" << "\n";
	newFile << " /~~         ~~\\" << "\n";
	newFile << "{               }" << "\n";
	newFile << " \\  _-     -_  /" << "\n";
	newFile << "   ~  \\ //  ~" << "\n";
	newFile << "_- -   | | _- _" << "\n";
	newFile << "  _--  | |   --_" << "\n";
	newFile << "      // \\\\" << std::endl;
}
