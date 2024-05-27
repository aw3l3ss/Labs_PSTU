#ifndef NUMBER_H
#define NUMBER_H

#include <string>

class Number {
    private:
        float mantissa;
        int exponent;
        std::string num;
    public:
        Number();
        Number(float mantissa, int exponent, std::string num);
        void set_mantissa(float mantissa);
        void set_exponent(int exponent);
        float get_mantissa();
        int get_exponent();
        std::string get_num();
};

#endif