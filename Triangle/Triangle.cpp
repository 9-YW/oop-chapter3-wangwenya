#include "Triangle.h"

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>

Triangle::Triangle(double sideA, double sideB, double sideC)
    : a(sideA), b(sideB), c(sideC) {
}

void Triangle::Init(double sideA, double sideB, double sideC) {
    a = sideA;
    b = sideB;
    c = sideC;
}

bool Triangle::isTriangle() const {
    const double eps = 1e-9;
    return a > 0.0 && b > 0.0 && c > 0.0
        && a + b > c + eps
        && a + c > b + eps
        && b + c > a + eps;
}

double Triangle::getSideA() const {
    return a;
}

double Triangle::getSideB() const {
    return b;
}

double Triangle::getSideC() const {
    return c;
}

void Triangle::setSideA(double value) {
    if (value <= 0.0) {
        std::cout << "Error: side length must be positive, value ignored.\n";
        return;
    }
    a = value;
}

void Triangle::setSideB(double value) {
    if (value <= 0.0) {
        std::cout << "Error: side length must be positive, value ignored.\n";
        return;
    }
    b = value;
}

void Triangle::setSideC(double value) {
    if (value <= 0.0) {
        std::cout << "Error: side length must be positive, value ignored.\n";
        return;
    }
    c = value;
}

double Triangle::perimeter() const {
    return isTriangle() ? a + b + c : 0.0;
}

double Triangle::area() const {
    if (!isTriangle()) {
        std::cout << "Error: cannot form a triangle\n";
        return 0.0;
    }

    const double p = perimeter() / 2.0;
    return std::sqrt(p * (p - a) * (p - b) * (p - c));
}

int Triangle::typeTriangle() const {
    if (!isTriangle()) {
        return 0;
    }

    double sides[3] = {a, b, c};
    std::sort(sides, sides + 3);
    const double x = sides[0];
    const double y = sides[1];
    const double z = sides[2];
    const double difference = x * x + y * y - z * z;

    if (std::fabs(difference) < 1e-6) {
        return 1;
    }
    return difference > 0.0 ? 2 : 3;
}

void Triangle::display() const {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Sides: " << a << ' ' << b << ' ' << c << '\n';

    if (!isTriangle()) {
        std::cout << "Error: cannot form a triangle\n";
        return;
    }

    const int type = typeTriangle();
    std::cout << "Perimeter: " << perimeter() << '\n';
    std::cout << "Area: " << area() << '\n';
    std::cout << "Type: "
              << (type == 1 ? "直角三角形" :
                  type == 2 ? "锐角三角形" : "钝角三角形")
              << '\n';
}
