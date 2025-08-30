/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:12:55 by mosokina          #+#    #+#             */
/*   Updated: 2025/08/30 22:47:04 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*point of the ex00 to determine in which case
it is better to allocate zombies on the stack or the heap.

STACK allocation is for objects with a short lifespan (like randomChump). it limits to the function where it's created.
It's faster and safer since memory is managed automatically.

HEAP allocation needs to persist beyond the current function's scope.
More flexibility but requires careful, manual memory management to prevent leaks.*/

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
