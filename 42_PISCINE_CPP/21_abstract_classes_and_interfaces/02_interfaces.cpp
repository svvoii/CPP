/*
** Source: 42 Piscine CPP
**
** 21_abstract_classes_and_interfaces
**
** This program demonstrates the use of
** interfaces in C++.
*/

#include <iostream>
#include <string>

// Interface for coffee makers
class ICoffeeMaker {
	public:
		virtual void fillWaterTank() = 0;
		virtual void makeCoffee(std::string const & type) = 0;
		virtual void fillBeansTank() = 0;
};

// Class for a drip coffee maker
class DripCoffeeMaker : public ICoffeeMaker {
	public:
		virtual void fillWaterTank() {
			std::cout << "Filling water tank for drip coffee maker" << std::endl;
		}

		virtual void makeCoffee(std::string const & type) {
			std::cout << "Making " << type << " coffee with drip coffee maker" << std::endl;
		}

		virtual void fillBeansTank() {
			std::cout << "Filling beans tank for drip coffee maker" << std::endl;
		}
};

// Class for an espresso machine
class EspressoMachine : public ICoffeeMaker {
	public:
		virtual void fillWaterTank() {
			std::cout << "Filling water tank for espresso machine" << std::endl;
		}

		virtual void makeCoffee(std::string const & type) {
			std::cout << "Making " << type << " coffee with espresso machine" << std::endl;
		}

		virtual void fillBeansTank() {
			std::cout << "Filling beans tank for espresso machine" << std::endl;
		}
};

/*
** In this example, an interface ICoffeeMaker is defined with three 
** pure virtual functions: 
** `fillWaterTank()`
** `makeCoffee()`
** `fillBeansTank()`
**
** Two classes `DripCoffeeMaker` and `EspressoMachine` are derived from the 
** `ICoffeeMaker` interface and implement the three functions in their own way.
*/

// Main function
int main() {

	// Create a pointer to a coffee maker object and assign it to a DripCoffeeMaker object
	ICoffeeMaker* coffeeMaker = new DripCoffeeMaker;

	// Fill the water tank
	coffeeMaker->fillWaterTank();

	// Make some coffee
	coffeeMaker->makeCoffee("drip");

	// Fill the beans tank
	coffeeMaker->fillBeansTank();

	// Delete the coffeeMaker object
	delete(coffeeMaker);

	// Create a pointer to a coffee maker object and assign it to an EspressoMachine object
	coffeeMaker = new EspressoMachine;

	// Fill the water tank
	coffeeMaker->fillWaterTank();

	// Make some coffee
	coffeeMaker->makeCoffee("espresso");

	// Fill the beans tank
	coffeeMaker->fillBeansTank();

	// Delete the coffeeMaker object
	delete(coffeeMaker);

	return 0;
}

/*
** In the main() we create a pointer to an `ICoffeeMaker` object
** and assigned it to a `DripCoffeeMaker` object. 
** 
** `fillWaterTank()`
** `makeCoffee()`
** `fillBeansTank()`
** functions are called on the coffeeMaker object, 
** which prints messages to the console indicating the actions performed.
** The coffeeMaker object is then deleted.
** 
** The same process is repeated with an EspressoMachine object.
**
** This example demonstrates how interfaces can be used 
** to define a common interface for a group of related classes, 
** while allowing each class to implement the interface in its own way.
**
** `ICoffeeMaker` interface defines a set of operations that 
** must be performed on a coffee maker, while the 
** `DripCoffeeMaker` and `EspressoMachine` classes implement 
** those operations in their own way.
*/
