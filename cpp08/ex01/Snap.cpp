/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snap.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:13:18 by mosokina          #+#    #+#             */
/*   Updated: 2025/10/07 15:49:59 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N): _maxSize(N)
{}

Span::Span(const Span &other): _storage(other._storage), _maxSize(other._maxSize)
{}

Span &Span::operator= (const Span &other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_storage = other._storage;
	}

	return *this;
}

Span::~Span(){}

void Span::addNumber(int num)
{
	if (_storage.size() >= this->_maxSize)
		throw FullSpanException();
	_storage.push_back(num);
}

int Span::shortestSpan() const
{
	if (_storage.size() < 2)
		throw NoSpanException();
	std::vector<int> sortedCopy (_storage);
	std::sort(sortedCopy.begin(), sortedCopy.end());
	int minSpan = INT_MAX;
	for (int i = sortedCopy.size() - 1; i > 0; --i)
	{
		int currenntSpan = sortedCopy[i] - sortedCopy[i - 1];
		minSpan = std::min(minSpan, currenntSpan);
	}
	return(minSpan);
}

int Span::longestSpan() const
{
	if (_storage.size() < 2)
		throw NoSpanException();
	std::vector<int>::const_iterator minIt;
	minIt = std::min_element(_storage.begin(), _storage.end());
	std::vector<int>::const_iterator maxIt;
	maxIt = std::max_element(_storage.begin(), _storage.end());	
	return(*maxIt - *minIt);
}

void Span::printStorage() const
{
	std::cout << "Integers in the storage:";
	for (std::vector<int>::const_iterator it = _storage.begin(); 
		 it != _storage.end(); 
		 ++it)
	{
		std::cout << " " << *it;
	}
	std::cout << std::endl;
}

const char* Span::FullSpanException::what() const throw()
{
	return "Span is full: Cannot add more numbers.";
}

const char* Span::NoSpanException::what() const throw()
{
	return "No span found.";
}
