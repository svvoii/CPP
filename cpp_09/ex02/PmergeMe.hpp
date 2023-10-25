#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <algorithm>
# include <ctime>

class PmergeMe {

	private:

		std::vector<int>	_vector;
		std::list<int>		_list;

	public:

		PmergeMe(void);
		PmergeMe(PmergeMe const & src);
		~PmergeMe(void);

		PmergeMe &operator=(PmergeMe const & rhs);

		bool	isValidInput(int argc, char **argv);
		void	sortVector(int argc, char **argv);
		void	sortList(int argc, char **argv);

};


#endif // PMERGE_ME_CLASS_HPP