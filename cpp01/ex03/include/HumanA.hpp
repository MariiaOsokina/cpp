/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:25:29 by mosokina          #+#    #+#             */
/*   Updated: 2025/08/31 11:45:14 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "../include/Weapon.hpp"

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