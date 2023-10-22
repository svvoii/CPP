/*
** Source: 42 Piscine CPP
**
** 20_sub-typing_polymorphism
**
** This program demonstrates the use of
** sub-typing polymorphism in C++.
*/

#include <iostream>
#include <string>

// Character is the base class
class	Character {
	public:
		void	sayHelloTo(std::string const & target);
};

void	Character::sayHelloTo(std::string const & target) {
	std::cout << "Hello " << target << " !" << std::endl;
}

// Warrior is a derived class from Character
class	Warrior : public Character {
	public:
		void	sayHelloTo(std::string const & target);
};

void	Warrior::sayHelloTo(std::string const & target) {
	std::cout << "Go to hell.. " << target << ", I don't like you !" << std::endl;
}

int	main() {

	/* in this case the method called will depend on the
	type of the instance (Warrior) */
	Warrior		*warrior = new Warrior;

	/* in this case the method called will depend on the 
	type of the pointer (Character) */
	Character	*characterWarrior = new Warrior;

	warrior->sayHelloTo("student");
	characterWarrior->sayHelloTo("student");

	delete(warrior);
	delete(characterWarrior);

	return 0;
}

/*
** If we use the virtual keyword in the base class, the method
** called will depend on the type of the instance (Warrior)
** in both cases.

class	Character {
	public:
		virtual void	sayHelloTo(std::string const & target);
};

void	Character::sayHello(std::string const & target) {
	std::cout << "Hello " << target << " !" << std::endl;
}

class	Warrior : public Character {
	public:
		virtual void	sayHelloTo(std::string const & target);
};

void	Warrior::sayHello(std::string const & target) {
	std::cout << "Go to hell.. " << target << ", I don't like you !" << std::endl;
}

*/
