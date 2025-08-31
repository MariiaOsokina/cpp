/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:38:42 by mosokina          #+#    #+#             */
/*   Updated: 2025/08/31 12:36:30 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"
#include <iostream>

Harl::Harl() {}

Harl::~Harl() {}

/*/*Here the switch statement is inplimented, instead og a chain of if/else if statements.
Firstly, it finds the numerical index of the input level string. 
Then, it uses this index to jump directly to the correct case label.*/

void Harl::complain(std::string level )
{
	int	i;

	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	i = 0;
	while (i < 4)
	{
		if (level == levels[i])
			break;
		i ++;
	}
	switch (i)
	{
		case 0:
			Harl::_debug();
			Harl::_info();
			Harl::_warning();
			Harl::_error();
			break;
		case 1:
			Harl::_info();
			Harl::_warning();
			Harl::_error();
			break;
		case 2:
			Harl::_warning();
			Harl::_error();
			break;
		case 3:
			Harl::_error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
			break;
	}
}

void Harl::_debug( void )
{
	std::cout << "[ DEBUG ] " << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
	std::cout << std::endl;
}

void Harl::_info( void )
{
	std::cout << "[ INFO ] " << std::endl;;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
	std::cout << std::endl;
}

void Harl::_warning( void )
{
	std::cout << "[ WARNING ] " << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;
	std::cout << std::endl;
}

void Harl::_error( void )
{
	std::cout << "[ ERROR ] " << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}
