/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:20:51 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/29 23:53:42 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"

/*reinterpret_cast:
Low-level reinterpretation of the underlying bit pattern of an object.
The most dangerous cast.*/

/*uintptr_t:
 uintptr_t is an unsigned integer type that is CAPABLE of storing a pointer.
Using uintptr_t ensures that the integer type is large enough (!) to hold a pointer value.
The size of uintptr_t depends on the architecture of the system. For example, on a 32-bit system, 
uintptr_t is typically 32 bits, 
and on a 64-bit system, it is typically 64 bits.*/

/*Serialization: 
is the process of converting a data structure/object into a format that can be easily stored or transmitted
Deserialization:
is the reverse process, converted back into its original data structure/object.
it's useful in practice primarily for low-level system programming */

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
