/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:52:48 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/15 15:05:30 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat(): Animal()
{
	type = "Cat";
	attribute =  new Brain();
	std::cout << "Cat default constructor called." << std::endl;
};


Cat::Cat(const Cat& other): Animal(other)
{
	attribute =  new Brain(*other.attribute); // deep copy
	std::cout << "Cat copy constructor called." << std::endl;
};

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat copy assignment operator called." << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return (*this);
};

Cat::~Cat()
{
	
	delete attribute;
	std::cout << "Cat destructor called."<< std::endl;
};

void Cat::makeSound() const
{
	std::cout << "Cat is meowing: Meow! Meow!" << std::endl;
};
