/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:08:36 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/16 11:25:49 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

/**virtual destructor:
- is the safeguard that guarantees proper cleanup in polymorphic hierarchies.
*/

/* The virtual keyword enables runtime polymorphism, 
which allows you to call a derived class's function through a base class pointer.
The compiler uses a virtual table (v-table) to look up the correct function at runtime.
*/

class Animal
{
	public:
		Animal();
		Animal(const Animal &other);
		Animal& operator=(const Animal &other);
		virtual ~Animal();

		virtual void makeSound() const;
    	const std::string& getType() const;
	protected:
		std::string type;
};

#endif