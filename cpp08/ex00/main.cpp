/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:40:20 by mosokina          #+#    #+#             */
/*   Updated: 2025/10/08 22:24:52 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>   // for std::find
#include <vector>
#include <list>
#include <iostream>

#include "easyfind.hpp"

template <typename T>
void testContainer(T& container, const int testInt)
{
	try
	{
		std::cout << "Integer for test: " << testInt << std::endl;
		easyfind(container, testInt);
		std::cerr << "Integer found" << std::endl;

	}
	catch(const std::runtime_error &e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
}

void testVectors()
{    
	std::cout << "\n\033[33m" << "Test1: with vectors" << "\033[0m" << std::endl;
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(20);
	vec.push_back(4);
	vec.push_back(10);

	std::cout << "Vector contents: ";

	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << " " << *it;
	}
	std::cout << std::endl;
	testContainer(vec, 3);
	testContainer(vec, 4);
}

void testLists()
{    
	std::cout << "\n\033[33m" << "Test2: with lists" << "\033[0m" << std::endl;
	std::list<int> testList;
	testList.push_back(1);
	testList.push_back(2);
	testList.push_back(20);
	testList.push_back(4);
	testList.push_back(10);

	std::cout << "List contents: ";

	for (std::list<int>::iterator it = testList.begin(); it != testList.end(); ++it)
	{
		std::cout << " " << *it;
	}
	std::cout << std::endl;
	testContainer(testList, 3);
	testContainer(testList, 4);
}

int main (void)
{
	testVectors();
	testLists();
	return 0;
}
