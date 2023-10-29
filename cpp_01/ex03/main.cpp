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
** To answer the question from the task:
** "In which case do you think it would be best to use a pointer to Weapon?"
** So, it would be best to use a pointer to Weapon in the case where we want
** to change the type of the weapon dynamically during runtime. 
** This is because when we use a pointer to Weapon,
**  we can change the value of the object it points to at any time, 
** whereas if we use a reference to Weapon, we cannot change the object 
** it refers to after initialization.
*/