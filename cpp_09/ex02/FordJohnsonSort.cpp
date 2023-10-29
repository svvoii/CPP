/*
** The Ford-Johnson merge-insertion sort is a three-step algorithm.
** Let `n` be the number of elements to be sorted.
**
** 1st step:
** Split the collection in two parts `n/2` pairs of `2` elements,
** and order each element pairwise.
** If the number of elements is odd, the last element is left unpaired.
**
** 2nd step:
** Recursively sort the pairs of elements by their highest value.
** If the number of elements is odd, the last element is not considered
** a highest value, and is left at the end of the collection.
** Consider that the highest values from a sorted list that we will call
** the `main chain`,while the rest of the elements will be known as
** the `pend` chain elements.
** Tag the elements of the `main chain` with the names `a_1, a_2, ..., a_n/2`,
** then tag the elements of the `pend` chain with the names `b_1, b_2, ..., b_n/2`.
** For every `k`, we have the relation `b_k < a_k`.
**
** 3rd step:
** Insert the `pend` elements into the `main chain`. We know that the first
** `pend` element `b_1` is smaller than the first `main chain` element `a_1`.
** We consider it to be part of the `main chain`, which then becomes
** `b_1, a_1, a_2, a_3, ..., a_n/2`.
** Now we need to insert the other `pend` elements into the `main chain`
** in a way thet ensures that the size of the insertion area
** is a power of `2` minus `1`.
** Basically, we will insert `b_3` inbetween `b_1, a_1`, a_2` (we know that `b_3 < a_3`).
** Then we will insert `b_2` inbetween `b_1, a_1, b_3` no matter where `b_3` was inserted.
** Note that during these insertions, the size of the insertion area is always
** at most 3 elements.
**
** The value of the next `pend` element `b_k` to insert into the `main chain`,
** while minimizing the number of comparisons, actually corresponds to the
** Jacobsthal sequence number.
** We inserted the element `3` first, so the next element will be `5`,
** then `11`, then `21`, then `43`, then `85`, then `171`, then `341`, etc.
**
** To sum up the insertion order of the first `pend` elements into the `main chain`
** is as follows: `b_1, b_3, b_2, b_5, b_4, b_{11}, b_{10}, b_9, b_8, b_7, b_6, ...`
*/

#include <iostream>
#include <vector>
#include <algorithm>

void ford_johnson_sort(std::vector<int>& sorted, std::vector<int>& sequence) {
	// Step 1: Order each pair of elements
	for (int i = 0; i < sequence.size() - 1; i += 2) {
		if (sequence[i] > sequence[i + 1]) {
			std::swap(sequence[i], sequence[i + 1]);
		}
	}

	// Step 2: Recursively sort pairs of elements by their highest value
	std::vector<int> main_chain;
	std::vector<int> pend_chain;
	for (int i = 0; i < sequence.size(); i += 2) {
		if (i == sequence.size() - 1) {
			main_chain.push_back(sequence[i]);
		} else {
			if (sequence[i] > sequence[i + 1]) {
				main_chain.push_back(sequence[i]);
				pend_chain.push_back(sequence[i + 1]);
			} else {
				main_chain.push_back(sequence[i + 1]);
				pend_chain.push_back(sequence[i]);
			}
		}
	}
	//std::reverse(pend_chain.begin(), pend_chain.end());

	// Insert pend elements into main chain
	main_chain.insert(main_chain.begin(), pend_chain[0]);
	pend_chain.erase(pend_chain.begin());
	int j = 0;
	for (int i = 1; i < main_chain.size(); i *= 2) {
		for (; j < pend_chain.size() && j < i; j++) {
			main_chain.insert(main_chain.begin() + i + j, pend_chain[j]);
		}
	}


	sorted = main_chain;
}

int main() {
	std::vector<int> sequence = {33, 11, 44, 22, 99, 55, 88, 66, 77, 100};
	std::vector<int> sorted;

	ford_johnson_sort(sorted, sequence);

	for (int i = 0; i < sorted.size(); i++) {
		std::cout << sorted[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}
