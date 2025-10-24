/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:26:28 by mosokina          #+#    #+#             */
/*   Updated: 2025/10/24 14:45:22 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

// PmergeMe::vecIt PmergeMe::_next(vecIt &it, int dist)
// {
// 	vecIt newIt(it);
// 	std::advance(newIt, dist);
// 	return newIt;
// }

void PmergeMe::printVector(const std::vector<int>& vec)
{
	std::cout << "[";
	// Using index access:
	for (size_t i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << " ";
	}
	std::cout << "]" << std::endl;
}

size_t PmergeMe::getNmbComp() const
{
	return (this->_nmbComp);
}

void PmergeMe::_sortPairs(std::vector<int>& vec, size_t pairsInLevel, size_t nmbsInBlock) //?
{
	vecIt lBlockStart = vec.begin();
	vecIt rBlockStart, lBlockEnd, rBlockEnd;

	for (int i = 0; i < pairsInLevel; i++)
	{
		rBlockStart = lBlockStart + nmbsInBlock;
		lBlockEnd = lBlockStart + (nmbsInBlock - 1);
		rBlockEnd = rBlockStart + (nmbsInBlock - 1);

		if (*lBlockEnd > *rBlockEnd) // Comparison and Swap
		{
			_nmbComp++;
			vecIt leftMover = lBlockStart;
			vecIt rightMover = rBlockStart;
			for (int j = 0; j < nmbsInBlock; j++)
			{
				std::iter_swap(leftMover, rightMover);
				leftMover++;
				rightMover++;
			}
		}
		lBlockStart = lBlockStart + (nmbsInBlock * 2); //to the next element block
	}
}

std::vector<int> PmergeMe::_createPend(std::vector<int>& vec, vecIt &levelEndIt, size_t nmbsInBlock)
{
	std::vector<int> pend;
	
	vecIt startIt  = vec.begin();
	vecIt lBlockStart = startIt + (nmbsInBlock * 2);
	vecIt lBlockEnd = lBlockStart + nmbsInBlock;
	while (lBlockStart < levelEndIt)
	{
		std::copy(lBlockStart, lBlockEnd, std::back_inserter(pend));// copy leftPair;
		std::advance(lBlockStart, nmbsInBlock * 2); // move to next element
		std::advance(lBlockEnd, nmbsInBlock * 2); // move to next element
	}
	
	return pend;
}

std::vector<int> PmergeMe::_createMain(std::vector<int>& vec, vecIt &levelEndIt, size_t nmbsInBlock)
{
	std::vector<int> main;
	
	vecIt startIt  = vec.begin();
	vecIt firstPairEndIt  = startIt + (nmbsInBlock * 2);
	std::copy(startIt, firstPairEndIt, std::back_inserter(main));// fisrt pair;


	vecIt rBlockStart = firstPairEndIt + nmbsInBlock;
	vecIt rBlockEnd = rBlockStart + nmbsInBlock;
	while (rBlockStart < levelEndIt) //while (rBlockStart + nmbsInBlock <= levelEndIt)??
	{
		std::copy(rBlockStart, rBlockEnd, std::back_inserter(main));// copy rightPair;
		std::advance(rBlockStart, nmbsInBlock * 2); // move to next element
		std::advance(rBlockEnd, nmbsInBlock * 2); // move to next element
	}
	return main;
}

/*Insertion with specific order defined by the JACOBSTHAL number sequence
to optimize the number of comparisons.*/

void PmergeMe::_invertPendToMain(std::vector<int>& main, std::vector<int>& pend)
{
	//to be added;
}

void PmergeMe::_copyMainToVec(std::vector<int>& vec, std::vector<int>& main, size_t totalNmbsInLevel)
{
	
	vecIt mainStartIt  = main.begin();
	vecIt mainEndIt  = mainStartIt + totalNmbsInLevel;
	std::copy(mainStartIt, mainEndIt, vec.begin());
}

void PmergeMe::mergeInsertSort(std::vector<int> &vec, vecIt &levelEndIt, size_t level)
{
	vecIt startIt  = vec.begin();
	
	size_t totalNmbsInLevel = levelEndIt - startIt; //?? +1
	if (totalNmbsInLevel <= 1) //empty or  one nbr
		return;

	size_t nmbsInPair = 1 << level; //2 , 4, 8, 16, 32, 

	if (nmbsInPair > totalNmbsInLevel)
		return;

	size_t nmbsInBlock = nmbsInPair / 2;
	size_t pairsInLevel = totalNmbsInLevel / nmbsInPair;

	_sortPairs(vec, pairsInLevel, nmbsInBlock);

	vecIt newLevelEndIt = startIt + (pairsInLevel * nmbsInPair);
	mergeInsertSort(vec, newLevelEndIt, level + 1); ////sort recursion
	std::vector<int> pend = _createPend(vec, levelEndIt, nmbsInBlock);
	std::vector<int> main = _createMain(vec, levelEndIt, nmbsInBlock);
	_invertPendToMain(main, pend);
	_copyMainToVec(vec, main, totalNmbsInLevel);
}
