#ifndef COMPLEX_H
#define COMPLEX_H

#include "pair.h"

class Complex : public Pair {
    public:
        Complex(int first, int second);
        Complex(const Complex &complex);
        friend std::ostream &operator << (std::ostream &out, const Complex &complex);
        Complex operator + (const Complex &complex);
        Complex operator - (const Complex &complex);
        Complex operator * (const Complex &complex);
};

#endif