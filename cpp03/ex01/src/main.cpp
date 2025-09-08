/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 10:30:30 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/08 13:45:00 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

int main(void)
{
	// Test constructor

	ClapTrap clap0;
	ClapTrap clap1("clap1");
	ScavTrap scav0;
	ScavTrap scav1("scav1");


	// Test copy constructor
	ScavTrap scav_copy(scav1);

	// Test copy assignment operator
	ScavTrap another_scav;
	another_scav = scav1;

	std::cout << "Attack:\n" << std::endl << std::endl;

	clap0.attack("target0");
	clap1.attack("target1");
	scav0.attack("target2");
	scav1.attack("target3");


	std::cout << "\nDamage and Repair:\n" << std::endl;
	clap1.takeDamage(5);
	clap1.beRepaired(3);
	scav1.takeDamage(10);
	scav1.beRepaired(5);

	std::cout << "\nSpecial Ability:\n" << std::endl;
	scav1.guardGate();

	return (0);
}