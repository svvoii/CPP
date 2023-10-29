#include "includes/Weapon.class.hpp"
#include "includes/HumanA.class.hpp"
#include "includes/HumanB.class.hpp"

int main(void) {
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);

		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");

		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}

/*
** The two main differences between the two implementations is that
** `HumanA` class does not have `setWeapon` method, and the wepon
** has to be set during initialization of the `HumanA` object.
**
** `HumanB` class has `setWeapon` method, and the weapon, so
** an instance of `HumanB` can be initialized without a weapon,
** and the weapon can be set later. 
**
** To answer the question from the task:
** "In which case do you think it would be best to use a pointer to Weapon?"
**
** ..it would be best to use a pointer to Weapon in the case where we want
** to change the type of the weapon dynamically during runtime. 
** This is because when we use a pointer to Weapon,
** we can change the value of the object it points to at any time,
** (in case of `HumanB` class, we can change the weapon of the instance of `HumanB` class) 
**
** whereas if we use a reference to Weapon, we cannot change the object 
** it refers to after initialization (in case of `HumanA` class, 
** we cannot change the weapon of the instance of `HumanA` class after initialization)
*/