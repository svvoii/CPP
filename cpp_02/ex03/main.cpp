#include "includes/Point.hpp"

/*
** The main task of this exercise is to implement a function
** which will determine if a point is inside a triangle or not.
** 
** For that mater we have created a class Point which represents
** a point in a 2D space. It has two private members `_x` and `_y`
** which are fixed const attributes. They represent the coordinates
** of a point.
**
** We have also created a function `bsp` (stands for 
** Binary Space Partitioning) which uses the 'Baricentric coordinate
** system' to determine if a point is inside a triangle or not
** (more on that in the respective file `bsp.cpp`).
**
** `bsp` function takes four arguments:
** `a`, `b`, `c` - three points which represent the vertices of
** a triangle.
** `point` - a point which we will check if it is inside the triangle
** or not.
**
** I also added a visual of the problem.
** It can be found at the bottom of this file, also in the
** `printTriangle` function, as well as in the terminal output.
** It represents the triangle and the points we will check.
*/

void	printResultBSP(Point a, Point b, Point c, Point point);
void	printTriangle();

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

	printTriangle();

	printResultBSP(a, b, c, point1);
	printResultBSP(a, b, c, point2);
	printResultBSP(a, b, c, point3);
	printResultBSP(a, b, c, point4);
	printResultBSP(a, b, c, point5);
	std::cout << std::endl;

	return 0;
}

void	printResultBSP(Point a, Point b, Point c, Point point) {

	std::cout << "Point (" << point.getX() << ", " << point.getY() << ")\t";
	if (bsp(a, b, c, point) == true) {
		std::cout << GREEN << "is within the triangle\t";
	}
	else {
		std::cout << RED << "is outside the triangle\t";
	}
	std::cout << MAGENTA;
	std::cout << "[ a(" << a.getX() << ", " << a.getY() << "), ";
	std::cout << "b(" << b.getX() << ", " << b.getY() << "), ";
	std::cout << "c(" << c.getX() << ", " << c.getY() << ") ]";
	std::cout << RESET << std::endl;
}

void printTriangle() {

	std::cout << std::endl;
	std::cout << MAGENTA << "  B(30, 0)" << std::endl;
	std::cout << "30" << RESET << "  *" << std::endl;
	std::cout << "    |\\ " << std::endl;
	std::cout << "    | \\" << std::endl;
	std::cout << "    |  \\          " << RED << " * " << RESET << "p(25, 25)" << std::endl;
	std::cout << "    |   \\" << std::endl;
	std::cout << "    |    \\" << std::endl;
	std::cout << "    |     \\" << std::endl;
	std::cout << MAGENTA << "20" << RESET << "  |      \\" << std::endl;
	std::cout << "    |       \\" << std::endl;
	std::cout << "    |        \\" << std::endl;
	std::cout << "    |         \\" << RED << "*" << RESET << " p(15, 15)" << std::endl;
	std::cout << "    |      p " << GREEN << "*" << RESET << " \\" << std::endl;
	std::cout << "    |   (14, 14)\\" << std::endl;
	std::cout << "    |            \\" << std::endl;
	std::cout << MAGENTA << "10" << RESET << "  |             \\" << std::endl;
	std::cout << "    |              \\" << std::endl;
	std::cout << "    |               \\" << std::endl;
	std::cout << "    | p(5, 5)        \\" << std::endl;
	std::cout << "    |  " << GREEN << "*" << RESET << "              \\" << std::endl;
	std::cout << "    |                  \\" << std::endl;
	std::cout << MAGENTA << " 0  " << GREEN << "*" << RESET << "–––––––––––––––––––*" << MAGENTA << " C(0, 30)" << std::endl;
	std::cout << MAGENTA << "    A     10    20     30" << std::endl;
	std::cout << "   (0, 0)" << RESET << std::endl;
	std::cout << std::endl;
}

/*
  B(30, 0)
30  *
    |\
    | \
    |  \
    |   \         * p(25, 25)
    |    \
    |     \
20  |      \
    |       \
    |     p *\
    |    (14, \* p(15, 15)
    |     14)  \
    |           \
    |            \
10  |             \
    |              \
    |               \
    | p(5, 5         \
    |  *              \
    |                  \
 0  *–––––––––––––––––––* C(0, 30)
    A     10	 20     30
	(0, 0)
*/
