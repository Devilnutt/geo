#include "circle.h"
#include "rectangle.h"
#include <iostream>

void printInfo(const Shape& shape) {
	std::cout << shape.getName() << " " << shape.getArea() << " "
		<< shape.getFrameRectangle().getCenter().getX() << " "
		<< shape.getFrameRectangle().getCenter().getY() << std::endl;
}

int main() {
	Rectangle rectangle(4.0, 6.0, Point(0.0, 0.0));

	std::cout << std::endl;
	printInfo(rectangle);

	rectangle.move(2.0, 3.0);
	std::cout << std::endl;
	printInfo(rectangle);

	rectangle.scale(2.0);
	std::cout << std::endl;
	printInfo(rectangle);
	return 0;
}