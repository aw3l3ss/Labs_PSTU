#include <iostream>

#include "pair.h"
#include "complex.h"

int main() {
    int a, b;
    std::cout << "Input a: ";
    std::cin >> a;
    std::cout << "Input b: ";
    std::cin >> b;

    Pair p(a, b);

    std::cout << p << std::endl;

    Pair p1(a + 1, b + 1);

    std::cout << p + p1 << std::endl;

    Complex c(a, b);
    Complex c1(a - 1, b - 1);

    std::cout << c << std::endl;
    std::cout << c + c1 << std::endl;
    std::cout << c - c1 << std::endl;
    std::cout << c * c1 << std::endl;

    return 0;
}