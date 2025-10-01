/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:33:12 by mosokina          #+#    #+#             */
/*   Updated: 2025/10/01 16:39:25 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

/*Type Template Parameters:
The keyword typename indicates that T is a placeholder for a type
(like int, double, or a custom class).*/

template <typename T>
T const &max(T const &x, T const &y)
{
	return (x > y ? x : y);
}

template <typename T>
T const &min(T const &x, T const &y)
{
	return (x < y ? x : y);
}

template <typename T>
void swap(T &x, T &y)
{
	T tempValue;

	tempValue = x;
	x = y;
	y = tempValue;
}

#endif
