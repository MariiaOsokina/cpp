/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:27:23 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/11 12:52:34 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

class Dog: public Animal
{
	public:
		Dog();
		Dog(const std::string &name);
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		~Dog();
		virtual void makeSound() const;
};
