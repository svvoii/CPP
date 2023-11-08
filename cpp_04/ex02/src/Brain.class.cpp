/*
** Definition of the new Brain class for this exercise.
*/

#include "../includes/Brain.class.hpp"

/*
** Constructor and destructor.
*/
Brain::Brain(void) {

	std::cout << CYAN << "\t< Brain constructor called >" << RESET << std::endl;
}

Brain::~Brain(void) {

	std::cout << RED << "\t< Brain destructor called >" << RESET << std::endl;
}
