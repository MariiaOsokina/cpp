/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:40:46 by mosokina          #+#    #+#             */
/*   Updated: 2025/10/03 12:44:32 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*T must be a type that behaves like a standard C++ container 
(e.g., std::vector<int>, std::list<int>, std::deque<int>).*/

/*In the C++ Standard Template Library (STL), the standard way to indicate 
that an element was not found in a range (like a container) is 
to return the end iterator (container.end()).

If found: std::find returns an iterator pointing directly to the element.
If not found: std::find returns the iterator pointing one past the last element (end()).*/