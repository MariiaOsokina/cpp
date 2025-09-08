/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:27:38 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/08 14:50:55 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"

/*New concept: Multiple Inheritance
*/

/*DiamondTrap Specifics
Private Attribute: The DiamondTrap class will have its own private _name attribute, 
which will conflict with the inherited _name from ClapTrap. 
To access and manage the correct name, you'll need to be precise with member function calls and attribute access.

Constructor Initialization: 
The constructor will be complex. 
You must call the constructors of ClapTrap, FragTrap, and ScavTrap in the DiamondTrap constructor's initialization list. 
The order is important: ClapTrap's constructor will be called first due to virtual inheritance, followed by FragTrap's, 
then ScavTrap's, and finally DiamondTrap's.

Attribute Values: You'll need to set the FragTrap and ScavTrap attribute values correctly. The exercise specifies that DiamondTrap uses FragTrap's hit points and attack damage, but ScavTrap's energy points.

Function Overriding: You'll need to override the attack() function to use ScavTrap's version. This means you will explicitly call ScavTrap::attack() within your DiamondTrap's attack() function.*/

class DiamondTrap: public ScavTrap, public FragTrap
{
	public:
		DiamondTrap();
		DiamondTrap(const std::string &name);
		~DiamondTrap();
		void attack(const std::string& target);

};

#endif