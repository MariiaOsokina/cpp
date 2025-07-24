/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:12:55 by mosokina          #+#    #+#             */
/*   Updated: 2025/06/05 14:21:18 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int N = 5;
	zombieHorde(N, "Bobby");

	// Zombie *zombie_arr = zombieHorde(N, "Bobby");
	// for (int i = 0; i < N; ++i)
	// 	delete &zombie_arr[i];
	return (0);
}
