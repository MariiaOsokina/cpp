/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:26:28 by mosokina          #+#    #+#             */
/*   Updated: 2025/11/21 00:40:20 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"


/*Difference between vector and list:
1.  iterator.std::vector has Random Access Iterators, which allow O(1) arithmetic like it + 5, it - 3, and comparisons like it1 < it2. 

2. std::list has Bidirectional Iterators, which only allow O(1) operations like ++it, --it, and *it (dereferencing).
Any movement by N steps must use std::advance(it, N), which is an O(N) operation.*/


size_t PmergeMe::nmbCompVec = 0;
size_t PmergeMe::nmbCompList = 0;

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
		(void)other;
	return *this;
}

PmergeMe::~PmergeMe(){}

void PmergeMe::printVector(const std::vector<int>& vec)
{
	for (size_t i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}


/*Insertion with specific order defined by the JACOBSTHAL number sequence
to optimize the number of comparisons.*/

long PmergeMe::_jacobsthalNumber(long n)
{
	double powerOfTwo = pow(2.0, n + 1);
	double powerOfNegOne = pow(-1.0, n);
	double result = (powerOfTwo + powerOfNegOne) / 3.0;
	return static_cast<long>(floor(result + 0.5));
}