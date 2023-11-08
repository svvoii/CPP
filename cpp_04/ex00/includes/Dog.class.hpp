/*
** This module will illustrate the concept of Polymorphism
** by using a base class and a derived class.
**
** `Dog` is a derived class of `Animal` and will inherit
** all of the public and protected members of `Animal`.
*/

#ifndef DOG_CLASS_HPP
# define DOG_CLASS_HPP

# include "Animal.class.hpp"

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(Dog const &src);
		virtual ~Dog(void);

		Dog &operator=(Dog const &rhs);

		void makeSound(void) const;
};

#endif
