/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 10:30:37 by mosokina          #+#    #+#             */
/*   Updated: 2025/08/29 19:40:36 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator = (const ClapTrap &other);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		// const std::string	getName(void) const;
		// int		getHitPoints(void) const;
		// int		getEnergyPoints(void) const;
		// int		getAttackDamage(void) const;

	private:
		std::string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;
		bool	_isResourcesEnough(void);
};

/*Name, which is passed as a parameter to the constructor
• Hit points (10), representing the health of the ClapTrap
• Energy points (10)
• Attack damage (0)*/