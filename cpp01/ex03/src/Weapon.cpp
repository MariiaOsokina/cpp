/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:33:41 by mosokina          #+#    #+#             */
/*   Updated: 2025/08/30 23:25:13 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Weapon.hpp"

Weapon::Weapon(std::string type): _type(type){}

Weapon::~Weapon(){}

void Weapon::setType(std::string new_type)
{
	this->_type = new_type;
}

/* getType() const - the method doesn’t modify the object
It guarantees that inside getType(), you can’t change any member variables 
(unless they are marked mutable).*/

const std::string& Weapon::getType() const
{
	return (this->_type);
}
