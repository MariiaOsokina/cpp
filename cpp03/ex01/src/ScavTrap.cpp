/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:24:40 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/03 15:18:11 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.h"
#include "../include/ScavTrap.h"


ScavTrap::ScavTrap(const std::string &name): _name(name), _hitPoints(100), _energyPoints(50), _attackDamage(20)
{
	std::cout << "Default constructor created ScavTrap with name " <<this->_name << std::endl;
	std::cout << std::endl;
};