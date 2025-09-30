/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:17:04 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/30 23:14:06 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename F>

/* The template automatically supports both const and non-const arrays because the array parameter's type, 
defined as a generic pointer T*, naturally carries the constness of the elements*/

/*When you pass an array of non-const elements (e.g., int arr[]), 
the compiler deduces T as int. The elements are mutable.
When you pass an array of const elements (e.g., const int arr[]), 
the compiler deduces T as const int. The elements are read-only.*/

void iter(T *array, const size_t length, F function)
{
	for (size_t i = 0; i < length; ++i)
	{
		function(array[i]);
	}
}

#endif
