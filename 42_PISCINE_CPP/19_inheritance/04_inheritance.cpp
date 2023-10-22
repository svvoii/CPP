#include <iostream>

/*
** This class demonstrates the
** concept of multiple inheritance in C++.
**
** Multiple inheritance is when a class inherits
** from more than one base class.
**
** The following example is an example of
** the diamond problem.
** 
*/

class A {
public:
	void print() {
		std::cout << "A" << std::endl;
	}
};

class B : public A {
public:
	void print() {
		std::cout << "B" << std::endl;
	}
};

class C : public A {
public:
	void print() {
		std::cout << "C" << std::endl;
	}
};

class D : public B, public C {
public:
	void print() {
		std::cout << "D" << std::endl;
	}
};

int main() {
	D d;
	d.B::print(); // prints "B"
	d.C::print(); // prints "C"
	d.print();    // compiler error: ambiguous call to 'print'
	return 0;
}

/*
** Class `A` is the base class, and classes 
** `B` and `C` are derived from `A` using public inheritance.
** Class `D` is derived from both `B` and `C` using multiple inheritance.
**
** Each of the classes has a member function called `print()`, 
** which simply outputs a string to the console.
** 
** In the `main()` function, we create an instance of class `D` 
** and call its `print()` function. 
** However, since `D` inherits from both `B` and `C`, 
** which in turn inherit from `A`, 
** there are two versions of the `print()` function available to `D`.
**
** When we call `d.print()`, the compiler is unable to determine
** which version of `print()` to call, 
** as both `B` and `C` have their own implementation of `print()`.
** This results in a compiler error: "ambiguous call to 'print'".
**
** To solve this problem we can use virtual inheritance.
** as shown in the next example.
*/

/* Solution to the diamond problem using virtual inheritance */
/*
class A {
public:
	void print() {
		std::cout << "A" << std::endl;
	}
};

class B : virtual public A {
public:
	void print() {
		std::cout << "B" << std::endl;
	}
};

class C : virtual public A {
public:
	void print() {
		std::cout << "C" << std::endl;
	}
};

class D : public B, public C {
public:
	void print() {
		std::cout << "D" << std::endl;
	}
};

int main() {
	D d;
	d.B::print(); // prints "B"
	d.C::print(); // prints "C"
	d.print();    // prints "D"
	return 0;
}

** `Class A` is the base class for `Class B` and `Class C`.
** `Class B` inherits from `Class A` it is a base class for `Class D`.
** `Class C` inherits from `Class A` it is a base class for `Class D`.
** `Class D` inherits from `Class B` and `Class C`.
**
** Using keyword `virtual` we can tell the compiler that
** `Class D` should only have one copy of `Class A`.
** This solves the diamond problem.
** Therefor when we call `d.print()` the compiler knows
** which method to call, the one from `Class D`.
*/
