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
		Student(std::string login) : _login(login) {
			std::cout << "Student " << this->_login << " is born." << std::endl;
		}

		~Student(void) {
			std::cout << "Student " << this->_login << " died." << std::endl;
		}
};

int	main() {

	Student stud1 = Student("bobby");
	Student *stud2 = new Student("jimmy");

	delete stud2;

	return 0;
}

/*
** Use of `new' will allocate memory for an instance of the Student class on the heap.
** The address of the allocated memory is returned by `new' and assigned to the pointer `stud2'.
** The constructor of the Student class is called with the argument "jimmy".
** 
** Then with the use of `delete', the memory allocated for the instance of the Student class
** is freed from the heap and the destructor of the Student class is called.
*/
