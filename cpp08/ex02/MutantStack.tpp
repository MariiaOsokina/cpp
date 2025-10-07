/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:36:15 by mosokina          #+#    #+#             */
/*   Updated: 2025/10/07 15:40:29 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(){}


template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other): std::stack<T>(other)
{}

template <typename T>
MutantStack<T>& MutantStack<T>::operator =(const MutantStack &other)
{
	if (this == &other)
		return *this;
	this->std::stack<T>::operator=(other); 
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack(){}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}
