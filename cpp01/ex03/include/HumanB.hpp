/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:18:00 by mosokina          #+#    #+#             */
/*   Updated: 2025/08/12 15:21:58 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Weapon.hpp"

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>

/*
HumanA takes the Weapon in its constructor, HumanB does not
HumanB may not always have a weapon, whereas HumanA will always be
armed
*/

class HumanB
{
	public:
		HumanB(const std::string name);
		~HumanB();

        void attack();
		void setWeapon(Weapon &weapon);

	private:
		std::string _name;
        Weapon* _weapon;
};
#endif