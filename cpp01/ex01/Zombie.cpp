/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:08:17 by mosokina          #+#    #+#             */
/*   Updated: 2025/08/11 14:51:13 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>   // for std::cin, std::cout
#include <string>     // for std::string

Zombie::Zombie() : _name("Unknown") {}

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
	std::cout << "<" << this->_name << ">: BraiiiiiiinnnzzzZ...";
	std::cout <<std::endl;
}

void Zombie::setName(std::string name)
{
	this->_name = name;
}
