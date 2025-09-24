/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:13:36 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/24 15:49:30 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

TypeLiteral ScalarConverter::_determineType(const std::string& literal)
{
	if (literal.size() == 3 && literal[0] == '\'' && literal[2] == '\''
			&& literal[1] > 0 && literal [1] <= 126)
		return CHAR;
	else if (literal == "nanf" || literal == "-inff" || literal == "+inff")
		return FLOAT;
	else if (literal == "nan" || literal == "-inf" || literal == "+inf")
		return DOUBLE;
	else if (literal.find('.') != std::string::npos)
	{
		if (literal[literal.size() - 1] == 'F' || literal[literal.size() - 1] == 'f')
			return FLOAT;
		else
			return DOUBLE;
	}
	else
	{
        char *endptr;
        strtol(literal.c_str(), &endptr, 10);
        if (*endptr == '\0')
            return INT;
        else
            return UNKNOWN;
	}
}

void ScalarConverter::convert(const std::string &literal)
{
	TypeLiteral type = UNKNOWN;
	double valueD;

	type = _determineType(literal);
	if (type == UNKNOWN)
	{
		_printImpossibleValue();
		return ;
	}
	if (type == CHAR)
		valueD = static_cast<double>(literal[1]);
    else if (type == INT)
    {
        valueD = static_cast<double>(strtol(literal.c_str(), NULL, 10));
    }
    else if (type == FLOAT)
    {
        valueD = static_cast<double>(strtof(literal.c_str(), NULL));
    }
    else
    {
        valueD = strtod(literal.c_str(), NULL);
    }
	_printChar(valueD);
	_printInt(valueD);
	_printFloat(valueD);
	_printDouble(valueD);
}

void ScalarConverter::_printImpossibleValue()
{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: impossible\n";
	std::cout << "double: impossible" <<std::endl;
}

void ScalarConverter::_printChar(double valueD)
{
	char valueC = static_cast<char>(valueD);
	if (valueD < 0 || valueD > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(valueC))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << valueC << "'" << std::endl;
}

void ScalarConverter::_printInt(double valueD)
{
	int valueI = static_cast<int>(valueD);
	std::cout << "int: " << valueI << std::endl;
}

void ScalarConverter::_printFloat(double valueD)
{
	float valueF = static_cast<float>(valueD);

	if (std::isnan(valueF))
		std::cout << "float: nanf" << std::endl;
	else if (std::isinf(valueF))
		std::cout << "float: " << (valueF > 0 ? "+inff" : "-inff") << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1)
				  << "float: " << valueF << "f" << std::endl; //??
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
