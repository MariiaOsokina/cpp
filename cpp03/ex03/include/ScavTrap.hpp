/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:24:56 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/08 14:39:36 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "../include/ClapTrap.hpp"

/*New: VIRTUAL inheritance for solving the diamond problem:
When inheriting from ClapTrap,  we tell the compiler to create 
only a single shared instance of ClapTrap for all derived classes.*/

class ScavTrap: virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const std::string &name);
		~ScavTrap();
		void attack(const std::string& target);
		void guardGate();
};

#endif