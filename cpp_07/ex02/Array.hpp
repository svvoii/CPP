/*
** In this exercise, we have a class template `Array` that contains
** elements of type `T`. 
**
** The class has a default constructor with no parameters, which
** creates an empty array.
**
** The class has another constructor that takes an `unsigned int n`
** as a parameter, which creates an array of `n` elements of type `T`,
** initialized by default.
** 
** Constructor by copy and assignment operator.
** 
** `new[]` is used to allocate memory for the array at the time of
** declaration of the array.
**
** Elements of the array can be accessed using the subscript `[]` operator.
** In case of accessing an element out of bound, an exception is thrown.
**
** The class has a `size()` method that returns the size of the array.
*/

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include <exception>

// Defining some ANSI escape codes for consol output colors
# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"

template <typename T>
class Array {

	private:
		T		*_array;
		size_t	_size;

	public:
		Array(void);
		Array(size_t n);
		Array(Array const &src);
		~Array(void);

		Array	&operator=(Array const &rhs);

		T		&operator[](size_t i);

		size_t	size(void);

		class OutOfBoundsException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "Index out of bounds";
			}
		};
};

/*
** This constructor is called when an object is initialized by default.
** No parameter is passed but the empty array is created
** with its value initialized with `0` by default.
*/
template <typename T>
Array<T>::Array(void) : _array(new T[0]), _size(0) {
	std::cout << GREEN << "\t<<< default constructor with no parameters called >>>" << RESET << std::endl;
}

/*
** This constructor is called when an object is initialized by passing
** a parameter to the constructor.
** The parameter `n` is passed as a parameter, new array is created and
** initialized by default. `_size` is set to `n`.
**
** The sytax `new T[n]()` is used to default-initialize an array of 
** zero elements of type `T`. This means that each element will be
** initialized with `0` by default.
**
** `new T[n]` is another way to allocate memory for an array of zero,
** in this case each element in the array will have an undefined value.
*/
template <typename T>
Array<T>::Array(size_t n) : _array(new T[n]()), _size(n) {
	std::cout << GREEN << "\t<<< constructor with [ " << n << " ] parameters called >>>" << RESET << std::endl;
}

/*
** This constructor is called when an object is initialized by another object
** of the same class. The object `src` is passed as a parameter,
** new array is created and the values of its data members are copied to
** the object `*this`.
*/
template <typename T>
Array<T>::Array(Array const &src) : _array(new T[src._size]), _size(src._size) {
	std::cout << GREEN << "\t<<< copy constructor called, new Array is created and values are copied >>>" << RESET << std::endl;

	for (size_t i = 0; i < this->_size; i++)
		this->_array[i] = src._array[i];
}

/*
** Destructor is called when an object is destroyed.
*/
template <typename T>
Array<T>::~Array(void) {
	std::cout << RED << "\t<<< Default destructor called >>>" << RESET << std::endl;
	delete [] this->_array;
}

/*
** This operator is called when an already initialized object is assigned
** a new value from another existing object of the same class.
** The object `rhs` is passed as a parameter and the values of its data
** members are copied to the object `*this`.
** The old array is deleted with `delete [] this->_array`.
** And a new array is created with `this->_array = new T[rhs._size]`.
*/
template <typename T>
Array<T>	&Array<T>::operator=(Array const &rhs) {
	std::cout << GREEN << "\t<<< Assignment operator called. `this->_array` is deleted and new Array is created. Values are copied from `&rhs`. >>>" << RESET << std::endl;

	if (this != &rhs) {
		delete [] this->_array;
		this->_array = new T[rhs._size];
		this->_size = rhs._size;

		for (size_t i = 0; i < this->_size; i++)
			this->_array[i] = rhs._array[i];
	}
	return *this;
}

/*
** This operator is called when an element of the array is accessed using
** the subscript `[]` operator.
** If the index is out of bound, an exception is thrown.
*/
template <typename T>
T		&Array<T>::operator[](size_t i) {
	if (i >= this->_size)
		throw Array::OutOfBoundsException();
	return this->_array[i];
}

/*
** This method simply returns the size of the array.
*/
template <typename T>
size_t	Array<T>::size(void) {
	return this->_size;
}

#endif
