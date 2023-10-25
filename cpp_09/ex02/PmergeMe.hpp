#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>

class PmergeMe {

	public:

		PmergeMe(void);
		PmergeMe(PmergeMe const & src);
		~PmergeMe(void);

		PmergeMe &operator=(PmergeMe const & rhs);

		void	sortVector(void);

	private:

};


#endif // PMERGE_ME_CLASS_HPP