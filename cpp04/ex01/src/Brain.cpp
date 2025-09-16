/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:23:11 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/16 15:02:49 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called." << std::endl;
	for (int i = 0; i < (int)numberOfIdeas; i++)
	{
		this->_ideas[i] = "empty idea";
	}
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor called." << std::endl;
	for (int i = 0; i < (int)numberOfIdeas; i++)
	{
		this->_ideas[i] = other._ideas[i];
	}
}

Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < (int)numberOfIdeas; i++)
		{
			this->_ideas[i] = other._ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called."<< std::endl;
}

void Brain::setIdea(unsigned int i, const std::string& idea)
{
	if (i >= numberOfIdeas)
		std::cerr << "Error: Index " << i << " is out of bounds." << std::endl;
	else
		this->_ideas[i] = idea;
}

const std::string& Brain::getIdea(unsigned int i) const
{
	if (i >= numberOfIdeas)
	{
		throw std::out_of_range("Index is out of bounds.");
	}
	return (this->_ideas[i]);
}
