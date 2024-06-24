#include <iostream>

#include "vector.h"

int main() {
    try {
        Vector x(2);
        Vector y;

        std::cout << x;

        int i;
        std::cin >> i;

        std::cout << x[i] << std::endl;
        std::cout << y[i] << std::endl;

        y = x;

        --x;
        std::cout << x << std::endl;

        y--;
        std::cout << y << std::endl;
        y--;
        std::cout << y << std::endl;
        y--;
        std::cout << y << std::endl;
    }

    catch (int) {
        std::cout << "Error" << std::endl;
    }

    return 0;
}