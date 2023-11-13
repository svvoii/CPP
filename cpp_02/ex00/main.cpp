/*
** This module starts with the introduction of the
** Orthodox Canonical Form of the class.
**
** The Orthodox Canonical Form of the class is a set of
** 4 members:
** The default constructor.
** The copy constructor.
** The assignment operator overload.
** The destructor.
** 
** In this exercise we are asked to implement the
** `Fixed` class. See `Fixed.hpp` for details.
*/
#include "Fixed.hpp"

int	main(void) {

	{
		Fixed a;
		Fixed b(a);
		Fixed c;

		c = b;

		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;

	}
	/*
	{
		Fixed d(10);
		Fixed e(20);

		std::cout << "d: " << d << std::endl;
		std::cout << "e: " << e << std::endl;

		Fixed f = d + e;
		std::cout << "f = d + e: " << f << std::endl;

		Fixed g = d - e;
		std::cout << "g = d - e: " << g << std::endl;

		Fixed h = d * e;
		std::cout << "h = d * e: " << h << std::endl;

		Fixed i = d / e;
		std::cout << "i = d / e: " << i << std::endl;

		std::cout << "d > e: " << (d > e) << std::endl;
		std::cout << "d < e: " << (d < e) << std::endl;
		std::cout << "d >= e: " << (d >= e) << std::endl;
		std::cout << "d <= e: " << (d <= e) << std::endl;
		std::cout << "d == e: " << (d == e) << std::endl;
		std::cout << "d != e: " << (d != e) << std::endl;

		std::cout << "d++: " << d++ << std::endl;
		std::cout << "++d: " << ++d << std::endl;
		std::cout << "d--: " << d-- << std::endl;
		std::cout << "--d: " << --d << std::endl;

		std::cout << "d max e: " << Fixed::max(d, e) << std::endl;
		std::cout << "d min e: " << Fixed::min(d, e) << std::endl;
		
	}

	a.setRawBits(42);
	std::cout << a.getRawBits() << std::endl;
	*/

	return 0;
}
