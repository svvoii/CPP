/*
** This is a new header for this exercise. It defines the Brain class.
**
** The implementation contains an array of 100 ideas:
** `std::string ideas[100];` which will be used to store the ideas.
** This class will be used in `Dog` and `Cat` classes for them to have 
** a private `Brain*` attribute.
**
** Upon construction, the `Dog` and `Cat` classes will create their Brain
** using `new Brain()`. 
** Respectively, the `Dog` and `Cat` classes will delete their Brain using
** `delete this->brain;` in their destructors.
*/

#ifndef BRAIN_CLASS_HPP
# define BRAIN_CLASS_HPP

# include <iostream>
# include <string>

// Defining some ANSI escape codes for consol output colors
# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"


class Brain
{
	public:
		Brain(void);
		~Brain(void);

		std::string		ideas[100];
};

#endif
