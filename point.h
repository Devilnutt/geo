#ifndef POINT_H
#define POINT_H

class Point {
public:
    Point(double x, double y);

    double getX() const;
    double getY() const;

private:
    double x_;
    double y_;
};

#endif