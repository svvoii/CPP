/*
** This class is another example of inheritance.
** `FragTrap` will inherit all the attributes and methods
** from the `ClapTrap` class. 
** It will be similar to the `ScavTrap` class, but will have
** its own individuality.
**
** `highFivesGuys` will be a unique method to the `FragTrap` class.
*/
#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	private:
		FragTrap(void);

	public:
		FragTrap(std::string name);
		~FragTrap(void);

		void highFivesGuys(void);

};

#endif
