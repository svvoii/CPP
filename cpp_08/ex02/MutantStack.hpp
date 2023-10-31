/*
** This is the implementation of the `MutantStack` class.
** The mainidea behind is to make the `stack` class iterable.
** `MutantStack` shall inherit from the `std::stack` class
** all its member functions and complete them with the
** iterating functionality.
**
** `std::stack` is a container adapter that gives the programmer
** the functionality of a stack - specifically, a LIFO (last-in, first-out)
** data structure.
**
** These are the member functions (main methods) of the `std::stack` class:
**
** `push(g)` - adds the element ‘g’ at the top of the stack.
** `pop()` - deletes the top most element of the stack.
** `top()` - returns a reference to the top most element of the stack.
** `empty()` - returns whether the stack is empty.
** `size()` - returns the size of the stack.
**
** In the example of `MutantStack` class we inherit member functions
** from the `std::stack` class and add the functionality of iterating
** through the elements of the stack.
*/

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(MutantStack const &other);
		virtual ~MutantStack();

		MutantStack &operator=(MutantStack const &other);

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin();
		iterator end();

		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator begin() const;
		const_iterator end() const;

		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin();
		reverse_iterator rend();

		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator rbegin() const;
		const_reverse_iterator rend() const;
};

/*
** This is the implementation of the `MutantStack` class which inherits
** from the `std::stack` class. This is indicated by the 
** `.. : public std::stack<T>` part of the declaration.
**
** `template <typename T>` is used to make the class generic.
** Meaning that it can be used with any type of data.
** `T` is a placeholder for the type name.
**
** `typedef typename std::stack<T>::container_type::iterator iterator;`
** is used to create a new name for the type `std::stack<T>::container_type::iterator`.
**
** `iterator`, `const_iterator`, `reverse_iterator` and `const_reverse_iterator`
** are all types of iterators that are used to traverse the elements of a container.
** Bellows is the explanation of each one of them.
*/


template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &other) : std::stack<T>(other) {}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &other) {
	if (this != &other)
		std::stack<T>::operator=(other);
	return (*this);
}

/*
** `iterator` is a regular iterator/pointer that is used to traverse
** and modify the elements in the `MutantStack` class.
** It moves from the beginning to the end of the given container, `std::stack`. 
*/
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return (std::stack<T>::c.end());
}

/*
** `const_iterator` is similar to the regular `iterator`, but 
** it cannot modify the elements it points to.
** It is used when we want to traverse the elements without modifying them.
** Like the regular `iterator`, it moves from the beginning to the end 
** of the given container, `std::stack`.
*/
template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const {
	return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const {
	return (std::stack<T>::c.end());
}

/*
** `reverse_iterator` is a bidirectional iterator. It works like the regular
** `iterator`, but in the opposite direction.Starts from te end and goes to 
** the beginning of the given container, `std::stack`.
** It can modify the elements it points to.
*/
template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin() {
	return (std::stack<T>::c.rbegin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend() {
	return (std::stack<T>::c.rend());
}

/*
** `const_reverse_iterator` is a combination of `const_iterator` and
** `reverse_iterator`. It traverses the elements from the end to the beginning,
** but it cannot modify the elements it points to.
*/
template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const {
	return (std::stack<T>::c.rbegin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const {
	return (std::stack<T>::c.rend());
}

#endif

/*
** Some more information about `std::stack` and `std::deque`:
** 
** `std::stack` has a protected member `c` which is the underlying container.
** It is protected because it is not meant to be accessed by the user.
** It is used to store the elements of the stack.
** `std::stack` has a default underlying container `std::deque`.
** `std::deque` is a sequence container that supports random access to its elements.
**
** It is very similar to `std::vector`, but unlike `std::vector`, it can grow at both ends.
** `std::deque` is implemented as a dynamic array of fixed-size arrays.
** It is very efficient in terms of memory allocation and reallocation.
** It is also efficient in terms of inserting and removing elements in any position.
** It is not efficient in terms of inserting and removing elements in the middle.
** It is not efficient in terms of iterating through the elements.
** `std::deque` is a double-ended queue.
*/