/*
** Source: 42 Piscine CPP
**
** 19_inheritance
**
** This program demonstrates the use of
** inheritance in C++. 
**
** The following example are inefficient ways
** of creating classes. 
*/

#include <string>

class Cat {

private:

	int		_numberOfLegs;

public:

	Cat(void);
	Cat(Cat const & );
	Cat& operator=(Cat const & );
	~Cat(void);

	void	run(int distance);

	void	scornSomeone(std::string const & target);

};

class Pony {

private:

	int		_numberOfLegs;

public:

	Pony(void);
	Pony(Pony const & );
	Pony& operator=(Pony const & );
	~Pony(void);

	void	run(int distance);

	void	doMagic(std::string const & target);

};

/*
** This way of creating a class is not very efficient.
** We have to write the same code for each class, where
** the only difference is the name of the class and the
** name of the method `scornSomeone()` / `doMagic()`.
**
** Imagine coding a forest with all the animals in it... 
** It would be a nightmare to maintain.
*/
