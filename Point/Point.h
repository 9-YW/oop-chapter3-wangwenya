#ifndef POINT_H
#define POINT_H

class Point {
public:
    Point(double x = 0.0, double y = 0.0, double z = 0.0);

    void Init(double x, double y, double z);

    double getX() const;
    double getY() const;
    double getZ() const;

    void setX(double value);
    void setY(double value);
    void setZ(double value);

    void display() const;
    double distanceTo(const Point& other) const;

    friend double euclideanDistance(const Point& a, const Point& b);
    friend double manhattanDistance(const Point& a, const Point& b);
    friend double chebyshevDistance(const Point& a, const Point& b);
    friend Point midpoint(const Point& a, const Point& b);
    friend double euclideanDistance(const Point& p);

private:
    double x;
    double y;
    double z;
};

#endif
