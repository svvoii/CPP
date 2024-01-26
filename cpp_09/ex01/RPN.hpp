#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>

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
*/

//template <typename T> 
class RPNCalculator {
private:
	std::stack<int> _stack;

public:
	RPNCalculator();
	~RPNCalculator();

	int		result();
	void	push(int value);
	void	performOperation(char op);

	bool	isInSet(char c, std::string set);
	bool	isValidOperator(char c);
	bool	isValidOperand(char c);
	bool	isEnoughOperands(int operandCount, int operatorCount);
	bool	isValidExpression(std::string expression);

};

#endif
