/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 22:37:50 by mosokina          #+#    #+#             */
/*   Updated: 2025/10/02 21:56:41 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>

class Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		Array& operator =(const Array &other);
		~Array();
		unsigned int size(void) const;
		T& operator[](unsigned int index);
		const T& operator[]( unsigned int index) const;

	private:
		unsigned int _nSize;
		T* _array;
};


/*To solve the linkage problem,
the compiler must see the full template definition
in the same translation unit where the template is instantiated.*/
#include "Array.tpp"

#endif

