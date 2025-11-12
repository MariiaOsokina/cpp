/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:54:50 by mosokina          #+#    #+#             */
/*   Updated: 2025/11/12 14:38:50 by mosokina         ###   ########.fr       */
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

		typedef std::vector<int>::iterator vecIt;
		void mergeInsertSort(std::vector<int> &vec, vecIt &levelLastElemIt, size_t level);
		void printVector(const std::vector<int>& vec);
		// void printItVector(const std::vector<vecIt>& vec);
		static bool compIetrators(vecIt lv, vecIt rv);
		static size_t nmbCompVec;
		
		typedef std::list<int>::iterator listIt;
		void mergeInsertSort(std::list<int> &list, listIt &levelLastElemIt, size_t level);
		void printList(const std::list<int>& list);

		static bool compIetrators(listIt lv, listIt rv);
		static size_t nmbCompList;

	private:
		void _sortPairs(std::vector<int>& vec, size_t elementsInLevel, size_t nmbsInBlock);
		std::vector<vecIt> _createMain(std::vector<int>& vec, vecIt &levelLastElemIt, size_t nmbsInBlock);	
		std::vector<vecIt> _createPend(std::vector<int>& vec, vecIt &levelLastElemIt, size_t nmbsInBlock);
		void _insertPendToMain(std::vector<vecIt>& main, std::vector<vecIt>& pend);
		void _jackNumInvertion(std::vector<vecIt>& main, std::vector<vecIt>& pend);
		void _orderedInvertion(std::vector<vecIt>& main, std::vector<vecIt>& pend);
		void _copyMainToVec(std::vector<int>& vec, std::vector<vecIt>& main, size_t nmbsInBlock);

		void _sortPairs(std::list<int>& list, size_t pairsInLevel, size_t nmbsInBlock);
		std::list<listIt> _createMain(std::list<int>& list, size_t pairsInLevel, size_t nmbsInBlock);	
		// std::list<listIt> _createPend(std::list<int>& list, listIt &levelLastElemIt, size_t nmbsInBlock);
		// void _insertPendToMain(std::list<vecIt>& main, std::list<vecIt>& pend);
		// void _jackNumInvertion(std::list<listIt>& main, std::list<listIt>& pend);
		// void _orderedInvertion(std::list<listIt>& main, std::list<listIt>& pend);
		// void _copyMainToVec(std::list<int>& list, std::list<listIt>& main, size_t nmbsInBlock);
		
		long _jacobsthalNumber(long n);
};

#endif