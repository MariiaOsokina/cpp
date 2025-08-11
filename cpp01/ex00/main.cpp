/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:12:55 by mosokina          #+#    #+#             */
/*   Updated: 2025/08/11 12:59:54 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*point of the ex00: 
to determine in which case
it is better to allocate zombies on the stack or the heap.*/

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
