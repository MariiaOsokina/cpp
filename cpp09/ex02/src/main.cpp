/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:37:39 by mosokina          #+#    #+#             */
/*   Updated: 2025/11/05 16:56:02 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

#include <iostream>
#include <string>
#include <limits>
#include <cerrno>  // errno, ERANGE
#include <climits> // Needed for INT_MAX
#include <ctime> // for clock()
#include <vector>
#include <cstdlib>  // for strtol or atoi
#include <algorithm>

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
	// if (temp_long_value == 0 || temp_long_value > INT_MAX) // without 0
	if (temp_long_value > INT_MAX)
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

size_t compTest(size_t elemNmb)
{
	size_t sum = 0;
	for (size_t k = 1; k <= elemNmb; ++k)
	{
		double value = (3.0 / 4.0) * k;
		sum += static_cast<int>(ceil(log2(value)));
	}
	return sum;
}

bool isVecSorted(const std::vector<int>& vec)
{
	if (vec.size() <= 1)
		return true;
	for (size_t i = 1; i < vec.size(); ++i)
	{
		if (vec[i] < vec[i - 1])
			return false;
	}
	return true;
}

void additionalTests(const std::vector<int>& vec, size_t vecSize)
{
	std::cout << "\033[33m" << "\nTEST 1: Number of comparisons" << "\033[0m"  << std::endl;
	size_t maxComp = compTest(vecSize);
	if (maxComp >= PmergeMe::nmbComp)
		std::cout << "\033[32m" << "Number osf comparisons do not exceed the max limit:" << compTest(vecSize) << "\n\033[0m" << std::endl;
	else
		std::cout << "\033[31m" << "Number osf comparisons EXCEEDS the max limit: " << compTest(vecSize) << "\n\033[0m" << std::endl;

	std::cout << "\033[33m" << "TEST 2: Sorting" << "\033[0m"  << std::endl;

	if (isVecSorted(vec))
		std::cout << "\033[32m" << "VECTOR IS SORTED!" << "\n\033[0m" << std::endl;
	else
		std::cout << "\033[31m" << "VECTOR IS UNSORTED!" << "\n\033[0m" << std::endl;
}


/*clock() returns the processor time (CPU time) used by your program.*/

int main(int argc, char **argv)
{
	if (!validateArgs(argc, argv))
		return 1;
	std::vector<int> vec = argsToVec(argc, argv);
	
	PmergeMe pm;
	// PmergeMe::nmbComp = 0;

	std::cout << "Before:	";
	pm.printVector(vec);
	size_t vecSize = vec.size();

	clock_t start, end;
	double cpuTimeUsed;
	start = clock();


	std::vector<int>::iterator lastElementIt = vec.end();
	lastElementIt --;
	// std::cout << "TEST Last Element : " << *lastElementIt << std::endl;

	pm.mergeInsertSort(vec, lastElementIt, 1);
	// size_t vecNmbComp =  pm.getNmbComp();

	end = clock();
	cpuTimeUsed = static_cast<double>(end - start) / CLOCKS_PER_SEC;

	std::cout << "After:	";
	pm.printVector(vec);
	std::cout << "Time to process a range of " << vecSize << " elements with std::[..] : " << cpuTimeUsed << " us" << std::endl;
	
	additionalTests(vec, vecSize);
}
