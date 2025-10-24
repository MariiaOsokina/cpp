

#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>


std::vector<size_t> generateJacobsthalIndices(size_t maxPendSize) {
	std::vector<size_t> indices;
	if (maxPendSize == 0)
		return indices;

	// a(k-2) and a(k-1) are the two previous terms in the *target* sequence
	size_t a_k_minus_2 = 1; // a1
	size_t a_k_minus_1 = 3; // a2

	indices.push_back(1); // a1 is the first index
	if (maxPendSize <= 1) return indices;

	indices.push_back(3); // a2 is the second index
	
	// Now generate a3, a4, a5, ... (5, 11, 21, 43, ...)
	while (true) {
		// Recurrence: a(k) = a(k-1) + 2 * a(k-2)
		// Check: 5 = 3 + 2*1 (Correct)
		// Check: 11 = 5 + 2*3 (Correct)
		// Check: 21 = 11 + 2*5 (Correct)
		
		size_t next_a_k = a_k_minus_1 + (2 * a_k_minus_2);

		if (next_a_k > maxPendSize)
			break;

		indices.push_back(next_a_k);

		// Shift the previous values
		a_k_minus_2 = a_k_minus_1;
		a_k_minus_1 = next_a_k;
	}
	return indices;
}