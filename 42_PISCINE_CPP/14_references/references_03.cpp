#include <iostream>

/*
GitHub Copilot: In this example, the `Student` class has four member functions that return either a reference or a pointer to the `_login` private member variable. 

*/

class Student {
	private:
		std::string _login;

	public:
		Student(std::string const & login) : _login(login) {
		}

		~Student() {
		}

		std::string&	getLoginRef() {
			return this->_login;
		}

		std::string const &	getLoginRefConst() const {
			return this->_login;
		}

		std::string*	getLoginPtr() {
			return &(this->_login);
		}

		std::string const *	getLoginPtrConst() const {
			return &(this->_login);
		}
};

/*
** `getLoginRef()` returns a reference to a non-const `std::string`, 
** which allows the caller to modify the value of `_login`.
**
** `getLoginRefConst()` returns a reference to a const `std::string`, 
** which prevents the caller from modifying the value of `_login`.
**
** `getLoginPtr()` returns a pointer to a non-const `std::string`, 
** which allows the caller to modify the value of `_login`.
** 
** `getLoginPtrConst()` returns a pointer to a const `std::string`, 
** which prevents the caller from modifying the value of `_login`.
*/

int	main() {

	Student 		bob = Student("bob_42");
	Student const	jim = Student("jim_42");

	std::cout << "bob.getLoginRefConst(): " << bob.getLoginRefConst() << std::endl;
	std::cout << "jim.getLoginRefConst(): " << jim.getLoginRefConst() << std::endl;

	std::cout << "*(bob.getLoginPtrConst()): " << *(bob.getLoginPtrConst()) << std::endl;
	std::cout << "*(jim.getLoginPtrConst()): " << *(jim.getLoginPtrConst()) << std::endl;

	bob.getLoginRef() = "bob_21";
	std::cout << "bob.getLoginRefConst(): " << bob.getLoginRefConst() << std::endl;

	*(bob.getLoginPtr()) = "bob_4422";
	std::cout << "bob.getLoginRefConst(): " << bob.getLoginRefConst() << std::endl;

	return 0;
}

/*
** In the `main()` function, we create two `Student` objects, `bob` and `jim`, 
** and call each of these member functions on both objects. 
** 
** We can see that when we modify the value of `_login` 
** using `getLoginRef()` or `getLoginPtr()`, 
** the change is reflected in subsequent calls to 
** `getLoginRefConst()` and `getLoginPtrConst()`. 
** 
** The usage of references and pointers in this example allows us to control 
** whether or not the caller can modify the value of `_login`. 
** References are useful when we want to provide a non-null alias to an object, 
** while pointers are useful when we want to pass around a null value or 
** when we want to modify the value of an object.
*/
