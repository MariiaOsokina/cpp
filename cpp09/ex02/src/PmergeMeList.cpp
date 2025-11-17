/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeList.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <mosokina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:34:39 by mosokina          #+#    #+#             */
/*   Updated: 2025/11/17 14:49:48 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

void printListIter(const std::list<std::list<int>::iterator>& itList)
{
	std::list<std::list<int>::iterator>::const_iterator it = itList.begin();
	while (it != itList.end())
	{
		std::cout << *(*it) << " ";
		it++;
	}
	std::cout << std::endl;
}

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

		// Move currentPos to the start of the next pair (L-block of next pair)
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

// /*Populates main with iterators to the last element of L1, R1, R2, R3...*/
// std::list<std::list<int>::iterator> PmergeMe::_createMain(std::list<int>& list, size_t pairsInLevel, size_t nmbsInBlock)
// {
// 	std::list<listIt> main;

// 	// L1 Last
// 	listIt startIt  = list.begin();
// 	listIt lBlockLast = startIt;
// 	std::advance(lBlockLast, nmbsInBlock - 1);
// 	main.push_back(lBlockLast); 

// 	// R1 Last
// 	listIt rBlockLast = lBlockLast;
// 	std::advance(rBlockLast, nmbsInBlock);
// 	main.push_back(rBlockLast); 
	
// 	// Adding R2, R3, R4...
// 	listIt currentBlockIt = startIt;
// 	std::advance(currentBlockIt, nmbsInBlock * 2); //  L2 Start
// 	for (size_t i = 1; i < pairsInLevel; ++i)
// 	{
// 		std::advance(currentBlockIt, nmbsInBlock); // R_i Start

// 		listIt rBlockEnd = currentBlockIt;
// 		std::advance(rBlockEnd, nmbsInBlock - 1); // Ri Last
// 		main.push_back(rBlockEnd);

// 		std::advance(currentBlockIt, nmbsInBlock); //L_i+1 Start
// 	}
// 	return main;
// }

bool PmergeMe::compIteratorsList(listIt lv, listIt rv)
{
	PmergeMe::nmbCompList++;
	// std::cout << nmbCompList << " ";
	return *lv < *rv;
}

// // std::upper_bound works on std::list iterators (O(N) runtime, but O(log N) comparisons)
// // List: Must use $O(k)$ std::advance to move iterators:
// //List: std::upper_bound is O(log N) comparisons but O(N) iterator movements (since it must step one by one).
// void PmergeMe::_jackNumInvertion(std::list<listIt>& main, std::list<listIt>& pend)
// {
// 	int prevJN = 1; // 1
// 	int insertedCount = 0;
// 	for (size_t k = 2;; k++)
// 	{
// 		int currJN = _jacobsthalNumber(k);

// 		int jackDiff =  currJN - prevJN;
// 		int offset = 0;
// 		if (jackDiff > static_cast<int>(pend.size()))
// 			break ;
		
// 		std::list<listIt>::iterator pendIt = pend.begin();
// 		std::advance(pendIt, (jackDiff - 1));
// 		std::list<listIt>::iterator boundIt = main.begin();
// 		std::advance(boundIt, (currJN + insertedCount));

// 		for (size_t i = jackDiff; i > 0; --i)
// 		{
// 			std::list<listIt>::iterator idxToInsert = std::upper_bound(main.begin(), boundIt, *pendIt, compIteratorsList);
// 			std::cout << "List _jackNumInvertion nmbCompList " << PmergeMe::nmbCompList << std::endl;

// 			// size_t index = std::distance(main.begin(), idxToInsert);
// 			// std::cout << "LIST: _jackNumInvertion INDEX TO INSERT" << index << std::endl << std::endl;

			
// 			std::list<listIt>::iterator inserted = main.insert(idxToInsert, *pendIt);
// 			pendIt = pend.erase(pendIt);
// 			pendIt --;
// 			// if (inserted - main.begin() == currJN + insertedCount)
// 			// 		offset ++;
// 			if (inserted == boundIt)
// 				offset++;
// 			boundIt = main.begin();
// 			size_t newBoundPos = static_cast<size_t>(currJN + insertedCount - offset);
// 			if (newBoundPos > main.size()) 
// 				newBoundPos = main.size();
// 			std::advance(boundIt, newBoundPos);
// 		}
// 		prevJN = currJN;
// 		insertedCount += jackDiff;
// 	}
// }

