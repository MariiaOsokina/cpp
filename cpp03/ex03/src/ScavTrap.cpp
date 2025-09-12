/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:24:40 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/12 12:56:27 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name): ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints= 50;
	_attackDamage= 20;
	std::cout << "ScavTrap constructor created ScavTrap with name " <<this->_name << std::endl;
	std::cout << std::endl;
};

ScavTrap::ScavTrap(): ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "Default ScavTrap constructor created." << std::endl;
	std::cout << std::endl;
};

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor copied " << this->_name << std::endl;
};

ScavTrap &ScavTrap::operator = (const ScavTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		std::cout << "ScavTrap copy assignment operator assigned " << this->_name << std::endl;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor: ScavTrap with name " << this->_name << " is deleted."<< std::endl;
	std::cout << std::endl;
};

void ScavTrap::attack(const std::string& target)
{
	if (_isResourcesEnough())
	{
		this->_energyPoints --;
		std::cout << "ScavTrap with name " << this->_name << " attacks " << target;
		std::cout << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		std::cout << "Attack damage: " << this->_attackDamage;
		std::cout << ", Hit points: " << this->_hitPoints;	
		std::cout << ", Energy points: " << this->_energyPoints << std::endl << std::endl;					
	}
};

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is now in Gatekeeper mode.\n" << std::endl;
};
