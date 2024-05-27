#include "fraction.h"

#define EPS 0.00001

Fraction::Fraction(double first, double second) {
    this->first = first;
    this->second = second;
}

bool Fraction::range_check(double x) {
    return ((x - first >= EPS) && (second - x >= EPS)); 
}

double Fraction::get_first() {
    return first;
}

double Fraction::get_second() {
    return second;
}