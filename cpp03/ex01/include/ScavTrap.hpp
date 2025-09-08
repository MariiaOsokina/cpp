/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:24:56 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/08 13:43:31 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "../include/ClapTrap.hpp"

/* "PUBLIC" specifies the access mode of inheritance:
- public members of ClapTrap will remain public in ScavTrap;
- protected members will remain protected.*/


/*Order:
1 - the base class constructor (ClapTrap);
2- the derived class constructor (ScavTrap).
*/


/*inside child class members and functions specific to this class
 Overriding a function means providing a new implementation for a function that is already present in the base class. 
 The new attack() function in ScavTrap will have the same name and parameters but will print a different message.
*/

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const std::string &name);
		~ScavTrap();
		void attack(const std::string& target);
		void guardGate();
};

#endif