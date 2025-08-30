/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:28:04 by mosokina          #+#    #+#             */
/*   Updated: 2025/08/30 22:37:44 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*This function creates a zombie, names it, and returns it so you can use it
outside of function scope*/

/*This is different from creating a local object (Zombie z(name);)
 — because that would be destroyed when the function ends.
Using new makes the object stay alive until you explicitly delete it.*/

Zombie* newZombie(std::string name)
{
	Zombie* z = new Zombie(name);
	return (z);
}
