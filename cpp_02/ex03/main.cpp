#include "includes/Point.hpp"

void	printResultBSP(Point a, Point b, Point c, Point point) {

	std::cout << "Point(" << point.getX() << ", " << point.getY() << ")\t";
	if (bsp(a, b, c, point) == true) {
		std::cout << "is inside the triangle\t[ ";
	}
	else {
		std::cout << "is outside the triangle\t[ ";
	}
	std::cout << "a(" << a.getX() << ", " << a.getY() << "), ";
	std::cout << "b(" << b.getX() << ", " << b.getY() << "), ";
	std::cout << "c(" << c.getX() << ", " << c.getY() << ") ]";
	std::cout << std::endl;
}

int		main(void) {

	// Triangle vertices
	Point a(0, 0);
	Point b(30, 0);
	Point c(0, 30);

	// Test points
	Point point1(5, 5);
	Point point2(14, 14);
	Point point3(15, 15);
	Point point4(25, 25);
	Point point5(0, 0);

	printResultBSP(a, b, c, point1);
	printResultBSP(a, b, c, point2);
	printResultBSP(a, b, c, point3);
	printResultBSP(a, b, c, point4);
	printResultBSP(a, b, c, point5);

	return 0;
}

