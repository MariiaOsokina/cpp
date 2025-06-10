/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:20:13 by mosokina          #+#    #+#             */
/*   Updated: 2025/06/10 23:49:33 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanB.hpp"
#include <iostream>
#include <cstdlib>

HumanB::HumanB(std::string name): _name(name), _weapon(NULL){};
HumanB::~HumanB(){};

void HumanB::attack()
{
	if (this->_weapon != NULL)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " has no weapon to attack with." << std::endl;
};

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
};
