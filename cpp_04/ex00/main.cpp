/*
** The first part of the main function (TEST 1) was given in the task description.
*/

#include "includes/Animal.class.hpp"
#include "includes/Cat.class.hpp"
#include "includes/Dog.class.hpp"
#include "includes/WrongCat.class.hpp"

int main(void)
{
	{
		// TEST 1 is offered in the task description
		std::cout << std::endl;
		std::cout << "= = = = = = = = = = TEST 1 = = = = = = = = = = =" << std::endl;
		std::cout << std::endl;

		const Animal *meta = new Animal();
		const Animal *j = new Dog();
		const Animal *i = new Cat();

		std::cout << std::endl;

		std::cout << "meta->getType(): " << meta->getType() << std::endl;
		std::cout << "j->getType(): " << j->getType() << std::endl;
		std::cout << "i->getType(): " << i->getType() << std::endl;
		std::cout << std::endl;

		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}
	{
		// in TEST 2 we initialized objects locally
		std::cout << "= = = = = = = = = = TEST 2 = = = = = = = = = = =" << std::endl;
		std::cout << std::endl;

		Animal	unknown;
		Dog		mylo;
		Cat		tom;

		std::cout << "unknown is a: " << unknown.getType() << std::endl;
		unknown.makeSound();

		std::cout << "mylo is a: " << mylo.getType() << std::endl;
		mylo.makeSound();

		std::cout << "tom is a: " << tom.getType() << std::endl;
		tom.makeSound();
	}
	{
		// in TEST 3 we will test `WrongAnimal` and `WrongCat` classes
		// both calls to `makeSound()` will produce the same output 
		std::cout << "= = = = = = = = = = TEST 3 = = = = = = = = = = =" << std::endl;
		std::cout << std::endl;

		const WrongAnimal *meta = new WrongAnimal();
		const WrongAnimal *cat = new WrongCat();

		std::cout << "Calling for object type as `meta->getType()`: " << meta->getType() << std::endl;
		std::cout << "Calling for object type as `cat->getType()`: " << cat->getType() << std::endl;
		std::cout << std::endl;

		cat->makeSound();
		meta->makeSound();

		delete meta;
		delete cat;
	}
	std::cout << std::endl;

	return (0);
}
