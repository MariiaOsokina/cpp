/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:27:50 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/12 13:22:23 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string &name): ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	this->_name = name;
	this->ClapTrap::_name = name + "_clap_name";
	this->_energyPoints = 50;
	std::cout << "DiamondTrap constructor created DiamondTrap with name " << this->_name << std::endl;
    std::cout << "ClapTrap name is set to " << this->ClapTrap::_name << std::endl;
	std::cout << std::endl;
};

DiamondTrap::DiamondTrap(): ClapTrap(), ScavTrap(), FragTrap()
{
	this->_name = _defaultName;
	this->ClapTrap::_name = _defaultName + "_clap_name";
	this->_energyPoints = 50;
	std::cout << "Default DiamondTrap constructor created." << std::endl;
	std::cout << std::endl;
};

void DiamondTrap::whoAmI()
{
    std::cout << "Who Am I?" << std::endl;
    std::cout << "My name is: " << this->_name << std::endl;
    std::cout << "My ClapTrap name is: " << this->ClapTrap::_name << std::endl << std::endl;
}

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

void DiamondTrap::printData()
{
	std::cout << "DiamondTrap with name " << this->_name << " has these data:" << std::endl;
	std::cout << "Attack damage: " << this->_attackDamage;
	std::cout << ", Hit points: " << this->_hitPoints;	
	std::cout << ", Energy points: " << this->_energyPoints << std::endl << std::endl;	
}
