#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <fstream>

class Time {
    private:
        int seconds;
        int minutes;
    public:
        Time();
        Time(int seconds, int minutes);
        Time(Time &other);
        ~Time();

        Time operator=(const Time &other);
        Time operator+(const int seconds);
        Time operator+(const Time &other);
        bool operator==(const Time &other) const;
        bool operator!=(const Time &other) const;
        bool operator<(const Time &other) const;
        bool operator>(const Time &other) const;

        friend std::ostream &operator<<(std::ostream &out, const Time &time);
        friend std::istream &operator>>(std::istream &in, Time &time);

        friend std::fstream &operator<<(std::fstream &fout, const Time &time);
        friend std::fstream &operator>>(std::fstream &fin, Time &time);
};

#endif