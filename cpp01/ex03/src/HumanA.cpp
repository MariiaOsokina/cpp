/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:38:42 by mosokina          #+#    #+#             */
/*   Updated: 2025/08/30 23:25:00 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanA.hpp"
#include <iostream>

/*
HumanA takes the Weapon in its constructor, HumanB does not
HumanB may not always have a weapon, whereas HumanA will always be
armed
*/

HumanA::HumanA(const std::string& name, Weapon& weapon):
	_name(name), _weapon(weapon) //initializer list
	{}

HumanA::~HumanA() {}

void HumanA::attack()
{
	std::cout << this->_name
			  << " attacks with their "
			  << this->_weapon.getType()
			  << std::endl;
}
