#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <algorithm>
# include <ctime>
# include <iterator>
# include <queue>

class PmergeMe {

	private:

		std::vector<int>	_vSorted;
		// std::list<int>		_list;

	public:

		PmergeMe(void);
		PmergeMe(PmergeMe const & src);
		~PmergeMe(void);

		PmergeMe &operator=(PmergeMe const & rhs);

		bool	isValidInputString(int argc, char **argv);
		bool	isValidNumSequence(int argc, char **argv);
		void	sortVector(int argc, char **argv);
		void	sortList(int argc, char **argv);

};


#endif // PMERGE_ME_CLASS_HPP