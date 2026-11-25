#include "Point.h"

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>

Point::Point(double xValue, double yValue, double zValue)
    : x(xValue), y(yValue), z(zValue) {
}

void Point::Init(double xValue, double yValue, double zValue) {
    x = xValue;
    y = yValue;
    z = zValue;
}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

double Point::getZ() const {
    return z;
}

void Point::setX(double value) {
    x = value;
}

void Point::setY(double value) {
    y = value;
}

void Point::setZ(double value) {
    z = value;
}

void Point::display() const {
    std::cout << std::fixed << std::setprecision(2)
              << '(' << x << ", " << y << ", " << z << ')';
}

double Point::distanceTo(const Point& other) const {
    const double dx = x - other.x;
    const double dy = y - other.y;
    const double dz = z - other.z;
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}

double euclideanDistance(const Point& a, const Point& b) {
    const double dx = a.x - b.x;
    const double dy = a.y - b.y;
    const double dz = a.z - b.z;
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}

double manhattanDistance(const Point& a, const Point& b) {
    return std::fabs(a.x - b.x)
         + std::fabs(a.y - b.y)
         + std::fabs(a.z - b.z);
}

double chebyshevDistance(const Point& a, const Point& b) {
    return std::max({
        std::fabs(a.x - b.x),
        std::fabs(a.y - b.y),
        std::fabs(a.z - b.z)
    });
}

Point midpoint(const Point& a, const Point& b) {
    return Point((a.x + b.x) / 2.0,
                 (a.y + b.y) / 2.0,
                 (a.z + b.z) / 2.0);
}

double euclideanDistance(const Point& p) {
    return std::sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
}
