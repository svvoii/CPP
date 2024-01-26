// Defining some ANSI escape codes for consol output colors
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

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

	std::cout << "Fill containers with random numbers..." << RESET << std::endl;
	std::cout << GREEN << "Vector:  \t";
	fillWithRandomNumbers(vect, MIN, MAX, MAX_COUNT);
	printContainer(vect);

	std::cout << BLUE << "List:    \t";
	fillWithRandomNumbers(lst, MIN, MAX, MAX_COUNT);
	printContainer(lst);

	std::cout << RED << "Deque:   \t";
	fillWithRandomNumbers(deque, MIN, MAX, MAX_COUNT);
	printContainer(deque);

	std::cout << CYAN << "Set:     \t";
	fillWithRandomNumbers(set, MIN, MAX, MAX_COUNT);
	printContainer(set);

	std::cout << MAGENTA << "Multiset:\t";
	fillWithRandomNumbers(multiset, MIN, MAX, MAX_COUNT);
	printContainer(multiset);

	std::cout << RESET << std::endl;
	std::cout << "Try to find [" << TO_FIND << "] in each container:" << std::endl;

	std::cout << GREEN << "Looking for [" << TO_FIND << "] in Vecotr... ";
	easyfind(vect, TO_FIND);

	std::cout << BLUE << "Looking for [" << TO_FIND << "] in a List... ";
	easyfind(lst, TO_FIND);

	std::cout << RED << "Looking for [" << TO_FIND << "] in Deque... ";
	easyfind(deque, TO_FIND);

	std::cout << CYAN << "Looking for [" << TO_FIND << "] in a Set... ";
	easyfind(set, TO_FIND);

	std::cout << MAGENTA << "Looking for [" << TO_FIND << "] in Multiset... ";
	easyfind(multiset, TO_FIND);
	std::cout << RESET << std::endl;

	return (0);
};
