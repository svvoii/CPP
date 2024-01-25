/*
** Here we define the ScalarConverter class
**
** It contains a method `convert(std::string const &input)`,
** it takes a string representing literal value of a scalar type.
**
** Example of `char` literal:
** `c`, `a`, ... (any character). If a conversion to char
** is not displayable, we print "Non displayable".
**
** Example of `int` literal:
** `0`, `42`, `-42`, ... (any integer).
**
** Example of `float` literal:
** `0.0f`, `42.0f`, `-42.0f`, `0.42f`, ... (any float).
** Pseudo-literals like `-inff`, `+inff`, `nanf` are handled as well.
**
** Example of `double` literal:
** `0.0`, `4.2`, `-4.2`, `0.42`, ... (any double).
** Pseudo-literals like `-inf`, `+inf`, `nan` are handled as well.
*/

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(const std::string &input): _input(input) {

	_char = 0;
	_int = 0;
	_float = 0;
	_double = 0;
	// std::cout << "ScalarConverter constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &other) {
	// std::cout << "ScalarConverter copy constructor called" << std::endl;
	*this = other;
}

ScalarConverter::~ScalarConverter() {
	// std::cout << "ScalarConverter destructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other) {
	// std::cout << "ScalarConverter assignation operator called" << std::endl;
	if (this != &other) {
		_input = other._input;
		_char = other._char;
		_int = other._int;
		_float = other._float;
		_double = other._double;
	}
	return *this;
}

bool	ScalarConverter::isSpecialFloatDouble() {
	return (_input == "inff" || _input == "-inff" || _input == "+inff" || _input == "nanf" ||
			_input == "inf" || _input == "-inf" || _input == "+inf" || _input == "nan");
}

int		ScalarConverter::getPrecision(bool isDouble) {

	int precision = 1;
	size_t dot = _input.find('.');

	if (dot == std::string::npos) {
		return precision;
	}
	else {
		size_t nonZeroPos = _input.find_last_not_of('0');
		precision = nonZeroPos - dot - 1;
		return std::min(precision, isDouble ? 15 : 7);
	}
}

void ScalarConverter::convert(const std::string &input) {

	ScalarConverter converter(input);
	converter.printChar();
	converter.printInt();
	converter.printFloat();
	converter.printDouble();
}

void ScalarConverter::printChar() {

	if (_input.length() == 1 && !std::isdigit(_input[0])) {
		_char = _input[0];
	}
	else {
		int tmp;
		std::stringstream ss(_input);
		ss >> tmp;

		if (ss.fail()) {
			std::cout << "char: impossible" << std::endl;
			return;
		}
		else {
			_char = static_cast<char>(tmp);
		}
	}

	if (std::isprint(_char)) {
		std::cout << "char: '" << _char << "'" << std::endl;
	}
	else {
		std::cout << "char: Non displayable" << std::endl;
	}
}

void ScalarConverter::printInt() {
	
	std::stringstream ss(_input);
	ss >> _int;

	if (ss.fail()) {
		std::cout << "int: impossible" << std::endl;
	}
	else {
		std::cout << "int: " << _int << std::endl;
	}
}

void ScalarConverter::printFloat() {

	int precision = getPrecision(false);

	if (isSpecialFloatDouble()) {
		_float = strtof(_input.c_str(), NULL);
	}
	else {
		std::stringstream ss(_input);
		ss >> _float;

		if (ss.fail()) {
			std::cout << "float: impossible" << std::endl;
			return;
		}
	}
	
	if (std::isinf(_float) || std::isnan(_float)) {
		std::cout << "float: " << _float << "f" << std::endl;
	}
	else {
		std::cout << "float: " << std::fixed << std::setprecision(precision) << _float << "f" << std::endl;
	}
}

void ScalarConverter::printDouble() {
	
	int precision = getPrecision(true);
	
	if (isSpecialFloatDouble()) {
		_double = strtod(_input.c_str(), NULL);
	}
	else {
		std::stringstream ss(_input);
		ss >> _double;

		if (ss.fail()) {
			std::cout << "double: impossible" << std::endl;
			return;
		}
	}
	
	if (std::isinf(_double) || std::isnan(_double)) {
		std::cout << "double: " << _double << std::endl;
	}
	else {
		std::cout << "double: " << std::fixed << std::setprecision(precision) << _double << std::endl;
	}
}
