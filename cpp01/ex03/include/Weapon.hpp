/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:16:48 by mosokina          #+#    #+#             */
/*   Updated: 2025/08/30 23:29:45 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

/*const guarantees that calling getType() 
won’t change _type or any other non-mutable data in Weapon.*/

/* returning const std::string&:
- avoids making a copy of _type
- the caller can’t modify _type through the return value*/

class Weapon
{
	public:
		Weapon(std::string type);
		~Weapon();
		void setType(std::string new_type);
		const std::string& getType() const;
	private:
		std::string _type;
};
#endif
