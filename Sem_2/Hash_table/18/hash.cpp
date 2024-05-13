#include "hash.h"

#define A 0.756389

double mod1(double n) {
    return n - static_cast<int>(n);
}

int get_hash(double k, int m) {
    return static_cast<int>(m * mod1(k * A));
}

int get_hash(std::string s, int m) {
    int hash = 5381;
    for (int i = 0; i < s.length(); i++) {
        hash = ((hash << 5) + hash) + s[i];
    }

    return get_hash(abs(hash), m);
}