/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:08:17 by mosokina          #+#    #+#             */
/*   Updated: 2025/06/05 14:15:53 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>   // for std::cin, std::cout
#include <string>     // for std::string


Zombie::Zombie(){};

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

/*Do not print the angle brackets (< and >). For a zombie named Foo, the message
would be:
Foo: BraiiiiiiinnnzzzZ...*/

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

void Zombie::setName(std::string name)
{
	this->_name = name;
}
