#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape {
public:
    Rectangle(double width, double height, const Point& pos);

    double getArea() const override;
    FrameRectangle getFrameRectangle() const override;
    void move(double dx, double dy) override;
    void scale(double factor) override;
    Rectangle* clone() const override;
    std::string getName() const override;

private:
    double width_;
    double height_;
    Point pos_;
};

#endif