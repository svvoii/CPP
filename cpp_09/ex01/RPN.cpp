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

bool	isInSet(char c, std::string set) {
	for (int i = 0; set[i]; i++) {
		if (c == set[i]) {
			return (true);
		}
	}
	return (false);
}

bool	isValidOperator(char c) {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool	isValidOperand(char c) {
	return (isdigit(c));
}

/*
** This check makes sure that the number of operands
** is always greater than the number of operators by 1 or more.
*/
bool	isEnoughOperands(int operandCount, int operatorCount) {
	if (operandCount > 0 && operatorCount == 0) {
		return (false);
	}
	return (operandCount - operatorCount >= 1);
}

bool	isValidExpression(std::string expression) {
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
