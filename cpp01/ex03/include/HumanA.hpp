/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:25:29 by mosokina          #+#    #+#             */
/*   Updated: 2025/06/10 23:42:19 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Weapon.hpp"

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
class HumanA
{
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();

		void attack();

	private:
		std::string _name;
		Weapon& _weapon;
};
#endif