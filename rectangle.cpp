#include "rectangle.h"
#include <iostream>

Rectangle::Rectangle(double width, double height, const Point& pos)
    : width_(width), height_(height), pos_(pos) {}

double Rectangle::getArea() const {
    return width_ * height_;
}

FrameRectangle Rectangle::getFrameRectangle() const {
    return FrameRectangle(width_, height_, pos_);
}

void Rectangle::move(double dx, double dy) {
    pos_ = Point(pos_.getX() + dx, pos_.getY() + dy);
}

void Rectangle::scale(double factor) {
    if (factor <= 0) {
        std::cerr << std::endl;
        return;
    }

    width_ *= factor;
    height_ *= factor;
}

Rectangle* Rectangle::clone() const {
    return new Rectangle(*this);
}

std::string Rectangle::getName() const {
    return "RECTANGLE";
}