// /*PROPER VERSION!!!*/
// void PmergeMe::_jackNumInvertion(std::list<listIt>& main, std::list<listIt>& pend)
// {
// 	int prevJN = 1; // 1
// 	int insertedCount = 0;
// 	for (size_t k = 2;; k++)
// 	{
// 		int currJN = _jacobsthalNumber(k);

// 		int jackDiff =  currJN - prevJN;
// 		int offset = 0;
// 		if (jackDiff > static_cast<int>(pend.size()))
// 			break ;
		
// 		std::list<listIt>::iterator pendIt = pend.begin();
// 		std::advance(pendIt, (jackDiff - 1));
// 		std::list<listIt>::iterator boundIt = main.begin();
// 		std::advance(boundIt, (currJN + insertedCount));

// 		for (size_t i = jackDiff; i > 0; --i)
// 		{
// 			size_t tmpnmbComp = PmergeMe::nmbCompList;

// 			std::list<listIt>::iterator idxToInsert = std::upper_bound(main.begin(), boundIt, *pendIt, compIteratorsList);
// 			std::cout << "List _jackNumInvertion nmbCompList " << (PmergeMe::nmbCompList - tmpnmbComp) << std::endl;

// 			// size_t index = std::distance(main.begin(), idxToInsert);
// 			// std::cout << "LIST: _jackNumInvertion INDEX TO INSERT" << index << std::endl << std::endl;

			
// 			std::list<listIt>::iterator inserted = main.insert(idxToInsert, *pendIt);
// 			pendIt = pend.erase(pendIt);
// 			pendIt --;
// 			// if (inserted - main.begin() == currJN + insertedCount)
// 			// 		offset ++;
// 			if (inserted == boundIt)
// 				offset++;
// 			boundIt = main.begin();
// 			size_t newBoundPos = static_cast<size_t>(currJN + insertedCount - offset);
// 			if (newBoundPos > main.size()) 
// 				newBoundPos = main.size();
// 			std::advance(boundIt, newBoundPos);
// 		}
// 		prevJN = currJN;
// 		insertedCount += jackDiff;
// 	}
// }


void PmergeMe::_jackNumInvertion(std::list<listIt>& main, std::list<listIt>& pend)
{
    int prevJN = 1;
    int insertedCount = 0;
    
    // To match vector, we loop until jacobsthal numbers are exhausted
    for (size_t k = 2;; k++)
    {
        int currJN = _jacobsthalNumber(k);
        int jackDiff = currJN - prevJN;
        
        if (jackDiff > static_cast<int>(pend.size()))
            break;

        // Point to the element in Pend we want to insert (starting from the Jacobsthal peak)
        std::list<listIt>::iterator pendIt = pend.begin();
        std::advance(pendIt, (jackDiff - 1));
        
        int offset = 0;

        // Insert the batch backwards
        for (size_t i = jackDiff; i > 0; --i)
        {
            // 1. Calculate the Boundary exactly like Vector
            // Vector logic: boundIt = main.begin() + (currJN + insertedCount - offset)
            size_t boundPos = currJN + insertedCount - offset;
            
            // Safety clamp
            if (boundPos > main.size()) 
                boundPos = main.size();

			size_t tmpnmbComp = PmergeMe::nmbCompList;

            // 2. Find Index (O(log N) comparisons)
            size_t idxToInsert = binarySearchIndex(main, *(*pendIt), boundPos);

			std::cout << "List _jackNumInvertion nmbCompList " << (PmergeMe::nmbCompList - tmpnmbComp) << std::endl;

            // 3. Move Iterator to that index (O(N) runtime, irrelevant for comp count)
            std::list<listIt>::iterator iterToInsert = main.begin();
            std::advance(iterToInsert, idxToInsert);

            // 4. Insert
            std::list<listIt>::iterator inserted = main.insert(iterToInsert, *pendIt);

            // 5. CRITICAL FIX: Update Offset logic using Distance
            // In vector: if (inserted - main.begin() == currJN + insertedCount)
            // We use std::distance to get the index of 'inserted'.
            long insertedIdx = std::distance(main.begin(), inserted);
            
            if (insertedIdx == (currJN + insertedCount))
            {
                offset++;
            }

            // 6. Cleanup Pend
            pendIt = pend.erase(pendIt);
            pendIt--; 
        }
        
        prevJN = currJN;
        insertedCount += jackDiff;
    }
}


