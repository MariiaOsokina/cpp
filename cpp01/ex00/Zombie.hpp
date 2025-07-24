/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:05:23 by mosokina          #+#    #+#             */
/*   Updated: 2025/06/05 12:37:32 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP


#include <string>

class Zombie
{
	public:
		Zombie(std::string	zombie_name);
		~Zombie();

		void announce( void );
		
	private:
		std::string	_name;

};

void randomChump( std::string name );
Zombie* newZombie(std::string name);


#endif