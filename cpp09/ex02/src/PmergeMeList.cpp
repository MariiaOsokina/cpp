/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeList.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:34:39 by mosokina          #+#    #+#             */
/*   Updated: 2025/11/21 12:23:12 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

// void printListIter(const std::list<std::list<int>::iterator>& itList)
// {
// 	std::list<std::list<int>::iterator>::const_iterator it = itList.begin();
// 	while (it != itList.end())
// 	{
// 		std::cout << *(*it) << " ";
// 		it++;
// 	}
// 	std::cout << std::endl;
// }

void PmergeMe::_sortPairs(std::list<int>& list, size_t pairsInLevel, size_t nmbsInBlock)
{
	listIt lBlockStart, rBlockStart, lBlockEnd, rBlockEnd;
	listIt currentPos = list.begin();

	for (size_t i = 0; i < pairsInLevel; i++)
	{
		lBlockStart = currentPos;
		rBlockStart = lBlockStart;
		std::advance(rBlockStart, nmbsInBlock);
		lBlockEnd = lBlockStart;
		std::advance(lBlockEnd, nmbsInBlock - 1);
		rBlockEnd = rBlockStart;
		std::advance(rBlockEnd, (nmbsInBlock - 1));

		PmergeMe::nmbCompList++;
		
		if (*lBlockEnd > *rBlockEnd) // Comparison and Swap
		{
			listIt leftMover = lBlockStart;
			listIt rightMover = rBlockStart;
			for (size_t j = 0; j < nmbsInBlock; j++)
			{
				std::iter_swap(leftMover, rightMover);
				leftMover++;
				rightMover++;
			}
		}
		currentPos = rBlockEnd;
		currentPos++; 
	}
}

/*PmergeMe::_createPend: Populates pend with iterators to the last element of L2, L3, L4...*/
std::list<std::list<int>::iterator> PmergeMe::_createPend(std::list<int>& list, size_t totalNmbsInLevel, size_t nmbsInBlock)
{
	std::list<listIt> pend;

	listIt lBlockStart = list.begin();
	std::advance(lBlockStart, nmbsInBlock * 2); //  L2 Start
	size_t lBlockStartIndex = nmbsInBlock * 2;
	while (lBlockStartIndex < totalNmbsInLevel)
	{
		listIt lBlockLast = lBlockStart;
		std::advance(lBlockLast, nmbsInBlock - 1); // Li Last
		pend.push_back(lBlockLast);
		std::advance(lBlockStart, nmbsInBlock *2); //L_i+1 Start
		lBlockStartIndex += nmbsInBlock * 2;
	}
	return pend;
}

/*Populates main with iterators to the last element of L1, R1, R2, R3...*/
std::list<std::list<int>::iterator> PmergeMe::_createMain(std::list<int>& list, size_t totalNmbsInLevel, size_t nmbsInBlock)
{
	std::list<listIt> main;

	// L1 Last
	listIt startIt  = list.begin();
	listIt lBlockLast = startIt;
	std::advance(lBlockLast, nmbsInBlock - 1);
	main.push_back(lBlockLast); 

	// R1 Last
	listIt r1BlockLast = lBlockLast;
	std::advance(r1BlockLast, nmbsInBlock);
	main.push_back(r1BlockLast);

	//R2 Start and R2 Last
	size_t rBlockStartIndex = nmbsInBlock * 3; // index of R2
	listIt rBlockStart = list.begin();
	std::advance(rBlockStart, nmbsInBlock * 3); //  R2 Start
	listIt rBlockLast = rBlockStart;
	std::advance(rBlockLast, (nmbsInBlock - 1)); //  R2 Last
	// Adding R2, R3, R4...
	while (rBlockStartIndex < totalNmbsInLevel)
	{
		main.push_back(rBlockLast);
		std::advance(rBlockStart, nmbsInBlock * 2); // move to next element
		std::advance(rBlockLast, nmbsInBlock * 2);
		rBlockStartIndex += nmbsInBlock * 2;

	}
	return main;
}

bool PmergeMe::compIteratorsList(listIt lv, listIt rv)
{
	PmergeMe::nmbCompList++;
	return *lv < *rv;
}

void PmergeMe::_jackNumInvertion(std::list<listIt>& main, std::list<listIt>& pend)
{
	int prevJN = 1;
	int insertedCount = 0;
	
	for (size_t k = 2;; k++)
	{
		int currJN = _jacobsthalNumber(k);
		int jackDiff = currJN - prevJN;
		
		if (jackDiff > static_cast<int>(pend.size()))
			break;

		std::list<listIt>::iterator pendIt = pend.begin();
		std::advance(pendIt, (jackDiff - 1));
		
		int offset = 0;

		for (size_t i = jackDiff; i > 0; --i)
		{
			size_t boundPos = currJN + insertedCount - offset;
			if (boundPos > main.size()) 
				boundPos = main.size();

			size_t idxToInsert = _binarySearchIndex(main, *(*pendIt), boundPos);
			std::list<listIt>::iterator iterToInsert = main.begin();
			std::advance(iterToInsert, idxToInsert);
	
			std::list<listIt>::iterator inserted = main.insert(iterToInsert, *pendIt);

			long insertedIdx = std::distance(main.begin(), inserted);
			
			if (insertedIdx == (currJN + insertedCount))
			{
				offset++;
			}
			pendIt = pend.erase(pendIt);
			pendIt--;
		}
		
		prevJN = currJN;
		insertedCount += jackDiff;
	}
}

