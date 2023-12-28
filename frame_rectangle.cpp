#include <iostream>
#include "frame_rectangle.h"

FrameRectangle::FrameRectangle(double width, double height, const Point& pos)
    : width_(width), height_(height), pos_(pos) {}

Point FrameRectangle::getCenter() const {
    return pos_;
}

double FrameRectangle::getWidth() const {
    return width_;
}

double FrameRectangle::getHeight() const {
    return height_;
}