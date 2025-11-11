/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:37:39 by mosokina          #+#    #+#             */
/*   Updated: 2025/11/10 14:27:29 by mosokina         ###   ########.fr       */
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
#include <list>
#include <cstdlib>  // for strtol or atoi
#include <algorithm>
#include <cmath>

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
	{
		long temp_long = std::strtol(argv[i], NULL, 10);
		vec.push_back(static_cast<int>(temp_long));
	}
	return vec;
}


std::list<int> argsToList(int argc, char **argv)
{
	std::list<int> list;

	for (int i = 1; i < argc; i++)
	{
		long temp_long = std::strtol(argv[i], NULL, 10);
		list.push_back(static_cast<int>(temp_long));
	}
	return list;
}



size_t compTest(size_t elemNmb)
{
	size_t sum = 0;
	for (size_t k = 1; k <= elemNmb; ++k)
	{
		double value = (3.0 / 4.0) * k;
		double log_base_2 = log(value) / log(2.0);
		sum += static_cast<int>(ceil(log_base_2));
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

bool isListSorted(const std::list<int>& list)
{
	if (list.size() <= 1)
		return true;
    std::list<int>::const_iterator current = list.begin();
    std::list<int>::const_iterator previous = list.begin();
	std::advance(current, 1); 

	while (current != list.end())
	{
		if (*current < *previous)
			return false;
		previous = current;
		std::advance(current, 1);
	}
	return true;
}

void testCompNmbs(int argc)
{
	std::cout << "\033[33m" << "\nTEST: Number of comparisons" << "\033[0m"  << std::endl;
	size_t maxComp = compTest(argc - 1);
	if (maxComp >= PmergeMe::nmbCompVec)
		std::cout << "\033[32m" << "Number osf comparisons do not exceed the max limit:" << maxComp << "\n\033[0m" << std::endl;
	else
		std::cout << "\033[31m" << "Number osf comparisons EXCEEDS the max limit: " << maxComp << "\n\033[0m" << std::endl;
	if (maxComp >= PmergeMe::nmbCompVec)
		std::cout << "\033[32m" << "Number osf comparisons do not exceed the max limit:" << maxComp << "\n\033[0m" << std::endl;
	else
		std::cout << "\033[31m" << "Number osf comparisons EXCEEDS the max limit: " << maxComp << "\n\033[0m" << std::endl;
}

void testSorting(const std::vector<int>& vec, const std::list<int>& list)
{
	std::cout << "\033[33m" << "TEST: Sorting" << "\033[0m"  << std::endl;

	if (isVecSorted(vec))
		std::cout << "\033[32m" << "VECTOR IS SORTED!" << "\n\033[0m" << std::endl;
	else
		std::cout << "\033[31m" << "VECTOR IS UNSORTED!" << "\n\033[0m" << std::endl;
	if (isListSorted(list))
		std::cout << "\033[32m" << "LIST IS SORTED!" << "\n\033[0m" << std::endl;
	else
		std::cout << "\033[31m" << "LIST IS UNSORTED!" << "\n\033[0m" << std::endl;
}

/*clock() returns the processor time (CPU time) used by your program.*/

int main(int argc, char **argv)
{
	if (!validateArgs(argc, argv))
		return 1;
	std::cout << "Before:	";
	for (int i = 1; i < argc; ++i)
		std::cout << argv[i] << " ";
	std::cout << std::endl;

	PmergeMe pm;
	
	std::vector<int> vec = argsToVec(argc, argv);
	size_t vecSize = vec.size();
	
	clock_t start, end;
	double cpuTimeUsed;
	start = clock();
	std::vector<int>::iterator lastElementItVec = vec.end();
	lastElementItVec --;
	// std::cout << "TEST Last Element : " << *lastElementIt << std::endl;
	pm.mergeInsertSort(vec, lastElementItVec, 1);
	end = clock();
	cpuTimeUsed = static_cast<double>(end - start) / CLOCKS_PER_SEC;

	std::cout << "After:	";
	pm.printVector(vec);
	std::cout << "Time to process a range of " << vecSize << " elements with std::[..] : " << cpuTimeUsed << " us" << std::endl;


	std::list<int> list = argsToList(argc, argv);
	std::cout << "TEST:list BEFORE:\n";
	pm.printList(list);
	// size_t listSize = list.size();
	std::list<int>::iterator lastElementItList = list.end();
	lastElementItList--;
	pm.mergeInsertSort(list, lastElementItList, 1);



	testCompNmbs(argc);
	testSorting(vec, list);
}
