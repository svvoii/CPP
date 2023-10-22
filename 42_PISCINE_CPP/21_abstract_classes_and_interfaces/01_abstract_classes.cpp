/*
** Source: 42 Piscine CPP
**
** 21_abstract_classes_and_interfaces
**
** This program demonstrates the use of
** abstract classes in C++.
*/

#include <iostream>
#include <string>

#include <iostream>
#include <string>

// Abstract class for characters
class ACharacter {
	private:
		std::string name; // Private member variable for character name

	public:
		// Pure virtual function for character attack
		virtual void attack(std::string const & target) = 0;

		// Function to greet a target character
		void sayHelloTo(std::string const & target);

		// Setter for character name
		void setName(std::string const & name) {
			this->name = name;
		}

		// Getter for character name
		std::string getName() const {
			return name;
		}
};

// Warrior class derived from Character
class Warrior : public ACharacter {
	public:
		// Implementation of attack function for Warrior
		virtual void attack(std::string const & target);
};

// Function to greet a target character
void ACharacter::sayHelloTo(std::string const & target) {
	std::cout << "Hello " << target << " !" << std::endl;
}

// Implementation of attack function for Warrior
void Warrior::attack(std::string const & target) {
	std::cout << getName() << " attacks " << target << " with a sword" << std::endl;
}

// Main function
int main() {

	// Create a pointer to a Character object and assign it to a Warrior object
	ACharacter* warriorCharacter = new Warrior;

	// Set the name of the warrior character
	warriorCharacter->setName("Conan");

	// Greet Batman
	warriorCharacter->sayHelloTo("Batman");

	// Attack Batman
	warriorCharacter->attack("Batman");

	// Delete the warriorCharacter object
	delete(warriorCharacter);

	return 0;
}

/*
** `virtual void attack(std::string const & target) = 0;` -
** This is a pure virtual function. 
** It has no implementation in the base class and is 
** declared with the = 0 syntax. 
** A class that contains at least one pure virtual function 
** is called an abstract class, and cannot be instantiated.
** Instead, it must be derived from and the pure virtual function(s)
** must be implemented in the derived class(es).
**
** The purpose of pure virtual functions is to provide a way 
** to define a common interface for a group of related classes, 
** while allowing each class to implement the interface in its own way.
** This is useful in situations where you want to define 
** a set of operations that must be performed on a group of objects, 
** but the exact implementation of those operations may vary depending 
** on the type of object.
*/

/*
class	ICoffeeMaker {
	public:
		virtual void	fillWaterTank(IWaterSource * src) = 0;
		virtual void	makeCoffee(std::string const & type) = 0;
		virtual void	fillBeansTank() = 0;
};
*/