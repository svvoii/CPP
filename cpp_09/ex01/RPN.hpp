#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>

bool	isInSet(char c, std::string set);
bool	isValidExpression(std::string expression);

/*
** Bellow is a template class implementation.
** Id defines the `RPNCalculator` class and its methods
** for performing arithmetic operations on top stack values.
**
** The usage examle is the following:
```
	RPNCalculator<int> calculator;
	calculator.push(5);
	calculator.push(10);
	calculator.add();
	int result = calculator.result(); // result = 15
```
**
** In the example below, the template class is used to create a stack values.
** The value type will be defined at the moment of 
** creating an instance of the class.
** Once the class is created, the value type cannot be changed.
**
** For example, if we instantiate the RPNCalculator class 
** with int data type as follows:
** `RPNCalculator<int> calculator;`
** then, we can only push int values onto the stack.
**
** `T` is the value to be pushed onto the stack.
** Methods:
** `push(T value)` - Pushes a value onto the stack
** `result()` - Returns the value currently on top of the stack
** `performOperation(char operator)` - Pops two values,
** performs the operation, based on the operator passed in,
** and pushes the result back onto the stack.
*/

template <typename T> 
class RPNCalculator {
private:
	std::stack<T> _stack;

public:
	RPNCalculator();

	T		result();
	void	push(T value);
	void	performOperation(char op);
};

/*
** `RPNCalculator()` - Default constructor
*/
template <typename T>
RPNCalculator<T>::RPNCalculator() {}

/* 
** `result()`
** Returns the value currently on top of the stack
** In case
*/
template <typename T>
T RPNCalculator<T>::result() {
	while (_stack.size() > 1) {
		_stack.pop();
	}
	return _stack.top();
}

/*
** `push(T value)`
** Pushes a value onto the stack
*/
template <typename T>
void RPNCalculator<T>::push(T value) {
	_stack.push(value);
}

/*
** `performOperation(char operator)`
** Pops two values, 
** performs the operation, based on the operator passed in, 
** and pushes the result back onto the stack
*/
template <typename T>
void RPNCalculator<T>::performOperation(char op) {
	T a, b;
	try {
		a = _stack.top();
		_stack.pop();
		b = _stack.top();
		_stack.pop();
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
		return;
	}
	switch (op) {
		case '+':
			_stack.push(a + b);
			break;
		case '-':
			_stack.push(b - a);
			break;
		case '*':
			_stack.push(a * b);
			break;
		case '/':
			if (a == 0) {
				std::cout << "Error: Division by zero" << std::endl;
				_stack.push(b);
				_stack.push(a);
				return;
			}
			_stack.push(b / a);
			break;
		default:
			std::cout << "Invalid operator" << std::endl;
			break;
	}
}

/*
** The try/catch block is used to catch exceptions.
** However, it is not necessary to use a try/catch block
** here since we check the proper number of operands
** vs. operators in the `isValidExpression()` function.
*/

#endif // RPN_HPP

/*
** There is no destructor in this class. 
** A destructor is necessary when a class has dynamically allocated memory
** or other resources that need to be released when the object is destroyed.
** If a class does not have any dynamically allocated memory
** or other resources that need to be released, 
** then a destructor is not necessary.
** The default destructor provided by the compiler will suffice.
**
** In this case, the stack
**
*/

/*
** The following methods are an alternative implementation
** of the `performOperation()` method.
**
**
** `add()`
** Pops top two values, 
** adds them, and 
** pushes the result back onto the stack
template <typename T>
void RPNCalculator<T>::add() {
	T a = _stack.top();
	_stack.pop();
	T b = _stack.top();
	_stack.pop();
	_stack.push(a + b);
}
*/

/*
** `subtract()`
** Pops top two values, 
** subtracts them, and pushes the result back onto the stack
template <typename T>
void RPNCalculator<T>::subtract() {
	T a = _stack.top();
	_stack.pop();
	T b = _stack.top();
	_stack.pop();
	_stack.push(b - a);
}
*/

/*
** `multiply()`
** Pops top two values, 
** multiplies them, and 
** pushes the result back onto the stack
template <typename T>
void RPNCalculator<T>::multiply() {
	T a = _stack.top();
	stack_.pop();
	T b = _stack.top();
	_stack.pop();
	_stack.push(a * b);
}
*/

/*
** `divide()`
** Pops top two values, 
** divides them, and 
** pushes the result back onto the stack
template <typename T>
void RPNCalculator<T>::divide() {
	T a = _stack.top();
	stack_.pop();
	T b = _stack.top();
	_stack.pop();
	_stack.push(b / a);
}
*/
