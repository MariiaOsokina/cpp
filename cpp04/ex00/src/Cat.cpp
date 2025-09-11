/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:52:48 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/11 14:04:24 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat(): Animal()
{
	type = "Cat";
	std::cout << "Cat default constructor called." << std::endl;
};


Cat::Cat(const Cat& other): Animal(other)
{
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
	std::cout << "Cat destructor called."<< std::endl;
};

void Cat::makeSound() const
{
	std::cout << "Cat is meowing: Meow! Meow!" << std::endl;
};
