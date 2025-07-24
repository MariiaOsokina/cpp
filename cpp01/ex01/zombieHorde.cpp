/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:50:15 by mosokina          #+#    #+#             */
/*   Updated: 2025/06/05 14:20:34 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*Steps:
1 - Use new Zombie[N] — calls the default constructor.
2 - Set names using a setter method (setName) after allocation.*/

Zombie* zombieHorde( int N, std::string name )
{
	if (N <= 0)
		return (NULL);
	Zombie *zombie_arr;
	zombie_arr = new Zombie[N]; //one signle allocation, default constructor
	for (int i = 0; i < N; ++i)
	{
		zombie_arr[i].setName(name);
		zombie_arr[i].announce();
	}
	return (zombie_arr);
}
