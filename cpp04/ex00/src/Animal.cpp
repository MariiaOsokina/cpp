/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:15:03 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/16 22:17:02 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

Animal::Animal(): type("Animal")
{
	std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal(const Animal &other): type(other.type)
{
	std::cout << "Animal copy constructor called." << std::endl;
}

Animal& Animal::operator = (const Animal &other)
{
	std::cout << "Animal copy assignment operator called." << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called."<< std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Animal makes a generic sound." << std::endl;
}

const std::string& Animal::getType() const
{
	return (type);
}
