#include <iostream>
#include "vector.h"

int main() {
    Vector a(5);
    std::cout << a << std::endl;
    std::cin >> a;
    std::cout << a << std::endl;
    a[2] = 100;
    std::cout << a << std::endl;
    Vector b(10);
    std::cout << b << std::endl;
    b = a;
    std::cout << b << std::endl;
    Vector c(10); 
    c = b * 2;
    std::cout << c << std::endl;
    std::cout << "the length of a = " << a() << std::endl;

    std::cout << *(a.first()) << std::endl;
    Iterator it = a.first();
    it -= 1;
    std::cout << *it << std::endl;

    return 0;
}