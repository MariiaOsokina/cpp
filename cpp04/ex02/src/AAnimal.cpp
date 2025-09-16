/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:15:03 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/16 15:49:32 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AAnimal.hpp"

AAnimal::AAnimal(): type("AAnimal")
{
	std::cout << "AAnimal default constructor called." << std::endl;
}

AAnimal::AAnimal(const AAnimal &other): type(other.type)
{
	std::cout << "AAnimal copy constructor called." << std::endl;
}

AAnimal& AAnimal::operator = (const AAnimal &other)
{
	std::cout << "AAnimal copy assignment operator called." << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called."<< std::endl;
}

const std::string& AAnimal::getType() const
{
    return (type);
}
