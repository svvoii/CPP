/*
** Source: 42 Piscine CPP
**
** 19_inheritance
**
** This program demonstrates the use of
** inheritance in C++. 
*/

#include <string>

class Animal {

private:

	int		_numberOfLegs;

public:

	Animal(void);
	Animal(Animal const & );
	Animal& operator=(Animal const & );
	~Animal(void);

	/* Common methods for all animals */
	void	run(int distance);
	void	call(void);
	void	sleep(void);
	void	eat(std::string const & food);
	void	walk(int distance);
};

class Cat : public Animal {

public:

	Cat(void);
	Cat(Cat const & );
	Cat& operator=(Cat const & );
	~Cat(void);

	/* Unique method for Cat */
	void	scornSomeone(std::string const & target);

};

class Pony : public Animal {

public:

	Pony(void);
	Pony(Pony const & );
	Pony& operator=(Pony const & );
	~Pony(void);

	/* Unique method for Pony */
	void	doMagic(std::string const & target);

};

class Armadillo : public Animal {

public:

	Armadillo(void);
	Armadillo(Armadillo const & );
	Armadillo& operator=(Armadillo const & );
	~Armadillo(void);

	/* Unique method for Armadillo */
	void	roll(void);

};

/*
** This way of creating a class is not very efficient.
** We have to write the same code for each class, where
** the only difference is the name of the class and the
** name of the method `scornSomeone()` / `doMagic()` etc.
**
** Things to note:
** - `class Cat : public Animal` is the syntax for inheritance.
** - `class Cat : public Animal` means that Cat inherits from Animal.
** - `class Cat : public Animal` means that Cat is a subclass of Animal.
** - `class Cat : public Animal` means that Cat is a child class of Animal.
** - `class Cat : public Animal` means that Animal is a parent class of Cat.
**
** Creating an instance of Cat means creating an instance of Animal.
** `Default Constructor` is on the Animal class.
** then `Default Constructor` is on the Cat class.
** then `Default Destructor` is on the Cat class.
** then `Default Destructor` is on the Animal class.
**
** The example below shows how to use inheritance to create a class.
** `Cat catInstance;` will call the `Default Constructor` on the Animal class.
** as well as the `Default Constructor` on the Cat class.
**
** When the program ends, the `Default Destructor` will be called on the Cat class.
** as well as the `Default Destructor` on the Animal class.
*/