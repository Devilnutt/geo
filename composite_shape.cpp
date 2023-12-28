#include <iostream>
#include "composite_shape.h"
#include <algorithm>

CompositeShape::CompositeShape(size_t maxSize) : shapes_(new Shape* [maxSize]), size_(0), maxSize_(maxSize) {}

CompositeShape::~CompositeShape() {
    for (size_t i = 0; i < size_; ++i) {
        delete shapes_[i];
    }
    delete[] shapes_;
}

double CompositeShape::getArea() const {
    double area = 0.0;
    for (size_t i = 0; i < size_; ++i) {
        area += shapes_[i]->getArea();
    }
    return area;
}

FrameRectangle CompositeShape::getFrameRectangle() const {
    if (size_ == 0) {
        return FrameRectangle(0.0, 0.0, Point(0.0, 0.0));
    }

    double left = std::numeric_limits<double>::max();
    double right = std::numeric_limits<double>::min();
    double bottom = std::numeric_limits<double>::max();
    double top = std::numeric_limits<double>::min();

    for (size_t i = 0; i < size_; ++i) {
        FrameRectangle frame = shapes_[i]->getFrameRectangle();
        Point center = frame.getCenter();
        double halfWidth = frame.getWidth() / 2.0;
        double halfHeight = frame.getHeight() / 2.0;

        left = std::min(left, center.getX() - halfWidth);
        right = std::max(right, center.getX() + halfWidth);
        bottom = std::min(bottom, center.getY() - halfHeight);
        top = std::max(top, center.getY() + halfHeight);
    }

    double width = right - left;
    double height = top - bottom;
    double centerX = left + width / 2.0;
    double centerY = bottom + height / 2.0;

    return FrameRectangle(width, height, Point(centerX, centerY));
}

void CompositeShape::move(double dx, double dy) {
    for (size_t i = 0; i < size_; ++i) {
        shapes_[i]->move(dx, dy);
    }
}

void CompositeShape::scale(double factor) {
    if (factor <= 0) {
        std::cerr << std::endl;
        return;
    }

    FrameRectangle frame = getFrameRectangle();
    Point center = frame.getCenter();

    for (size_t i = 0; i < size_; ++i) {
        shapes_[i]->move(-center.getX(), -center.getY());
        shapes_[i]->scale(factor);
        shapes_[i]->move(center.getX(), center.getY());
    }
}

Shape* CompositeShape::clone() const {
    CompositeShape* clone = new CompositeShape(maxSize_);
    for (size_t i = 0; i < size_; ++i) {
        clone->addShape(shapes_[i]->clone());
    }
    return clone;
}

std::string CompositeShape::getName() const {
    return "COMPOSITE_SHAPE";
}

void CompositeShape::addShape(Shape* shape) {
    if (size_ < maxSize_) {
        shapes_[size_++] = shape;
    }
    else {
        std::cerr << std::endl;
    }
}

void CompositeShape::removeShape(size_t index) {
    if (index < size_) {
        delete shapes_[index];
        std::copy(shapes_ + index + 1, shapes_ + size_, shapes_ + index);
        --size_;
    }
    else {
        std::cerr << std::endl;
    }
}