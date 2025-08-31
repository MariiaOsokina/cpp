/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:38:42 by mosokina          #+#    #+#             */
/*   Updated: 2025/08/31 11:42:01 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanA.hpp"
#include <iostream>

/*HumanA is designed to ALWAYS have a weapon. 
Its constructor takes a Weapon object by reference (Weapon&).*/

/*A REFERENCE acts as an alias or a direct link to an existing object. 
It must be initialized when the HumanA object is created.
This guarantees that the _weapon member is NEVER NULL or invalid.*/

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
