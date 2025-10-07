/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:40:38 by mosokina          #+#    #+#             */
/*   Updated: 2025/10/07 11:53:18 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>   // for std::find
#include <stdexcept> // for std::runtime_error

/*T must be a type that behaves like a standard C++ container 
(e.g., std::vector<int>, std::list<int>, std::deque<int>).*/
/*It supports linear containers (like vectors, lists, deques).
Associative containers (like maps and sets) manage searching differently.*/

/*Iterator:
-  is like a pointer that lets you move through the elements of a container 
(like a vector, list, deque, etc.) 
without knowing how the container stores its data.
*/

/*std::find If found, returns an iterator pointing directly to the element. if not, return end().
v.begin() → first element
v.end() → position after the last element*/

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::runtime_error("Interger not found in container.");
	return it;
}

#endif