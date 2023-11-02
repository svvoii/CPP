#include "Fixed.hpp"

int main(void) {

	{
		Fixed a;
		Fixed const b(Fixed(5.05f) * Fixed(2));

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max(a, b) << std::endl;
	}
	{
		std::cout << "= = = = = = = = = = TEST 1 = = = = = = = = = =" << std::endl;
		std::cout << "Initializing object as:`" << std::endl;
		Fixed fixed;

		std::cout << "`Fixed fixed;`" << std::endl;
		std::cout << "`_rawBits` value should be initialized to 0" << std::endl;
		std::cout << "Expect value { [0] }" << std::endl; 
		std::cout << "Actual value { [" << fixed.getRawBits() << "] }" << std::endl;
		std::cout << std::endl;
	
		std::cout << "= = = = = = = = = = TEST 2 = = = = = = = = = =" << std::endl;
		std::cout << "Initializing object and test variables:`" << std::endl;
		int		raw_int = 42;
		int		expected = raw_int << 8;
		Fixed	fixed2(raw_int);

		std::cout << "`int raw = 42`" << std::endl;
		std::cout << "`Fixed fixed2(raw);`" << std::endl;
		std::cout << "The `_rawBits` should be set to the int value shifted left by 8 (_fractionalBits):" << std::endl;
		std::cout << "Expect value { (" << raw_int << " << 8):\t[" << expected << "] }" << std::endl; 
		std::cout << "Actual value { _rawBits:\t[" << fixed2.getRawBits() << "] }" << std::endl;
		std::cout << std::endl;

		std::cout << "= = = = = = = = = = TEST 3 = = = = = = = = = =" << std::endl;
		std::cout << "Initializing object and test variables:`" << std::endl;
		float	raw_f = 3.14f;
		expected = roundf(raw_f * pow(2, 8));
		Fixed	fixed3(raw_f);

		std::cout << "`float raw = 3.14f`" << std::endl;
		std::cout << "`int expected = roundf(raw2 * pow(2, 8))`" << std::endl;
		std::cout << "Fixed fixed3(raw)" << std::endl;
		std::cout << "The `_rawBits` should be set to the float value multiplied by 2^8 (_fractionalBits) and rounded to the nearest integer" << std::endl;
		std::cout << "Expect value { (" << raw_f << " * pow(2, 8)):\t[" << expected << "] }" << std::endl;
		std::cout << "Actual value { _rawBits:\t\t[" << fixed3.getRawBits() << "] }" << std::endl;
		std::cout << std::endl;

		std::cout << "= = = = = = = = = = TEST 4 = = = = = = = = = =" << std::endl;
		std::cout << "Initializing object and test variables:`" << std::endl;
		raw_f = 0.1f;
		expected = roundf(raw_f * pow(2, 8));
		Fixed	fixed4(raw_f);
		
		std::cout << "`float raw = 0.1f`" << std::endl;
		std::cout << "`int expected = roundf(raw2 * pow(2, 8))`" << std::endl;
		std::cout << "Fixed fixed4(raw)" << std::endl;
		std::cout << "The `_rawBits` should be set to the rounded float with a value that cannot be represented exactly in binary fraction." << std::endl;
		std::cout << "Expect value { (" << raw_f << " * pow(2, 8)):\t[" << expected << "] }" << std::endl;
		std::cout << "Actual value { _rawBits:\t\t[" << fixed4.getRawBits() << "] }" << std::endl;
		std::cout << std::endl;

		std::cout << "= = = = = = = = = = TEST 5 = = = = = = = = = =" << std::endl;
		std::cout << "Initializing object and test variables:`" << std::endl;
		raw_int = 1000000000;
		expected = raw_int > 0 ? raw_int << 8 : raw_int >> 8;
		Fixed	fixed5(raw_int);

		std::cout << "`int raw = 1000000000`" << std::endl;
		std::cout << "`int expected = raw > 0 ? raw << 8 : raw >> 8`" << std::endl;
		std::cout << "Fixed fixed5(raw)" << std::endl;
		std::cout << "The `_rawBits` should be set to the maximum or minimum value if the int value is too big or too small to be represented as a fixed point number." << std::endl;
		std::cout << "Expect value { (raw > 0 ? raw << 8 : raw >> 8):\t[" << expected << "] }" << std::endl;
		std::cout << "Actual value { _rawBits:\t\t\t[" << fixed5.getRawBits() << "] }" << std::endl;
		std::cout << std::endl;

		std::cout << "= = = = = = = = = = TEST 6 = = = = = = = = = =" << std::endl;
		std::cout << "Initializing object and test variables:`" << std::endl;
		Fixed	fixed6(5);
		Fixed	fixed7(3);
		Fixed	fixed8(2);
		Fixed	result1 = fixed6 + fixed7;
		Fixed	result2 = fixed6 - fixed8;

		std::cout << "`Fixed fixed6(5);`" << std::endl;
		std::cout << "`Fixed fixed7(3);`" << std::endl;
		std::cout << "`Fixed fixed8(2);`" << std::endl;
		std::cout << "`Fixed result1 = fixed6 + fixed7;`" << std::endl;
		std::cout << "`Fixed result2 = fixed6 - fixed8;`" << std::endl;
		std::cout << "The `+` operator should add the two fixed point numbers and return a new Fixed object." << std::endl;
		std::cout << "Expect value { (" << (5 << 8) << " + " << (3 << 8) << "):\t[" << (5 << 8) + (3 << 8) << "] >> int:[" << (((5 << 8) + (3 << 8)) >> 8) << "] }" << std::endl;
		std::cout << "Actual value { (" << fixed6.getRawBits() << " + " << fixed7.getRawBits() << "):\t[" << result1.getRawBits() << "], toInt:[" << result1.toInt() << "] }" << std::endl;
		std::cout << "The `-` operator should subtract the two fixed point numbers and return a new Fixed object." << std::endl;
		std::cout << "Expect value { (" << (5 << 8) << " - " << (2 << 8) << "):\t[" << (5 << 8) - (2 << 8) << "] >> int:[" << (((5 << 8) - (2 << 8)) >> 8) << "] }" << std::endl;
		std::cout << "Actual value { (" << fixed6.getRawBits() << " - " << fixed8.getRawBits() << "):\t[" << result2.getRawBits() << "], toInt:[" << result2.toInt() << "] }" << std::endl;
		std::cout << std::endl;
	}

	return 0;
}
