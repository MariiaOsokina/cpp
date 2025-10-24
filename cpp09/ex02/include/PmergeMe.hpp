/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:54:50 by mosokina          #+#    #+#             */
/*   Updated: 2025/10/24 15:19:25 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe operator=(const PmergeMe &other);
		~PmergeMe();

		typedef std::vector<int>::iterator vecIt;
		
		void mergeInsertSort(std::vector<int> &vec, vecIt &levelEndIt, size_t level);
		size_t getNmbComp() const;

		void printVector(const std::vector<int>& vec);
		std::vector<size_t> generateJacobsthalIndices(size_t maxPendSize);

	private:
		// vecIt _next(vecIt &it, int dist);
		void _sortPairs(std::vector<int>& vec, size_t elementsInLevel, size_t nmbsInBlock);
		void _storePend(std::vector<int>& vec, vecIt lBlockStart, vecIt rBlockStart);
		std::vector<int> _createMain(std::vector<int>& vec, vecIt &levelEndIt, size_t nmbsInBlock);
		std::vector<int> _createPend(std::vector<int>& vec, vecIt &levelEndIt, size_t nmbsInBlock);
		void _invertPendToMain(std::vector<int>& main, std::vector<int>& pend);
		void _copyMainToVec(std::vector<int>& vec, std::vector<int>& main, size_t nmbsInBlock);
		std::vector<size_t> generateJacobsthalIndices(size_t maxPendSize);


		size_t _nmbComp;
		std::vector<int> _pendulums;
		std::vector<size_t> _jacobsthalIndices;
};

#endif