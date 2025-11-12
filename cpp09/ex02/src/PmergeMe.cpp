/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:26:28 by mosokina          #+#    #+#             */
/*   Updated: 2025/11/12 14:43:04 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"


/*Difference between vector and list:
1.  iterator.std::vector has Random Access Iterators, which allow O(1) arithmetic like it + 5, it - 3, and comparisons like it1 < it2. 

2. std::list has Bidirectional Iterators, which only allow O(1) operations like ++it, --it, and *it (dereferencing).
Any movement by N steps must use std::advance(it, N), which is an O(N) operation.*/


size_t PmergeMe::nmbCompVec = 0;
size_t PmergeMe::nmbCompList = 0;

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
		(void)other;
	return *this;
}

PmergeMe::~PmergeMe(){}

void PmergeMe::printVector(const std::vector<int>& vec)
{
	// std::cout << "[";
	for (size_t i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << " ";
	}
	// std::cout << "]";
	std::cout << std::endl;

}

void PmergeMe::_sortPairs(std::vector<int>& vec, size_t pairsInLevel, size_t nmbsInBlock)
{
	vecIt lBlockStart = vec.begin();
	vecIt rBlockStart, lBlockEnd, rBlockEnd;

	for (size_t i = 0; i < pairsInLevel; i++)
	{
		rBlockStart = lBlockStart + nmbsInBlock;
		lBlockEnd = lBlockStart + (nmbsInBlock - 1);
		rBlockEnd = rBlockStart + (nmbsInBlock - 1);
		
		PmergeMe::nmbCompVec++; //fixed!!!

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
	
	vecIt startIt  = vec.begin();
	// main.insert(main.end(), startIt + (nmbsInBlock - 1));
	// main.insert(main.end(), startIt + (nmbsInBlock * 2 - 1));
	main.push_back(startIt + (nmbsInBlock - 1));
	main.push_back(startIt + (nmbsInBlock * 2 - 1));	
	vecIt rBlockStart = startIt + (nmbsInBlock * 3);
	vecIt rBlockLast = rBlockStart + (nmbsInBlock - 1);

	while (rBlockStart < levelLastElemIt) // while (rBlockLast < levelLastElemIt)
	{
		// main.insert(main.end(), rBlockLast);
		main.push_back(rBlockLast);
		std::advance(rBlockStart, nmbsInBlock * 2); // move to next element
		std::advance(rBlockLast, nmbsInBlock * 2); // move to next element
	}

	return main;
}

/*Insertion with specific order defined by the JACOBSTHAL number sequence
to optimize the number of comparisons.

TO ADD!!!!!!!!! 3, 5, 11, ..

*/

// long PmergeMe::_jacobsthalNumber(long n)
// {
// 	return round((pow(2, n + 1) + pow(-1, n)) / 3);
// }

#include <cmath> // make sure floor is available

long PmergeMe::_jacobsthalNumber(long n)
{
	double powerOfTwo = pow(2.0, n + 1);
	double powerOfNegOne = pow(-1.0, n);
	double result = (powerOfTwo + powerOfNegOne) / 3.0;
	return static_cast<long>(floor(result + 0.5));
}

/*std::upper_bound performs a BINARY SEARCH on a sorted or 
partially ordered range to find the "UPPER BOUND" of a value in a range.
It returns an iterator pointing to the first element in the range [first, last)
whose value is greater than the specified search value.*/

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
			std::vector<vecIt>::iterator idxToInsert = std::upper_bound(main.begin(), boundIt, *pendIt, compIetrators);

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

// void PmergeMe::_orderedInvertion(std::vector<vecIt>& main, std::vector<vecIt>& pend)
// {
// 	if (pend.empty())
// 		return ;	
// 	bool isOdd = false;
// 	if (pend.size() + main.size() % 2 != 0)
// 		isOdd = true;
// 	for (int i = pend.size() - 1; i >= 0; i--)
// 	{
// 		std::vector<vecIt>::iterator pendIt = pend.begin() + i;
// 		std::vector<vecIt>::iterator boundIt =
// 			main.begin() + (main.size() - pend.size() + i + isOdd);
// 			main.begin() + (main.size() - pend.size() + i);
// 		std::vector<vecIt>::iterator idxToInsert =
// 			std::upper_bound(main.begin(), boundIt, *pendIt, compIetrators);
// 		main.insert(idxToInsert, *pendIt);
// 	}
// }

void PmergeMe::_orderedInvertion(std::vector<vecIt>& main, std::vector<vecIt>& pend)
{
	if (pend.empty())
		return ;

	// Safe countdown loop fixed previously
	for (int i = pend.size() - 1; i >= 0; i--)
	{
		std::vector<vecIt>::iterator pendIt = pend.begin() + i;
		
		// Re-introduce the +1 correction, which addresses the straggler (odd element)
		// that was causing the off-by-one boundary error.
		std::vector<vecIt>::iterator boundIt =
			main.begin() + (static_cast<int>(main.size()) - static_cast<int>(pend.size()) + i + 1); 
			
		// Use a safe upper bound (cannot exceed main.end())
		if (boundIt > main.end()) {
			 boundIt = main.end();
		}
			
		std::vector<vecIt>::iterator idxToInsert =
			std::upper_bound(main.begin(), boundIt, *pendIt, compIetrators);
			
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
	vecIt newLevelEndIt = startIt + (pairsInLevel * nmbsInPair) - 1;

	mergeInsertSort(vec, newLevelEndIt, level + 1); ////sort recursion
	
	std::vector<std::vector<int>::iterator> main = _createMain(vec, levelLastElemIt, nmbsInBlock);
	std::vector<std::vector<int>::iterator> pend = _createPend(vec, levelLastElemIt, nmbsInBlock);
	if (level == 1 && vec.size() % 2 != 0) // the last odd element
		pend.push_back(levelLastElemIt);
	
	_insertPendToMain(main, pend);
	_copyMainToVec(vec, main, nmbsInBlock);

}

bool PmergeMe::compIetrators(vecIt lv, vecIt rv) //static function
{
	PmergeMe::nmbCompVec++;
	// return *lv <= *rv; //??
	return *lv < *rv; //??

}

void PmergeMe::mergeInsertSort(std::list<int> &list, listIt &levelLastElemIt, size_t level)
{
	std::cout << "level: " << level << std::endl;
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
	std::cout << "TEST1: list:\n";
	printList(list);
	_sortPairs(list, pairsInLevel, nmbsInBlock);
	std::cout << "TEST2: list:\n";
	printList(list);
	listIt newLevelEndIt = list.begin();
	std::advance(newLevelEndIt, (pairsInLevel * nmbsInPair - 1));
	mergeInsertSort(list, newLevelEndIt, level + 1); ////sort recursion

	std::list<std::list<int>::iterator> main = _createMain(list, levelLastElemIt, nmbsInBlock);
	// std::vector<std::vector<int>::iterator> pend = _createPend(vec, levelLastElemIt, nmbsInBlock);
	// if (level == 1 && vec.size() % 2 != 0) // the last odd element
	// 	pend.push_back(levelLastElemIt);
	
	// _insertPendToMain(main, pend);
	// _copyMainToVec(vec, main, nmbsInBlock);

}





// /*The std::list::splice() only changes the internal pointers of the nodes, 
// making the block movement an O(1) operation,
// regardless of the block size (nmbsInBlock).*/

void PmergeMe::_sortPairs(std::list<int>& list, size_t pairsInLevel, size_t nmbsInBlock)
{
	std::cout << "TEST before sort: list:\n";
	printList(list);
	
	listIt lBlockStart, rBlockStart, lBlockEnd, rBlockEnd;

	for (size_t i = 0; i < pairsInLevel; i++)
	{
		listIt tmpIt = list.begin();
		std::advance(tmpIt, (nmbsInBlock* 2 * i));
		lBlockStart = tmpIt;
		rBlockStart =  lBlockStart;
		std::advance(rBlockStart, nmbsInBlock);
		lBlockEnd = lBlockStart;
		std::advance(lBlockEnd, nmbsInBlock - 1);
		rBlockEnd = rBlockStart;
		std::advance(rBlockEnd, (nmbsInBlock - 1));
		PmergeMe::nmbCompList++;
		if (*lBlockEnd > *rBlockEnd) // Comparison and Swap
		{
			listIt nextBlockStart = rBlockEnd;
			nextBlockStart++;
			list.splice(lBlockStart, list, rBlockStart, nextBlockStart);
		}
	}
	std::cout << "TEST after sort: list:\n";
	printList(list);
}

// void PmergeMe::_sortPairsList(std::list<int>& list, listIt currentLevelStart, size_t pairsInLevel, size_t nmbsInBlock)
// {
// 	listIt lBlockStart = currentLevelStart; 
// 	listIt rBlockStart, lBlockEnd, rBlockEnd;

// 	for (size_t i = 0; i < pairsInLevel; i++)
// 	{
// 		rBlockStart = lBlockStart;
// 		std::advance(rBlockStart, nmbsInBlock);
// 		lBlockEnd = rBlockStart;
// 		--lBlockEnd;
// 		rBlockEnd = rBlockStart;
// 		std::advance(rBlockEnd, (nmbsInBlock - 1));

// 		PmergeMe::nmbCompList++;
		
// 		if (*lBlockEnd > *rBlockEnd)
// 		{
// 			// O(1) Block Swap using splice
// 			listIt nextBlockStart = rBlockEnd;
// 			++nextBlockStart;
// 			list.splice(lBlockStart, list, rBlockStart, nextBlockStart);
// 		}
// 		std::advance(lBlockStart, (nmbsInBlock * 2)); 
// 	}
// }

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


// /*PmergeMe::_createPend: Populates pend with iterators to the last element of L2, L3, L4...*/
// std::vector<std::vector<int>::iterator> PmergeMe::_createPend(std::vector<int>& vec, vecIt &levelLastElemIt, size_t nmbsInBlock)
// {
// 	std::vector<vecIt> pend;
	
// 	vecIt startIt  = vec.begin();
// 	vecIt lBlockStart = startIt + (nmbsInBlock * 2);
// 	vecIt lBlockLast = lBlockStart + (nmbsInBlock - 1);

// 	while (lBlockStart < levelLastElemIt) // while (rBlockLast < levelLastElemIt)??
// 	{
// 		// pend.insert(pend.end(), lBlockLast);
// 		pend.push_back(lBlockLast);
// 		std::advance(lBlockStart, nmbsInBlock * 2); // move to next element
// 		std::advance(lBlockLast, nmbsInBlock * 2); // move to next element
// 	}
	
// 	return pend;
// }

// /*Populates main with iterators to the last element of L1, R1, R2, R3...*/
// std::vector<std::vector<int>::iterator> PmergeMe::_createMain(std::vector<int>& vec, vecIt &levelLastElemIt, size_t nmbsInBlock)
// {
// 	std::vector<vecIt> main;
	
// 	vecIt startIt  = vec.begin();
// 	// main.insert(main.end(), startIt + (nmbsInBlock - 1));
// 	// main.insert(main.end(), startIt + (nmbsInBlock * 2 - 1));
// 	main.push_back(startIt + (nmbsInBlock - 1));
// 	main.push_back(startIt + (nmbsInBlock * 2 - 1));	
// 	vecIt rBlockStart = startIt + (nmbsInBlock * 3);
// 	vecIt rBlockLast = rBlockStart + (nmbsInBlock - 1);

// 	while (rBlockStart < levelLastElemIt) // while (rBlockLast < levelLastElemIt)
// 	{
// 		// main.insert(main.end(), rBlockLast);
// 		main.push_back(rBlockLast);
// 		std::advance(rBlockStart, nmbsInBlock * 2); // move to next element
// 		std::advance(rBlockLast, nmbsInBlock * 2); // move to next element
// 	}

// 	return main;
// }


std::list<std::list<int>::iterator> PmergeMe::_createMain(std::list<int>& list, size_t pairsInLevel, size_t nmbsInBlock)
{
	std::list<listIt> main;

	listIt startIt  = list.begin();
	listIt lBlockEnd = std::next(startIt, nmbsInBlock - 1);
	main.push_back(lBlockEnd); // add L1

	listIt rBlockLast = std::next(lBlockEnd, nmbsInBlock);
	main.push_back(rBlockLast); // add R1
	
	//R2
	listIt rBlockStart = std::next(startIt, nmbsInBlock * 3);
	rBlockLast = std::next(rBlockStart, (nmbsInBlock - 1));

	for (size_t i = 1; i < pairsInLevel; ++i)
	{
		main.push_back(rBlockLast);
		std::advance(rBlockStart, nmbsInBlock * 2); // move to next element
		std::advance(rBlockLast, nmbsInBlock * 2); // move to next element
	}

	return main;
}





bool PmergeMe::compListIetrators(listIt lv, listIt rv)
{
	PmergeMe::nmbCompList++;
	return *lv < *rv;
}