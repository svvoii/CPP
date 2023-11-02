#include "../includes/Point.hpp"

Point::Point(void) : _x(0), _y(0) {
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
}

/*
** This is the copy constructor we explicitly copy the attributes
** `_x` and `_y` from the `point` object to the current object.
** Otherwise, the `point` values will NOT be copied to the current object.
*/
Point::Point(const Point &point) : _x(point._x), _y(point._y) {
	// std::cout << "\t < Copy constructor called";
	if (this == &point) {
		// std::cout << ", self-copying >" << std::endl;
		return ;
	}
	*this = point;
	// std::cout << " _x: " << this->_x << ", _y: " << this->_y << " >" << std::endl;
}

Point::~Point(void) {
}

/*
** This is the assignment operator overload.
** `(Fixed)` is used to cast the `Fixed` object to a `float` value.
** since the `_x` and `_y` attributes are of type `Fixed`, 
** so we need to cast the `float` value to a `Fixed` object.
*/
Point &Point::operator=(const Point &point) {
	(Fixed)this->_x = point.getX();
	(Fixed)this->_y = point.getY();
	return *this;
}

Fixed Point::getX(void) const {
	return this->_x;
}

Fixed Point::getY(void) const {
	return this->_y;
}
