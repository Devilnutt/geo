#ifndef SHAPE_H
#define SHAPE_H

#include "frame_rectangle.h"
#include <string>

class Shape {
public:
    virtual double getArea() const = 0;
    virtual FrameRectangle getFrameRectangle() const = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void scale(double factor) = 0;
    virtual Shape* clone() const = 0;
    virtual std::string getName() const = 0;
    virtual ~Shape() = default;
};

#endif