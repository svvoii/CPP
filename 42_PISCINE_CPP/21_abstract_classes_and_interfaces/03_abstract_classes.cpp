#include <iostream>

// Abstract class
class Shape
{
public:
	// Pure virtual function
	virtual double area() = 0;
};

// Derived class
class Rectangle : public Shape
{
public:
	Rectangle(double w, double h) : width(w), height(h) {}
	double area() { return width * height; }

private:
	double width;
	double height;
};

int main()
{
	// Shape s; // Error: Cannot instantiate abstract class
	Rectangle r(5, 10);
	std::cout << "Area of rectangle: " << r.area() << std::endl;
	return 0;
}

/*
** The purpose of abstract classes and pure virtual functions 
** is to provide a way to define a common interface for a group of
** related classes, while allowing each class to 
** implement the interface in its own way. 
**
** In this example, the Shape class defines a common interface for shapes,
** while the Rectangle class implements that interface in its own way
** by calculating the area of a rectangle. 
** By using an abstract class and pure virtual functions,
** you can ensure that each derived class implements the required functionality, 
** while still providing a common interface for the program
** to interact with all shapes.
*/
