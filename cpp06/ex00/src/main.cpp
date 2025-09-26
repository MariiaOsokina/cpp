/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:16:27 by mosokina          #+#    #+#             */
/*   Updated: 2025/09/26 14:24:51 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

void test()
{
	std::string tests[] = {
		"'a'", "'Z'", "' '", "'\\'", "42", "-42", "0",
		"42.0", "42.", ".42", "42.0f", "0.0f", "42.f",
		"42f", "42.0fx", "nan", "nanf", "+inf", "-inf",
		"+inff", "-inff", "abc", "12.34.56", "''"
	};

	for (size_t i = 0; i < sizeof(tests)/sizeof(tests[0]); ++i)
	{
		ScalarConverter::convert(tests[i]);
	}
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Please write only one parameter: char, int, float or double. \n";
		std::cout << "You can write \"test\" run built-in tests." << std::endl;
		return 1;
	}
	if (std::string(argv[1]) == "test")
		test();
	else
		ScalarConverter::convert(argv[1]);
	return 0;
}
