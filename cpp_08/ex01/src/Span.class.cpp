#include "../includes/Span.class.hpp"

Span::Span(unsigned int N) : _N(N) {
	return ;
}

Span::Span(Span const &other) {
	*this = other;
	return ;
}

Span::~Span(void) {
	return ;
}

Span	&Span::operator=(Span const &other) {

	if (this != &other) {
		this->_N = other._N;
		this->_vec = other._vec;
	}

	return (*this);
}

int		Span::getSpanSize(void) const {
	return (this->_vec.size());
}

/*
** `addNumber` simply adds a number to the Span, to fill it in.
*/
void	Span::addNumber(int n) {
	if (this->_vec.size() == this->_N) {
		throw Span::FullSpanException();
	}
	this->_vec.push_back(n);

	return ;
}

/*
** `shortestSpan` claculates the shortest span between all the numbers.
** First we check if there are at least 2 numbers stored in the Span.
** Then we create a copy of the vector and sort it.
** We then pick the difference between the first 2 numbers
** and store it in `min`.
** We then loop through the sorted vector and check if the difference
** the following 2 numbers is smaller than `min` and if it is, we
** `min` is updated with the new minimum difference.
*/
int		Span::shortestSpan(void) {

	if (this->_vec.size() < 2) {
		throw Span::NotEnoughNumbersException();
	}

	std::vector<int>	tmp(this->_vec);
	std::sort(tmp.begin(), tmp.end());
	int					min = tmp[1] - tmp[0];

	for (unsigned int i = 2; i < tmp.size(); i++) {
		if (tmp[i] - tmp[i - 1] < min) {
			min = tmp[i] - tmp[i - 1];
		}
	}

	return (min);
}

/*
** `longestSpan` claculates the longest span between all the numbers.
** First we check if there are at least 2 numbers stored in the Span.
** Then we create a copy of the vector and sort it.
** We then pick the difference between the first and last numbers
** and return it.
*/
int		Span::longestSpan(void) {

	if (this->_vec.size() < 2) {
		throw Span::NotEnoughNumbersException();
	}

	std::vector<int>	tmp(this->_vec);
	std::sort(tmp.begin(), tmp.end());

	return (tmp[tmp.size() - 1] - tmp[0]);
}

/*
** `addRange` takes 2 arguments:
** `begin` - the beginning of the range
** `end` - the end of the range
** It will add all CONSECUTIVE numbers between `begin` and `end` inclusive.
** For example, if `begin = 1` and `end = 3`, it will add 1, 2, 3.
*/
void	Span::addRange(size_t begin, size_t end) {

	if (begin >= end || (end <= 0 || begin <= 0) || this->_vec.size() + (end - begin) > this->_N) {
		throw Span::FullSpanException();
	}

	for (size_t i = 0; i < (end - begin + 1); i++) {
		this->_vec.push_back(begin + i);
	}
	//this->_vec.insert(this->_vec.end(), begin, end);
}

/*
*/
void	Span::addRangeOfIterators(std::vector<int>::iterator begin, std::vector<int>::iterator end) {

	if (begin >= end || this->_vec.size() + (end - begin) > this->_N) {
		throw Span::FullSpanException();
	}

	this->_vec.insert(this->_vec.end(), begin, end);
}

/*
** `addRandomNumbers` takes 3 arguments:
** `amount` - the amount of numbers to add to the Span
** `lowerBound` - the lower bound of the range of random numbers
** `upperBound` - the upper bound of the range of random numbers
** It will add `amount` random numbers to the Span.
*/
void	Span::addRandomNumbers(size_t amount, int lowerBound, int upperBound) {

	if (this->_vec.size() + amount > this->_N) {
		throw Span::FullSpanException();
	}

	int randNum = 0;
	for (size_t i = 0; i < amount; ++i) {
		randNum = lowerBound + (rand() % (upperBound - lowerBound + 1));
		this->_vec.push_back(randNum);
	}
}

/*
** This is helper function to print the contents of a container.
*/
void	Span::printSpan(void) {
	
	std::vector<int>::iterator it;

	std::cout << "Span: ";
	for (it = this->_vec.begin(); it != this->_vec.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Span size:\t" << Span::getSpanSize() << std::endl;
}


const char	*Span::FullSpanException::what(void) const throw() {
	return ("Span is full");
}

const char	*Span::NotEnoughNumbersException::what(void) const throw() {
	return ("Not enough numbers");
}
