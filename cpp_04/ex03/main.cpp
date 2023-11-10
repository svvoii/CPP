/*
** This goal of this exercise is to recap and solidify
** the concepts of Interfaces or/and Abstract classes.
**
** We have the following classes:
**
** `AMateria` this is an Abstract class
** `Ice` this is a class that inherits from `AMateria`
** `Cure` this is a class that inherits from `AMateria`
**
** `ICharacter` this is an Interface
** `Character` this is a class that inherits from `ICharacter`
**
** `IMateriaSource` this is an Interface
** `MateriaSource` this is a class that inherits from `IMateriaSource`
** 
** More details in the respective `.cpp and .hpp` files.
**
** The first part of the main function is given in the subject.
*/

#include "includes/Character.hpp"
#include "includes/Ice.hpp"
#include "includes/Cure.hpp"
#include "includes/MateriaSource.hpp"


int main()
{
	/*
	{
		std::cout << GREEN << "= = = = = = = = = = = =  = = = = = = = = = =" << RESET << std::endl;
		std::cout << GREEN << "= = = = = = = = = = TEST 1 = = = = = = = = = =" << RESET << std::endl;
		std::cout << GREEN << "= = = = = = = = = = = =  = = = = = = = = = =" << RESET << std::endl;
		std::cout << MAGENTA << "Testing the `Ice` class and its methods. Creating an instance as `Ice ice;`" << RESET << std::endl;
		//std::cout << std::endl;
		// Create an instance of the Ice class
		Ice ice;

		// Test the getType() and getXP() methods
		std::cout << MAGENTA << "Testing the `ice.getType()` and `ice.getXP()` inherited methods:" << RESET << std::endl; 
		std::cout << "Ice type: " << ice.getType() << std::endl; // Expected output: Ice
		std::cout << "Ice XP: " << ice.getXP() << std::endl; // Expected output: 0
		std::cout << std::endl;

		// Test the use method
		std::cout << MAGENTA << "Testing overriden use method `ice.use(*bob)`. First creating target `ICharacter *bob = new Character(\"bob\"))`:" << RESET << std::endl;
		ICharacter* bob = new Character("bob");
		ice.use(*bob);
		std::cout << "Ice XP after use: " << ice.getXP() << std::endl; // Expected output: 10
		std::cout << std::endl;

		// Test the assignment operator
		std::cout << MAGENTA << "Testing the assignment operator `Ice ice2 = ice`:" << RESET << std::endl;
		Ice ice2 = ice;
		std::cout << "Ice2 type: " << ice2.getType() << std::endl; // Expected output: Ice
		std::cout << "Ice2 XP: " << ice2.getXP() << std::endl; // Expected output: 10
		std::cout << std::endl;

		// Test the copy constructor
		std::cout << MAGENTA << "Testing the copy constructor as `Ice ice2(ice)`:" << RESET << std::endl;
		Ice ice3(ice);
		std::cout << "Ice3 type: " << ice3.getType() << std::endl; // Expected output: Ice
		std::cout << "Ice3 XP: " << ice3.getXP() << std::endl; // Expected output: 10
		std::cout << std::endl;

		std::cout << MAGENTA << "Testing the copy constructor as `Ice *ice2_ptr = new Ice(ice)`:" << RESET << std::endl;
		AMateria *ice_ptr = new Ice(ice);
		std::cout << "Ice_ptr type: " << ice_ptr->getType() << std::endl; // Expected output: Ice
		std::cout << "Ice_ptr XP: " << ice_ptr->getXP() << std::endl; // Expected output: 10
		std::cout << std::endl;

		// Test the clone method
		std::cout << MAGENTA << "Testing the clone method as `AMateria *ice4 = ice.clone()`:" << RESET << std::endl;
		AMateria *ice4 = ice.clone();
		std::cout << "Ice4 type: " << ice4->getType() << std::endl; // Expected output: Ice
		std::cout << "Ice4 XP: " << ice4->getXP() << std::endl; // Expected output: 10
		std::cout << std::endl;

		// Clean up
		delete bob;
		delete ice_ptr;
		delete ice4;
	}
	{
		std::cout << GREEN << "= = = = = = = = = = = =  = = = = = = = = = =" << RESET << std::endl;
		std::cout << GREEN << "= = = = = = = = = = TEST 2 = = = = = = = = = =" << RESET << std::endl;
		std::cout << GREEN << "= = = = = = = = = = = =  = = = = = = = = = =" << RESET << std::endl;
		std::cout << MAGENTA << "Testing the `Cure` class and its methods" << RESET << std::endl;
		std::cout << std::endl;

		// Create an instance of the Cure class
		Cure cure;

		// Test the getType() and getXP() methods
		std::cout << MAGENTA << "Testing the `cure.getType()` and `cure.getXP()` inherited methods:" << RESET << std::endl;
		std::cout << "Cure type: " << cure.getType() << std::endl; // Expected output: Cure
		std::cout << "Cure XP: " << cure.getXP() << std::endl; // Expected output: 0
		std::cout << std::endl;

		// Test the use method
		std::cout << MAGENTA << "Testing overriden method `cure.use(*bob)`. First creating `ICharacter *bob = new Character(\"bob\"))`:" << RESET << std::endl;
		ICharacter *bob = new Character("bob");
		cure.use(*bob);
		std::cout << "Cure XP after use: " << cure.getXP() << std::endl; // Expected output: 10
		std::cout << std::endl;

		// Test the assignment operator
		std::cout << MAGENTA << "Testing the assignment operator `Cure cure2 = cure`:" << RESET << std::endl;
		Cure cure2 = cure;
		std::cout << "Cure2 type: " << cure2.getType() << std::endl; // Expected output: Cure
		std::cout << "Cure2 XP: " << cure2.getXP() << std::endl; // Expected output: 10
		std::cout << std::endl;

		// Test the copy constructor
		std::cout << MAGENTA << "Testing the copy constructor as `Cure cure3(cure)`:" << RESET << std::endl;
		Cure cure3(cure);
		std::cout << "Cure3 type: " << cure3.getType() << std::endl; // Expected output: Ice
		std::cout << "Cure3 XP: " << cure3.getXP() << std::endl; // Expected output: 10
		std::cout << std::endl;

		std::cout << MAGENTA << "Testing the copy constructor as `Cure *cure_ptr = new Cure(cure)`:" << RESET << std::endl;
		AMateria *cure_ptr = new Cure(cure);
		std::cout << "Cure_ptr type: " << cure_ptr->getType() << std::endl; // Expected output: Ice
		std::cout << "Cure_ptr XP: " << cure_ptr->getXP() << std::endl; // Expected output: 10
		std::cout << std::endl;

		// Test the clone method
		std::cout << MAGENTA << "Testing the clone method `AMateria *cure4 = cure.clone()`:" << RESET << std::endl;
		AMateria *cure4 = cure.clone();
		std::cout << "Cure4 type: " << cure4->getType() << std::endl; // Expected output: Cure
		std::cout << "Cure4 XP: " << cure4->getXP() << std::endl; // Expected output: 10
		std::cout << std::endl;

		// Clean up
		delete bob;
		delete cure_ptr;
		delete cure4;
	}
	*/
	{
		std::cout << GREEN << "= = = = = = = = = = = =  = = = = = = = = = =" << RESET << std::endl;
		std::cout << GREEN << "= = = = = = = = = = TEST 3 = = = = = = = = = =" << RESET << std::endl;
		std::cout << GREEN << "= = = = = = = = = = = =  = = = = = = = = = =" << RESET << std::endl;
		std::cout << MAGENTA << "Testing the `Character` class and its methods" << RESET << std::endl;
		std::cout << std::endl;

		// Create an instance of the Character class
		Character character("bob");

		// Test the getName() method
		std::cout << MAGENTA << "Testing the `character.getName()` inherited method:" << RESET << std::endl;
		std::cout << "Character name: " << character.getName() << std::endl; // Expected output: bob
		std::cout << std::endl;

		// Test the equip method
		std::cout << MAGENTA << "Creating `AMateria *ice = new Ice()` and testing the `character.equip(&ice)` method:" << RESET << std::endl;
		AMateria *ice = new Ice();
		character.equip(ice);
		std::cout << "Character inventory size: " << character.getInventorySize() << std::endl; // Expected output: 1
		std::cout << std::endl;

		// printInventory() 
		std::cout << MAGENTA << "Printing Inventory `character.printInventory()`:" << RESET << std::endl;
		character.printInventory();
		std::cout << std::endl;

		// Creating another instance of Character as target
		std::cout << MAGENTA << "Creating another instance of Character as target `Character target(\"alice\")`:" << RESET << std::endl;
		Character target("alice");
		std::cout << std::endl;

		// Test the use method
		std::cout << MAGENTA << "Testing the `character.use(0, target)` method:" << RESET << std::endl;
		character.use(0, target);
		std::cout << std::endl;

		// Test the unequip method
		std::cout << MAGENTA << "Testing the `character.unequip(0)` method:" << RESET << std::endl;
		character.unequip(0);
		std::cout << "Character inventory size: " << character.getInventorySize() << std::endl; // Expected output: 0
		std::cout << std::endl;
		
		// printInventory()
		std::cout << MAGENTA << "Printing Inventory `character.printInventory()`:" << RESET << std::endl;
		character.printInventory();
		std::cout << std::endl;

		// Test the equip method
		std::cout << MAGENTA << "Testing the `character.equip(&ice)` method:" << RESET << std::endl;
		character.equip(ice);
		std::cout << "Character inventory size: " << character.getInventorySize() << std::endl; // Expected output: 1
		std::cout << std::endl;	

		// Creating another instance of Character as target
		std::cout << MAGENTA << "Creating another instance of Character as target `ICharacter *target2 = new Character(\"charlie\")`:" << RESET << std::endl;
		ICharacter *target2 = new Character("charlie");
		std::cout << std::endl;

		// Test the use method
		std::cout << MAGENTA << "Testing the `character.use(0, *target2)` method:" << RESET << std::endl;
		character.use(0, *target2);
		std::cout << std::endl;

		// Clean up
		//delete ice;
		delete target2;

		/*
		So, if all the instances of the AMateria is equipped, it will be freed in the Character destructor,
		by calling the _deleteInventory() method.
		
		Otherwise, all the instances of the AMateria, which is not equipped, shall be freed manually with `delete`.
		*/

	}

	/*
	*/
		/* EXPECTED OUTPUT:
	// The following TEST is given in the subject.
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		
		ICharacter* me = new Character("me");
		
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		
		ICharacter* bob = new Character("bob");
		
		me->use(0, *bob);
		me->use(1, *bob);
		
		delete bob;
		delete me;
		delete src;
	}
	* shoots an ice bolt at bob *
	* heals bob's wounds *
		*/
	/*
	// MORE TESTS
	{
		// Test 1: Create a new MateriaSource and learn a new Ice Materia
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		AMateria* ice = src->createMateria("ice");
		std::cout << "Ice Materia type: " << ice->getType() << std::endl; // Expected output: Ice

		// Test 2: Create a new Character and equip the Ice Materia
		ICharacter* me = new Character("me");
		me->equip(ice);
		std::cout << "Ice Materia XP before use: " << ice->getXP() << std::endl; // Expected output: 0

		// Test 3: Use the Ice Materia on a new Character
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		std::cout << "Ice Materia XP after use: " << ice->getXP() << std::endl; // Expected output: 10

		// Test 4: Create a new MateriaSource and learn a new Cure Materia
		IMateriaSource* src2 = new MateriaSource();
		src2->learnMateria(new Cure());
		AMateria* cure = src2->createMateria("cure");
		std::cout << "Cure Materia type: " << cure->getType() << std::endl; // Expected output: Cure

		// Test 5: Equip the Cure Materia and use it on the Character
		me->equip(cure);
		me->use(1, *bob);
		//std::cout << "Bob's HP after being healed: " << bob->getHP() << std::endl; // Expected output: 110

		// Test 6: Create a new Character and equip the Ice Materia twice
		ICharacter* alice = new Character("alice");
		me->equip(ice);
		me->equip(ice);
		me->use(2, *alice);
		std::cout << "Ice Materia XP after double use: " << ice->getXP() << std::endl; // Expected output: 20

		// Test 7: Create a new MateriaSource and learn a new Ice Materia
		src->learnMateria(new Ice());
		AMateria* ice2 = src->createMateria("ice");
		std::cout << "Second Ice Materia type: " << ice2->getType() << std::endl; // Expected output: Ice

		// Test 8: Create a new MateriaSource and learn a new Cure Materia
		src2->learnMateria(new Cure());
		AMateria* cure2 = src2->createMateria("cure");
		std::cout << "Second Cure Materia type: " << cure2->getType() << std::endl; // Expected output: Cure

		// Test 9: Create a new Character and equip all four Materia
		ICharacter* charlie = new Character("charlie");
		me->equip(ice2);
		me->equip(cure2);
		me->equip(ice);
		me->equip(cure);
		me->use(3, *charlie);
		//std::cout << "Charlie's HP after being healed: " << charlie->getHP() << std::endl; // Expected output: 110

		// Clean up memory
		delete bob;
		delete alice;
		delete charlie;
		delete me;
		delete src;
		delete src2;
		delete ice;
		delete ice2;
		delete cure;
		delete cure2;
	}
	*/
	
	return 0;
}
