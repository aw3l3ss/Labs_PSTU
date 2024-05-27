#include "number.h"

Number::Number() {
    mantissa = 0.0;
    exponent = 0;
}

Number::Number(float mantissa, int exponent, std::string num) {
    this->mantissa = mantissa;
    this->exponent = exponent;
    this->num = num;
}

void Number::set_mantissa(float mantissa) {
    this->mantissa = mantissa;
}

void Number::set_exponent(int exponent) {
    this->exponent = exponent;
}

float Number::get_mantissa() {
    return mantissa;
}

int Number::get_exponent() {
    return exponent;
}

std::string Number::get_num() {
    return num;
}