/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:05:18 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/23 15:49:44 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

enum LiteralType {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    UNKNOWN
};

class ScalarConverter
{
	public:
		static  void convert(const std::string &literal); //called directly from class
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter & operator= (const ScalarConverter &other);
		~ScalarConverter();

		LiteralType _determineType(const std::string& literal);
		static void _printChar(double value);
		static void _printInt(double value);
		static void _printFloat(double value);
		static void _printDouble(double value);
};

#endif
