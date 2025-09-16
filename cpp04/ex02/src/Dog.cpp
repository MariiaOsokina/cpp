/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:32:08 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/16 15:58:12 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog(): AAnimal()
{
	type = "Dog";
	_attribute =  new Brain();
	std::cout << "Dog default constructor called." << std::endl;
}

/*SHALLOW COPY: duplicates the object's top-level structure, but not the data it points to. 
If the original object contains pointers, the shallow copy will contain pointers to the SAME (!) memory locations. 
This can lead to a double-free error.

DEEP COPY: duplicates the object's entire structure,  including the data pointed to by pointers. 
The new object completely independent of the original. 
Each object will then have its own unique set of resources to manage and deallocate.*/

Dog::Dog(const Dog& other): AAnimal(other)
{
	_attribute =  new Brain(*other._attribute); // deep (not shallow) copy
	std::cout << "Dog copy constructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog copy assignment operator called." << std::endl;
	if (this != &other)
	{
		AAnimal::operator=(other);
		delete this->_attribute; // 2. Deallocate old brain to prevent a memory leak
		this->_attribute = new Brain(*other._attribute);// 3. Allocate a new brain/ perform a deep copy
	}
	return (*this);
}

Dog::~Dog()
{
	delete _attribute;
	std::cout << "Dog destructor called."<< std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Dog is barking: Woof! Woof!" << std::endl;
}

void Dog::setDogIdea(unsigned int i, const std::string &idea)
{
	this->_attribute->setIdea(i, idea);
}

const std::string&  Dog::getDogIdea(unsigned int i) const
{
	return (this->_attribute->getIdea(i));
}
