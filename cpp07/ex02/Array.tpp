/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:46:47 by mosokina          #+#    #+#             */
/*   Updated: 2025/10/01 14:35:25 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*.tpp file:
Using a .tpp extension is simply a naming convention to signal that 
this file contains implementation code that MUST BE INCLUDED by header,
unlike a regular .cpp file which is compiled separately.*/

/*The general rule for template class files is that all definitions needed 
for instantiation must be VISIBLE when the template is used.*/

#include "Array.hpp"
#include <stdexcept>

template<typename T>
Array<T>::Array(): _nSize(0), _array(NULL)
{
	std::cout << "\033[32m" << "Array default constructor called." << "\033[0m" << std::endl;
}


/*value initialization (like int(), float(), or T()), 
The value is initialized to zero (or false for bool, or NULL for pointers).*/

template<typename T>
Array<T>::Array(unsigned int n): _nSize(n), _array(NULL)
{
	if (_nSize == 0)
		return ;
	_array = new T[_nSize];
	for (unsigned int i = 0; i < _nSize; ++i)
	{
		_array[i] = T();
	}
	std::cout << "\033[32m" << "Array constructor called." << "\033[0m" << std::endl;
}

template<typename T>
Array<T>::Array(const Array<T> &other): _nSize(other._nSize), _array(NULL)
{
	if (_nSize == 0)
		return ;
	_array = new T[_nSize];
	for (unsigned int i = 0; i < _nSize; ++i)
	{
		_array[i] = other._array[i];
	}	
	std::cout << "Array copy constructor called." << std::endl;
}


/*only destroying the old memory if the new memory allocation succeeds.
if any exception occurs during the allocation or copying process,
the original object remains untouched and valid.*/

template<typename T>
Array<T>& Array<T>::operator =(const Array<T> &other)
{
	if (this == &other)
		return *this;
	T *newArray = new T[other._nSize];
	for (unsigned int i = 0; i < other._nSize; ++i)
	{
		newArray[i] = other._array[i];
	}
	delete[] _array;
	_nSize = other._nSize;
	_array = newArray;
	std::cout << "Array copy assignment operator  called." << std::endl;
	return *this;
}

template<typename T>
Array<T>::~Array()
{
	delete[] _array;
	std::cout << "\033[32m" << "Array destructor called." << "\033[0m" << std::endl;
}

template<typename T>
unsigned int Array<T>::size(void) const
{
	return _nSize;
}


template<typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _nSize)
		throw std::out_of_range("Index is out of bounds.");
	return _array[index];
}

template<typename T>
const T& Array<T>::operator[]( unsigned int index) const
{
	if (index >= _nSize)
		throw std::out_of_range("Index is out of bounds.");
	return _array[index];
}
