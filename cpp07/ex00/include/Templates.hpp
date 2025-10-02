/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:33:12 by mosokina          #+#    #+#             */
/*   Updated: 2025/10/02 22:53:49 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

/*Template Instantiation at the COMPILATION(!) phase: 
When the compiler sees a usage like Array<int> numbers;
it looks up the template definition and generates the concrete machine code for the Array<int> class. 
If you use Array<double>, it generates a separate Array<double> class.*/


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
