/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:37:39 by mosokina          #+#    #+#             */
/*   Updated: 2025/11/21 12:09:21 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

#include <iostream>
#include <string>
#include <limits>
#include <cerrno>  // errno, ERANGE
#include <climits> // Needed for INT_MAX

#include <vector>
#include <list>
#include <cstdlib>  // for strtol or atoi
#include <algorithm>
#include <cmath>
#include <iomanip> // Needed for std::fixed and std::setprecision
#include <sys/time.h> // Required for gettimeofday()

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
		std::cout << "\033[32m" << "Comparisons in VECTOR is " << PmergeMe::nmbCompVec << " and do not exceed the max limit: " << maxComp << "\n\033[0m" << std::endl;
	else
		std::cout << "\033[31m" << "Comparisons in VECTOR is " << PmergeMe::nmbCompVec << " and EXCEEDS the max limit: " << maxComp << "\n\033[0m" << std::endl;
	if (maxComp >= PmergeMe::nmbCompList)
		std::cout << "\033[32m" << "Comparisons in LIST is " << PmergeMe::nmbCompList << " and do not exceed the max limit: " << maxComp << "\n\033[0m" << std::endl;
	else
		std::cout << "\033[31m" << "Comparisons in LIST is " << PmergeMe::nmbCompList << " and  EXCEEDS the max limit: " << maxComp << "\n\033[0m" << std::endl;
}

void testSorting(const std::vector<int>& vec, const std::list<int>& list)
{
	std::cout << "\033[33m" << "TEST: Sorting" << "\033[0m"  << std::endl;

	if (isVecSorted(vec))
		std::cout << "\033[32m" << "VECTOR IS SORTED!" << "\033[0m" << std::endl;
	else
		std::cout << "\033[31m" << "VECTOR IS UNSORTED!" << "\033[0m" << std::endl;
	if (isListSorted(list))
		std::cout << "\033[32m" << "LIST IS SORTED!" << "\033[0m" << std::endl;
	else
		std::cout << "\033[31m" << "LIST IS UNSORTED!" << "\033[0m" << std::endl;
}

int main(int argc, char **argv)
{
	struct timeval startVecTime, endVecTime;
	struct timeval startListTime, endListTime;

	if (!validateArgs(argc, argv))
		return 1;
	std::cout << "Before:	";
	for (int i = 1; i < argc; ++i)
		std::cout << argv[i] << " ";
	std::cout << std::endl;

	PmergeMe pm;
	
	std::cout << "\n\033[32m" << "---VECTOR---" << "\033[0m" << std::endl;
	gettimeofday(&startVecTime, NULL);

	std::vector<int> vec = argsToVec(argc, argv);
	size_t vecSize = vec.size();
	std::vector<int>::iterator lastElementItVec = vec.end();
	lastElementItVec --;
	pm.mergeInsertSort(vec, lastElementItVec, 1);

	gettimeofday(&endVecTime, NULL);

	std::cout << "After:	";
	pm.printVector(vec);


	double cpuTimeUsedVec = (endVecTime.tv_sec - startVecTime.tv_sec) * 1000000.0 + (endVecTime.tv_usec - startVecTime.tv_usec);
	std::cout << "Time to process a range of " << vecSize << " elements with std::vec : " 
			<< std::fixed << std::setprecision(5) << cpuTimeUsedVec << " us" << std::endl;

	std::cout << "\n\033[32m" << "---LIST---" << "\033[0m" << std::endl;
	gettimeofday(&startListTime, NULL);

	std::list<int> list = argsToList(argc, argv);
	size_t listSize = list.size();
	std::list<int>::iterator lastElementItList = list.end();
	lastElementItList--;
	pm.mergeInsertSort(list, lastElementItList, 1);

	gettimeofday(&endListTime, NULL);
	
	std::cout << "After:	";
	pm.printList(list);

	double cpuTimeUsedList = (endListTime.tv_sec - startListTime.tv_sec) * 1000000.0 + (endListTime.tv_usec - startListTime.tv_usec);
	std::cout << "Time to process a range of " << listSize << " elements with std::list : " 
			  << std::fixed << std::setprecision(5) << cpuTimeUsedList << " us" << std::endl;

	testCompNmbs(argc);
	testSorting(vec, list);
}
