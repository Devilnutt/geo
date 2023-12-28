#include <iostream>
#include "circle.h"

Circle::Circle(double radius, const Point& center) : radius_(radius), center_(center) {}

double Circle::getArea() const {
    return 3.14159 * radius_ * radius_;
}

FrameRectangle Circle::getFrameRectangle() const {
    return FrameRectangle(2 * radius_, 2 * radius_, center_);
}

void Circle::move(double dx, double dy) {
    center_ = Point(center_.getX() + dx, center_.getY() + dy);
}

void Circle::scale(double factor) {
    if (factor <= 0) {
        std::cerr << std::endl;
        return;
    }

    radius_ *= factor;
}

Circle* Circle::clone() const {
    return new Circle(*this);
}

std::string Circle::getName() const {
    return "CIRCLE";
}