// void PmergeMe::_orderedInvertion(std::list<listIt>& main, std::list<listIt>& pend)
// {
// 	if (pend.empty())
// 		return ;

// 	std::list<listIt>::iterator pendIt = pend.end();
// 	pendIt--; //last elem in pend
// 	for (int i = pend.size() - 1; i >= 0; i--)
// 	{
// 		std::list<listIt>::iterator boundIt = main.begin();
// 		size_t boundPos = static_cast<int>(main.size()) - static_cast<int>(pend.size()) + i + 1;
// 		std::advance(boundIt, boundPos);

// 		if (boundPos > main.size())
// 			boundIt = main.end();
// 		// std::cout << "\n boundIt is " << *(*boundIt) <<std::endl;
// 		// std::cout << "pendIt " << *(*pendIt) << std::endl;
// 		std::list<listIt>::iterator idxToInsert = std::upper_bound(main.begin(), boundIt, *pendIt, compIteratorsList);
// 		// std::cout << "TEST list comp i is " << i <<std::endl;
// 		// std::cout << "nmbCompList " << PmergeMe::nmbCompList << std::endl;

// 		main.insert(idxToInsert, *pendIt);
// 		pendIt = pend.erase(pendIt);
// 		if (i > 0)
// 			 pendIt--;
// 	}
// }

// void PmergeMe::_orderedInvertion(std::list<listIt>& main, std::list<listIt>& pend)
// {
// 	if (pend.empty())
// 		return ;

// 	std::list<listIt>::iterator pendIt = pend.end();
// 	pendIt--; //last elem in pend
// 	for (int i = pend.size() - 1; i >= 0; i--)
// 	{
// 		size_t boundPos = static_cast<int>(main.size()) - static_cast<int>(pend.size()) + i + 1;
// 		// std::cout << "pendIt " << *(*pendIt) << std::endl;
// 		size_t tmpnmbComp = PmergeMe::nmbCompList;

// 		size_t idxToInsert = binarySearchIndex(main, *(*pendIt), boundPos);

// 		// std::cout << "TEST list comp i is " << i <<std::endl;
// 		std::cout << "List _orderedInvertion nmbCompList " << (PmergeMe::nmbCompList - tmpnmbComp) << std::endl;


// 		std::list<listIt>::iterator iterToInsert = main.begin();
// 		std::advance(iterToInsert, idxToInsert);

// 		// std::cout << "LIST INDEX TO INSERT" << idxToInsert << std::endl << std::endl;

// 		main.insert(iterToInsert, *pendIt);
// 		pendIt = pend.erase(pendIt);
// 		if (i > 0)
// 			 pendIt--;
// 	}
// }

// /*SECOND VERSION*/
// void PmergeMe::_orderedInvertion(std::list<listIt>& main, std::list<listIt>& pend)
// {
//     if (pend.empty())
//         return;

//     std::list<listIt>::iterator pendIt = pend.end();
//     pendIt--; 

//     // Track how many elements we have inserted in this specific loop
//     size_t addedCount = 0;

//     for (int i = pend.size() - 1; i >= 0; i--)
//     {
//         // PROBLEM: In List, pend.size() decreases and main.size() increases.
//         // This causes boundPos to grow larger than the Vector version.
//         // FIX: Subtract 'addedCount' to counteract the shift and keep boundPos constant.
//         size_t boundPos = main.size() - pend.size() + i + 1 - addedCount;
        
//         // Safety clamp
//         if (boundPos > main.size())
//             boundPos = main.size();
//         size_t tmpnmbComp = PmergeMe::nmbCompList;

//         size_t idxToInsert = binarySearchIndex(main, *(*pendIt), boundPos);

//         std::cout << "List _orderedInvertion nmbCompList " << (PmergeMe::nmbCompList - tmpnmbComp) << std::endl;

//         std::list<listIt>::iterator iterToInsert = main.begin();
//         std::advance(iterToInsert, idxToInsert);

//         main.insert(iterToInsert, *pendIt);
        
//         // Increment the count of added elements
//         addedCount++;
        
//         pendIt = pend.erase(pendIt);
//         if (i > 0)
//              pendIt--;
//     }
// }

