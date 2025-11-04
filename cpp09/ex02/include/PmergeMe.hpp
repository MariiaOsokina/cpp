/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:54:50 by mosokina          #+#    #+#             */
/*   Updated: 2025/11/04 11:36:15 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <cstddef> //for size_t 
#include <cmath>
class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe& operator=(const PmergeMe &other);
		~PmergeMe();

		typedef std::vector<int>::iterator vecIt;
		// typedef std::vector<vecIt>::iterator vecItIt;
		
		void mergeInsertSort(std::vector<int> &vec, vecIt &levelLastElemIt, size_t level);
		size_t getNmbComp() const;

		void printVector(const std::vector<int>& vec);
		void printItVector(const std::vector<vecIt>& vec);

	private:
		// vecIt _next(vecIt &it, int dist);
		std::vector<vecIt>::iterator _next(std::vector<vecIt>::iterator it, int dist);
		void _sortPairs(std::vector<int>& vec, size_t elementsInLevel, size_t nmbsInBlock);
		void _storePend(std::vector<int>& vec, vecIt lBlockStart, vecIt rBlockStart);
		// std::vector<int> _createMain(std::vector<int>& vec, vecIt &levelLastElemIt, size_t nmbsInBlock);
		std::vector<vecIt> _createMain(std::vector<int>& vec, vecIt &levelLastElemIt, size_t nmbsInBlock);
		// std::vector<int> _createPend(std::vector<int>& vec, vecIt &levelLastElemIt, size_t nmbsInBlock);
	
		std::vector<vecIt> _createPend(std::vector<int>& vec, vecIt &levelLastElemIt, size_t nmbsInBlock);
		void _insertPendToMain(std::vector<vecIt>& main, std::vector<vecIt>& pend);
		void _jackNumInvertion(std::vector<vecIt>& main, std::vector<vecIt>& pend);
		void _orderedInvertion(std::vector<vecIt>& main, std::vector<vecIt>& pend);

		void _copyMainToVec(std::vector<int>& vec, std::vector<vecIt>& main, size_t nmbsInBlock);
		long _jacobsthalNumber(long n);

		static bool _comp(vecIt lv, vecIt rv); //??static

		size_t _nmbComp;
		std::vector<int> _pendulums;
};

#endif