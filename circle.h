#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : public Shape {
public:
    Circle(double radius, const Point& center);

    double getArea() const override;
    FrameRectangle getFrameRectangle() const override;
    void move(double dx, double dy) override;
    void scale(double factor) override;
    Circle* clone() const override;
    std::string getName() const override;

private:
    double radius_;
    Point center_;
};

#endif