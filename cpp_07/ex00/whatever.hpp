#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &a, T &b) {

	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T min(T &a, T &b) {

	return (a < b ? a : b);
}

template <typename T>
T max(T &a, T &b) {

	return (a > b ? a : b);
}

#endif

/*
** Not much to explain here..
** Simple template functions `swap`, `min` and `max`..
**
** `template <typename T>` is used to make the functions
** generic, so they can be used with any type.
**
** In `min` and `max` one line conditional statement is used.
** It's a ternary operator, that states:
** "if a is less than b, return a, else return b".
*/