void PmergeMe::_orderedInvertion(std::list<listIt>& main, std::list<listIt>& pend)
{
    if (pend.empty())
        return;

    // 1. Setup iterator at the last element of pend
    std::list<listIt>::iterator pendIt = pend.end();
    pendIt--; 

    // 2. Loop backwards (matching vector index logic)
    for (int i = pend.size() - 1; i >= 0; i--)
    {
        // Exact Vector Logic: 
        // Bound = Current_Main_Size - Fixed_Pend_Size + current_i + 1
        // Since we are NOT erasing pend, pend.size() is constant, matching Vector.
        size_t boundPos = main.size() - pend.size() + i + 1;
        
        // Safety clamp
        if (boundPos > main.size())
            boundPos = main.size();

        // Perform Binary Search
        size_t idxToInsert = binarySearchIndex(main, *(*pendIt), boundPos);

        // Move iterator to insertion point
        std::list<listIt>::iterator iterToInsert = main.begin();
        std::advance(iterToInsert, idxToInsert);

        // Insert
        main.insert(iterToInsert, *pendIt);
        
        // Move pendIt backwards for the next iteration (manually)
        // We do NOT erase here, to keep pend.size() constant for the math above.
        if (i > 0)
             pendIt--;
    }
    
    // 3. Clear pend after the loop is done (optional, but good for cleanup)
    pend.clear();
}

size_t PmergeMe::binarySearchIndex(std::list<listIt>& main, int value, size_t boundPos)
{
    size_t len = boundPos;
    size_t idx = 0; // Relative index from the start of search range
    std::list<listIt>::iterator current = main.begin();

    while (len > 0)
    {
        size_t half = len / 2;
        std::list<listIt>::iterator middle = current;
        std::advance(middle, half);

        PmergeMe::nmbCompList++; // Count comparison
        
        if (value < *(*middle)) // upper_bound logic: value < element
        {
            len = half;
        }
        else
        {
            current = middle;
            ++current;
            idx += half + 1; // Accumulate index
            len = len - half - 1;
        }
    }
    return idx;
}

// size_t PmergeMe::binarySearchIndex(std::list<listIt>& main, int value, size_t boundPos)
// {
//     // Start iterator for the search range
//     std::list<listIt>::iterator first = main.begin();
    
//     // Total size of the search range (from first to boundPos)
//     size_t len = boundPos;

//     // Use a temporary iterator to advance the start to boundPos
//     std::list<listIt>::iterator temp_it = main.begin();
//     std::advance(temp_it, boundPos);
//     // The 'right' boundary is not strictly needed for the loop, but the size 'len' is.

//     // Index tracking (optional, but necessary for the size_t return type)
//     size_t current_index = 0;

//     // The loop continues as long as there are elements in the range
//     while (len > 0)
//     {
//         // 1. Calculate the 'step' (midpoint offset)
//         size_t step = len / 2;

//         // 2. Find the midpoint iterator 'it'
//         std::list<listIt>::iterator it = first;
//         // The expensive O(N) step, but is only O(len/2) from 'first'
//         std::advance(it, step);

//         // 3. Comparison
//         nmbCompList++;
        
//         if (value == *(*it))
//             return current_index + step; // Found exact match
        
//         else if (value < *(*it))
//         {
//             // Value is in the left half (range before 'it')
//             // 'first' remains the same. The right boundary (len) is reduced.
//             len = step; 
//         }
//         else // value > *(*it)
//         {
//             // Value is in the right half (range after 'it')
//             // The left boundary ('first') is moved past 'it'
//             first = ++it; // Move 'first' to the element *after* 'it'
            
//             // The starting index is updated
//             current_index += step + 1;
            
//             // The search size is reduced by the elements we just skipped (step + 1)
//             len = len - (step + 1); 
//         }
//     }
    
//     // When the loop finishes, 'current_index' holds the insertion position.
//     // It corresponds to the index where 'first' ended up.
//     return current_index;
// }

// size_t	PmergeMe::binarySearchIndex(std::list<listIt>& main, int value, size_t boundPos)
// {
// 	size_t left = 0;			// inclusive
// 	size_t right = boundPos;	// exclusive

//     // 1. Logarithmic Block Search (O(log N) comparisons)
// 	while (left < right)
// 	{
// 		size_t mid = (left + right) / 2;

