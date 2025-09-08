/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:27:50 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/08 15:01:11 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string &name): ScavTrap(name), FragTrap(name)
{
	this->_name = name;
    _hitPoints = FragTrap::_hitPoints;
	_energyPoints= ScavTrap::_energyPoints;
	_attackDamage= FragTrap::_attackDamage;
	std::cout << "DiamondTrap constructor created DiamondTrap with name " << this->_name << std::endl;
	std::cout << std::endl;
};

DiamondTrap::DiamondTrap(): ScavTrap(), FragTrap()
{
	this->_name = _defaultName;
    _hitPoints = FragTrap::_hitPoints;
	_energyPoints= ScavTrap::_energyPoints;
	_attackDamage= FragTrap::_attackDamage;
	std::cout << "Default DiamondTrap constructor created." << std::endl;
	std::cout << std::endl;
};

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destructor: DiamondTrap with name " << this->_name << " is deleted."<< std::endl;
	std::cout << std::endl;
};


/*Function Overriding*/

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
};
