/*
** This module will illustrate the concept of Polymorphism
** by using a base class and a derived class.
** The base class will be called Animal and the derived class
** will be called Cat and Dog.
**
** Both derived classes will inherit from the base class.
** `Animal` as a base class will have a virtual function
** is `makeSound()` and the derived classes will override
** the function. 
*/

#ifndef ANIMAL_CLASS_HPP
# define ANIMAL_CLASS_HPP

# include <iostream>
# include <string>

// Defining some ANSI escape codes for consol output colors
# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"

class Animal
{
	protected:
		std::string _type;

	public:
		Animal(void);
		Animal(std::string type);
		Animal(Animal const &src);
		virtual ~Animal(void);

		Animal &operator=(Animal const &rhs);

		std::string getType(void) const;
		virtual void makeSound(void) const;
};

#endif

/*
** The `virtual` keyword in `virtual ~Animal(void)` destructor
** indicates that it is a virtual destructor. 
** A virtual destructor is used when a class is intended to be 
** used as a base class for other derived classes. 
** It ensures that the destructor of the derived class is called 
** when an object of the derived class is destroyed. 
*/
