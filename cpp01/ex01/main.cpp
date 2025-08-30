/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:12:55 by mosokina          #+#    #+#             */
/*   Updated: 2025/08/30 22:48:54 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*ex01:
- new[] and delete [] for allocate and delete array of objects;
- new() keyword to allocate on the heap*/

int main(void)
{
	Zombie	*zombie_arr;
	int	N = 5;

	zombie_arr = zombieHorde(N, "Bobby");
	if (zombie_arr)
	{
		for (int i = 0; i < N; i++)
			zombie_arr[i].announce();
		delete[] zombie_arr;
	}
	return (0);
}
