/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVec.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:36:28 by mosokina          #+#    #+#             */
/*   Updated: 2025/11/21 01:04:07 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

void printItVector(const std::vector<std::vector<int>::iterator>& vec)
{
	std::cout << "[";
	for (size_t i = 0; i < vec.size(); ++i) {
		std::cout << *(vec[i]) << " ";
	}
	std::cout << "]" << std::endl;
}

void PmergeMe::_sortPairs(std::vector<int>& vec, size_t pairsInLevel, size_t nmbsInBlock)
{
	vecIt rBlockStart, lBlockEnd, rBlockEnd;
	vecIt lBlockStart = vec.begin();

	for (size_t i = 0; i < pairsInLevel; i++)
	{
		rBlockStart = lBlockStart + nmbsInBlock;
		lBlockEnd = lBlockStart + (nmbsInBlock - 1);
		rBlockEnd = rBlockStart + (nmbsInBlock - 1);
		
		PmergeMe::nmbCompVec++;

		if (*lBlockEnd > *rBlockEnd) // Comparison and Swap
		{
			vecIt leftMover = lBlockStart;
			vecIt rightMover = rBlockStart;
			for (size_t j = 0; j < nmbsInBlock; j++)
			{
				std::iter_swap(leftMover, rightMover);
				leftMover++;
				rightMover++;
			}
		}
		lBlockStart = lBlockStart + (nmbsInBlock * 2); //to the next element block
	}
}

/*PmergeMe::_createPend: Populates pend with iterators to the last element of L2, L3, L4...*/
std::vector<std::vector<int>::iterator> PmergeMe::_createPend(std::vector<int>& vec, vecIt &levelLastElemIt, size_t nmbsInBlock)
{
	std::vector<vecIt> pend;
	vecIt startIt  = vec.begin();
	vecIt lBlockStart = startIt + (nmbsInBlock * 2);
	vecIt lBlockLast = lBlockStart + (nmbsInBlock - 1);

	while (lBlockStart < levelLastElemIt) // while (rBlockLast < levelLastElemIt)??
	{
		// pend.insert(pend.end(), lBlockLast);
		pend.push_back(lBlockLast);
		std::advance(lBlockStart, nmbsInBlock * 2); // move to next element
		std::advance(lBlockLast, nmbsInBlock * 2); // move to next element
	}
	return pend;
}

/*Populates main with iterators to the last element of L1, R1, R2, R3...*/
std::vector<std::vector<int>::iterator> PmergeMe::_createMain(std::vector<int>& vec, vecIt &levelLastElemIt, size_t nmbsInBlock)
{
	std::vector<vecIt> main;

	// L1 Last
	vecIt startIt  = vec.begin();
	main.push_back(startIt + (nmbsInBlock - 1));

	// R1 Last
	main.push_back(startIt + (nmbsInBlock * 2 - 1));	
	vecIt rBlockStart = startIt + (nmbsInBlock * 3);
	vecIt rBlockLast = rBlockStart + (nmbsInBlock - 1);

	// Adding R2, R3, R4...
	while (rBlockStart < levelLastElemIt) // while (rBlockLast < levelLastElemIt)
	{
		main.push_back(rBlockLast);
		std::advance(rBlockStart, nmbsInBlock * 2); // move to next element
		std::advance(rBlockLast, nmbsInBlock * 2); // move to next element
	}
	return main;
}

/*std::upper_bound performs a BINARY SEARCH on a sorted or 
partially ordered range to find the "UPPER BOUND" of a value in a range.
It returns an iterator pointing to the first element in the range [first, last)
whose value is greater than the specified search value.*/
bool PmergeMe::compIteratorsVec(vecIt lv, vecIt rv)
{
	PmergeMe::nmbCompVec++;
	return *lv < *rv;
}


