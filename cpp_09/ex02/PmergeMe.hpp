#ifndef PMERGEME_HPP
# define PMERGEME_HPP

// Defining some ANSI escape codes for consol output colors
# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"


# include <iostream>
# include <limits>
# include <climits>
# include <vector>
# include <list>
# include <algorithm>
# include <ctime>
# include <iterator>
# include <queue>
# include <iomanip>
# include <sys/time.h>

class PmergeMe {

	private:

		std::vector<int>	_vectorUnsorted;
		std::list<int>		_listUnsorted;

		std::vector<int>	_vSorted;
		std::list<int>		_lSorted;

		std::vector<int>	_vSortedFordJohnson;
		std::list<int>		_lSortedFordJohnson;

		double				_timeToMergeSortVector;
		double				_timeToMergeSortList;
		double				_timeToSortFordJohnsonVector;
		double				_timeToSortFordJohnsonList;

	public:

		PmergeMe(void);
		PmergeMe(PmergeMe const & src);
		PmergeMe &operator=(PmergeMe const & rhs);
		~PmergeMe(void);

		void				sort(int argc, char **argv);

		void				sortVector();
		std::vector<int>	splitInTwoThenMergeVector(std::vector<int>& v);
		std::vector<int>	mergeVector(std::vector<int>& v1, std::vector<int>& v2);

		void				sortList();
		std::list<int>		mergeInsertList(std::list<int>& lst);
		std::list<int>		mergeList(std::list<int>& first, std::list<int>& second);

		void				fordJohnsonSortVector();
		void				fordJohnsonSortList();

		// Helper functions
		template<typename T>
		void				saveUnsortedContainer(T& container, int argc, char **argv);
		template<typename T>
		void				printContainer(const T& container);
		bool				isValidInputString(int argc, char **argv);
		bool				isValidNumSequence(int argc, char **argv);

};

#endif
