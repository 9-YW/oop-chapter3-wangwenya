#include "Triangle.h"

#include <iostream>

int main() {
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;

    std::cout << "Enter three sides: ";
    if (!(std::cin >> a >> b >> c)) {
        std::cerr << "Error: invalid input format.\n";
        return 1;
    }

    Triangle triangle(a, b, c);
    triangle.display();

    std::cout << "\n-- Acute triangle test --\n";
    triangle.Init(5.0, 5.0, 6.0);
    triangle.display();

    std::cout << "\n-- Obtuse triangle test --\n";
    triangle.Init(2.0, 3.0, 4.0);
    triangle.display();

    std::cout << "\n-- Invalid setter test --\n";
    triangle.setSideA(-2.0);
    std::cout << "Sides remain: " << triangle.getSideA() << ' '
              << triangle.getSideB() << ' ' << triangle.getSideC() << '\n';

    std::cout << "\n-- Invalid triangle test --\n";
    Triangle invalid(1.0, 2.0, 5.0);
    invalid.display();

    return 0;
}
