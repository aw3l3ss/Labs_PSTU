#ifndef TIME_H
#define TIME_H

#include <iostream>

class Time {
    private:
        int minutes;
        int seconds;
    public:
        Time();
        Time(int minutes, int seconds);
        Time(const Time &time);
        ~Time();

        int get_min();
        int get_sec();
        void set_min(int minutes);
        void set_sec(int seconds);
        
        Time &operator = (const Time &time);
        Time &operator ++ ();
        Time operator ++ (int);
        Time operator + (const Time &time);
        Time operator + (int seconds);
        bool operator == (const Time &time);
        bool operator != (const Time &time);
        
        friend std::istream &operator >> (std::istream &in, Time &t); 
        friend std::ostream &operator << (std::ostream &out, const Time &t);
};

#endif