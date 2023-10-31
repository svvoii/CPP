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
	std::cout << "Test `push(42)` and `top()`: " << std::endl;
	expected = 42;
	mstack.push(expected);
	actual = mstack.top();
	std::cout << "Expected top: " << expected << std::endl;
	std::cout << "Actual top: " << actual << std::endl;
	if (expected == actual) {
		std::cout << "The top of the stack is: [" << actual;
		std::cout << "] == [" << expected << "]" << std::endl;
		std::cout << "OK" << std::endl;
	} else {
		std::cout << " expected: [" << expected << "] != " << actual << "] actual." << std::endl;
		std::cout << "> KO <" << std::endl;
	}
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl;

    // Test pop
	std::cout << "Test `pop()` and `empty()`:" << std::endl;
    mstack.pop();
    //assert(mstack.empty());
	if (mstack.empty()) {
		std::cout << "mstack is empty !" << std::endl;
		std::cout << "OK" << std::endl;
	} else {
		std::cout << "Test failed!" << std::endl;
		std::cout << "> KO <" << std::endl;
	}
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl;

    // Test size
	std::cout << "Test `push(1 to 3)` and `size()`:" << std::endl;
    mstack.push(1);
    mstack.push(2);
    mstack.push(3);
    //assert(mstack.size() == 3);
	if (mstack.size() == 3) {
		std::cout << "mstack size is 3 !" << std::endl;
		std::cout << "OK" << std::endl;
	} else {
		std::cout << "Test failed!" << std::endl;
		std::cout << "> KO <" << std::endl;
	}
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl;

    // Test iterator
	std::cout << "Test iterator:" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    //assert(*it == 1);
    //assert(*(ite - 1) == 3);
	if (*it == 1 && *(ite - 1) == 3) {
		std::cout << "mstack.begin() iterator `*it` is pointing to:\t[" << *it << "]" << std::endl;
		std::cout << "mstack.end() iterator `*(ite-1)` is pointing to\t[" << *(ite - 1) << "]" << std::endl;
		std::cout << "OK" << std::endl;
	} else {
		std::cout << "Test failed!" << std::endl;
		std::cout << "> KO <" << std::endl;
	}
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl;

    // Test const iterator
	std::cout << "Test const iterator:" << std::endl;
    MutantStack<int>::const_iterator cit = mstack.begin();
    MutantStack<int>::const_iterator cite = mstack.end();
    //assert(*cit == 1);
    //assert(*(cite - 1) == 3);
	if (*cit == 1 && *(cite - 1) == 3) {
		std::cout << "mstack.begin() const_iterator `*cit` pointing to:    \t[" << *cit << "]" << std::endl;
		std::cout << "mstack.end() const_iterator `*(cite - 1)` pointing to\t[" << *(cite - 1) << "]" << std::endl;
		std::cout << "OK" << std::endl;
	} else {
		std::cout << "Test failed!" << std::endl;
		std::cout << "> KO <" << std::endl;
	}
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl;

    // Test reverse iterator
	std::cout << "Test reverse iterator:" << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    //assert(*rit == 3);
    //assert(*(rite - 1) == 1);
	if (*rit == 3 && *(rite - 1) == 1) {
		std::cout << "mstack.rbegin() iterator `*rit` is pointing to:  \t[" << *rit << "]" << std::endl;
		std::cout << "mstack.rend() iterator `*(rite-1)` is pointing to\t[" << *(rite - 1) << "]" << std::endl;
		std::cout << "OK" << std::endl;
	} else {
		std::cout << "Test failed!" << std::endl;
		std::cout << "> KO <" << std::endl;
	}
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl;

    // Test const reverse iterator
	std::cout << "Test const reverse iterator:" << std::endl;
    MutantStack<int>::const_reverse_iterator crit = mstack.rbegin();
    MutantStack<int>::const_reverse_iterator crite = mstack.rend();
    //assert(*crit == 3);
    //assert(*(crite - 1) == 1);
	if (*crit == 3 && *(crite - 1) == 1) {
		std::cout << "mstack.rbegin() iterator `*rite` is pointing to:\t[" << *crit << "]" << std::endl;
		std::cout << "mstack.rend() iterator `*(crit-1)` is pointing to\t[" << *(crite - 1) << "]" << std::endl;
		std::cout << "OK" << std::endl;
	} else {
		std::cout << "Test failed!" << std::endl;
		std::cout << "> KO <" << std::endl;
	}
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl;

    std::cout << "All tests passed!" << std::endl;

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
