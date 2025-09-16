/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:11:55 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/11 14:44:00 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal& operator = (const WrongAnimal &other);
		~WrongAnimal(); // not virtual!!

		void makeSound() const; // not virtual!!
    	const std::string& getType() const;
	protected:
		std::string type;
};

#endif