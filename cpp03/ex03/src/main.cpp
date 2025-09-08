/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 10:30:30 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/08 14:51:09 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"

/*The order is important: 
ClapTrap's constructor will be called first due to virtual inheritance, 
followed by FragTrap's,  then ScavTrap's, 
and finally DiamondTrap's.*/

int main(void)
{
	// Test constructor

	DiamondTrap d0();
	DiamondTrap d1("diamond1");


	// Test copy constructor
	DiamondTrap diamond_copy(d1);
	
	// Test copy assignment operator
	DiamondTrap another_diamond;
	another_diamond = d1;

	std::cout << "Attack:\n" << std::endl << std::endl;

	d1.attack("target_test");

	std::cout << "\nDamage and Repair:\n" << std::endl;
	d0.takeDamage(5);
	d0.beRepaired(3);
	d1.takeDamage(10);
	d1.beRepaired(5);

	std::cout << "\nSpecial Ability:\n" << std::endl;
	d1.highFivesGuys();
	d1.guardGate();
	
	return (0);
}