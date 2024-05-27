#include <iostream>

#include "fraction.h"

int main() {
    double x1, x2;
    std::cout << "First: ";
    std::cin >> x1;
    std::cout << "Second: ";
    std::cin >> x2;

    Fraction f(x1, x2);

    double x;
    std::cout << "x: ";
    std::cin >> x;

    std::cout << f.range_check(x) << std::endl;

    return 0;
}