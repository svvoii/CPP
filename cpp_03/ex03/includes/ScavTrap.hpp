/*
** This class will illustrate the concept of inheritance.
** It will inherit from the ClapTrap class, which was created
** in the previous exercise. (see `ClapTrap.hpp`)
**
** `ScavTrap` will inherit all the attributes and methods
** from the `ClapTrap` class. It will be a derived robot.
**
** `ScavTrap` class will have different messages in its 
** constructor, destructor and attack method to show that
** its own individuality.
**
** `ScavTrap` will use the attributes of `ClapTrap` class,
** which must be initialuzed to:
** `_name` = "ScavTrap" by default or the name passed to it. 
** `_hitPoints` = 100, representing the amount of health points.
** `_energyPoints` = 50, representing the amount of energy points.
** `_attackDamage` = 20, representing the amount of damage points.
**
** `ScavTrap` will have one additional method called `guardGate`.
** `guardGate` will have a unique message stating that the `ScavTrap`
** is in the Gate keeper mode.
**
** In order to avoid double inheritance of `ClapTrap` class by
** `DiamondTrap` we add the keyword `virtual` to the declaration
** statement below.
*/
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
	protected:
		ScavTrap(void);

	public:
		ScavTrap(std::string name);
		~ScavTrap(void);

		void attack(std::string const &target);
		void guardGate(void);

};

#endif
