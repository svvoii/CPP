/*
** This exccercise is about conversion of scalar types.
** `static class ScalarConverter` contains a method 
** `convert(std::string const &input)`, it takes a string
** representing literal value of a scalar type.
** It must belong to one of the following scalar types:
** `char`, `int`, `float`, `double`.
*/

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <sstream>
# include <iomanip>
# include <limits>
# include <cmath>

class ScalarConverter {
	private:
		std::string _input;
		char		_char;
		int			_int;
		float		_float;
		double		_double;

		bool		isSpecialFloatDouble();
		int			getPrecision(bool isDouble);
		
	public:
		ScalarConverter(std::string const &input);
		ScalarConverter(ScalarConverter const &other);
		~ScalarConverter();
		ScalarConverter &operator=(ScalarConverter const &other);
		
		static void convert(const std::string &input);

		void printChar();
		void printInt();
		void printFloat();
		void printDouble();

};

#endif
