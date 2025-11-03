/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:26:28 by mosokina          #+#    #+#             */
/*   Updated: 2025/11/03 21:55:16 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"


// 11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7

PmergeMe::PmergeMe()
{
    std::cout << "PmergeMe: Default constructor called." << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    (void)other; // Mark 'other' as unused to suppress compiler warnings
    std::cout << "PmergeMe: Copy constructor called." << std::endl;
    // Example for copying a member 'sorted_data':
    // this->sorted_data = other.sorted_data;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &other)
{
    std::cout << "PmergeMe: Assignment operator called." << std::endl;
    if (this != &other)
    {
        // 1. Clean up existing resources if necessary (not needed here)
        
        // 2. Perform deep copy of members
        // Example for assigning a member 'sorted_data':
        // this->sorted_data = other.sorted_data;
        (void)other; // Mark 'other' as unused
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
    std::cout << "PmergeMe: Destructor called." << std::endl;
}

void PmergeMe::printVector(const std::vector<int>& vec)
{
	std::cout << "[";
	for (size_t i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << " ";
	}
	std::cout << "]" << std::endl;
}

void PmergeMe::printItVector(const std::vector<vecIt>& vec)
{
	std::cout << "[";
	for (size_t i = 0; i < vec.size(); ++i) {
		std::cout << *(vec[i]) << " ";
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

	for (size_t i = 0; i < pairsInLevel; i++)
	{
		rBlockStart = lBlockStart + nmbsInBlock;
		lBlockEnd = lBlockStart + (nmbsInBlock - 1);
		rBlockEnd = rBlockStart + (nmbsInBlock - 1);

		if (*lBlockEnd > *rBlockEnd) // Comparison and Swap
		{
			_nmbComp++;
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
		pend.insert(pend.end(), lBlockLast);
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
	main.insert(main.end(), startIt + (nmbsInBlock - 1));
    main.insert(main.end(), startIt + (nmbsInBlock * 2 - 1));
	
	vecIt rBlockStart = startIt + (nmbsInBlock * 3);
	vecIt rBlockLast = rBlockStart + (nmbsInBlock - 1);
	while (rBlockStart < levelLastElemIt) // while (rBlockLast < levelLastElemIt)
	{
		main.insert(main.end(), rBlockLast);
		std::advance(rBlockStart, nmbsInBlock * 2); // move to next element
		std::advance(rBlockLast, nmbsInBlock * 2); // move to next element
	}
	return main;
}

/*Insertion with specific order defined by the JACOBSTHAL number sequence
to optimize the number of comparisons.

TO ADD!!!!!!!!! 3, 5, 11, ..



*/

long PmergeMe::_jacobsthalNumber(long n)
{
	return round((pow(2, n + 1) + pow(-1, n)) / 3);
}

/*std::upper_bound performs a BINARY SEARCH on a sorted or 
partially ordered range to find the "UPPER BOUND" of a value in a range.
It returns an iterator pointing to the first element in the range [first, last)
whose value is greater than the specified search value.*/

void PmergeMe::_insertPendToMain(std::vector<vecIt>& main, std::vector<vecIt>& pend)
{
	if (pend.empty())
		return ;
	// int prevJN = _jacobsthalNumber(1); // 1
	int prevJN = 1; // 1
	int insertedCount = 0;
	for (int k = 2;; k++)
	{
		int currJN = _jacobsthalNumber(k);

		int jackDiff =  currJN - prevJN;
		std::cout << "TEST1: prevJacNum " << prevJN <<std::endl;
		std::cout << "TEST1: currJN " << currJN <<std::endl;
		std::cout << "TEST1: jackDiff " << jackDiff <<std::endl;
		int offset = 0;
		if (jackDiff > static_cast<int>(pend.size()))
			break ;
		
		std::vector<vecIt>::iterator pendIt = pend.begin() + (jackDiff - 1);
		std::vector<vecIt>::iterator boundIt = main.begin() + (currJN + insertedCount);
		// std::cout << "TEST4 boundIt it: " << boundIt << std::endl;

		for (int i = jackDiff; i > 0; --i)
		{
			std::vector<vecIt>::iterator idxToInsert = std::upper_bound(main.begin(), boundIt, *pendIt, _comp);
			// std::cout << "TEST3 pend it: " << *(*pendIt) << std::endl;
			std::cout << "TEST5!!!!!!! idxToInsert it: " << *(*idxToInsert) << std::endl;

			std::vector<vecIt>::iterator inserted = main.insert(idxToInsert, *pendIt);
			pendIt = pend.erase(pendIt);
			pendIt --;
			if (inserted - main.begin() == currJN + insertedCount)
					offset ++;
			boundIt = main.begin() + (currJN + insertedCount - offset);
			
			
			std::cout << "TEST2 pend after: " << std::endl;
			this->printItVector(pend);
			std::cout << "TEST2 main after: " << std::endl;
			this->printItVector(main);
		}
		prevJN = currJN;
		insertedCount += jackDiff;
	}
	// Insert the remaining elements in the reversed order

}

