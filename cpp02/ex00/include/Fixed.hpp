/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 09:45:16 by mosokina          #+#    #+#             */
/*   Updated: 2025/08/17 14:42:23 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>



/*This class is designed in the Orthodox Canonical Form and provides:
- a default constructor;
- a copy constructor;
- a copy assignment operator; and
- a destructor.*/

class Fixed
{
    public:
        Fixed();
        Fixed (const Fixed &other);
        Fixed &operator = (const Fixed &other);

        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits( int const raw );

    private:
        int _fixed_point_number;
        static const int _number_o_fractional_bits = 8;

};

#endif