/*
** Source: 42 Piscine CPP
**
** 19_inheritance
**
** This program demonstrates the use of
** inheritance in C++. 
*/

#include <iostream>

/* 
** In C++, there are three types of inheritance:
** public
** private
** protected
** 
** These types determine the accessibility of the 
** base class members in the derived class.
**
** Public inheritance means that the public members of the
** base class become public members of the derived class, 
** and the protected members of the base class become 
** protected members of the derived class. 
**
** Private members of the base class are not accessible in the
** derived class. This means that a derived class object can 
** access the public and protected members of its base class, 
** but not its private members.
**
** Private inheritance means that the public and protected members
** of the base class become private members of the derived class. 
** This means that a derived class object can access the 
** public and protected members of its base class, 
** but only through its own member functions. 
**
** Protected inheritance means that the public and protected members
** of the base class become protected members of the derived class.
** This means that a derived class object can access the public 
** and protected members of its base class, 
** but only through its own member functions.
**
** Encapsulation levels.
** Multiple inheritance.
** Virtual inheritance.
*/

class Animal {
public:
	int age;
};

class Mammal : virtual public Animal {
public:
	void feedMilk() {
		std::cout << "Feeding milk." << std::endl;
	}
};

class Bird : virtual public Animal {
public:
	void layEggs() {
		std::cout << "Laying eggs." << std::endl;
	}
};

class Platypus : public Mammal, public Bird {
public:
	void swim() {
		std::cout << "Swimming." << std::endl;
	}
};

int main() {
	Platypus p;
	p.age = 5;
	p.feedMilk();
	p.layEggs();
	p.swim();
	return 0;
}

/*
** In the example above, we have a base class Animal 
** and two derived classes Mammal and Bird, 
** both of which inherit virtually from Animal.
**
** We then have a derived class Platypus that inherits 
** from both Mammal and Bird.
**
** Since Mammal and Bird both inherit virtually from Animal,
** there is only one instance of Animal shared between them.
** This means that when Platypus inherits from both Mammal and Bird,
** it only gets one instance of Animal, rather than two separate instances.
**
** Virtual inheritance can be useful in cases where 
** multiple inheritance is used and there is a need to avoid ambiguity 
** or redundancy in the inheritance hierarchy. 
**
** However, it also adds complexity and should be used wisely.
**
** To recap, virtual inheritance is used to avoid ambiguity
** when multiple inheritance is used.
** It is declared using `virtual` keyword in the derived class:
** `class Derived : virtual access_specifier Base { ... };`
**
** In the `derived` class, the `virtual` keyword is used before
** the `access_specifier` of the `base` class, 
** which is usually `public`, `private` or `protected`.
**
** When a `derived` class inherits virtually from a `base` class,
** it shares a single instance of the `base` class with any other
** `derived` classes that also inherit virtually from that `base` class.
** This ensures that there is only one copy of the `base` class
** in the inheritance hierarchy.
*/
