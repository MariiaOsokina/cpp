/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:52:48 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/16 15:53:31 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat(): AAnimal()
{
	type = "Cat";
	_attribute =  new Brain();
	std::cout << "Cat default constructor called." << std::endl;
}

/*SHALLOW COPY: duplicates the object's top-level structure, but not the data it points to. 
If the original object contains pointers, the shallow copy will contain pointers to the SAME (!) memory locations. 
This can lead to a double-free error.

DEEP COPY: duplicates the object's entire structure,  including the data pointed to by pointers. 
The new object completely independent of the original. 
Each object will then have its own unique set of resources to manage and deallocate.*/

Cat::Cat(const Cat& other): AAnimal(other)
{
	_attribute =  new Brain(*other._attribute); // deep (not shallow) copy
	std::cout << "Cat copy constructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat copy assignment operator called." << std::endl;
	if (this != &other)
	{
		AAnimal::operator=(other);
		delete this->_attribute; // 2. Deallocate old brain to prevent a memory leak
		this->_attribute = new Brain(*other._attribute);// 3. Allocate a new brain/ perform a deep copy
	}
	return (*this);
}

Cat::~Cat()
{
	delete _attribute;
	std::cout << "Cat destructor called."<< std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Cat is meowing: Meow! Meow!" << std::endl;
}

void Cat::setCatIdea(unsigned int i, const std::string &idea)
{
	this->_attribute->setIdea(i, idea);
}

const std::string&  Cat::getCatIdea(unsigned int i) const
{
	return (this->_attribute->getIdea(i));
}

void Cat::printCatIdeas() const
{
	this->_attribute->printIdeas();
}