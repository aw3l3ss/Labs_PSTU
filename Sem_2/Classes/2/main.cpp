#include <iostream>

#include "number.h"

int main() {
    float mantissa;
    int exponent;
    std::string num;

    std::cout << "Enter mantissa: ";
    std::cin >> mantissa;
    std::cout << "Enter exponent: ";
    std::cin >> exponent;
    std::cout << "Enter number: ";
    std::cin >> num;

    Number n(mantissa, exponent, num);

    std::cout << "Exponent: " << n.get_exponent() << std::endl;
    std::cout << "Mantissa: " << n.get_mantissa() << std::endl;
    std::cout << "Number: " << n.get_num() << std::endl;

    return 0;
}