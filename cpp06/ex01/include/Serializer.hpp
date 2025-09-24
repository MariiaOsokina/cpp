/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:20:57 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/24 16:52:56 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIIALIZER_HPP
#define SERIIALIZER_HPP


#include "../include/Data.hpp" 

#include <string>
#include <iostream>

struct Data;

class Serializer
{
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
	private:
		Serializer();
		Serializer(const Serializer &other);
		Serializer & operator= (const Serializer &other);
		~Serializer();

};

#endif



#endif