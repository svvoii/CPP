/*
** Implementation of this calss has the same logic as Animal.class.hpp
** but in this case we will not use the virtual keyword for the
** makeSound() member function.
** This will result in the output of the base class's
** makeSound() member function instead of the derived class's
** makeSound(). 
*/

#ifndef WRONGANIMAL_CLASS_HPP
# define WRONGANIMAL_CLASS_HPP

# include <iostream>
# include <string>

// Defining some ANSI escape codes for consol output colors
# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"

class WrongAnimal
{
	protected:
		std::string _type;

	public:
		WrongAnimal(void);
		WrongAnimal(std::string type);
		WrongAnimal(WrongAnimal const &src);
		virtual ~WrongAnimal(void);

		WrongAnimal &operator=(WrongAnimal const &rhs);

		std::string getType(void) const;
		void makeSound(void) const;
};

#endif
