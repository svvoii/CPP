#include "Fixed.hpp"

#define EXPECTED_OUTPUT "0\n0.00390625\n0.00390625\n0.00390625\n0.0078125\n10.1016\n10.1016\n"

std::string boolToString(bool b) {
	return b ? "true" : "false";
}

int main(void) {

	{
		std::cout << std::endl << MAGENTA;
		std::cout << "= = = = = = = = = = ====== = = = = = = = = = =" << std::endl;
		std::cout << "= = = = = = = = = = TEST 0 = = = = = = = = = =" << std::endl;
		std::cout << "= = = = = = = = = = ====== = = = = = = = = = =" << std::endl;
		std::cout << "Basic test from the task description." << RESET << std::endl;
		std::cout << "Expected output:" << std::endl;
		std::cout << MAGENTA << EXPECTED_OUTPUT << RESET << std::endl;
		std::cout << "Actual output:" << std::endl;

		Fixed a;
		Fixed const b(Fixed(5.05f) * Fixed(2));

		std::cout << "a:\t["<< a << "]" << std::endl;
		std::cout << "++a\t[" << ++a << "]" << std::endl;
		std::cout << "a:\t[" << a << "]" << std::endl;
		std::cout << "a++:\t[\n" << a++ << "]" << std::endl;
		std::cout << "a:\t[" << a << "]" << std::endl;
		std::cout << "b:\t[" << b << "]" << std::endl;
		std::cout << "max(a, b): [" << Fixed::max(a, b) << "]" << std::endl;
		/*
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max(a, b) << std::endl;
		*/
	}
	{
		std::cout << std::endl << MAGENTA;
		std::cout << "= = = = = = = = = = ====== = = = = = = = = = =" << std::endl;
		std::cout << "= = = = = = = = = =  TEST  = = = = = = = = = =" << std::endl;
		std::cout << "= = = = = = = = = = ====== = = = = = = = = = =" << std::endl;
		std::cout << "  > < == !=  COMPARISON OPERATORS  != == < >" << RESET << std::endl;
		std::cout << RESET << std::endl;

		float	a_fl	= -5.5f;
		int 	b_int	= 3;
		float	c_fl	= 5.5f;

		std::cout << BLUE << "Using `Fixed a(5.5f);` and `Fixed b(2);`" << RESET << std::endl;
		Fixed a(a_fl);
		Fixed b(b_int);
		Fixed c(c_fl);

		std::cout << std::endl;
		std::cout << "Output of raw `a`, `b` and `c`:" << std::endl;
		std::cout << "a:\t[" << a << "]" << std::endl;
		std::cout << "b:\t[" << b << "]" << std::endl;
		std::cout << "c:\t[" << c << "]" << std::endl;

		bool aIsBigger = (a > b);
		std::cout << BLUE << "Using `bool aIsBigger = (a > b);`" << RESET;
		std::cout << "( " << a << " > " << b << " )" << std::endl;
		std::cout << "aIsBigger:\t[" << boolToString(aIsBigger) << "]" << std::endl;
		std::cout << "expected:\t[" << boolToString(a_fl > b_int) << "]\n" << std::endl;

		bool aIsSmaller = (a < b);
		std::cout << BLUE << "Using `bool aIsSmaller = (a < b);`" << RESET;
		std::cout << "( " << a << " < " << b << " )" << std::endl;
		std::cout << "aIsSmaller:\t[" << boolToString(aIsSmaller) << "]" << std::endl;
		std::cout << "expected:\t[" << boolToString(a_fl < b_int) << "]\n" << std::endl;

		bool aIsBiggerOrEqual = (a >= b);
		std::cout << BLUE << "Using `bool aIsBiggerOrEqual = (a >= b);`" << RESET;
		std::cout << "( " << a << " >= " << b << " )" << std::endl;
		std::cout << "aIsBiggOrEq:\t[" << boolToString(aIsBiggerOrEqual) << "]" << std::endl;
		std::cout << "expected:\t[" << boolToString(a_fl >= b_int) << "]\n" << std::endl;

		bool aIsSmallerOrEqual = (a <= b);
		std::cout << BLUE << "Using `bool aIsSmallerOrEqual = (a <= b);`" << RESET;
		std::cout << "( " << a << " <= " << b << " )" << std::endl;
		std::cout << "aIsSmallOrEq:\t[" << boolToString(aIsSmallerOrEqual) << "]" << std::endl;
		std::cout << "expected:\t[" << boolToString(a_fl <= b_int) << "]\n" << std::endl;

		bool aIsEqual = (a == b);
		std::cout << BLUE << "`bool aIsEqual = (a == b);`" << RESET << "( " << a << " == " << b << " )" << std::endl;
		std::cout << "aIsEqual:\t[" << boolToString(aIsEqual) << "]" << std::endl;
		std::cout << "expected:\t[" << boolToString(a_fl == b_int) << "]\n" << std::endl;

		bool aIsNotEqual = (a != b);
		std::cout << BLUE << "`bool aIsNotEqual = (a != b);`" << RESET << "( " << a << " != " << b << " )" << std::endl;
		std::cout << "aIsNotEqual:\t[" << boolToString(aIsNotEqual) << "]" << std::endl;
		std::cout << "expected:\t[" << boolToString(a_fl != b_int) << "]\n" << std::endl;

		bool aIsEqualc = (a == c);
		std::cout << BLUE << "`bool aIsEqual = (a == c);`" << RESET << "( " << a << " == " << c << " )" << std::endl;
		std::cout << "aIsEqual:\t[" << boolToString(aIsEqualc) << "]" << std::endl;
		std::cout << "expected:\t[" << boolToString(a_fl == c_fl) << "]\n" << std::endl;

		bool aIsNotEqualc = (a != c);
		std::cout << BLUE << "Using `bool aIsNotEqual = (a != c);`" << RESET << "( " << a << " != " << c << " )" << std::endl;
		std::cout << "aIsNotEqual:\t[" << boolToString(aIsNotEqualc) << "]" << std::endl;
		std::cout << "expected:\t[" << boolToString(a_fl != c_fl) << "]\n" << std::endl;

		std::cout << BLUE << "`Fixed zero;`";
		Fixed zero;
		bool aIsNotEqualz = (a != zero);
		std::cout << " and `bool aIsNotEqualz = (a != zero);`" << RESET << "( " << a << " != " << zero << " )" << std::endl;
		std::cout << "aIsNotEqual:\t[" << boolToString(aIsNotEqualz) << "]" << std::endl;
		std::cout << "expected:\t[" << boolToString(a_fl != 0) << "]\n" << std::endl;

		bool aIsEqualz = (a == zero);
		std::cout << BLUE << "`bool aIsEqualz = (a == zero);`" << RESET << "( " << a << " == " << zero << " )" << std::endl;
		std::cout << "aIsEqual:\t[" << boolToString(aIsEqualz) << "]" << std::endl;
		std::cout << "expected:\t[" << boolToString(a_fl == 0) << "]\n" << std::endl;
	}
	{
		std::cout << std::endl << MAGENTA;
		std::cout << "= = = = = = = = = = ====== = = = = = = = = = =" << std::endl;
		std::cout << "= = = = = = = = = =  TEST  = = = = = = = = = =" << std::endl;
		std::cout << "= = = = = = = = = = ====== = = = = = = = = = =" << std::endl;
		std::cout << "  + - * /  ARITHMETIC OPERATORS  / * - +" << RESET << std::endl;
		std::cout << RESET << std::endl;

		std::cout << BLUE << "Using `Fixed a(5.5f);` and `Fixed b(2);`" << RESET << std::endl;
		Fixed a(5.5f);
		Fixed b(2);

		std::cout << "Output of raw `a` and `b`:" << std::endl;
		std::cout << "a:\t[" << a << "]" << std::endl;
		std::cout << "b:\t[" << b << "]" << std::endl;

		std::cout << BLUE << "Using `Fixed c = a + b;`" << RESET << std::endl;
		Fixed addition = a + b;

		std::cout << "Output of `c`:" << std::endl;
		std::cout << "int   addition:\t[" << addition.toInt() << "]" << std::endl;
		std::cout << "float addition:\t[" << addition.toFloat() << "]" << std::endl;

		std::cout << BLUE << "Using `Fixed substraction = a - b;`" << RESET << std::endl;
		Fixed substraction = a - b;

		std::cout << "Output of `substraction`:" << std::endl;
		std::cout << "int   substruction:\t[" << substraction.toInt() << "]" << std::endl;
		std::cout << "float substructio:\t[" << substraction.toFloat() << "]" << std::endl;

		std::cout << BLUE << "Using `Fixed multiplication = a * b;`" << RESET << std::endl;
		Fixed multiplication = a * b;

		std::cout << "Output of `multiplication`:" << std::endl;
		std::cout << "int   multiplication:\t[" << multiplication.toInt() << "]" << std::endl;
		std::cout << "float multiplication:\t[" << multiplication.toFloat() << "]" << std::endl;

		std::cout << BLUE << "Using `Fixed division = a / b;`" << RESET << std::endl;
		Fixed division = a / b;

		std::cout << "Output of `division`:" << std::endl;
		std::cout << "int   division:\t[" << division.toInt() << "]" << std::endl;
		std::cout << "float division:\t[" << division.toFloat() << "]" << std::endl;

		std::cout << BLUE << "Using `Fixed zero;` and `Fixed division = a / zero;`" << RESET << std::endl;
		Fixed zero;
		Fixed divisionByZero = a / zero;

		std::cout << "Output of `divisionByZero`:" << std::endl;
		std::cout << "int   divisionByZero:\t[" << divisionByZero.toInt() << "]" << std::endl;
		std::cout << "float divisionByZero:\t[" << divisionByZero.toFloat() << "]" << std::endl;

		std::cout << BLUE << "Using `Fixed c(2);` and `Fixed d(3);`" << RESET << std::endl;
		Fixed c(-5.5f);
		Fixed d(-2);

		std::cout << "Output of raw `c` and `d`:" << std::endl;
		std::cout << "c:\t[" << c << "]" << std::endl;
		std::cout << "d:\t[" << d << "]" << std::endl;

		std::cout << BLUE << "Using `Fixed e = c + d;`" << RESET << std::endl;
		Fixed e = c + d;

		std::cout << "Output of `e`:" << std::endl;
		std::cout << "int   e:\t[" << e.toInt() << "]" << std::endl;
		std::cout << "float e:\t[" << e.toFloat() << "]" << std::endl;
		
		/*
		std::cout << BLUE << "Using `Fixed int_max(2147483647);` and `Fixed one(1);`" << RESET << std::endl;
		Fixed int_max(2147483647); // 2147483647
		Fixed one(1);

		std::cout << "Output of raw `int_max` and `one`:" << std::endl;
		std::cout << "int_max:\t[" << int_max << "]" << std::endl;
		std::cout << "one:\t\t[" << one << "]" << std::endl;

		std::cout << BLUE << "Using `Fixed int_max_plus_one = int_max + one;`" << RESET << std::endl;
		Fixed int_max_plus_one = int_max + one;

		std::cout << "Output of `int_max_plus_one`:" << std::endl;
		std::cout << "int   int_max_plus_one:\t[" << int_max_plus_one.toInt() << "]" << std::endl;
		std::cout << "float int_max_plus_one:\t[" << int_max_plus_one.toFloat() << "]" << std::endl;

		std::cout << BLUE << "Using `Fixed int_min(-2147483648);` and `Fixed minus_one(-1);`" << RESET << std::endl;
		Fixed int_min(static_cast<int>(-2147483648)); // -2147483648
		Fixed minus_one(-1);

		std::cout << "Output of raw `int_min` and `minus_one`:" << std::endl;
		std::cout << "int_min:\t[" << int_min << "]" << std::endl;
		std::cout << "minus_one:\t[" << minus_one << "]" << std::endl;

		std::cout << BLUE << "Using `Fixed int_min_minus_one = int_min - minus_one;`" << RESET << std::endl;
		Fixed int_min_minus_one = int_min - minus_one;

		std::cout << "Output of `int_min_minus_one`:" << std::endl;
		std::cout << "int   int_min_minus_one:\t[" << int_min_minus_one.toInt() << "]" << std::endl;
		std::cout << "float int_min_minus_one:\t[" << int_min_minus_one.toFloat() << "]" << std::endl;
		*/
	}
	/*
	{
		std::cout << std::endl << MAGENTA;
		std::cout << "= = = = = = = = = = ====== = = = = = = = = = =" << std::endl;
		std::cout << "= = = = = = = = = =  TEST  = = = = = = = = = =" << std::endl;
		std::cout << "= = = = = = = = = = ====== = = = = = = = = = =" << std::endl;
		std::cout << "++ -- INCREMENT AND DECREMENT OPERATORS -- ++" << RESET << std::endl;

		std::cout << BLUE << "Using postfix increment operator as ";
		std::cout << "`Fixed a(5.5f);` and `Fixed b = a++;`" << RESET << std::endl;
		Fixed a(5.5f);
		Fixed b = a++;

		std::cout << "Output of `a` and `b` should be different:" << std::endl;
		std::cout << "a:\t[" << a << "]" << std::endl;
		std::cout << "b:\t[" << b << "]" << std::endl;

		std::cout << BLUE << "Using prefix increment operator as ";
		std::cout << "`Fixed c(5.5f);` and `Fixed d = ++c;`" << RESET << std::endl;
		Fixed c(5.5f);
		Fixed d = ++c;
		
		std::cout << "Output of `c` and `d` should be the same:" << std::endl;
		std::cout << "c:\t[" << c << "]" << std::endl;
		std::cout << "d:\t[" << d << "]" << std::endl;

		std::cout << BLUE << "Using postfix decrement operator as ";
		std::cout << "`Fixed e(42);` and `Fixed f = e--;`" << RESET << std::endl;
		Fixed e(42);
		Fixed f = e--;

		std::cout << "Output of `e` and `f` should be different:" << std::endl;
		std::cout << "e:\t[" << e << "]" << std::endl;
		std::cout << "f:\t[" << f << "]" << std::endl;

		std::cout << BLUE << "Using prefix decrement operator as ";
		std::cout << "`Fixed g(42);` and `Fixed h = --g;`" << RESET << std::endl;
		Fixed g(42);
		Fixed h = --g;

		std::cout << "Output of `g` and `h` should be the same:" << std::endl;
		std::cout << "g:\t[" << g << "]" << std::endl;
		std::cout << "h:\t[" << h << "]" << std::endl;

		std::cout << BLUE << "Using postfix increment operator as ";
		std::cout << "`Fixed fixed(42);` and `fixed.operator++();`" << RESET << std::endl;
		Fixed fixed(42);
		std::cout << "fixed:\t[" << fixed << "]" << std::endl;
		fixed.operator++();
		std::cout << "fixed:\t[" << fixed << "]" << std::endl;
		fixed.operator++();
		std::cout << "fixed:\t[" << fixed << "]" << std::endl;
		fixed.operator++();
		std::cout << "fixed:\t[" << fixed << "]" << std::endl;
		fixed.operator++();

		std::cout << "Output of `fixed` should be incremented by one:" << std::endl;
		std::cout << "fixed:\t[" << fixed << "]" << std::endl;

	}
	{
		std::cout << std::endl << MAGENTA;
		std::cout << "= = = = = = = = = = ====== = = = = = = = = = =" << std::endl;
		std::cout << "= = = = = = = = = = TEST ex01 = = = = = = = = = =" << std::endl;
		std::cout << "= = = = = = = = = = ====== = = = = = = = = = =" << std::endl;
		std::cout << RESET << std::endl;

		std::cout << "Fixed a;" << std::endl;
		Fixed 		a;
		std::cout << "Fixed const b(10);" << std::endl;
		Fixed const b(10);
		std::cout << "Fixed const c(42.42f);" << std::endl;
		Fixed const c(42.42f);
		std::cout << "Fixed const d(b);" << std::endl;
		Fixed const d(b);

		std::cout << "a = Fixed(1234.4321f);" << std::endl;
		a = Fixed(1234.4321f);

		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;
		std::cout << std::endl;
		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	}
	{
		std::cout << std::endl << MAGENTA;
		std::cout << "= = = = = = = = = = ====== = = = = = = = = = =" << std::endl;
		std::cout << "= = = = = = = = = = TEST 1 = = = = = = = = = =" << std::endl;
		std::cout << "= = = = = = = = = = ====== = = = = = = = = = =" << std::endl;
		std::cout << RESET << std::endl;

		std::cout << "Testing basic initialization as: `Fixed fixed;`" << std::endl;
		Fixed fixed;
		std::cout << BLUE << "`_rawBits` value should be initialized to 0" << RESET << std::endl;
		std::cout << "Expect value { [0] }" << std::endl; 
		std::cout << "Actual value { [" << fixed.getRawBits() << "] }" << std::endl;
	
		std::cout << std::endl << MAGENTA;
		std::cout << "= = = = = = = = = = ====== = = = = = = = = = =" << std::endl;
		std::cout << "= = = = = = = = = = TEST 2 = = = = = = = = = =" << std::endl;
		std::cout << "= = = = = = = = = = ====== = = = = = = = = = =" << std::endl;
		std::cout << RESET << std::endl;

		std::cout << "`raw_int = 42`" << std::endl;
		int		raw_int = 42;
		int		expected = raw_int << 8;
		std::cout << "`Fixed fixed2(raw_int);`" << std::endl;
		Fixed	fixed2(raw_int);

		std::cout << BLUE << "The `_rawBits` should be set to the int value shifted left by 8 (_fractionalBits):" << RESET << std::endl;
		std::cout << "Expect value { (" << raw_int << " << 8):\t[" << expected << "] }" << std::endl; 
		std::cout << "Actual value { _rawBits:\t[" << fixed2.getRawBits() << "] }" << std::endl;

		std::cout << std::endl << MAGENTA;
		std::cout << "= = = = = = = = = = ====== = = = = = = = = = =" << std::endl;
		std::cout << "= = = = = = = = = = TEST 3 = = = = = = = = = =" << std::endl;
		std::cout << "= = = = = = = = = = ====== = = = = = = = = = =" << std::endl;
		std::cout << "Initializing object and test variables:`" << RESET << std::endl;

		std::cout << "`raw_f = 3.14f`" << std::endl;
		float	raw_f = 3.14f;
		std::cout << "`expected = roundf(raw2 * pow(2, 8))`" << std::endl;
		expected = roundf(raw_f * pow(2, 8));
		std::cout << "Fixed fixed3(raw)" << std::endl;
		Fixed	fixed3(raw_f);

		std::cout << BLUE << "The `_rawBits` should be set to the float value multiplied by 2^8 (_fractionalBits) and rounded to the nearest integer" << RESET << std::endl;
		std::cout << "Expect value { (" << raw_f << " * pow(2, 8)):\t[" << expected << "] }" << std::endl;
		std::cout << "Actual value { _rawBits:\t\t[" << fixed3.getRawBits() << "] }" << std::endl;

		std::cout << std::endl << MAGENTA;
		std::cout << "= = = = = = = = = = ====== = = = = = = = = = =" << std::endl;
		std::cout << "= = = = = = = = = = TEST 4 = = = = = = = = = =" << std::endl;
		std::cout << "= = = = = = = = = = ====== = = = = = = = = = =" << std::endl;
		std::cout << "Initializing object and test variables:`" << RESET << std::endl;

		std::cout << "`float raw_f = 0.1f`" << std::endl;
		raw_f = 0.1f;
		std::cout << "`expected = roundf(raw2 * pow(2, 8))`" << std::endl;
		expected = roundf(raw_f * pow(2, 8));
		std::cout << "Fixed fixed4(raw)" << std::endl;
		Fixed	fixed4(raw_f);
		
		std::cout << BLUE << "The `_rawBits` should be set to the rounded float with a value that cannot be represented exactly in binary fraction." << RESET << std::endl;
		std::cout << "Expect value { (" << raw_f << " * pow(2, 8)):\t[" << expected << "] }" << std::endl;
		std::cout << "Actual value { _rawBits:\t\t[" << fixed4.getRawBits() << "] }" << std::endl;

		std::cout << std::endl << MAGENTA;
		std::cout << "= = = = = = = = = = ====== = = = = = = = = = =" << std::endl;
		std::cout << "= = = = = = = = = = TEST 5 = = = = = = = = = =" << std::endl;
		std::cout << "= = = = = = = = = = ====== = = = = = = = = = =" << std::endl;
		std::cout << "Initializing object and test variables:`" << RESET << std::endl;

		std::cout << "`raw_int = 1000000000`" << std::endl;
		raw_int = 1000000000;
		std::cout << "`expected = raw > 0 ? raw << 8 : raw >> 8`" << std::endl;
		expected = raw_int > 0 ? raw_int << 8 : raw_int >> 8;
		std::cout << "Fixed fixed5(raw)" << std::endl;
		Fixed	fixed5(raw_int);

		std::cout << BLUE << "The `_rawBits` should be set to the maximum or minimum value if the int value is too big or too small to be represented as a fixed point number." << RESET << std::endl;
		std::cout << "Expect value { (raw > 0 ? raw << 8 : raw >> 8):\t[" << expected << "] }" << std::endl;
		std::cout << "Actual value { _rawBits:\t\t\t[" << fixed5.getRawBits() << "] }" << std::endl;

		std::cout << std::endl << MAGENTA;
		std::cout << "= = = = = = = = = = ====== = = = = = = = = = =" << std::endl;
		std::cout << "= = = = = = = = = = TEST 6 = = = = = = = = = =" << std::endl;
		std::cout << "= = = = = = = = = = ====== = = = = = = = = = =" << std::endl;
		std::cout << "Initializing object and test variables:`" << RESET << std::endl;

		std::cout << "`Fixed fixed6(5);`" << std::endl;
		Fixed	fixed6(5);
		std::cout << "`Fixed fixed7(3);`" << std::endl;
		Fixed	fixed7(3);
		std::cout << "`Fixed fixed8(2);`" << std::endl;
		Fixed	fixed8(2);
		std::cout << "`Fixed result1 = fixed6 + fixed7;`" << std::endl;
		Fixed	result1 = fixed6 + fixed7;

		std::cout << BLUE << "The `+` operator should add the two fixed point numbers and return a new Fixed object." << RESET << std::endl;
		std::cout << "Expect value { (" << (5 << 8) << " + " << (3 << 8) << "):\t[" << (5 << 8) + (3 << 8) << "] >> int:[" << (((5 << 8) + (3 << 8)) >> 8) << "] }" << std::endl;
		std::cout << "Actual value { (" << fixed6.getRawBits() << " + " << fixed7.getRawBits() << "):\t[" << result1.getRawBits() << "], toInt:[" << result1.toInt() << "] }" << std::endl;
		std::cout << std::endl;

		std::cout << "`Fixed result2 = fixed6 - fixed8;`" << std::endl;
		Fixed	result2 = fixed6 - fixed8;

		std::cout << BLUE << "The `-` operator should subtract the two fixed point numbers and return a new Fixed object." << RESET << std::endl;
		std::cout << "Expect value { (" << (5 << 8) << " - " << (2 << 8) << "):\t[" << (5 << 8) - (2 << 8) << "] >> int:[" << (((5 << 8) - (2 << 8)) >> 8) << "] }" << std::endl;
		std::cout << "Actual value { (" << fixed6.getRawBits() << " - " << fixed8.getRawBits() << "):\t[" << result2.getRawBits() << "], toInt:[" << result2.toInt() << "] }" << std::endl;
		std::cout << std::endl;
	}
	*/

	return 0;
}

/* Expected output of the TEST 0:
$> ./a.out
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
$>
*/
