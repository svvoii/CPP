// Defining some ANSI escape codes for consol output colors
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

#include "includes/Span.class.hpp"

#define		N				200
#define		MIN_RANGE		0
#define		MAX_RANGE		10000
#define		AMOUNT			10

int main()
{
	Span sp(N);
	int random = 0;

	try {
		/////////////////////////////////////////////////////////////////
		// Fill the Span up to AMOUNT with random numbers using addNumber()
		std::cout << MAGENTA << "Filling the Span with numbers using addNumber() in a random manner";
		std::cout << " with a range from " << MIN_RANGE << " to " << MAX_RANGE << RESET << std::endl;
		for (int i = 0; i < AMOUNT; i++) {

			random = rand() % (MAX_RANGE - MIN_RANGE) + MIN_RANGE;
			sp.addNumber(random);
		}
		std::cout << CYAN << "Printing out resulting Span:" << RESET << std::endl;
		sp.printSpan();
		std::cout << GREEN << "Shortest span:\t" << RESET << sp.shortestSpan() << std::endl;
		std::cout << RED << "Longest span:\t" << RESET << sp.longestSpan() << std::endl;
		std::cout << std::endl;

		/////////////////////////////////////////////////////////////////
		// Fill the Span with a range of iterators using addRangeOfIterators()
		std::cout << MAGENTA << "Filling the Span with a range of iterators using addRangeOfIterators()" << std::endl;
		std::vector<int> vec;
		for (int i = 1; i < AMOUNT; i += 2) {
			vec.push_back(i);
		}
		sp.addRangeOfIterators(vec.begin(), vec.end());
		std::cout << CYAN << "Printing out resulting Span:" << RESET << std::endl;
		sp.printSpan();

		std::cout << GREEN << "Shortest span:\t" << RESET << sp.shortestSpan() << std::endl;
		std::cout << RED << "Longest span:\t" << RESET << sp.longestSpan() << std::endl;
		std::cout << std::endl;

		/////////////////////////////////////////////////////////////////
		// Fill the Span with random numbers using addRandomNumbers(amount, lower bound, upper bound)
		std::cout << MAGENTA << "Filling the Span with random numbers {10, 0, 10000}" << std::endl;
		sp.addRandomNumbers(10, 0, 10000);
		std::cout << CYAN << "Printing out resulting Span:" << RESET << std::endl;
		sp.printSpan();

		std::cout << GREEN << "Shortest span:\t" << RESET << sp.shortestSpan() << std::endl;
		std::cout << RED << "Longest span:\t" << RESET << sp.longestSpan() << std::endl;
		std::cout << std::endl;

		/////////////////////////////////////////////////////////////////
		// Fill the Span with a fixed range of numbers 
		std::cout << MAGENTA << "Filling the Span with a fixed range using addRange(begin, end) 1 - 5" << std::endl;
		sp.addRange(1, 5);
		std::cout << CYAN << "Printing out resulting Span:" << RESET << std::endl;
		sp.printSpan();

		std::cout << GREEN << "Shortest span:\t" << RESET << sp.shortestSpan() << std::endl;
		std::cout << RED << "Longest span:\t" << RESET << sp.longestSpan() << std::endl;
		std::cout << std::endl;
		
	}
	catch (const Span::NotEnoughNumbersException& e) {
		std::cerr << "error: " << e.what() << '\n';
	}
	catch (const Span::FullSpanException& e) {
		std::cerr << "error: " << e.what() << '\n';
	}

	return 0;
}

/*
** test from the task description:

int	main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Shortest span:\t" << sp.shortestSpan() << std::endl;
	std::cout << "Longest span:\t" << sp.longestSpan() << std::endl;

	return (0);
}
*/
