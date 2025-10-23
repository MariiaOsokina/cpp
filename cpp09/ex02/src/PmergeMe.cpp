/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:26:28 by mosokina          #+#    #+#             */
/*   Updated: 2025/10/23 21:46:15 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

PmergeMe::vecIt PmergeMe::_next(vecIt &it, int dist)
{
	vecIt newIt(it);
	std::advance(newIt, dist);
	return newIt;
}

void PmergeMe::_sortPairs(std::vector<int>& vec, size_t elementsInLevel, size_t nmbsInPair)
{
	vecIt lPairStart = vec.begin();
	vecIt rPairStart, lPairEnd, rPairEnd;

	for (int i = 0; i < elementsInLevel; i++)
	{
		rPairStart = _next(lPairStart, nmbsInPair);
		lPairEnd = _next(lPairStart, nmbsInPair - 1);
		rPairEnd = _next(rPairStart, nmbsInPair - 1);

		if (*lPairEnd > *rPairEnd) // Comparison and Swap
		{
			_nmbComp++;
			vecIt leftMover = lPairStart;
			vecIt rightMover = rPairStart;
			for (int j = 0; j < nmbsInPair; j++)

			{
				std::iter_swap(leftMover, rightMover);
				leftMover++;
				rightMover++;
			}
		}
		lPairStart = _next(lPairStart, nmbsInPair * 2); //to the next element block
	}
}

void PmergeMe::_storePend(std::vector<int>& pend, vecIt PairStart, vecIt PairEnd)
{
	std::copy(pendStart, pendEnd,  std::back_inserter(pend));
}

	// vecIt totalElementsEnd = _next(startIt, pairsInLevel * nmbsInPair);//???

	// std::vector<int> tempPend();
	// bool isOdd = false;
	// if (nmbsToBeSorted % nmbsInElement != 0) //if odd pair
	// 	isOdd = true;
	// if (isOdd)
	// {
	// 	vecIt totalPairesEnd = _next(startIt, pairsInLevel * nmbsInPair);//???
	// 	std::copy(totalElementsEnd + 1, pendEnd,  std::back_inserter(tempPend));
	// }



// 1. Pairing and Block-Swapping Phase 
//    - Identify winners (Main Chain) and losers (Pendulums)

// 2. Separate them (Conceptual)
//    - Store Pendulums in a temporary container (T)
//    - The Main Chain (M) is now contiguous at the front of vec

// 3. Recursive Sort
//mergeInsertSort(vec, end_of_main_chain_iterator, level + 1);

// 4. Insertion Phase
//    - Insert the elements from T into the sorted M using binary search in Jacobsthal order.

void PmergeMe::mergeInsertSort(std::vector<int> &vec, vecIt &startIt, vecIt &EndIt, size_t level)
{
	size_t totalNmbsInLevel = EndIt - startIt;
	if (totalNmbsInLevel <= 1) //empty or  one element
		return;

	size_t nextNmbsInElement = 1 << (level + 1);
    if (nextNmbsInElement > totalNmbsInLevel)
		return;

	size_t nmbsInElement = 1 << level; //2 , 4, 8, 16, 32, 
	size_t nmbsInPair = nmbsInElement / 2;
	size_t elementsInLevel = totalNmbsInLevel / nmbsInElement;
	size_t pairsInLevel = totalNmbsInLevel / nmbsInPair;

	_sortPairs(vec, elementsInLevel, nmbsInPair);

	vecIt newEndIt = _next(startIt, (pairsInLevel * nmbsInPair));
	if (elementsInLevel > 2)
		mergeInsertSort(vec, startIt, newEndIt, level + 1); ////sort recursion
	
	// vecIt mainChainEnd = _next(startIt, (pairsInLevel * nmbsInPair));
	//continue insertion //
}

// void PmergeMe::_storeTempPend(std::vector<int>& pend, vecIt PairStart, vecIt PairEnd)
// {
// 	std::copy(pendStart, pendEnd,  std::back_inserter(pend));
// }

