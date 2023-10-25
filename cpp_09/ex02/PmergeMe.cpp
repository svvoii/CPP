#include "PmergeMe.hpp"

/*
** Constructors
*/
PmergeMe::PmergeMe(void) {
}

PmergeMe::PmergeMe(PmergeMe const & src) {
	*this = src;
}

PmergeMe::~PmergeMe() {
}

PmergeMe &PmergeMe::operator=(PmergeMe const & rhs) {
	if (this != &rhs) {
		// to do
		(void)rhs;
	}
	return *this;
}

void	printVector(std::vector<int>& v) {
	std::cout << "Vector: ";
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	printList(std::list<int>& l) {
	std::cout << "List: ";
	for (std::list<int>::iterator it = l.begin(); it != l.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

std::vector<int>	mergeVector(std::vector<int>& first, std::vector<int>& second) {
	std::vector<int>	merged;
	std::vector<int>::iterator	it1 = first.begin();
	std::vector<int>::iterator	it2 = second.begin();

	while (it1 != first.end() && it2 != second.end()) {
		if (*it1 < *it2) {
			merged.push_back(*it1);
			it1++;
		}
		else {
			merged.push_back(*it2);
			it2++;
		}
	}
	while (it1 != first.end()) {
		merged.push_back(*it1);
		it1++;
	}
	while (it2 != second.end()) {
		merged.push_back(*it2);
		it2++;
	}
	return merged;
}

std::list<int>	mergeList(std::list<int>& first, std::list<int>& second) {
	std::list<int>	merged;
	std::list<int>::iterator	it1 = first.begin();
	std::list<int>::iterator	it2 = second.begin();

	while (it1 != first.end() && it2 != second.end()) {
		if (*it1 < *it2) {
			merged.push_back(*it1);
			it1++;
		}
		else {
			merged.push_back(*it2);
			it2++;
		}
	}
	while (it1 != first.end()) {
		merged.push_back(*it1);
		it1++;
	}
	while (it2 != second.end()) {
		merged.push_back(*it2);
		it2++;
	}
	return merged;
}

std::vector<int>	mergeInsertVector(std::vector<int>& v) {

	if (v.size() <= 1) {
		return v;
	}

	// dividing the vector into two parts
	int	middle = v.size() / 2;
	std::vector<int>	first(v.begin(), v.begin() + middle);
	std::vector<int>	second(v.begin() + middle, v.end());

	// sorting the two parts
	first = mergeInsertVector(first);
	second = mergeInsertVector(second);

	// merging the two parts
	return mergeVector(first, second);
}

void	PmergeMe::sortVector(int argc, char **argv) {

	std::vector<int>	unsorted;

	for (int i = 1; i < argc; i++) {
		unsorted.push_back(atoi(argv[i]));
	}

	std::cout << "Before: ";
	printVector(unsorted);

	std::clock_t	start = std::clock();
	
	std::vector<int>	sorted = mergeInsertVector(unsorted);

	double	timeLapse = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * 100000;

	std::cout << "After: ";
	printVector(sorted);
	
	std::cout << "Time to process a range of " << argc - 1;
	std::cout << " elements with std::vector<int> : " << timeLapse;
	std::cout << " ~s" << std::endl;
}

std::list<int> mergeInsertList(std::list<int>& lst) {

	if (lst.size() <= 1) {
		return lst;
	}

	// Dividing the list into two parts
	int middle = lst.size() / 2;
	std::list<int>::iterator it = lst.begin();
	std::advance(it, middle);
	std::list<int> first(lst.begin(), it);
	std::list<int> second(it, lst.end());

	// Recursively sort the two parts
	first = mergeInsertList(first);
	second = mergeInsertList(second);

	// Merge the two sorted parts
	std::list<int> result;
	std::merge(first.begin(), first.end(), second.begin(), second.end(), std::back_inserter(result));

	return result;
}

void	PmergeMe::sortList(int argc, char **argv) {

	std::list<int>	unsorted;

	for (int i = 1; i < argc; i++) {
		unsorted.push_back(atoi(argv[i]));
	}

	std::cout << "Before: ";
	printList(unsorted);

	std::clock_t	start = std::clock();
	
	std::list<int>	sorted = mergeInsertList(unsorted);

	double	timeLapse = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * 100000;

	std::cout << "After: ";
	printList(sorted);
	
	std::cout << "Time to process a range of " << argc - 1;
	std::cout << " elements with std::list<int> : " << timeLapse;
	std::cout << " ~s" << std::endl;
}

bool	PmergeMe::isValidInputString(int argc, char **argv) {

	for (int i = 1; i < argc; i++) {
		if (std::string(argv[i]).find_first_not_of("0123456789 ") != std::string::npos) {
			return false;
		}
		if (atoi(argv[i]) < 0) {
			return false;
		}
	}
	return true;
}

bool	PmergeMe::isValidNumSequence(int argc, char **argv) {

	int	num = 0;
	std::vector<int>	numbers;

	for (int i = 1; i < argc; i++) {
		num = atoi(argv[i]);
		if (std::find(numbers.begin(), numbers.end(), num) != numbers.end()) {
			return false;
		}
		numbers.push_back(num);
	}
	return true;
}
