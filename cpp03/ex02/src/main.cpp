/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 10:30:30 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/08 14:23:03 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"

int main(void)
{
	// Test constructor

	ClapTrap clap0;
	ClapTrap clap1("clap1");
	ScavTrap scav0;
	ScavTrap scav1("scav1");
	FragTrap frag0;
	FragTrap frag1("Frag1");

	// Test copy constructor
	FragTrap frag_copy(frag1);
	
	// Test copy assignment operator
	FragTrap another_frag;
	another_frag = frag1;

	std::cout << "Attack:\n" << std::endl << std::endl;

	clap0.attack("target0");
	clap1.attack("target1");
	scav0.attack("target2");
	scav1.attack("target3");
	frag0.attack("target4");
	frag1.attack("target5");

	std::cout << "\nDamage and Repair:\n" << std::endl;
	clap1.takeDamage(5);
	clap1.beRepaired(3);
	scav1.takeDamage(10);
	scav1.beRepaired(5);
	frag1.takeDamage(10);
	frag1.beRepaired(5);	

	std::cout << "\nSpecial Ability:\n" << std::endl;
	frag1.highFivesGuys();
	
	return (0);
}