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

Brain::Brain(Brain const &src) {

	*this = src;

	std::cout << CYAN << "\t< Brain copy constructor called >" << RESET << std::endl;
}

Brain::~Brain(void) {

	std::cout << RED << "\t< Brain destructor called >" << RESET << std::endl;
}

Brain &Brain::operator=(Brain const &rhs) {

	std::cout << CYAN << "\t< Brain assignment operator called >" << RESET << std::endl;

	if (this != &rhs) {
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = rhs.ideas[i];
		}
	}
	return (*this);
}

/*
** Getter and setter for the ideas array.
*/
void	Brain::setIdea(int index, std::string idea) {

	this->ideas[index] = idea;
}

std::string	Brain::getIdea(int index) const {

	return (this->ideas[index]);
}
