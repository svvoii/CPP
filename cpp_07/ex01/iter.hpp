#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, size_t length, void (*f)(T const &)) {

	for (size_t i = 0; i < length; i++) {
		f(array[i]);
	}
}

template <typename T>
void print(T const &element) {

	std::cout << element;
}

#endif

/*
** In this exercise, we implemented a generic function `iter` that takes an array
** of any type, its length and a pointer to another function.
** The `iter` function calls the function passed as a parameter on each element
** of the array.
** In this example we used the `print` function to print each element at a time.
** See main.cpp for more details.
*/