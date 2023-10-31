/*
** Here we have the Span class.
** Span class can store a maximum of N unsigned int.
** `N` is the only parameter passed to the constructor.
**
** Span class has 3 member functions:
** `addNumber` which adds a number to the Span, to fill it in.
** If the new `N` element already exists, an exception is thrown.
**
** `shortestSpan` - shall return the shortest span (distance) between
** all the numbers stored in the Span. 
** If there are less than 2 numbers stored an exception is thrown.
**
** `longestSpan` - shall return the longest span (distance) between
** all the numbers stored in the Span.
** If there are less than 2 numbers stored an exception is thrown.
*/

#ifndef SPAN_CLASS_HPP
# define SPAN_CLASS_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>


class Span
{
	private:
		unsigned int		_N;
		std::vector<int>	_vec;

	public:
		Span(unsigned int N);
		Span(Span const &other);
		~Span(void);

		Span	&operator=(Span const &other);

		int		getSpanSize(void) const;
		void	addRange(size_t begin, size_t end);
		void	addRangeOfIterators(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		void	addRandomNumbers(size_t amount, int lowerBound, int upperBound);
		void	addNumber(int n);
		int		shortestSpan(void);
		int		longestSpan(void);

		void	printSpan(void);

		class	FullSpanException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};

		class	NotEnoughNumbersException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
};

#endif
