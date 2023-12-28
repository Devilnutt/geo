#ifndef FRAME_RECTANGLE_H
#define FRAME_RECTANGLE_H

#include "point.h"

class FrameRectangle {
public:
    FrameRectangle(double width, double height, const Point& pos);

    Point getCenter() const;
    double getWidth() const;
    double getHeight() const;

private:
    double width_;
    double height_;
    Point pos_;
};

#endif