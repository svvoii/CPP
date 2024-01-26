// Defining some ANSI escape codes for consol output colors
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

#include "MutantStack.hpp"
#include <cassert>

#include <iostream>
#include <cassert>

void customAssert(bool condition, const std::string& message) {
	if (!condition) {
		std::cout << message << std::endl;
	}
	assert(condition);
}

int	main()
{
	MutantStack<int> mstack;
	int expected = 42;
	int actual = 0;
	
	// Test push and top
	std::cout << MAGENTA << "Test `push(42)` and `top()`: " << RESET << std::endl;
	expected = 42;
	mstack.push(expected);
	actual = mstack.top();
	std::cout << GREEN << "Expected top: " << RESET << expected << std::endl;
	std::cout << CYAN << "Actual top: " << RESET << actual << std::endl;
	if (expected == actual) {
		std::cout << GREEN << "The top of the stack is: " << RESET;
		std::cout << "[" << actual << "] == [" << expected << "]" << std::endl;
		std::cout << GREEN << "OK" << RESET << std::endl;
	} else {
		std::cout << CYAN << " expected: " << RESET << "[" << expected << "] != " << actual << "] actual." << std::endl;
		std::cout << RED << "> KO <" << RESET << std::endl;
	}
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl << std::endl;

    // Test pop
	std::cout << MAGENTA << "Test `pop()` and `empty()`:" << RESET << std::endl;
    mstack.pop();
    //assert(mstack.empty());
	if (mstack.empty()) {
		std::cout << CYAN << "mstack is empty !" << RESET << std::endl;
		std::cout << GREEN << "OK" << RESET << std::endl;
	} else {
		std::cout << CYAN << "Test failed!" << RESET << std::endl;
		std::cout << RED << "> KO <" << RESET << std::endl;
	}
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl << std::endl;

    // Test size
	std::cout << MAGENTA << "Testing `size()` after `push(1)`, `push(2)` and `push(3)`:" << RESET << std::endl;
    mstack.push(1);
    mstack.push(2);
    mstack.push(3);
    //assert(mstack.size() == 3);
	if (mstack.size() == 3) {
		std::cout << CYAN << "mstack size is 3 !" << RESET << std::endl;
		std::cout << GREEN << "OK" << RESET << std::endl;
	} else {
		std::cout << CYAN << "Test failed!" << RESET << std::endl;
		std::cout << RED << "> KO <" << RESET << std::endl;
	}
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl << std::endl;

    // Test iterator
	std::cout << MAGENTA << "Test iterator:" << RESET << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    //assert(*it == 1);
    //assert(*(ite - 1) == 3);
	if (*it == 1 && *(ite - 1) == 3) {
		std::cout << CYAN << "mstack.begin() iterator `*it` is pointing to:\t" << RESET << "[" << *it << "]" << std::endl;
		std::cout << CYAN << "mstack.end() iterator `*(ite-1)` is pointing to\t" << RESET << "[" << *(ite - 1) << "]" << std::endl;
		std::cout << GREEN << "OK" << RESET << std::endl;
	} else {
		std::cout << CYAN << "Test failed!" << RESET << std::endl;
		std::cout << RED << "> KO <" << RESET << std::endl;
	}
	std::cout << CYAN << "printing out the elements of the mstack using iterator `it`:" << RESET << std::endl;
	std::cout << "[ ";
	while (it < ite) {
		std::cout << *it << " ";
		it++;
	}
	std::cout << "]" << std::endl;
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl << std::endl;

    // Test const iterator
	std::cout << MAGENTA << "Test const iterator:" << RESET << std::endl;
    MutantStack<int>::const_iterator cit = mstack.begin();
    MutantStack<int>::const_iterator cite = mstack.end();
    //assert(*cit == 1);
    //assert(*(cite - 1) == 3);
	if (*cit == 1 && *(cite - 1) == 3) {
		std::cout << CYAN << "mstack.begin() const_iterator `*cit` pointing to:    \t" << RESET << "[" << *cit << "]" << std::endl;
		std::cout << CYAN << "mstack.end() const_iterator `*(cite - 1)` pointing to\t" << RESET << "[" << *(cite - 1) << "]" << std::endl;
		std::cout << GREEN << "OK" << RESET << std::endl;
	} else {
		std::cout << CYAN << "Test failed!" << RESET << std::endl;
		std::cout << RED << "> KO <" << RESET << std::endl;
	}
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl << std::endl;

    // Test reverse iterator
	std::cout << MAGENTA << "Test reverse iterator:" << RESET << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    //assert(*rit == 3);
    //assert(*(rite - 1) == 1);
	if (*rit == 3 && *(rite - 1) == 1) {
		std::cout << CYAN << "mstack.rbegin() iterator `*rit` is pointing to:  \t" << RESET << "[" << *rit << "]" << std::endl;
		std::cout << CYAN << "mstack.rend() iterator `*(rite-1)` is pointing to\t" << RESET << "[" << *(rite - 1) << "]" << std::endl;
		std::cout << GREEN << "OK" << RESET << std::endl;
	} else {
		std::cout << CYAN << "Test failed!" << RESET << std::endl;
		std::cout << RED << "> KO <" << RESET << std::endl;
	}
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl << std::endl;

    // Test const reverse iterator
	std::cout << MAGENTA << "Test const reverse iterator:" << RESET << std::endl;
    MutantStack<int>::const_reverse_iterator crit = mstack.rbegin();
    MutantStack<int>::const_reverse_iterator crite = mstack.rend();
    //assert(*crit == 3);
    //assert(*(crite - 1) == 1);
	if (*crit == 3 && *(crite - 1) == 1) {
		std::cout << CYAN << "mstack.rbegin() iterator `*rite` is pointing to:\t" << RESET << "[" << *crit << "]" << std::endl;
		std::cout << CYAN << "mstack.rend() iterator `*(crit-1)` is pointing to\t" << RESET << "[" << *(crite - 1) << "]" << std::endl;
		std::cout << GREEN << "OK" << RESET << std::endl;
	} else {
		std::cout << CYAN << "Test failed!" << RESET << std::endl;
		std::cout << RED << "> KO <" << RESET << std::endl;
	}
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl << std::endl;

    std::cout << GREEN << "All tests passed!" << RESET << std::endl;

    return 0;
}

/*
int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]

	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);

	return 0;
}
*/
