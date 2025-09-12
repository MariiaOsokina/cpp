/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:24:56 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/12 12:51:28 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "../include/ClapTrap.hpp"

/* "PUBLIC" specifies the access mode of inheritance:
- public members of base class will remain public derived class;
- protected members will remain protected
- Private members of the base class are never accessible by the derived class.*/

/*Order:
1 - the base class constructor (ClapTrap);
2- the derived class constructor (ScavTrap).
*/


/*inside derived class members and functions specific to this class
 Overriding a function means providing a new implementation for a function that is already present in the base class. 
 The new attack() function in ScavTrap will have the same name and parameters but will print a different message.
*/

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap &other);
		ScavTrap &operator = (const ScavTrap &other);
		~ScavTrap();
		void attack(const std::string& target);
		void guardGate();
};

#endif