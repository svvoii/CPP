#include "PmergeMe.hpp"

/*
** Constructors
*/
PmergeMe::PmergeMe(void) {
}

PmergeMe::PmergeMe(PmergeMe const & src) {
	*this = src;
}

PmergeMe &PmergeMe::operator=(PmergeMe const & rhs) {

	if (this != &rhs) {
		this->_vSorted = rhs._vSorted;
		this->_lSorted = rhs._lSorted;
	}
	return *this;
}

PmergeMe::~PmergeMe() {
}

void	PmergeMe::sort(int argc, char **argv) {

	std::vector<std::string>	args(argv + 1, argv + argc);

	std::cout << std::endl << RED << "Before: " << RESET;
	printContainer(args);

	saveUnsortedContainer(_vectorUnsorted, argc, argv);
	saveUnsortedContainer(_listUnsorted, argc, argv);

	sortVector();

	sortList();

	fordJohnsonSortVector();

	fordJohnsonSortList();

	std::cout << YELLOW << "After : " RESET;
	printContainer(_vSorted);
	// printContainer(_lSorted);
	// printContainer(_vSortedFordJohnson);
	// printContainer(_lSortedFordJohnson);

	std::cout << GREEN << "Time to sort a range of " << RESET << argc - 1;
	std::cout << GREEN << " elements with merge-sort and std::vector<int>: " << RESET << std::fixed << std::setprecision(6) << _timeToMergeSortVector << " s;" << std::endl;

	std::cout << CYAN << "Time to sort a range of " << RESET << argc - 1;
	std::cout << CYAN << " elements with merge-sort and std::list<int>:   " << RESET << std::fixed << std::setprecision(6) << _timeToMergeSortList << " s;" << std::endl;

	std::cout << BLUE << "Time to sort a range of " << RESET << argc - 1;
	std::cout << BLUE << " elements with Ford-Johnson and std::vector<int>: " << RESET << std::fixed << std::setprecision(6) << _timeToSortFordJohnsonVector << " s;" << std::endl;

	std::cout << MAGENTA << "Time to sort a range of " << RESET << argc - 1;
	std::cout << MAGENTA << " elements with Ford-Johnson and std::list<int>:   " << RESET << std::fixed << std::setprecision(6) << _timeToSortFordJohnsonList << " s;" << std::endl;

	std::cout << std::endl;
}

/*
** SORT USING VECTOR
**
** The following 3 functions are used to sort a vector of integers
** using the merge-sort algorithm.
** This algorithm recursively splits the vector in two parts until
** each part contains only one element.
** 
** Then, the algorithm merges the two parts by comparing the elements
** of each part and pushing the smallest element into a new vector.
**
** `sortVector` is the main sorting function that calls the other two functions.
** First we declare a vector of `unsorted` integers and fill it with the
** values passed as arguments. We also print the unsorted vector.
** Then we call the `splitInTwoThenMergeVector` to sort the vector.
** Finally we print the sorted vector and the time it took to sort it.
*/
void	PmergeMe::sortVector() {

	struct timeval	start, end;

	gettimeofday(&start, NULL);
	this->_vSorted = splitInTwoThenMergeVector(_vectorUnsorted);
	gettimeofday(&end, NULL);

	_timeToMergeSortVector = ((end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec)) / 1000000.0;
}

/*
** In `splitInTwoThenMergeVector` function we recursively split the vector 
** in two parts until each part contains only one element (base if condition).
** On each recursive call, the function will split the vector in two parts
** and call itself on each part until the base if condition is met.
** Then, the function will call `mergeVector` to merge the two parts.
*/
std::vector<int>	PmergeMe::splitInTwoThenMergeVector(std::vector<int>& v) {

	if (v.size() <= 1) {
		return v;
	}

	// dividing the vector into two parts
	int	middle = v.size() / 2;
	std::vector<int>	first(v.begin(), v.begin() + middle);
	std::vector<int>	second(v.begin() + middle, v.end());

	// sorting the two parts
	first = splitInTwoThenMergeVector(first);
	second = splitInTwoThenMergeVector(second);

	// merging the two parts
	return mergeVector(first, second);
}

