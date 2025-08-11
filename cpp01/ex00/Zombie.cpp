/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:08:17 by mosokina          #+#    #+#             */
/*   Updated: 2025/08/11 13:20:46 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>   // for std::cin, std::cout
#include <string>     // for std::string

Zombie::Zombie(std::string	zombie_name): _name(zombie_name)
{
	std::cout << "Zombie " << this->_name << " has appeared. Grrr!";
	std::cout <<std::endl;
}


Zombie::~Zombie()
{
	std::cout << "Zombie " << this->_name << " is dead now.";
	std::cout <<std::endl;
}

void Zombie::announce(void)
{
	if (this->_name == "Foo")
	{
		std::cout << this->_name << ": BraiiiiiiinnnzzzZ...";
		std::cout <<std::endl;		
	}
	else
	{
		std::cout << "<" << this->_name << ">: BraiiiiiiinnnzzzZ...";
		std::cout <<std::endl;		
	}

}
