/*
** This module will illustrate the concept of Polymorphism
** by using a base class and a derived class.
**
** `Cat` is a derived class of `Animal` and will inherit
** all of the public and protected members of `Animal`.
*/

#ifndef CAT_CLASS_HPP
# define CAT_CLASS_HPP

# include "Animal.class.hpp"

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(Cat const &src);
		virtual ~Cat(void);

		Cat &operator=(Cat const &rhs);

		void makeSound(void) const;
};

#endif
