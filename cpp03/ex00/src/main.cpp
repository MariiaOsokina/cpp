/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 10:30:30 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/12 10:42:41 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

int main(void)
{
	ClapTrap ctr0;
	ClapTrap ctr1("First");
	ClapTrap ctr2("Second");
	ClapTrap ctr3("Third");
	ClapTrap ctr4(ctr3);
	
	ctr3 = ctr2;
	
	ctr1.printData();
	ctr1.attack("clap trap second");

	ctr2.printData();
	ctr2.takeDamage(2);

	ctr3.printData();
	ctr3.beRepaired(3);
	
	return (0);
}
