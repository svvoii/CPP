/*
** This is the implementation of the class Point.
** It consists of the following members and methods:
**
** Private members:
** `_x` and `_y` are fixed const attributes which represent
** the coordinates of a point.
**
** Public members:
** `Point(void)` is the default constructor. It initializes
** the coordinates `_x` and `_y` to 0.
** 
** `Point(const float x, const float y)` - constructor which
** takes two float arguments and initializes the coordinates
** `_x` and `_y` accordingly.
**
** `Point(const Point &point)` - copy constructor.
**
** `~Point(void)` - destructor.
**
** `Point &operator=(const Point &point)` - assignment operator overload.
**
** `Fixed getX(void) const` - getter for the `_x` coordinate.
** `Fixed getY(void) const` - getter for the `_y` coordinate.
*/

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
	private:
		Fixed const	_x;
		Fixed const	_y;

	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Point &point);
		~Point(void);

		Point &operator=(const Point &point);

		Fixed getX(void) const;
		Fixed getY(void) const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif

/*
** `Fixed` is our class we created in the previous exercises.
*/
