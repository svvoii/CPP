/*
** This module will illustrate the concept of Polymorphism
** by using a base class and a derived class.
**
** `Cat` is a derived class of `Animal` and will inherit
** all of the public and protected members of `Animal`.
**
** In this exercise, we will add a private attribute to
** the `Cat` class. This attribute will be a pointer to
** a `Brain` object.
**
** When a `Cat` object is created, it will create a `Brain`
** object using `new Brain()`.
** It will also make a deep copy of the `Brain` object
** when a copy of a `Cat` object is made.
**
** The `Brain` class is defined as separate class in the 
** `Brain.class.hpp` header file.
*/

#ifndef CAT_CLASS_HPP
# define CAT_CLASS_HPP

# include "AAnimal.class.hpp"
# include "Brain.class.hpp"

class Cat : public AAnimal
{
	private:
		Brain*	_brain;

		void	_copyBrain(Brain const &src);
		void	_deleteBrain(void);

	public:
		Cat(void);
		Cat(Cat const &src);
		virtual ~Cat(void);

		Cat &operator=(Cat const &rhs);

		void makeSound(void) const;
};

#endif

/*
** Deep copy means that the copy of an object will also
** copy the objects that it contains.
** In this case, the `Cat` class contains a pointer to
** a `Brain` object. When a copy of a `Cat` object is
** made, the `Brain` object will also be copied.
**
** Some general information about deep copy:
** A deep copy is a copy of an object that also copies 
** all of the object's internal data. 
** In C++, this means that a deep copy will copy all of 
** the object's member variables, including any pointers,
** and create new copies of any objects that are pointed to.
** This is in contrast to a shallow copy, which only copies 
** the object's member variables, but not any of the objects 
** that are pointed to by pointers.
*/