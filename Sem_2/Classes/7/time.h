#ifndef TIME_H
#define TIME_H

#include <iostream>

class Time {
    private:
        int min;
        int sec;
    public:
        Time(void);
        Time(int, int);
        Time(const Time&);
        Time &operator=(const Time&);
        virtual ~Time(void);
        friend std::ostream& operator<<(std::ostream& out, const Time&);
        friend std::istream& operator>>(std::istream& in, Time&);
        Time operator*(const int);
};

#endif