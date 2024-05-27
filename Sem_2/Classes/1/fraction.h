#ifndef FRACTION_H
#define FRACTION_H

class Fraction {
    private:
        double first;
        double second;
    public:
        Fraction(double first, double second);
        bool range_check(double x);
        double get_first();
        double get_second();
};

#endif