/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:27:23 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/16 15:05:25 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "../include/Animal.hpp"
#include "../include/Brain.hpp"
#include <string>
#include <iostream>


class Dog: public Animal
{
	public:
		Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		~Dog();

		virtual void makeSound() const;
		void setDogIdea(unsigned int i, const std::string &str);
		const std::string&  getDogIdea(unsigned int i) const;

	private:
		Brain *_attribute;
};

#endif
