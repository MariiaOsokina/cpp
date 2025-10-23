/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:37:39 by mosokina          #+#    #+#             */
/*   Updated: 2025/10/22 13:54:07 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
// #include <string>
#include <limits>
#include <cerrno>  // errno, ERANGE
#include <climits> // Needed for INT_MAX
#include <ctime> // for clock()
#include <vector>
#include <cstdlib>  // for strtol or atoi


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

bool validateArgs(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cerr << "Error\n" << "No arguments passed" << std::endl;
		return false;
	}
	for (int i = 1; i < argc; i++)
	{
		const char *arg_str = argv[i];
		if (!isItPositiveInt(arg_str))
		{
			std::cerr << "Error\n" << "Should be only positive integers" << std::endl;
			return false;
		}
	}
	return true;
}

std::vector<int> argsToVec(int argc, char **argv)
{
	std::vector<int> vec;

	for (int i = 1; i < argc; i++)
        vec.push_back(std::atoi(argv[i]));
		
	return vec;
}

/*clock() returns the processor time (CPU time) used by your program.*/

int main(int argc, char **argv)
{
	if (!validateArgs(argc, argv))
		return 1;
	std::vector<int> vec = argsToVec(argc, argv);
	
    clock_t start, end;
    double cpuTimeUsed;
    start = clock();
	
	end = clock();
	cpuTimeUsed = static_cast<double>(end - start) / CLOCKS_PER_SEC;

	std::cout << cpuTimeUsed << std::endl;

	return 0;
}
