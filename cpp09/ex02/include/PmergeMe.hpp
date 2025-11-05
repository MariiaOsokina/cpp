/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:54:50 by mosokina          #+#    #+#             */
/*   Updated: 2025/11/05 16:41:08 by mosokina         ###   ########.fr       */
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
		
		void mergeInsertSort(std::vector<int> &vec, vecIt &levelLastElemIt, size_t level);

		void printVector(const std::vector<int>& vec);
		// void printItVector(const std::vector<vecIt>& vec);

		static bool compIetrators(vecIt lv, vecIt rv);
		static size_t nmbComp;


	private:
		void _sortPairs(std::vector<int>& vec, size_t elementsInLevel, size_t nmbsInBlock);
		std::vector<vecIt> _createMain(std::vector<int>& vec, vecIt &levelLastElemIt, size_t nmbsInBlock);	
		std::vector<vecIt> _createPend(std::vector<int>& vec, vecIt &levelLastElemIt, size_t nmbsInBlock);
		void _insertPendToMain(std::vector<vecIt>& main, std::vector<vecIt>& pend);
		long _jacobsthalNumber(long n);
		void _jackNumInvertion(std::vector<vecIt>& main, std::vector<vecIt>& pend);
		void _orderedInvertion(std::vector<vecIt>& main, std::vector<vecIt>& pend);
		void _copyMainToVec(std::vector<int>& vec, std::vector<vecIt>& main, size_t nmbsInBlock);
};

#endif