void PmergeMe::_orderedInvertion(std::list<listIt>& main, std::list<listIt>& pend)
{
	if (pend.empty())
		return;

	std::list<listIt>::iterator pendIt = pend.end();
	pendIt--; 

	for (int i = pend.size() - 1; i >= 0; i--)
	{
		size_t boundPos = main.size() - pend.size() + i + 1;
		
		if (boundPos > main.size())
			boundPos = main.size();

		size_t idxToInsert = _binarySearchIndex(main, *(*pendIt), boundPos);

		std::list<listIt>::iterator iterToInsert = main.begin();
		std::advance(iterToInsert, idxToInsert);

		main.insert(iterToInsert, *pendIt);
		
		if (i > 0)
			 pendIt--;
	}	
	pend.clear();
}

size_t PmergeMe::_binarySearchIndex(std::list<listIt>& main, int value, size_t boundPos)
{
	size_t len = boundPos;
	size_t idx = 0;
	std::list<listIt>::iterator current = main.begin();

	while (len > 0)
	{
		size_t half = len / 2;
		std::list<listIt>::iterator middle = current;
		std::advance(middle, half);

		PmergeMe::nmbCompList++;
		
		if (value < *(*middle))
		{
			len = half;
		}
		else
		{
			current = middle;
			++current;
			idx += half + 1;
			len = len - half - 1;
		}
	}
	return idx;
}

void PmergeMe::_insertPendToMain(std::list<listIt>& main, std::list<listIt>& pend)
{
	if (pend.empty())
		return ;
	_jackNumInvertion(main, pend);
	_orderedInvertion(main, pend);
}

void PmergeMe::_copyMainToList(std::list<int>& list, std::list<listIt>& main, size_t nmbsInBlock)
{
	std::list<int> tmpList;
	std::list<listIt>::iterator itFromMain;
	for (itFromMain = main.begin(); itFromMain != main.end(); ++itFromMain)
	{
		listIt blockEndIt = *itFromMain;
		listIt blockStartIt = blockEndIt;
		size_t stepsBackward = nmbsInBlock - 1;
		for (size_t k = 0; k < stepsBackward; ++k)
		{
			if (nmbsInBlock > 0)
				--blockStartIt; 
		}
		listIt itInBlock = blockStartIt;
		for (size_t j = 0; j < nmbsInBlock; j++)
		{
			tmpList.push_back(*itInBlock);
			++itInBlock;
		}
	}
	std::list<int>::iterator destIt = list.begin();
	std::list<int>::iterator srcIt = tmpList.begin();

	while (srcIt != tmpList.end())
	{
		*destIt = *srcIt;
		
		++destIt;
		++srcIt;
	}
}
 
void PmergeMe::mergeInsertSort(std::list<int> &list, listIt &levelLastElemIt, size_t level)
{
	listIt startIt  = list.begin();

	std::list<int>::difference_type totalCountSigned = std::distance(startIt, levelLastElemIt);
	totalCountSigned++;
	if (totalCountSigned <= 0)
		return ;
	size_t totalNmbsInLevel = static_cast<size_t>(totalCountSigned);
	if (totalNmbsInLevel <= 1) //empty or one nbr
		return ;

	size_t nmbsInPair = 1 << level; //2 , 4, 8, 16, 32, ... 
	if (nmbsInPair > totalNmbsInLevel)
		return ;

	size_t nmbsInBlock = nmbsInPair / 2;
	size_t pairsInLevel = totalNmbsInLevel / nmbsInPair;
	_sortPairs(list, pairsInLevel, nmbsInBlock);
	listIt newLevelEndIt = list.begin();
	std::advance(newLevelEndIt, (pairsInLevel * nmbsInPair - 1));
	mergeInsertSort(list, newLevelEndIt, level + 1); ////sort recursion

	std::list<std::list<int>::iterator> main = _createMain(list, totalNmbsInLevel, nmbsInBlock);
	std::list<std::list<int>::iterator> pend = _createPend(list, totalNmbsInLevel, nmbsInBlock);

	_insertPendToMain(main, pend);

	_copyMainToList(list, main, nmbsInBlock);
}

void PmergeMe::printList(const std::list<int>& list)
{
	std::list<int>::const_iterator it = list.begin();
	while (it != list.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}
