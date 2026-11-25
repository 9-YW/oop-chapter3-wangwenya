#include "Point.h"

#include <iomanip>
#include <iostream>

int main() {
    double x1 = 0.0;
    double y1 = 0.0;
    double z1 = 0.0;
    double x2 = 0.0;
    double y2 = 0.0;
    double z2 = 0.0;

    std::cout << "Enter point A (x y z): ";
    if (!(std::cin >> x1 >> y1 >> z1)) {
        std::cerr << "Error: invalid input for A.\n";
        return 1;
    }
    std::cout << "Enter point B (x y z): ";
    if (!(std::cin >> x2 >> y2 >> z2)) {
        std::cerr << "Error: invalid input for B.\n";
        return 1;
    }

    const Point a(x1, y1, z1);
    const Point b(x2, y2, z2);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "A = ";
    a.display();
    std::cout << "\nB = ";
    b.display();
    std::cout << "\nEuclidean distance: " << euclideanDistance(a, b);
    std::cout << "\nManhattan distance: " << manhattanDistance(a, b);
    std::cout << "\nChebyshev distance: " << chebyshevDistance(a, b);
    std::cout << "\nMidpoint: ";
    midpoint(a, b).display();
    std::cout << '\n';

    std::cout << "\n-- Member vs friend test --\n";
    std::cout << "a.distanceTo(b) = " << a.distanceTo(b) << '\n';

    std::cout << "\n-- Origin distance overload test --\n";
    std::cout << "euclideanDistance(B) = " << euclideanDistance(b) << '\n';

    Point changed;
    changed.Init(1.0, 2.0, 3.0);
    changed.setX(4.5);
    std::cout << "\n-- Init and accessor test --\n";
    std::cout << "changed = ";
    changed.display();
    std::cout << "\nGetters: " << changed.getX() << ' '
              << changed.getY() << ' ' << changed.getZ() << '\n';

    return 0;
}
