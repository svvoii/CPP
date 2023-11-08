/*
** In this man function we create and fill an array of `Animal` objects.
** Half of the array is filled with `Dog` objects and the other half with
** `Cat` objects.
**
** The copies of a `Dog` and `Cat` objects are deep copies, meaning that
** the `Brain` object is also copied properly.
** 
** At the end of the program, we delete the array of `Animal` objects
** directly as `Animal` objects. It will show the appropriate destructor
** being called for each object, which is: `Dog` and `Cat` destructors
** and `Brain` destructor for each `Dog` and `Cat` object.
**
** To test for memory leaks, run:
** `make valgrind`
*/

#include "includes/Dog.class.hpp"
#include "includes/Cat.class.hpp"

int	main() {
	
	{
		std::cout << std::endl;
		std::cout << "= = = = = = = = = = TEST 1 = = = = = = = = = = =" << std::endl;
		std::cout << std::endl;

		const	Animal* j = new Dog();
		const	Animal* i = new Cat();

		delete j; // should not create a leak
		delete i;
	}
	{
		std::cout << std::endl;
		std::cout << "= = = = = = = = = = TEST 2 = = = = = = = = = = =" << std::endl;
		std::cout << std::endl;

		Animal* animals[10];

		for (int i = 0; i < 10; i++) {
			if (i % 2 == 0)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}

		for (int i = 0; i < 10; i++) {
			delete animals[i];
		}
	}

	return 0;
}
