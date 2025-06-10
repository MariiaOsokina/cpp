/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:18:00 by mosokina          #+#    #+#             */
/*   Updated: 2025/06/10 13:36:24 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Weapon.hpp"

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
class HumanB
{
	public:
		HumanB(std::string name);
		~HumanB();

        void attack();
		void setWeapon(Weapon &weapon);

	private:
		std::string _name;
        Weapon* _weapon;
};
#endif