/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:25:29 by mosokina          #+#    #+#             */
/*   Updated: 2025/08/30 23:24:57 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "../include/Weapon.hpp"

/*HumanA takes the Weapon in its constructor, HumanB does not;
HumanB may not always have a weapon, whereas HumanA will always be armed*/

class HumanA
{
	public:
		HumanA(const std::string& name, Weapon& weapon);
		~HumanA();

		void attack();

	private:
		std::string _name; //by value (copy)
		Weapon& _weapon; //reference (link) to existing Weapon object
};
#endif