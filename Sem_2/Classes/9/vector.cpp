#include "vector.h"

Vector::Vector(int s) {
    if (s > MAX_SIZE) {
        throw 1;
    }

    size = s;
    beg = new int[size];
    for (int i = 0; i < size; ++i) {
        beg[i] = 0;
    }
}

Vector::Vector(const Vector &v) {
    size = v.size;
    beg = new int[size];
    for (int i = 0; i < size; ++i) {
        beg[i] = v.beg[i];
    }
}

Vector::Vector(int s, int *mas) {
    if (s > MAX_SIZE) {
        throw 1;
    }

    size = s;
    beg = new int[size];
    for (int i = 0; i < size; ++i) {
        beg[i] = mas[i];
    }
}

Vector::~Vector() {
    if (beg) {
        delete[] beg;
    }
}

const Vector &Vector::operator=(const Vector &v) { 
    if (this == &v) {
        return *this;
    }

    if (beg) {
        delete[] beg;
    }

    size = v.size;
    beg = new int[size];
    for (int i = 0; i < size; ++i) {
        beg[i] = v.beg[i];
    }

    return *this;
}

std::ostream& operator<<(std::ostream& out, const Vector &v) {
    if (v.size == 0) {
        out << "Empty!" << std::endl;
    }

    else {
        for (int i = 0; i < v.size; ++i) {
            out << v.beg[i] << " ";
        }
        out << std::endl;
    }

    return out;
}

std::istream& operator>>(std::istream& in, Vector &v) {
    for (int i = 0; i < v.size; ++i) {
        in >> v.beg[i];
    }

    return in;
}

int &Vector::operator[](int i) {
    if (i < 0) {
        throw 2;
    }

    if (i >= size) {
        throw 3;
    }

    return beg[i];  
}

Vector &Vector::operator--() {
    if (size == 0) {
        throw 4;
    }

    if (size == 1) {
        size = 0;
        delete [] beg;
        beg = 0;
        return *this;
    }

    Vector temp(size, beg);
    delete [] beg;
    --size;

    beg = new int[size];
    for (int i = 0; i < size; ++i) {
        beg[i] = temp.beg[i];
    }

    return *this;
}


Vector Vector::operator--(int) {
    if (size == 0) {
        throw 4;
    }

    if (size == 1) {
        size = 0;
        delete [] beg;
        beg = 0;
        return *this;
    }

    Vector temp(size, beg);
    delete [] beg;
    --size;

    beg = new int[size];
    for (int i = 0; i < size; ++i) {
        beg[i] = temp.beg[i + 1];
    }

    return *this;
}