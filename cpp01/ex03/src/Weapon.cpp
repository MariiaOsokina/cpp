/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:33:41 by mosokina          #+#    #+#             */
/*   Updated: 2025/08/12 15:31:27 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Weapon.hpp"

Weapon::Weapon(std::string type): _type(type){}

Weapon::~Weapon(){}

void Weapon::setType(std::string new_type)
{
	this->_type = new_type;
}

const std::string& Weapon::getType() const
{
	return this->_type;
}
