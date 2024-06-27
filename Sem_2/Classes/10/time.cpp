#include "time.h"

Time::Time() {
    seconds = 0;
    minutes = 0;
}

Time::Time(int s, int m) {
    seconds = s;
    minutes = m;
}

Time::Time(Time &other) {
    seconds = other.seconds;
    minutes = other.minutes;
}

Time::~Time() {
}

Time Time::operator=(const Time &other) {
    seconds = other.seconds;
    minutes = other.minutes;
    return *this;
}

Time Time::operator+(const int s) {
    int tmp = minutes * 60 + seconds + s;

    Time result;
    result.minutes = tmp / 60;
    result.seconds = tmp % 60;
    return result;
}

Time Time::operator+(const Time &other) {
    int tmp = minutes * 60 + seconds + other.minutes * 60 + other.seconds;

    Time result;
    result.minutes = tmp / 60;
    result.seconds = tmp % 60;
    return result;
}

bool Time::operator==(const Time &other) const{
    return seconds == other.seconds && minutes == other.minutes;
}

bool Time::operator!=(const Time &other) const{
    return seconds != other.seconds || minutes != other.minutes;
}

bool Time::operator<(const Time &other) const{
    return minutes * 60 + seconds < other.minutes * 60 + other.seconds;
}

bool Time::operator>(const Time &other) const{
    return minutes * 60 + seconds > other.minutes * 60 + other.seconds;
}

std::ostream &operator<<(std::ostream &out, const Time &time) {
    out << time.minutes << ":" << time.seconds;
    return out;
}

std::istream &operator>>(std::istream &in, Time &time) {
    in >> time.minutes >> time.seconds;
    return in;
}

std::fstream &operator<<(std::fstream &fout, const Time &time) {
    fout << time.minutes << std::endl << time.seconds << std::endl;
    return fout;
}

std::fstream &operator>>(std::fstream &fin, Time &time) {
    fin >> time.minutes;
    fin >> time.seconds;
    return fin;
}