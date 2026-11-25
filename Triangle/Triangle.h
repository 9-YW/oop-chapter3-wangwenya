#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle {
public:
    Triangle(double a = 1.0, double b = 1.0, double c = 1.0);

    void Init(double a, double b, double c);

    bool isTriangle() const;

    double getSideA() const;
    double getSideB() const;
    double getSideC() const;

    void setSideA(double value);
    void setSideB(double value);
    void setSideC(double value);

    double perimeter() const;
    double area() const;
    int typeTriangle() const;
    void display() const;

private:
    double a;
    double b;
    double c;
};

#endif
