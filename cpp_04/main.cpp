/*
** This main function was given in the task description.
*/

#include "Animal.class.hpp"
#include "Cat.class.hpp"
#include "Dog.class.hpp"

int main(void)
{
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

	return (0);
}
