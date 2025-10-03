/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:40:38 by mosokina          #+#    #+#             */
/*   Updated: 2025/10/03 15:25:51 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP


/*
begin(): Points at the first element you want to include (inclusive).

end(): Points after the last element you want to include (exclusive).*/



/*Iterator:
- generalization of a C++ pointer. It is an object that can point to an element in a container and allows you to move to the next or previous element.
- Purpose: To provide a uniform interface for access. std::vector stores elements contiguously in memory (like an array), while std::list stores them non-contiguously (in nodes). 
Iterators hide these internal differences, allowing algorithms to treat all containers the same way.
*/

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    return std::find(container.begin(), container.end(), value);
}


#endif