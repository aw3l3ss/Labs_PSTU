#include "complex.h"

Complex::Complex(void):Pair() {
}

Complex::~Complex(void) {
}

Complex::Complex(int first, int second) : Pair(first, second) {}

Complex::Complex(const Complex &complex) : Pair(complex.first, complex.second) {}

void Complex::show() {
    std::cout << first << " + " << second << "i" << std::endl;
}

std::ostream &operator << (std::ostream &out, const Complex &complex) {
    out << complex.first << " + " << complex.second << "i";
    return out;
}

Complex Complex::operator + (const Complex &complex) {
    return Complex(this->first + complex.first, this->second + complex.second);
}

Complex Complex::operator - (const Complex &complex) {
    return Complex(this->first - complex.first, this->second - complex.second);
}

Complex Complex::operator * (const Complex &complex) {
    return Complex(this->first * complex.first - this->second * complex.second, this->first * complex.second + this->second * complex.first);
}