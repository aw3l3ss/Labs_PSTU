#include <iostream>

#include "object.h"
#include "pair.h"
#include "complex.h"
#include "vector.h"

int main() {
    Vector v(5);
    Pair a;
    std::cin >> a; 
    Complex b;
    std::cin >> b; 
    Object*p=&a;
    v.add_object(p);
    p=&b;
    v.add_object(p);
    std::cout << v;

    return 0;
}