// 		// The time-consuming O(N) step, but crucial for comparison logic
// 		std::list<listIt>::iterator	midIt = main.begin();
// 		std::advance(midIt, mid); // Last element of mid-block

// 		nmbCompList++;
// 		if (value == *(*midIt))
// 			return mid;
// 		else if (value < *(*midIt))
// 			right = mid;
// 		else
// 			left = mid + 1;
// 	}
// 	return right;
// }

	// // 2. Locate the start of the insertion block
	// std::list<int>::iterator	blockStartIt = list.begin();
	// // This O(N) advance is unavoidable if not using auxiliary data structures
	// std::advance(blockStartIt, left * blockSize);

    // // 3. Linear Search WITHIN the final block (O(blockSize) comparisons)
    // // The total comparisons remain low because blockSize is small and fixed
    // std::list<int>::iterator blockEndIt = blockStartIt;
    
    // // Safety check for the list end, necessary because 'left * blockSize' might be outside the list
    // size_t remainingElements = totalNmbsInLevel - (left * blockSize);
    // size_t searchLength = (remainingElements < blockSize) ? remainingElements : blockSize;

    // std::advance(blockEndIt, searchLength);

    // std::list<int>::iterator finalInsertPos = 
    //     std::upper_bound(blockStartIt, blockEndIt, value, compIteratorsList);

	// return finalInsertPos;
// }






void PmergeMe::_insertPendToMain(std::list<listIt>& main, std::list<listIt>& pend)
{
	if (pend.empty())
		return ;
	_jackNumInvertion(main, pend);
	// std::cout << "TEST:  _jackNumInvertion PmergeMe::nmbCompList " << PmergeMe::nmbCompList << std::endl;
	_orderedInvertion(main, pend);
	// std::cout << "TEST:  _orderedInvertion PmergeMe::nmbCompList " << PmergeMe::nmbCompList << std::endl;

}

void PmergeMe::_copyMainToList(std::list<int>& list, std::list<listIt>& main, size_t nmbsInBlock)
{
	std::list<int> tmpList;
	std::list<listIt>::iterator itFromMain;
	// 1. Create the temporary list with sorted values
	for (itFromMain = main.begin(); itFromMain != main.end(); ++itFromMain)
	{
		listIt blockEndIt = *itFromMain;
		listIt blockStartIt = blockEndIt;
		size_t stepsBackward = nmbsInBlock - 1;
		for (size_t k = 0; k < stepsBackward; ++k)
		{
			// IMPORTANT: Ensure nmbsInBlock is >= 1 to prevent issues
			if (nmbsInBlock > 0)
				--blockStartIt; 
		}
		// copy all numbers in the Block to the temporary list
		listIt itInBlock = blockStartIt;
		for (size_t j = 0; j < nmbsInBlock; j++)
		{
			tmpList.push_back(*itInBlock);
			++itInBlock;
		}
	}
	// 2. Copy values from tmpList over the original list
	std::list<int>::iterator destIt = list.begin();
	std::list<int>::iterator srcIt = tmpList.begin();

	// Copy the values one by one.
	// This assumes tmpList.size() <= list.size() at this point,
	// which it should be for this algorithm.
	while (srcIt != tmpList.end())
	{
		*destIt = *srcIt; // Overwrite the value
		
		++destIt;
		++srcIt;
	}
}
 
void PmergeMe::mergeInsertSort(std::list<int> &list, listIt &levelLastElemIt, size_t level)
{
	// std::cout << "level: " << level << std::endl;
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

	// std::cout << "Level List:\n" << level << std::endl;
	// std::cout << "Main1 List:\n";
	// printListIter(main);
	// std::cout << "Pend1 List:\n";
	// printListIter(pend);

	// if (level == 1 && list.size() % 2 != 0) // the last odd element
	// 	pend.push_back(levelLastElemIt);
	// std::cout << "PendXXX List:\n";
	// printListIter(pend);

	_insertPendToMain(main, pend);

	// std::cout << "Level List:\n" << level << std::endl;
	// std::cout << "Main2 List:\n";
	// printListIter(main);
	// std::cout << "Pend2 List:\n";
	// printListIter(pend);

	_copyMainToList(list, main, nmbsInBlock);
	// std::cout << "LEVEL: "<< level << " List In the end of recursion:\n";
	// printList(list);
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
