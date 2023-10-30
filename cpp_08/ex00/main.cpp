#include "easyfind.hpp"

#define MIN			10
#define MAX			50
#define MAX_COUNT	20
#define TO_FIND		42

int		main(void)
{
	std::vector<int>		vect;
	std::list<int>			lst;
	std::deque<int>			deque;
	std::set<int>			set;
	std::multiset<int>		multiset;

	std::cout << "Fill containers with random numbers..." << std::endl;
	std::cout << "Vector:  \t";
	fillWithRandomNumbers(vect, MIN, MAX, MAX_COUNT);
	printContainer(vect);

	std::cout << "List:    \t";
	fillWithRandomNumbers(lst, MIN, MAX, MAX_COUNT);
	printContainer(lst);

	std::cout << "Deque:   \t";
	fillWithRandomNumbers(deque, MIN, MAX, MAX_COUNT);
	printContainer(deque);

	std::cout << "Set:     \t";
	fillWithRandomNumbers(set, MIN, MAX, MAX_COUNT);
	printContainer(set);

	std::cout << "Multiset:\t";
	fillWithRandomNumbers(multiset, MIN, MAX, MAX_COUNT);
	printContainer(multiset);

	std::cout << std::endl;
	std::cout << "Try to find [" << TO_FIND << "] in each container:" << std::endl;

	std::cout << "Looking for [" << TO_FIND << "] in Vecotr... ";
	easyfind(vect, TO_FIND);

	std::cout << "Looking for [" << TO_FIND << "] in a List... ";
	easyfind(lst, TO_FIND);

	std::cout << "Looking for [" << TO_FIND << "] in Deque... ";
	easyfind(deque, TO_FIND);

	std::cout << "Looking for [" << TO_FIND << "] in a Set... ";
	easyfind(set, TO_FIND);

	std::cout << "Looking for [" << TO_FIND << "] in Multiset... ";
	easyfind(multiset, TO_FIND);

	return (0);
};
