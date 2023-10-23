#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>

template <typename T>

class RPNCalculator {
public:
	RPNCalculator();
	void push(T value);
	void add();
	void subtract();
	void multiply();
	void divide();
	T result();
private:
	std::stack<T> stack_;
};

template <typename T>
RPNCalculator<T>::RPNCalculator() {}

template <typename T>
void RPNCalculator<T>::push(T value) {
	stack_.push(value);
}

template <typename T>
void RPNCalculator<T>::add() {
	T a = stack_.top();
	stack_.pop();
	T b = stack_.top();
	stack_.pop();
	stack_.push(a + b);
}

template <typename T>
void RPNCalculator<T>::subtract() {
	T a = stack_.top();
	stack_.pop();
	T b = stack_.top();
	stack_.pop();
	stack_.push(b - a);
}

template <typename T>
void RPNCalculator<T>::multiply() {
	T a = stack_.top();
	stack_.pop();
	T b = stack_.top();
	stack_.pop();
	stack_.push(a * b);
}

template <typename T>
void RPNCalculator<T>::divide() {
	T a = stack_.top();
	stack_.pop();
	T b = stack_.top();
	stack_.pop();
	stack_.push(b / a);
}

template <typename T>
T RPNCalculator<T>::result() {
	return stack_.top();
}

#endif // RPN_HPP

/*
** RPNCalculator is a template class that takes a type parameter T. 
** It allows pushing values of type T onto a stack, and performing 
** arithmetic operations on the top values of the stack.
**
** The main methods are:
**
** push(T value) - Pushes a value onto the stack
**
** add() - Pops the top two values, adds them, and pushes the result back onto the stack
**
** subtract(), multiply(), divide() - Similar methods for other arithmetic operations
** 
** result() - Returns the value currently on top of the stack
** 
** The class maintains a private std::stack member to hold the values.
** 
** To use the calculator:
** 
** Push operands onto the stack in the desired order
** Call the operation methods like add() and multiply() to operate on those values
** result() will then return the calculated result.
** So the user does not need to deal with operator precedence, 
** unlike in traditional infix notation. The order of pushes and operations 
** defines the evaluation order.
** 
** This allows evaluating arithmetic expressions without using parentheses 
** or following precedence rules. The logic and flow is defined entirely 
** by the order of stack operations.
** 
** So in summary, RPNCalculator implements a stack-based calculator that 
** can evaluate expressions in reverse Polish notation, 
** by pushing operands and calling operations to act on them.
*/