// Vector: Uses $O(1)$ random access arithmetic to find iterators
// Vector: std::upper_bound is $O(\log N)$ comparisons and O(\log N) iterator movements.
void PmergeMe::_jackNumInvertion(std::vector<vecIt>& main, std::vector<vecIt>& pend)
{
	int prevJN = 1; // 1
	int insertedCount = 0;
	for (size_t k = 2;; k++)
	{
		int currJN = _jacobsthalNumber(k);

		int jackDiff =  currJN - prevJN;
		int offset = 0;
		if (jackDiff > static_cast<int>(pend.size()))
			break ;
		
		std::vector<vecIt>::iterator pendIt = pend.begin() + (jackDiff - 1);
		std::vector<vecIt>::iterator boundIt = main.begin() + (currJN + insertedCount);

		for (size_t i = jackDiff; i > 0; --i)
		{
			std::vector<vecIt>::iterator idxToInsert = std::upper_bound(main.begin(), boundIt, *pendIt, compIteratorsVec);
		
			std::vector<vecIt>::iterator inserted = main.insert(idxToInsert, *pendIt);
			pendIt = pend.erase(pendIt);
			pendIt --;
			if (inserted - main.begin() == currJN + insertedCount)
					offset ++;
			boundIt = main.begin() + (currJN + insertedCount - offset);
			
		}
		prevJN = currJN;
		insertedCount += jackDiff;
	}
}

void PmergeMe::_orderedInvertion(std::vector<vecIt>& main, std::vector<vecIt>& pend)
{
	if (pend.empty())
		return ;

	for (int i = pend.size() - 1; i >= 0; i--)
	{
		std::vector<vecIt>::iterator pendIt = pend.begin() + i;

		std::vector<vecIt>::iterator boundIt =
			main.begin() + (static_cast<int>(main.size()) - static_cast<int>(pend.size()) + i + 1); 
		// Use a safe upper bound (cannot exceed main.end())
		if (boundIt > main.end())
			 boundIt = main.end();

		std::vector<vecIt>::iterator idxToInsert =
			std::upper_bound(main.begin(), boundIt, *pendIt, compIteratorsVec);
		main.insert(idxToInsert, *pendIt);
	}
}

void PmergeMe::_insertPendToMain(std::vector<vecIt>& main, std::vector<vecIt>& pend)
{
	if (pend.empty())
		return ;
	_jackNumInvertion(main, pend);
	_orderedInvertion(main, pend);

}

void PmergeMe::_copyMainToVec(std::vector<int>& vec, std::vector<vecIt>& main, size_t nmbsInBlock)
{
	std::vector<int> tmpVec;
	tmpVec.reserve(vec.size());
	// 1. Create the temporary list with sorted values
	for (size_t i = 0; i < static_cast<size_t>(main.size()); i ++)
	{
		std::vector<vecIt>::iterator itFromMain = main.begin() + i;

		vecIt itInBlock = *itFromMain - (nmbsInBlock - 1);
		for (size_t j = 0; j < nmbsInBlock; j++) //copy numbers in Block
		{
			tmpVec.insert(tmpVec.end(), *itInBlock);
			itInBlock ++;
		}
	}
	std::copy(tmpVec.begin(), tmpVec.end(), vec.begin());	
}

void PmergeMe::mergeInsertSort(std::vector<int> &vec, vecIt &levelLastElemIt, size_t level)
{
	vecIt startIt  = vec.begin();

	size_t totalNmbsInLevel = levelLastElemIt - startIt + 1;
	if (totalNmbsInLevel <= 1) //empty or one nbr
		return ;

	size_t nmbsInPair = 1 << level; //2 , 4, 8, 16, 32, ... 
	if (nmbsInPair > totalNmbsInLevel)
		return ;
	size_t nmbsInBlock = nmbsInPair / 2;
	size_t pairsInLevel = totalNmbsInLevel / nmbsInPair;
	_sortPairs(vec, pairsInLevel, nmbsInBlock);

	vecIt newLevelEndIt = startIt + (pairsInLevel * nmbsInPair - 1);
	mergeInsertSort(vec, newLevelEndIt, level + 1); ////sort recursion
	

	std::vector<std::vector<int>::iterator> main = _createMain(vec, levelLastElemIt, nmbsInBlock);
	std::vector<std::vector<int>::iterator> pend = _createPend(vec, levelLastElemIt, nmbsInBlock);
	
	if (level == 1 && vec.size() % 2 != 0) // the last odd element
		pend.push_back(levelLastElemIt);

	_insertPendToMain(main, pend);

	
	_copyMainToVec(vec, main, nmbsInBlock);
}

