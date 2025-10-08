/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:36:18 by mosokina          #+#    #+#             */
/*   Updated: 2025/10/08 13:08:11 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

/*The std::stack<T> is a container ADAPTOR(!).
Its job is to adapt a versatile container (like std::deque or std::vector)
to strictly enforce the LIFO (Last-In, First-Out) principle.

So, the std::stack class is intentionally designed to HIDE(!) the underlying container's full interface.
It only provides restricted functions like push, pop, and top.

MutantStack acts as a "bridge":
It uses its special derived-class access to peek at the PROTECTED member c.
It then exposes c's functions (c.begin()) via its own public interface (MutantStack::begin()).
We cannot access it through the base class (std::stack) object directly*/

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack &other);
		MutantStack& operator =(const MutantStack &other);
		~MutantStack();
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin();
		iterator end();

};

#include "MutantStack.tpp"

#endif
