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

/*
** The following 3 functions are used to sort a vector of integers
** using the merge-sort algorithm.
** Th algorithm recursively splits the vector in two parts until
** each part contains only one element.
** 
** Then, the algorithm merges the two parts by comparing the elements
** of each part and pushing the smallest element into a new vector.
**
** `sortVector` is the main function that calls the other two functions.
** First we declare a vector of `unsorted` integers and fill it with the
** values passed as arguments. We also print the unsorted vector.
** Then we call the `splitInTwoThenMergeVector` to sort the vector.
** Finally we print the sorted vector and the time it took to sort it.
*/
void	PmergeMe::sortVector(int argc, char **argv) {

	std::vector<int>	unsorted;

	for (int i = 1; i < argc; i++) {
		unsorted.push_back(atoi(argv[i]));
	}

	std::cout << "Before: ";
	printVector(unsorted);

	std::clock_t	start = std::clock();
	
	this->_vSorted = splitInTwoThenMergeVector(unsorted);

	double	timeLapse = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * 100000;

	std::cout << "After: ";
	printVector(this->_vSorted);
	
	std::cout << "Time to process a range of " << argc - 1;
	std::cout << " elements with std::vector<int> : " << timeLapse;
	std::cout << " ~s" << std::endl;
}

/*
** In `splitInTwoThenMergeVector` function we recursively split the vector 
** in two parts until each part contains only one element (base if condition).
** On each recursive call, the function will split the vector in two parts
** and call itself on each part until the base if condition is met.
** Then, the function will call `mergeVector` to merge the two parts.
*/
static std::vector<int>	splitInTwoThenMergeVector(std::vector<int>& v) {

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
static std::vector<int>	mergeVector(std::vector<int>& first, std::vector<int>& second) {
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
** 
*/
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
		if (atoi(argv[i]) < 0) {
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

/*
** Ford-Johnson algorithm
**
** This implementation constructs a graph of tasks, 
** where each task represents a number in the sequence. 
** The graph is then used to find the longest path, 
** which represents the optimal order in which to perform the tasks. 
**
** The sorted sequence is then constructed by performing the tasks in the optimal order.

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
*/

using namespace std;

/*
** Here we definingthe struct Task to represent each number in the sequence.
** Each task has a value and a list of dependencies.
** The value is the number itself.
** The dependencies are the indices of all numbers (in the unsorted sequence)
** that come before the number/value in the given task.
**
** For example, if the sequence is {3, 1, 4, 2}, and we are constructing the task for 4,
** then the value of the task is 4, and the dependencies are the indices of 3 and 1,
** `dependencies = {0, 1}`.
** because 3 and 1 come before 4 in the unsorted sequence.
*/
struct Task {
	int value; // The value of the number
	vector<int> dependencies; // The indices of the numbers that come before this number
};

// Define a function to construct the graph for the Ford-Johnson algorithm
vector<Task> constructGraph(vector<int>& sequence) {
	vector<Task> graph(sequence.size());
	for (int i = 0; i < sequence.size(); i++) {
		graph[i].value = sequence[i];
		for (int j = 0; j < i; j++) {
			if (sequence[j] < sequence[i]) {
				graph[i].dependencies.push_back(j);
			}
		}
	}
	return graph;
}

// Define a function to find the longest path in the graph using the Bellman-Ford algorithm
vector<int> findLongestPath(vector<Task>& graph) {
	vector<int> dist(graph.size(), numeric_limits<int>::min());
	dist[0] = 0;
	for (int i = 0; i < graph.size(); i++) {
		for (int j = 0; j < graph[i].dependencies.size(); j++) {
			int k = graph[i].dependencies[j];
			if (dist[k] + graph[k].value > dist[i]) {
				dist[i] = dist[k] + graph[k].value;
			}
		}
	}
	return dist;
}

// Define a function to sort the sequence using the Ford-Johnson algorithm
vector<int> fordJohnsonSort(vector<int>& sequence) {
	vector<Task> graph = constructGraph(sequence);
	vector<int> dist = findLongestPath(graph);
	vector<int> sorted(sequence.size());
	priority_queue<pair<int, int>> pq;
	for (int i = 0; i < sequence.size(); i++) {
		pq.push(make_pair(dist[i], sequence[i]));
	}
	for (int i = 0; i < sequence.size(); i++) {
		sorted[i] = pq.top().second;
		pq.pop();
	}
	return sorted;
}

/*
// Define a main function to test the Ford-Johnson algorithm
int main() {
	vector<int> sequence = {3, 1, 4, 2};
	vector<int> sorted = fordJohnsonSort(sequence);
	for (int i = 0; i < sorted.size(); i++) {
		cout << sorted[i] << " ";
	}
	cout << endl;
	return 0;
}
*/
