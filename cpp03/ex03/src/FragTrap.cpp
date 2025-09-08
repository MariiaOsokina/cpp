/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 13:48:53 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/08 14:24:27 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"

FragTrap::FragTrap(const std::string &name): ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints= 100;
	_attackDamage= 30;
	std::cout << "FragTrap constructor created FragTrap with name " <<this->_name << std::endl;
	std::cout << std::endl;
};

FragTrap::FragTrap(): ClapTrap()
{
	_hitPoints = 100;
	_energyPoints= 100;
	_attackDamage= 30;
	std::cout << "Default FragTrap constructor created." << std::endl;
	std::cout << std::endl;
};

FragTrap::~FragTrap()
{
	std::cout << "Destructor: FragTrap with name " << this->_name << " is deleted."<< std::endl;
	std::cout << std::endl;
};

void FragTrap::highFivesGuys()
{
    std::cout << "Hey, give me a high five!\n" <<std::endl;
};
