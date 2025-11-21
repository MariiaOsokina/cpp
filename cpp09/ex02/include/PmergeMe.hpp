/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:54:50 by mosokina          #+#    #+#             */
/*   Updated: 2025/11/21 12:01:54 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
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

		// --- Vector Part---
		static size_t nmbCompVec;
		typedef std::vector<int>::iterator vecIt;
	
		void mergeInsertSort(std::vector<int> &vec, vecIt &levelLastElemIt, size_t level);
		void printVector(const std::vector<int>& vec);
	
		static bool compIteratorsVec(vecIt lv, vecIt rv);

		// --- List Part---
		static size_t nmbCompList;
		typedef std::list<int>::iterator listIt;
	
		void mergeInsertSort(std::list<int> &list, listIt &levelLastElemIt, size_t level);
		void printList(const std::list<int>& list);
		
		static bool compIteratorsList(listIt lv, listIt rv);

	private:
		// --- Vector Helpers---
		void _sortPairs(std::vector<int>& vec, size_t elementsInLevel, size_t nmbsInBlock);
		std::vector<vecIt> _createMain(std::vector<int>& vec, vecIt &levelLastElemIt, size_t nmbsInBlock);	
		std::vector<vecIt> _createPend(std::vector<int>& vec, vecIt &levelLastElemIt, size_t nmbsInBlock);
		void _insertPendToMain(std::vector<vecIt>& main, std::vector<vecIt>& pend);
		void _jackNumInvertion(std::vector<vecIt>& main, std::vector<vecIt>& pend);
		void _orderedInvertion(std::vector<vecIt>& main, std::vector<vecIt>& pend);
		void _copyMainToVec(std::vector<int>& vec, std::vector<vecIt>& main, size_t nmbsInBlock);

		// --- List Helpers---
		void _sortPairs(std::list<int>& list, size_t pairsInLevel, size_t nmbsInBlock);
		std::list<listIt> _createMain(std::list<int>& list, size_t totalNmbsInLevel, size_t nmbsInBlock);	
		std::list<listIt> _createPend(std::list<int>& list, size_t totalNmbsInLevel, size_t nmbsInBlock);
		void _insertPendToMain(std::list<listIt>& main, std::list<listIt>& pend);
		void _jackNumInvertion(std::list<listIt>& main, std::list<listIt>& pend);
		void _orderedInvertion(std::list<listIt>& main, std::list<listIt>& pend);
		size_t	_binarySearchIndex(std::list<listIt>& main, int value, size_t boundPos);
		void _copyMainToList(std::list<int>& list, std::list<listIt>& main, size_t nmbsInBlock);

		// --Math Helper
		long _jacobsthalNumber(long n);
};

#endif