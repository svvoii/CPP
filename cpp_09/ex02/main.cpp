#include "PmergeMe.hpp"

/*
** Program name : PmergeMe
**
** Usage example :
** `$>./PmergeMe 3 5 9 7 4`
** `Before: 3 5 9 7 4`
** `After: 3 4 5 7 9`
** `Time to process a range of 5 elements with std::list : 0.000000 us`
** `Time to process a range of 5 elements with std::vector : 0.000000 us`
**
** INPUTS :
** `./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "``
** `Before: 141 79 526 321 [...]`
** `After: 79 141 321 526 [...]`
** `Time to process a range of 3000 elements with std::list : 0.000000 us`
** `Time to process a range of 3000 elements with std::vector : 0.000000 us`
**
** `$>./PmergeMe "-1" "2"`
** `Error`
*/

int main(int argc, char **argv) {

	if (argc < 2) {
		std::cout << "Error: Usage: " << std::endl;
		std::cout << "./PmergeMe 3 5 9 7 4" << std::endl;
		return 0;
	}
	PmergeMe pmergeMe;

	try {
		if (!pmergeMe.isValidInputString(argc, argv)) {
			throw std::invalid_argument("invalid input values.");
		} else if (!pmergeMe.isValidNumSequence(argc, argv)) {
			throw std::invalid_argument("duplicate number in the sequence.");
		}

		pmergeMe.sort(argc, argv);

		// std::cout << "Using vector<int>:" << std::endl;
		// pmergeMe.sortVector(argc, argv);

		// std::cout << std::endl << "Using list<int>:" << std::endl;
		// pmergeMe.sortList(argc, argv);

	}
	catch(const std::exception& e) {
		std::cerr << "Error: " << e.what() << '\n';
	}
	
	return 0;
}

/*
** Program requirements and constraints :
** 
** - Must take a positive integer sequence as argument.
** - Must sort the sequence using merge-insertion sort algorithm.
** - Ford-Johnson algorithm must be used to sort the sequence.
** - Must handle at least 3000 different integers.
** - At least 2 different containers must be used in the program.
** - If there is an error, during the execution, the program
** must display "Error" on the standard output.
**
** About displaying information line-by-line :
** - On the first line, the program must display an explicit
** text followed by the unsorted sequence of positive integers.
**
** - On the second line, the program must display an explicit
** text followed by the sorted sequence of positive integers.
**
** - On the third line, the program must display an explicit
** text indicating the time taken by the algorithm by specifying
** the first container used to sort the sequence.
**
** - On the fourth line, the program must display an explicit
** text indicating the time taken by the algorithm by specifying
** the second container used to sort the sequence.
*/
