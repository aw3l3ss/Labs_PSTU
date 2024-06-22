#include "time.h"

Time::Time(void) {
    min = 0;
    sec = 0;
}

Time::Time(int min, int sec) {
    this->min = min;
    this->sec = sec;
}

Time::Time(const Time &other) {
    min = other.min;
    sec = other.sec;
}

Time &Time::operator=(const Time& other) {
    min = other.min;
    sec = other.sec;
    return *this;
}

Time::~Time(void) {
}

std::ostream& operator<<(std::ostream& out, const Time& t) {
    out << t.min << ":" << t.sec;
    return out;
}

std::istream& operator>>(std::istream& in, Time& t) {
    in >> t.min >> t.sec;
    return in;
}

Time Time::operator*(const int k) {
    int tmp = min * 60 + sec;
    tmp *= k;
    int newMin = tmp / 60;
    int newSec = tmp % 60;

    return Time(newMin, newSec);
}