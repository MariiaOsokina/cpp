/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:37:39 by mosokina          #+#    #+#             */
/*   Updated: 2025/10/21 15:51:49 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <limits>
#include <cerrno>  // errno, ERANGE
#include <climits> // Needed for INT_MAX


bool isItPositiveInt(const char *str)
{
	if (!str || *str == '\0')
		return false;
	if (*str == '+' || *str == '-')
		return false;

	char *endptr;
	long temp_long_value;
	errno = 0;
	temp_long_value = strtol(str, &endptr, 10);
	if (*endptr != '\0' || endptr == str || errno == ERANGE)
		return false;
	if (temp_long_value == 0 || temp_long_value > INT_MAX)
		return false;
	return true;
}

int checkArgs(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cerr << "Error\n" << "No arguments passed" << std::endl;
		return 1;
	}
	for (int i = 1; argv[i]; i++)
	{
		const char *arg_str = argv[i];
		if (!isItPositiveInt(arg_str))
		{
			std::cerr << "Error\n" << "Should be only positive integers" << std::endl;
			return 1;
		}
	}
	return 0;
}

int main(int argc, char **argv)
{
	if (!checkArgs(argc, argv))
		return 1;
	return 0;
}
