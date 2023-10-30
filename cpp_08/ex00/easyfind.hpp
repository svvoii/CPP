#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <list>
# include <deque>
# include <set>
# include <map>
# include <typeinfo>
# include <algorithm>
# include <cstdlib>

/*
** `easyfind` is the function template
** It will take two arguments, 
** a `type T` container and an `int` value.
** The function has to find the first occurence of the value in the container.
*/

template <typename T>
void	easyfind(T &container, int value)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), value);
	if (it == container.end()) {
		std::cout << "..there is no " << value << " in here :(" << std::endl;	
		return ;
	}
	int index = std::distance(container.begin(), it);
	std::cout << "..here it is >>> [" << *it << "] at index [" << index << "]" << std::endl;
}

template <typename T>
void	printContainer(const T &container) {

	typename T::const_iterator it;

	for (it = container.begin(); it != container.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void fillWithRandomNumbers(T &container, int rangeStart, int rangeEnd, int count) {

	int randNum;

	for (int i = 0; i < count; ++i) {
		randNum = rangeStart + (rand() % (rangeEnd - rangeStart + 1));
		container.insert(container.end(), randNum);
	}
}

#endif