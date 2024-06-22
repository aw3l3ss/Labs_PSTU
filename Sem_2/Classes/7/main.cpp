#include <iostream>
#include "vector.h"
#include "time.h"

int main() {
    Time t;
    std::cin >> t;
    std::cout << t << std::endl;

    Vector<Time> A(5, t);
    std::cin >> A;
    std::cout << A << std::endl;

    Vector<Time> B(10, t);
    std::cout << B << std::endl;

    B = A;
    std::cout << B << std::endl;
    std::cout << A[2] << std::endl;
    std::cout << "size A = " << A() << std::endl;

    B = A * 2;
    std::cout << A << std::endl;
    std::cout << B << std::endl;

    return 0;
}