#include <iostream>
#include <cmath>

double sin_number(int x, double sin, int num, double c, int n) {
    sin += c;
    if (n == num) {
        return sin;
    }
    ++n; 
    c = c * (-1) * x * x / ((2 * n - 1) * (2 * n - 2));
    return sin_number(x, sin, num, c, n);
}



int main() {
    int n, x;
    std::cout << "sin(x) = ?" << std::endl;
    std::cout << "x = ";
    std::cin >> x;
    std::cout << "n = ";
    std::cin >> n;
    std::cout << "sin(" << x << ") = " << sin_number(x, 0, n, x, 1) << std::endl;
    std::cout << "std::sin(" << x << ") = " << std::sin(x) << std::endl;

    return 0;
}