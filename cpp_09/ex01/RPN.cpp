#include "RPN.hpp"
/*
** Here is the implementation of the `RPNCalculator` class.
** The `RPNCalculator` class is a template class.
** 
** Functions bellow check the input string for errors.
** And we check if it is a valid expression.
**
** According to the subject, the input string must be 
** an inverted Polish mathematical expression.
** `7 - 7 * 7` is not a valid expression.
** `7 7 * 7 -` is a valid expression.
** `1 2 * 2 / 2 * 2 4 - +` is a valid expression.
** `(1 + 1)` is not a valid expression.
** `1 2` is not a valid expression.
** `5` is a valid expression.
** `2 8 1 *` is ambiguous and output is considered as undefined.
*/

/*
** `RPNCalculator()` - Default constructor
*/
RPNCalculator::RPNCalculator() {
}

/*
** Copy constructor
*/
RPNCalculator::RPNCalculator(const RPNCalculator &other) {
	*this = other;
}

/*
** Copy assignment operator
*/
RPNCalculator &RPNCalculator::operator=(const RPNCalculator &other) {
	if (this != &other) {
		_stack = other._stack;
	}
	return *this;
}

RPNCalculator::~RPNCalculator() {
}

/* 
** `result()`
** Returns the value currently on top of the stack
*/
int RPNCalculator::result() {
	while (_stack.size() > 1) {
		_stack.pop();
	}
	return _stack.top();
}

/*
** Pushes a value onto the stack
*/
void RPNCalculator::push(int value) {
	_stack.push(value);
}

/*
** `performOperation(char operator)`
** Pops two values, 
** performs the operation, based on the operator passed in, 
** and pushes the result back onto the stack
*/
void RPNCalculator::performOperation(char op) {

	int a, b;

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

bool	RPNCalculator::isInSet(char c, std::string set) {

	for (int i = 0; set[i]; i++) {

		if (c == set[i]) {
			return true;
		}
	}
	return false;
}

bool	RPNCalculator::isValidOperator(char c) {

	return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool	RPNCalculator::isValidOperand(char c) {
	return (isdigit(c));
}

/*
** This check makes sure that the number of operands
** is always greater than the number of operators by 1 or more.
*/
bool	RPNCalculator::isEnoughOperands(int operandCount, int operatorCount) {

	if (operandCount > 0 && operatorCount == 0) {
		return (false);
	}
	return (operandCount - operatorCount >= 1);
}

bool	RPNCalculator::isValidExpression(std::string expression) {

	int		operandCount = 0;
	int		operatorCount = 0;

	for (int i = 0; expression[i]; i++) {
		if (isspace(expression[i])) {
			continue;
		}
		else if (isValidOperand(expression[i])) {
			operandCount++;
		} else if (isValidOperator(expression[i])) {
			operatorCount++;
			if (!isEnoughOperands(operandCount, operatorCount)) {
				return (false);
			}
		} else {
			return (false);
		}
	}
	return (isEnoughOperands(operandCount, operatorCount));
}
