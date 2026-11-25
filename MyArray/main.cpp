#include "MyArray.h"

#include <iostream>

int main() {
    MyArray a(3);
    a.set(0, 6);
    a.set(1, 8);
    a.set(2, 9);

    MyArray b(3);
    b.set(0, 3);
    b.set(1, 2);
    b.set(2, 4);

    std::cout << "A = ";
    a.display();
    std::cout << "\nB = ";
    b.display();

    std::cout << "\nA merge B = ";
    a.merge(b).display();
    std::cout << "\nA + B = ";
    a.add(b).display();
    std::cout << "\nA - B = ";
    a.subtract(b).display();
    std::cout << "\nA * B = ";
    a.multiply(b).display();
    std::cout << "\nA / B = ";
    a.divide(b).display();
    std::cout << '\n';

    std::cout << "\n-- Deep-copy isolation test --\n";
    MyArray copy = a;
    copy.set(0, 100);
    std::cout << "A after changing copy = ";
    a.display();
    std::cout << "\nCopy = ";
    copy.display();
    std::cout << "\nA.size() = " << a.size() << '\n';

    MyArray assigned(2, 7);
    assigned = a;
    assigned.set(1, -8);
    std::cout << "A after copy assignment and change = ";
    a.display();
    std::cout << "\nAssigned = ";
    assigned.display();
    std::cout << '\n';

    std::cout << "\n-- Different-size operation test --\n";
    MyArray c(3);
    c.set(0, 1);
    c.set(1, 2);
    c.set(2, 3);
    MyArray d(2);
    d.set(0, 4);
    d.set(1, 5);
    std::cout << "C + D = ";
    c.add(d).display();
    std::cout << '\n';

    std::cout << "\n-- Bounds and zero-divisor tests --\n";
    a.set(5, 99);
    std::cout << "get(5) result: " << a.get(5) << '\n';
    MyArray zeroDivisor(3, 0);
    zeroDivisor.set(0, 2);
    zeroDivisor.set(2, 3);
    std::cout << "A / {2, 0, 3} = ";
    a.divide(zeroDivisor).display();
    std::cout << '\n';

    MyArray empty;
    std::cout << "Empty array size/display: " << empty.size() << ' ';
    empty.display();
    std::cout << '\n';

    return 0;
}
