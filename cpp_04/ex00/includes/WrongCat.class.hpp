/*
** This class inherits from the `WrongAnimal` class.
** Its usage in the main function will show that the base class's
** makeSound() member function will be called instead of the derived
** `WrongCat` class's makeSound() member function.
*/

#ifndef WRONGCAT_CLASS_HPP
# define WRONGCAT_CLASS_HPP

# include "WrongAnimal.class.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(WrongCat const &src);
		virtual ~WrongCat(void);

		WrongCat &operator=(WrongCat const &rhs);

		void makeSound(void) const;
};

#endif
