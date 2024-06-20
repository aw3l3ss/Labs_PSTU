#include "vector.h"

Vector::Vector() {
    beg = 0;
    size = 0;
    cur = 0;
}

Vector::~Vector() {
    if (beg) {
        delete[] beg;
        beg = 0;
    }
}

Vector::Vector(int n) {
    beg = new Object*[n];
    cur = 0;
    size = n;
}

void Vector::add_object(Object *p) {
    if (cur < size) {
        beg[cur] = p;
        cur++;
    }
}

std::ostream& operator<<(std::ostream& os, const Vector& v) {
    if (v.size == 0) {
        os << "Vector is empty" << std::endl;
        return os;
    }

    Object **p = v.beg;

    for (int i = 0; i < v.cur; i++) {
        (*p)->show();
        p++;
    }

    return os;
}