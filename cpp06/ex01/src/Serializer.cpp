/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:20:51 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/24 16:50:49 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"

/*uintptr_t:
 uintptr_t is an unsigned integer type that is CAPABLE of storing a pointer.
Using uintptr_t ensures that the integer type is large enough (!) to hold a pointer value.
The size of uintptr_t depends on the architecture of the system. For example, on a 32-bit system, 
uintptr_t is typically 32 bits, 
and on a 64-bit system, it is typically 64 bits.*/

/*Serialization: 
is the process of converting a data structure/object into a format that can be easily stored or transmitted
Deserialization:
is the reverse process, converted back into its original data structure/object.*/



// Serializes a pointer to an unsigned integer.
// We use a reinterpret_cast, which is necessary for this type of conversion.
uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

// Deserializes an unsigned integer back to a pointer.
// This is the reverse operation of serialize().
Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
