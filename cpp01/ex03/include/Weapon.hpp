/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:16:48 by mosokina          #+#    #+#             */
/*   Updated: 2025/06/10 12:25:03 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
class Weapon
{
	public:
		Weapon(std::string type);
		~Weapon();
		void setType(std::string new_type);
		std::string getType() const;
	private:
		std::string _type;
};
#endif
