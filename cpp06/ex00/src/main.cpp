/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:16:27 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/23 15:19:22 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"


// ./convert 0
// char: Non displayable
// int: 0
// float: 0.0f
// double: 0.0
// ./convert nan
// char: impossible
// int: impossible
// float: nanf
// double: nan
// ./convert 42.0f
// char: '*'
// int: 42
// float: 42.0f
// double: 42.0

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        ///
    }
    ScalarConverter::convert(argv[1]);
        
    return 0;
}