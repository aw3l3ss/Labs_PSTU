#include "pair.h"

Pair::Pair(int first, int second) {
    this->first = first;
    this->second = second;
}

Pair::Pair(const Pair &pair) {
    this->first = pair.first;
    this->second = pair.second;
}
        
int Pair::get_first() {
    return first;
}

int Pair::get_second() {
    return second;
}

void Pair::set_first(int first) {
    this->first = first;
}

void Pair::set_second(int second) {
    this->second = second;
}
        
Pair Pair::operator + (const Pair &pair) {
    return Pair(this->first + pair.first, this->second + pair.second);
}
        
std::istream &operator >> (std::istream &in, Pair &pair) {
    in >> pair.first >> pair.second;
    return in;
}

std::ostream &operator << (std::ostream &out, const Pair &pair) {
    out << "(" << pair.first << "," << pair.second << ")";
    return out;
}