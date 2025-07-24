/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:17:06 by mosokina          #+#    #+#             */
/*   Updated: 2025/06/05 11:56:34 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>   // for std::cin, std::cout
#include <string>     // for std::string

// • void randomChump( std::string name );
// This function creates a zombie, names it, and makes it announce itself.

void randomChump( std::string name )
{
	Zombie  random_zombie(name);
	random_zombie.announce();
	return ;
}
