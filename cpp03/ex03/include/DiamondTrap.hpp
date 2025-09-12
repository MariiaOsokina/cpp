/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:27:38 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/12 12:26:58 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"

/*New concept: Multiple Inheritance
*/

class DiamondTrap: public ScavTrap, public FragTrap
{
	public:
		DiamondTrap();
		DiamondTrap(const std::string &name);
		~DiamondTrap();
		void attack(const std::string& target);
		void printData();
		void whoAmI();

	private:
		std::string _name;
};

#endif