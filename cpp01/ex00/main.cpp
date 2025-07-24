/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:12:55 by mosokina          #+#    #+#             */
/*   Updated: 2025/06/05 13:29:40 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie Zombie_Bob("Bob");
	Zombie_Bob.announce();

	Zombie Zombie_Foo("Foo");
	Zombie_Foo.announce();

	randomChump("Bill");

	Zombie *Zombie_Jonny;
	Zombie_Jonny = newZombie("Jonny");
	Zombie_Jonny->announce();
	delete Zombie_Jonny;
	return (0);
}
