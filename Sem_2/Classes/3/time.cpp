#include "time.h"

Time::Time() {
    minutes = 0;
    seconds = 0;
}
        
Time::Time(int minutes, int seconds) {
    this->minutes = minutes;
    this->seconds = seconds;

    if (seconds >= 60) {
        minutes += seconds / 60;
        seconds %= 60;
    }
}

Time::Time(const Time &time) {
    this->minutes = time.minutes;
    this->seconds = time.seconds;
}

Time::~Time() {
    minutes = 0;
    seconds = 0;
}

int Time::get_min() {
    return minutes;
}

int Time::get_sec() {
    return seconds;
}

void Time::set_min(int minutes) {
    this->minutes = minutes;
}

void Time::set_sec(int seconds) {
    this->seconds = seconds;

    if (seconds >= 60) {
        minutes += seconds / 60;
        seconds %= 60;
    }
}
        
Time &Time::operator = (const Time &time) {
    this->minutes = time.minutes;
    this->seconds = time.seconds;

    return *this;
}

Time &Time::operator ++ () {
    ++seconds;

    if (seconds >= 60) {
        ++minutes;
        seconds %= 60;
    }

    return *this;
}

Time Time::operator ++ (int) {
    Time temp = *this;
    ++seconds;

    if (seconds >= 60) {
        ++minutes;
        seconds %= 60;
    }

    return temp;
}

Time Time::operator + (const Time &time) {
    Time temp;
    temp.minutes = this->minutes + time.minutes;
    temp.seconds = this->seconds + time.seconds;

    if (temp.seconds >= 60) {
        temp.minutes += temp.seconds / 60;
        temp.seconds %= 60;
    }

    return temp;
}

Time Time::operator + (int seconds) {
    Time temp;
    temp.minutes = this->minutes;
    temp.seconds = this->seconds + seconds;

    if (temp.seconds >= 60) {
        temp.minutes += temp.seconds / 60;
        temp.seconds %= 60;
    }

    return temp;
}

bool Time::operator == (const Time &time) {
    return (this->minutes == time.minutes && this->seconds == time.seconds);
}

bool Time::operator != (const Time &time) {
    return (this->minutes!= time.minutes || this->seconds!= time.seconds);
}
        
std::istream &operator >> (std::istream &in, Time &t) {
    in >> t.minutes >> t.seconds;

    if (t.seconds >= 60) {
        t.minutes += t.seconds / 60;
        t.seconds %= 60;
    }

    return in;
}

std::ostream &operator << (std::ostream &out, const Time &t) {
    out << t.minutes << ":" << t.seconds;

    return out;
}