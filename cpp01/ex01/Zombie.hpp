/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:05:23 by mosokina          #+#    #+#             */
/*   Updated: 2025/08/30 22:51:16 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

/*Zombie(); ->> default constructor*/

class Zombie
{
	public:
		Zombie();
		Zombie(std::string	zombie_name);
		~Zombie();	
		void setName(std::string name);
		void announce( void );
	private:
		std::string	_name;
};

Zombie* zombieHorde( int N, std::string name );

#endif