/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:54:50 by mosokina          #+#    #+#             */
/*   Updated: 2025/10/23 13:28:23 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <algorithm>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe operator=(const PmergeMe &other);
		~PmergeMe();

		typedef std::vector<int>::iterator vecIt;
		
		void mergeInsertSort(std::vector<int> &vec, vecIt &startIt, vecIt &EndIt, size_t level);

	private:
		vecIt _next(vecIt &it, int dist);
		void _sortPairs(std::vector<int>& vec, size_t elementsInLevel, size_t nmbsInPair);
		void _storePend(std::vector<int>& vec, vecIt lPairStart, vecIt rPairStart);

		unsigned int _nmbComp;
		std::vector<int> _pendulums;
};
		// void _swapPaire(vecIt &it, int level);

#endif