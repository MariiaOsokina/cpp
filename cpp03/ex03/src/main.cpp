/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 10:30:30 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/12 12:27:37 by mosokina         ###   ########.fr       */
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

	DiamondTrap d0;
	DiamondTrap d1("diamond1");

	std::cout << "Data:\n" << std::endl;
	d0.printData();
	d1.printData();

	std::cout << "Attack:\n" << std::endl << std::endl;
	d0.attack("target");
	d1.attack("target_test");

	std::cout << "Special attribute:\n" << std::endl << std::endl;
	d0.whoAmI();
	d1.whoAmI();

	std::cout << "\nMore tests with functions:\n" << std::endl;
	d1.highFivesGuys();
	d1.guardGate();
	d1.printData();
	d1.takeDamage(10);
	d1.beRepaired(5);
	
	
	return (0);
}