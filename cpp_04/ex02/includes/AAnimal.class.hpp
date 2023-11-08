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
**
** In this exercise, we change the `makeSound()` function
** to a pure virtual function. 
** A pure virtual function is a function that is declared
** in the base class but has no implementation.
** A pure virtual function is declared by adding `= 0` to
** the end of the function declaration.
** A class that contains a pure virtual function is called
** an abstract class.
**
** So, in this exercise, the `Animal` class is an abstract
** class. And it shall not be instantiated once a derived
** class is created.
*/

#ifndef AANIMAL_CLASS_HPP
# define AANIMAL_CLASS_HPP

# include <iostream>
# include <string>

// Defining some ANSI escape codes for consol output colors
# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"

class AAnimal
{
	protected:
		std::string _type;

	public:
		AAnimal(void);
		AAnimal(std::string type);
		AAnimal(AAnimal const &src);
		virtual ~AAnimal(void);

		AAnimal &operator=(AAnimal const &rhs);

		std::string getType(void) const;
		virtual void makeSound(void) const = 0;
};

#endif
