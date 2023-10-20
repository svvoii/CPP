/*
** Source: 42 Piscine CPP
**
** 13_new_and_delete
**
** This program demonstrates the usage of dynamic memory allocation in C++.
** Specifically, the usage of the `new` and `delete` operators.
*/

#include <iostream>

class Student {
	
	private:
		std::string	_login;

	public:
		Student(void) {
			std::cout << "Student " << this->_login << " is born." << std::endl;
		}

		~Student(void) {
			std::cout << "Student " << this->_login << " died." << std::endl;
		}
};

int	main() {

	Student*	students = new Student[42];

	delete[] students;

	return 0;
}

/*
** Use of `new' will allocate memory for an array of 42 instances of the Student class on the heap.
** 
** To note that the use of `new` won't support the parameterized constructor of the Student class.
** Meaning that we cannot pass an argument to the constructor of the Student class.
** In our Student class, the constructor wont take any argument.
**
** If we want to pass an argument to the constructor of the Student class, 
** we would need to do this separately.
**
** Special `delete` syntax shall be used to free the memory allocated for an array of instances.
** `delete [] Students' will free the memory allocated for the array of instances.
*/
