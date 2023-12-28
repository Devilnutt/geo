#ifndef COMPOSITE_SHAPE_H
#define COMPOSITE_SHAPE_H

#include "shape.h"

class CompositeShape : public Shape {
public:
    explicit CompositeShape(size_t maxSize);
    ~CompositeShape() override;

    double getArea() const override;
    FrameRectangle getFrameRectangle() const override;
    void move(double dx, double dy) override;
    void scale(double factor) override;
    Shape* clone() const override;
    std::string getName() const override;

    void addShape(Shape* shape);
    void removeShape(size_t index);

private:
    Shape** shapes_;
    size_t size_;
    size_t maxSize_;
};

#endif