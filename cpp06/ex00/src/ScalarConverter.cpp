/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:13:36 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/30 11:45:53 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

/*pseudo-literals: "nanf", "-inff", "+inff", "nan", "-inf", and "+inf"
they are strings that standard C++ I/O or conversion functions (like strtof and strtod) 
are explicitly designed to parse and convert into these special floating-point values.
Infinity - e.g. dividing a positive number by zero
Not number - e.g. such as dividing zero by zero */

TypeLiteral ScalarConverter::_determineType(const std::string& literal)
{
	if (literal.size() == 1 && !isdigit(literal[0]))
		return CHAR;
	else if (literal == "nanf" || literal == "-inff" || literal == "+inff")
		return FLOAT;
	else if (literal == "nan" || literal == "-inf" || literal == "+inf")
		return DOUBLE;
	else if (literal.find('.') != std::string::npos && literal[literal.size() - 1] == 'f')
	{
		char *endptr;
		strtof(literal.c_str(), &endptr);
		if (*endptr == 'f' && *(endptr + 1) == '\0')
			return FLOAT;
		return UNKNOWN;
	}
	else if (literal.find('.') != std::string::npos)
	{
		char *endptr;
		strtod(literal.c_str(), &endptr);
		if (*endptr == '\0')
			return DOUBLE;
		return UNKNOWN;
	}
	else
	{
		char *endptr;
		strtol(literal.c_str(), &endptr, 10); //str to a long (!) int
		if (*endptr == '\0')
			return INT; //can be long int!!!
		else
			return UNKNOWN;
	}
}

void ScalarConverter::_printImpossibleValue()
{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: impossible\n";
	std::cout << "double: impossible" <<std::endl;
}

/*STATIC_CAST(explicit cast)
- well-defined and non-polymorphic;
- Converting from a wider type (like double) to a narrower type (int or char) 
- involves truncating the fractional part and checking for overflow.
Because the compiler knows these conversions can be unsafe,
we must use an explicit (!) cast to force the action*/

void ScalarConverter::_printChar(double valueD)
{
	char valueC = static_cast<char>(valueD);

	if (std::isnan(valueD) || std::isinf(valueD) ||
		valueD < std::numeric_limits<char>::min() ||
		valueD > std::numeric_limits<char>::max())
			std::cout << "char: impossible" << std::endl;
	else if (!isprint(valueC))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << valueC << "'" << std::endl;
}

void ScalarConverter::_printInt(double valueD)
{
	if (std::isnan(valueD) || std::isinf(valueD) ||
		valueD < static_cast<double>(std::numeric_limits<int>::min()) ||
		valueD > static_cast<double>(std::numeric_limits<int>::max()))
	{
		std::cout << "int: impossible\n";
		return ;
	}
	int valueI = static_cast<int>(valueD);
	std::cout << "int: " << valueI << std::endl;
}

/*std::fixed is a C++ stream manipulator that:
- Forces floating-point numbers to be printed in fixed-point decimal notation (e.g., 42.0) 
instead of scientific notation (e.g., 4.2e+01).
- Works together with std::setprecision(n) to control the number of digits after the decimal point.
Formatting output like 0.0f or 42.0f.*/

void ScalarConverter::_printFloat(double valueD)
{
	float valueF = static_cast<float>(valueD);

	if (std::isnan(valueF))
		std::cout << "float: nanf" << std::endl;
	else if (std::isinf(valueF))
		std::cout << "float: " << (valueF > 0 ? "+inff" : "-inff") << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1)
				  << "float: " << valueF << "f" << std::endl;
}

void ScalarConverter::_printDouble(double valueD)
{
	if (std::isnan(valueD))
		std::cout << "double: nan" << std::endl;
	else if (std::isinf(valueD))
	{
		if (valueD > 0)
			std::cout << "double: +inf" << std::endl;
		else
			std::cout << "double: -inf" << std::endl;
	}
	else
		std::cout << std::fixed << std::setprecision(1) 
					<< "double: " << valueD << std::endl;
}


/*double (!) as the single intermediate type (valueD):
- Promote all initial input values (char, int, float) to the widest type (double).
- Convert from this single, highest-fidelity type (double) down to all target types.*/

void ScalarConverter::convert(const std::string &literal)
{
	TypeLiteral type = UNKNOWN;
	double valueD = 0.0;

	type = _determineType(literal);
	if (type == CHAR)
		valueD = static_cast<double>(literal[0]);
	else if (type == INT)
		valueD = static_cast<double>(strtol(literal.c_str(), NULL, 10));
	else if (type == FLOAT)
		valueD = static_cast<double>(strtof(literal.c_str(), NULL));
	else if (type == DOUBLE)
		valueD = strtod(literal.c_str(), NULL);
	
	std::cout << "\n\033[33m" << "Convertion results for " << literal << ":" << "\033[0m" << std::endl;
	if (type == UNKNOWN)
		_printImpossibleValue();
	else
	{
		_printChar(valueD);
		_printInt(valueD);
		_printFloat(valueD);
		_printDouble(valueD);		
	}
	std::cout << "-------------------------" << std::endl;
}
