/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:17:02 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/11 14:42:43 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	type = "WrongCat";
	std::cout << "WrongCat default constructor called." << std::endl;
};


WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other)
{
	std::cout << "Cat copy constructor called." << std::endl;
};

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "WrongCat copy assignment operator called." << std::endl;
	if (this != &other)
	{
		WrongAnimal::operator=(other);
	}
	return (*this);
};

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called."<< std::endl;
};

void WrongCat::makeSound() const
{
	std::cout << "WrongCat is meowing: Meow! Meow!" << std::endl;
};
