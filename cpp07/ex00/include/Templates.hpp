/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:33:12 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/29 13:51:21 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP


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