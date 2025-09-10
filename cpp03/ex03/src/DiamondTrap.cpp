/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:27:50 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/09 13:20:01 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string &name): ScavTrap(name), FragTrap(name)
{
	this->_name = name;
	this->ClapTrap::_name = name + "_clap_name";
    // Manually sets energy points to ScavTrap's value to meet the requirement.
	this->_hitPoints =  this->FragTrap::_hitPoints;
	this->_energyPoints = this->ScavTrap::_energyPoints;
	this->_attackDamage = this->FragTrap::_attackDamage;
	std::cout << "DiamondTrap constructor created DiamondTrap with name " << this->_name << std::endl;
    std::cout << "ClapTrap name is set to " << this->ClapTrap::_name << std::endl;
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
