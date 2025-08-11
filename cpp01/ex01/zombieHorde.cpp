/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:50:15 by mosokina          #+#    #+#             */
/*   Updated: 2025/08/11 14:56:38 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie	*zombie_arr;
	
	if (N <= 0)
		return (NULL);
	zombie_arr = new Zombie[N]; //one signle allocation
	for (int i = 0; i < N; i ++)
		zombie_arr[i].setName(name);
	return (zombie_arr);
}
