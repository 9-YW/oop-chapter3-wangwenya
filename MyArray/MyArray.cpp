#include "MyArray.h"

#include <iostream>

MyArray::MyArray()
    : p(nullptr), N(0) {
}

MyArray::MyArray(int n, int value)
    : p(nullptr), N(0) {
    if (n <= 0) {
        if (n < 0) {
            std::cout << "Error: array size cannot be negative.\n";
        }
        return;
    }

    p = new int[n];
    N = n;
    for (int i = 0; i < N; ++i) {
        p[i] = value;
    }
}

MyArray::MyArray(const MyArray& other)
    : p(nullptr), N(other.N) {
    if (N <= 0) {
        N = 0;
        return;
    }

    p = new int[N];
    for (int i = 0; i < N; ++i) {
        p[i] = other.p[i];
    }
}

MyArray& MyArray::operator=(const MyArray& other) {
    if (this == &other) {
        return *this;
    }

    int* newData = nullptr;
    if (other.N > 0) {
        newData = new int[other.N];
        for (int i = 0; i < other.N; ++i) {
            newData[i] = other.p[i];
        }
    }

    delete[] p;
    p = newData;
    N = other.N;
    return *this;
}

MyArray::~MyArray() {
    delete[] p;
    p = nullptr;
    N = 0;
}

int MyArray::size() const {
    return N;
}

int MyArray::get(int index) const {
    if (index < 0 || index >= N) {
        std::cout << "Error: index " << index << " is out of range.\n";
        return 0;
    }
    return p[index];
}

void MyArray::set(int index, int value) {
    if (index < 0 || index >= N) {
        std::cout << "Error: index " << index
                  << " is out of range, set operation ignored.\n";
        return;
    }
    p[index] = value;
}

void MyArray::display() const {
    std::cout << '{';
    for (int i = 0; i < N; ++i) {
        if (i != 0) {
            std::cout << ", ";
        }
        std::cout << p[i];
    }
    std::cout << '}';
}

MyArray MyArray::merge(const MyArray& other) const {
    MyArray result(N + other.N);
    for (int i = 0; i < N; ++i) {
        result.p[i] = p[i];
    }
    for (int i = 0; i < other.N; ++i) {
        result.p[N + i] = other.p[i];
    }
    return result;
}

MyArray MyArray::add(const MyArray& other) const {
    const int count = shorterSize(*this, other);
    warnDifferentSizes(*this, other);
    MyArray result(count);
    for (int i = 0; i < count; ++i) {
        result.p[i] = p[i] + other.p[i];
    }
    return result;
}

MyArray MyArray::subtract(const MyArray& other) const {
    const int count = shorterSize(*this, other);
    warnDifferentSizes(*this, other);
    MyArray result(count);
    for (int i = 0; i < count; ++i) {
        result.p[i] = p[i] - other.p[i];
    }
    return result;
}

MyArray MyArray::multiply(const MyArray& other) const {
    const int count = shorterSize(*this, other);
    warnDifferentSizes(*this, other);
    MyArray result(count);
    for (int i = 0; i < count; ++i) {
        result.p[i] = p[i] * other.p[i];
    }
    return result;
}

MyArray MyArray::divide(const MyArray& other) const {
    const int count = shorterSize(*this, other);
    warnDifferentSizes(*this, other);
    MyArray result(count);
    for (int i = 0; i < count; ++i) {
        if (other.p[i] == 0) {
            std::cout << "Warning: divisor at index " << i
                      << " is zero, result set to 0.\n";
            result.p[i] = 0;
        } else {
            result.p[i] = p[i] / other.p[i];
        }
    }
    return result;
}

int MyArray::shorterSize(const MyArray& left, const MyArray& right) {
    return left.N < right.N ? left.N : right.N;
}

void MyArray::warnDifferentSizes(const MyArray& left, const MyArray& right) {
    if (left.N == right.N) {
        return;
    }

    std::cout << "Warning: different sizes (" << left.N << " vs " << right.N
              << "), use the shorter one\n";
}
