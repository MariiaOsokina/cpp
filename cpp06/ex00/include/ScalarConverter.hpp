/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:05:18 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/30 11:09:11 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cmath>
#include <iomanip> // for std::fixed and std::setprecision()
#include <cstdlib> // For strtol, strtof, strtod
#include <limits> // for std::numeric_limits<T> min() and max()

typedef enum TypeLiteral
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	UNKNOWN
} TypeLiteral;

/*STATIC(!) function is called directly from class*/

class ScalarConverter
{
	public:
		static  void convert(const std::string &literal);
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter & operator= (const ScalarConverter &other);
		~ScalarConverter();

		//private helper functions
		static TypeLiteral _determineType(const std::string& literal);
		static void _printChar(double value);
		static void _printInt(double value);
		static void _printFloat(double value);
		static void _printDouble(double value);
		static void _printImpossibleValue();
};

#endif
