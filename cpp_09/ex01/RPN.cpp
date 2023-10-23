#include "RPN.hpp"

double calculateRPN(std::string expression) {
	std::stack<double> operands;
	for (char c : expression) {
		if (isdigit(c)) {
			operands.push(c - '0');
		} else if (c == '+') {
			double op2 = operands.top();
			operands.pop();
			double op1 = operands.top();
			operands.pop();
			operands.push(op1 + op2);
		} else if (c == '-') {
			double op2 = operands.top();
			operands.pop();
			double op1 = operands.top();
			operands.pop();
			operands.push(op1 - op2);
		} else if (c == '*') {
			double op2 = operands.top();
			operands.pop();
			double op1 = operands.top();
			operands.pop();
			operands.push(op1 * op2);
		} else if (c == '/') {
			double op2 = operands.top();
			operands.pop();
			double op1 = operands.top();
			operands.pop();
			operands.push(op1 / op2);
		}
	}
	return operands.top();
}