void PmergeMe::_copyMainToVec(std::vector<int>& vec, std::vector<vecIt>& main, size_t nmbsInBlock)
{
	std::vector<int> tmpVec;
	tmpVec.reserve(vec.size());
	for (int i = 0; i < static_cast<int>(main.size()); i ++)
	{
		std::vector<vecIt>::iterator itFromMain = main.begin() + i;
		vecIt itInBlock = *itFromMain - (nmbsInBlock + 1);
		for (size_t j = 0; j < nmbsInBlock; j++) //copy numbers in Block
		{
			tmpVec.insert(tmpVec.end(), *itInBlock);
			itInBlock ++;
		}
	}
	vecIt tmpIt  = tmpVec.begin();
	vecIt vecIt  = vec.begin();
	while(tmpIt != tmpVec.end())
	{
		*vecIt = *tmpIt;
		tmpIt ++;
		vecIt ++;
	}
}

void PmergeMe::mergeInsertSort(std::vector<int> &vec, vecIt &levelLastElemIt, size_t level)
{
	
	std::cout << "TEST level : " << level << std::endl;

	vecIt startIt  = vec.begin();
	
	size_t totalNmbsInLevel = levelLastElemIt - startIt + 1; //?? +1
	// std::cout << "TEST totalNmbsInLevel : " << totalNmbsInLevel << std::endl;

	if (totalNmbsInLevel <= 1) //empty or one nbr
		return ;

	size_t nmbsInPair = 1 << level; //2 , 4, 8, 16, 32, ... 

	if (nmbsInPair > totalNmbsInLevel)
		return ;

	size_t nmbsInBlock = nmbsInPair / 2;
	size_t pairsInLevel = totalNmbsInLevel / nmbsInPair;

	// std::cout << "TEST nmbsInPair : " << nmbsInPair << std::endl;
	// std::cout << "TEST nmbsInBlock : " << nmbsInBlock << std::endl;
	// std::cout << "TEST pairsInLevel : " << pairsInLevel << std::endl;

	_sortPairs(vec, pairsInLevel, nmbsInBlock);
	// std::cout << "TEST after  _sortPairs: " << std::endl;
	this->printVector(vec);

	vecIt newLevelEndIt = startIt + (pairsInLevel * nmbsInPair) - 1;
	// std::cout << "TEST newLevelEndIt : " << *newLevelEndIt << std::endl;

	mergeInsertSort(vec, newLevelEndIt, level + 1); ////sort recursion

	std::vector<std::vector<int>::iterator> pend = _createPend(vec, levelLastElemIt, nmbsInBlock);
	std::cout << "TEST pend level : " << level << std::endl;
	std::cout << "TEST vec: " << std::endl;
	this->printVector(vec);
	std::cout << "TEST pend before: " << std::endl;
	this->printItVector(pend);
	
	std::cout << "TEST main before: " << std::endl;

	std::vector<std::vector<int>::iterator> main = _createMain(vec, levelLastElemIt, nmbsInBlock);
	this->printItVector(main);

	std::cout << "TEST main and pend after insert: " << std::endl;

	_insertPendToMain(main, pend);

	std::cout << "TEST pend after: " << std::endl;
	this->printItVector(pend);
	std::cout << "TEST main after: " << std::endl;
	this->printItVector(main);

	// _copyMainToVec(vec, main, nmbsInBlock);
}

// PmergeMe::vecIt PmergeMe::_next(vecIt &it, int dist)
// {
// 	vecIt newIt(it);
// 	std::advance(newIt, dist);
// 	return newIt;
// }


bool PmergeMe::_comp(vecIt lv, vecIt rv)
{
	// _nmbComp++;
	return *lv < *rv;
}