/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:08:36 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/16 15:49:59 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>
#include <iostream>

/*
ABSTRACT CLASS: is a blueprint for other classes. 
It defines an interface that its derived classes must follow.
In C++, a class becomes abstract if it contains AT LEAST one pure virtual function.

PURE VURTUAL FUNCTIONS:
is a virtual function that is declared but not defined in the base class.
It's declared by appending = 0 to its signature.*/

class AAnimal
{
	public:
		AAnimal();
		AAnimal(const AAnimal &other);
		AAnimal& operator = (const AAnimal &other);
		virtual ~AAnimal();

		virtual void makeSound() const = 0; // pure virtual function
    	const std::string& getType() const;
	protected:
		std::string type;
};

#endif