/*
** `mergeVector` will merge the two parts by comparing the elements of each part
** and pushing the smallest element into a new vector.
*/
std::vector<int>	PmergeMe::mergeVector(std::vector<int>& first, std::vector<int>& second) {

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

/*
** SORT USING LIST
*/
void	PmergeMe::sortList() {

	struct timeval	start, end;

	gettimeofday(&start, NULL);
	this->_lSorted = mergeInsertList(_listUnsorted);
	gettimeofday(&end, NULL);

	_timeToMergeSortList = ((end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec)) / 1000000.0;
}

std::list<int> PmergeMe::mergeInsertList(std::list<int>& lst) {

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

std::list<int>	PmergeMe::mergeList(std::list<int>& first, std::list<int>& second) {
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

/*
** FORD-JOHNSON ALGORITHM WITH VECTOR
*/
void	PmergeMe::fordJohnsonSortVector() {

	std::vector<std::pair<int, int> >	pairs;
	int n = _vectorUnsorted.size();
	struct timeval	start, end;

	gettimeofday(&start, NULL);

	// Pairing the elements of the vector and sorting them
	for (int i = 0; i < n - 1; i += 2) {
		if (_vectorUnsorted[i] < _vectorUnsorted[i + 1]) {
			pairs.push_back(std::make_pair(_vectorUnsorted[i], _vectorUnsorted[i + 1]));
		}
		else {
			pairs.push_back(std::make_pair(_vectorUnsorted[i + 1], _vectorUnsorted[i]));
		}
	}

	// If there is an unpaired element, we add it to the end of the vector
	if (n % 2 == 1) {
		pairs.push_back(std::make_pair(_vectorUnsorted[n - 1], INT_MAX));
	}

	// Merging the pairs into a sorted vector
	while (!pairs.empty()) {

		int min_index = 0;

		for (size_t i = 1; i < pairs.size(); i++) {
			if (pairs[i].first < pairs[min_index].first) {
				min_index = i;
			}
		}

		_vSortedFordJohnson.push_back(pairs[min_index].first);

		if (pairs[min_index].second != std::numeric_limits<int>::max()) {
			pairs[min_index].first = pairs[min_index].second;
			pairs[min_index].second = std::numeric_limits<int>::max();
		}
		else {
			pairs.erase(pairs.begin() + min_index);
		}
	}

	gettimeofday(&end, NULL);

	_timeToSortFordJohnsonVector = ((end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec)) / 1000000.0;

}

/*
** FORD-JOHNSON ALGORITHM WITH LIST
*/
void	PmergeMe::fordJohnsonSortList() {

	std::list<std::pair<int, int> >	pairs;
	int n = _listUnsorted.size();
	struct timeval	start, end;

	gettimeofday(&start, NULL);

	// Pairing the elements of the list and sorting them
	std::list<int>::iterator	it = _listUnsorted.begin();
	for (int i = 0; i < n - 1; i += 2) {

		std::list<int>::iterator	first = it++;
		std::list<int>::iterator	second = it++;
		if (*first < *second) {
			pairs.push_back(std::make_pair(*first, *second));
		}
		else {
			pairs.push_back(std::make_pair(*second, *first));
		}
	}

	// If there is an unpaired element, we add it to the end of the list
	if (n % 2 == 1) {
		pairs.push_back(std::make_pair(*it, INT_MAX));
	}

	// Merging the pairs into a sorted list
	while (!pairs.empty()) {

		std::list<std::pair<int, int> >::iterator	min_it = pairs.begin();
		//int min_index = 0;

		for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
			if (it->first < min_it->first) {
				min_it = it;
			}
		}

		_lSortedFordJohnson.push_back(min_it->first);

		if (min_it->second != INT_MAX) {
			min_it->first = min_it->second;
			min_it->second = INT_MAX;
		}
		else {
			pairs.erase(min_it);
		}
	}

	gettimeofday(&end, NULL);

	_timeToSortFordJohnsonList = ((end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec)) / 1000000.0;
}


/*
** Helper functions
*/

/*
** Saving the unsorted elements into container
*/
template <typename T>
void	PmergeMe::saveUnsortedContainer(T& container, int argc, char **argv) {

	for (int i = 1; i < argc; i++) {

		container.push_back(atoi(argv[i]));
	}
}

/*
** Printing out the container
*/
template <typename T>
void	PmergeMe::printContainer(const T& container) {

	typename T::const_iterator	it = container.begin();
	int count = 0;

	for (; it != container.end() && count < 14; it++, count++) {

		std::cout << CYAN << *it << " ";
	}

	if (it != container.end()) {
		std::cout << "[...]";
	}

	std::cout << RESET << std::endl;
}

/*
** The following functions are used to check the validity of the input
** before parsing it.
**
** `isValidInputString` checks if the input is a string of positive integers
*/
bool	PmergeMe::isValidInputString(int argc, char **argv) {

	for (int i = 1; i < argc; i++) {

		if (std::string(argv[i]).find_first_not_of("0123456789 ") != std::string::npos) {
			return false;
		}
	}
	return true;
}

/*
** `isValidNumSequence` checks if the input is a sequence of unique positive integers
*/
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
