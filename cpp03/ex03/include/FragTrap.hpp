/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 13:48:40 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/08 14:40:20 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "../include/ClapTrap.hpp"

/*New: VIRTUAL inheritance for solving the diamond problem:
When inheriting from ClapTrap,  we tell the compiler to create 
only a single shared instance of ClapTrap for all derived classes.*/

class FragTrap: virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const std::string &name);
		~FragTrap();
		void highFivesGuys();
};

#endif