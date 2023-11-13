/*
** In this exercise we will extend the usage of 
** `Fixed` class by adding mopre functionality.
**
** Adding overload of the following operators:
** 6 comparison operators: `>`, `<`, `>=`, `<=`, `==`, `!=`
** 4 arithmetic operators: `+`, `-`, `*`, `/`
** 4 increment/decrement (pre- and post- increment)
** and (pre- and post- decrement) operators.
**
** Some public overloaded member functions:
**
** `static Fixed &min(Fixed &a, Fixed &b);` that takes
** two references on fixed point numbers, and returns
** a reference to the smallest of the two.
**
** `static Fixed const &min(Fixed const &a, Fixed const &b);` 
** that takes two references to constant fixed point numbers,
** and returns a reference to the smallest of the two.
**
** `static Fixed &max(Fixed &a, Fixed &b);` that takes
** two references on fixed point numbers, and returns
** a reference to the biggest of the two.
**
** `static Fixed const &max(Fixed const &a, Fixed const &b);`
** that takes two references to constant fixed point numbers,
** and returns a reference to the biggest of the two.
*/

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

// Defining some ANSI escape codes for consol output colors
# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"

class Fixed {
	private:
		int					_rawBits;
		static const int	_fractionalBits = 8;

	public:
		Fixed(void);
		Fixed(const Fixed &fixed);
		Fixed(const int raw);
		Fixed(const float raw);
		~Fixed(void);

		Fixed &operator=(const Fixed &fixed);

		bool operator>(const Fixed &fixed) const;
		bool operator<(const Fixed &fixed) const;
		bool operator>=(const Fixed &fixed) const;
		bool operator<=(const Fixed &fixed) const;
		bool operator==(const Fixed &fixed) const;
		bool operator!=(const Fixed &fixed) const;

		Fixed operator+(const Fixed &fixed) const;
		Fixed operator-(const Fixed &fixed) const;
		Fixed operator*(const Fixed &fixed) const;
		Fixed operator/(const Fixed &fixed) const;

		Fixed &operator++(void);
		Fixed operator++(int);
		Fixed &operator--(void);
		Fixed operator--(int);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		int toInt(void) const;
		float toFloat(void) const;

		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed const &min(Fixed const &a, Fixed const &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static Fixed const &max(Fixed const &a, Fixed const &b);

};

/*
** The following declaration is used to overload the `std::ostream`
** operator `<<` so that it can be used with the `Fixed` class.
*/
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
