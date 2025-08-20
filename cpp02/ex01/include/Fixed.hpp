/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 09:45:16 by mosokina          #+#    #+#             */
/*   Updated: 2025/08/20 12:24:24 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
/*This class is designed in the Orthodox Canonical Form and provides:
- a default constructor;
- a copy constructor;
- a copy assignment operator; and
- a destructor.*/

class Fixed
{
	public:
		Fixed();
		Fixed(const int number);
		Fixed(const float number);
		Fixed(const Fixed &other);
		Fixed &operator = (const Fixed &other);

		~Fixed();

		int	getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt( void ) const;

	private:
		int _fixed_point_number;
		static const int _number_of_fractional_bits = 8;
};

std::ostream& operator<<(std::ostream& os, Fixed const& other);

#endif
