/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 10:30:33 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/08 10:59:43 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.h"

ClapTrap::ClapTrap(): _name(_defaultName), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default constructor created." << std::endl;
	std::cout << std::endl;
};

ClapTrap::ClapTrap(const std::string &name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Constructor created ClapTrap with name " <<this->_name << std::endl;
	std::cout << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap &other)
	:_name(other._name),
	_hitPoints(other._hitPoints),
	_energyPoints(other._energyPoints),
	_attackDamage(other._attackDamage)
{
	std::cout << "Copy constructor: copied ClapTrap with name " << this->_name << std::endl;
	std::cout << std::endl;
};

ClapTrap& ClapTrap::operator = (const ClapTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
		std::cout << "Copy assignment operator:  copied ClapTrap with name " << this->_name << std::endl;
		std::cout << std::endl;
	}
	return (*this);
};

ClapTrap::~ClapTrap()
{
	std::cout << "Destractor: ClapTrap with name " << this->_name << " is deleted."<< std::endl;
	std::cout << std::endl;
};

bool	ClapTrap::_isResourcesEnough(void)
{
	if (this->_hitPoints <= 0)
		std::cout << "Sorry! ClapTrap with name " << this->_name << " has no Hit Points :(\n" << std::endl ;
	else if (this->_energyPoints <= 0)
		std::cout << "Sorry! ClapTrap with name " << this->_name << " has no Energy Points :(\n" << std::endl;
	else
		return (true);
	return (false);
}

void ClapTrap::attack(const std::string& target)
{
	if (_isResourcesEnough())
	{
		this->_energyPoints --;
		std::cout << "ClapTrap with name " << this->_name << " attacks " << target;
		std::cout << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		std::cout << "Attack damage: " << this->_attackDamage;
		std::cout << ", Hit points: " << this->_hitPoints;	
		std::cout << ", Energy points: " << this->_energyPoints << std::endl << std::endl;					
	}
};

void ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints = (this->_hitPoints > amount) ? (this->_hitPoints - amount) : 0; // as unsigned int
	std::cout << "ClapTrap with name " << this->_name << " took damage." << std::endl;
	std::cout << "Attack damage: " << this->_attackDamage;
	std::cout << ", Hit points: " << this->_hitPoints;	
	std::cout << ", Energy points: " << this->_energyPoints << std::endl << std::endl;
};

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_isResourcesEnough())
	{
		this->_energyPoints --;
		this->_hitPoints += amount;
		std::cout << "ClapTrap with name " << this->_name << " has been repaired." << std::endl;
		std::cout << "Attack damage: " << this->_attackDamage;
		std::cout << ", Hit points: " << this->_hitPoints;	
		std::cout << ", Energy points: " << this->_energyPoints << std::endl << std::endl;			
	}
};

const std::string ClapTrap::_defaultName = "no name";
