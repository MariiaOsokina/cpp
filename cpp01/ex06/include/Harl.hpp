/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:25:29 by mosokina          #+#    #+#             */
/*   Updated: 2025/08/31 12:36:35 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
	public:
		Harl();
		~Harl();

		void complain( std::string level );

	private:
		void _debug( void );
		void _info( void );
		void _warning( void );
		void _error( void );
};

#endif