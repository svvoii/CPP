/*
** In this exercise, we use same defined classes as in
** previous exercise. The only difference is that we
** the parent class now is used as an abstract class.
**
** Because the parent class is now an abstract class,
** we can no longer create instances of the parent class.
** So, the messages that are related to the parent class
** are not printed anymore.
**
** An abstract class is a class that is designed to be
** specifically used as a parent class. This class is
** labeled as abstract by using the `virtual` keyword
** in its declaration.
*/

#include "includes/Cat.class.hpp"
#include "includes/Dog.class.hpp"

int	main(void) {

	{
		AAnimal *dog = new Dog();
		dog->makeSound();

		delete dog;

		Dog *dog2 = new Dog();
		dog2->makeSound();

		delete dog2;
	}
	{
		std::cout << std::endl;
		std::cout << "= = = = = = = = = = = = TEST 1 = = = = = = = = = = " << std::endl;
		std::cout << std::endl;
		// Animal animal; // This will not compile anymore
		// std::cout << animal.getType() << std::endl;
		// animal.makeSound();

		AAnimal *cat = new Cat();
		std::cout << cat->getType() << std::endl;
		cat->makeSound();
		delete cat;

		AAnimal *dog = new Dog();
		std::cout << dog->getType() << std::endl;
		dog->makeSound();
		delete dog;
	}
	{
		std::cout << std::endl;
		std::cout << "= = = = = = = = = = = = TEST 2 = = = = = = = = = = " << std::endl;
		std::cout << std::endl;

		Cat tom;
		Dog mylo;

		std::cout << tom.getType() << std::endl;
		tom.makeSound();

		std::cout << mylo.getType() << std::endl;
		mylo.makeSound();

	}
	{
		std::cout << std::endl;
		std::cout << "= = = = = = = = = = = = TEST 3 = = = = = = = = = = " << std::endl;
		std::cout << std::endl;

		Cat tom;
		Cat jerry(tom);

		std::cout << tom.getType() << std::endl;
		tom.makeSound();

		std::cout << jerry.getType() << std::endl;
		jerry.makeSound();
	}
	{
		std::cout << std::endl;
		std::cout << "= = = = = = = = = = = = TEST 4 = = = = = = = = = " << std::endl;
		std::cout << std::endl;

		Cat tom;
		Cat jerry;

		std::cout << tom.getType() << std::endl;
		tom.makeSound();

		std::cout << jerry.getType() << std::endl;
		jerry.makeSound();

		jerry = tom;

		std::cout << tom.getType() << std::endl;
		tom.makeSound();

		std::cout << jerry.getType() << std::endl;
		jerry.makeSound();
	}
	/*
	*/
	return (0);
}
